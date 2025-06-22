import time
import os
import subprocess
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler
import threading
import json
import collections
import locale
import sys # sys 모듈 추가

# 스크립트가 위치한 디렉토리를 AutoGenerate 폴더로 간주
SCRIPT_DIR = os.path.dirname(os.path.abspath(__file__))
CONFIG_FILE_PATH = os.path.join(SCRIPT_DIR, "config.json")

# 설정 파일 로드
try:
    with open(CONFIG_FILE_PATH, 'r', encoding='utf-8') as f:
        config = json.load(f)
except FileNotFoundError:
    print(f"[ERROR] 설정 파일 (config.json)을 찾을 수 없습니다: {CONFIG_FILE_PATH}")
    # 파일이 없으면 그냥 종료. 배치 파일에서 PAUSE로 메시지 확인 가능.
    sys.exit(1) # sys.exit 사용
except json.JSONDecodeError:
    print(f"[ERROR] config.json 파일 형식이 올바르지 않습니다. 파싱 실패.")
    sys.exit(1) # sys.exit 사용

# 설정값 가져오기
PROJECT_ROOT_PATH = os.path.abspath(os.path.join(SCRIPT_DIR, config.get("ProjectRootPath", "..")))
WATCH_PATHS = config.get("WatchPaths", ["Source", "Plugins"])
RUN_FILE = config.get("GenerateScript", "GenerateProjectFile.ps1")

DEBOUNCE_TIME_FOR_MODIFIED_MS = config.get("DebounceTimeForModifiedMs", 100)
DEBOUNCE_TIME_FOR_OTHER_EVENTS_MS = config.get("DebounceTimeForOtherEventsMs", 100)
DEFAULT_DEBOUNCE_TIME_MS_DISPLAY = config.get("DebounceTimeMs", 300000)

class ChangeHandler(FileSystemEventHandler):
    def __init__(self):
        super().__init__()
        self.timer = None
        self.last_event_time = 0
        self.debounce_lock = threading.Lock()
        self.recent_events = collections.deque(maxlen=10)

    def on_any_event(self, event):
        current_time = time.time()
        
        if event.event_type not in ['modified', 'created', 'deleted', 'moved', 'renamed']:
            return

        ignored_extensions = ['.obj', '.pdb', '.tmp', '.user', '.log', '.ilk', '.ipch', '.sdf', '.vs', '.VC.opendb', '.suo', '.ncb', '.bak', '~', '.swp', '.lock']
        if any(event.src_path.lower().endswith(ext) for ext in ignored_extensions):
            return
        
        normalized_path = event.src_path.lower().replace(os.sep, '/')
        ignored_dirs = ['/intermediate/', '/saved/', '/binaries/', '/build/', '/deriveddata/', '/staging/']
        if any(ignored_dir in normalized_path for ignored_dir in ignored_dirs):
            return

        event_key = (event.event_type, event.src_path)
        for timestamp, key in list(self.recent_events): 
            if current_time - timestamp > 0.1:
                self.recent_events.popleft()
            else:
                if key == event_key:
                    return
        self.recent_events.append((current_time, event_key))

        print(f"[INFO] 변경 감지됨: {event.src_path} (이벤트 타입: {event.event_type})")

        if event.event_type == 'modified':
            delay_ms = DEBOUNCE_TIME_FOR_MODIFIED_MS
            delay_reason = f"소스 변경 ({delay_ms / 1000.0}초 지연)"
        else:
            delay_ms = DEBOUNCE_TIME_FOR_OTHER_EVENTS_MS
            delay_reason = f"파일/폴더 추가/삭제/이동 ({delay_ms / 1000.0}초 지연)"
        
        with self.debounce_lock:
            if self.timer is not None:
                self.timer.cancel()

            self.last_event_time = current_time
            self.current_delay_ms = delay_ms
            
            print(f"[INFO] 프로젝트 갱신 예약됨: {delay_reason}. 추가 변경 감지 시 재예약.")
            self.timer = threading.Timer(delay_ms / 1000.0, self.run_update_script)
            self.timer.start()

    def run_update_script(self):
        with self.debounce_lock:
            if (time.time() - self.last_event_time) * 1000 < self.current_delay_ms:
                return

            self.timer = None 

            print(f"[INFO] 예약된 지연 시간 ({self.current_delay_ms/1000.0}초) 만료. VS 프로젝트 갱신 시작!")
            try:
                run_file_full_path = os.path.join(SCRIPT_DIR, RUN_FILE)

                if not os.path.exists(run_file_full_path):
                    print(f"[ERROR] 실행할 스크립트를 찾을 수 없습니다: {run_file_full_path}")
                    return

                try_encodings = ['utf-8', locale.getdefaultlocale()[1], 'latin-1'] # latin-1은 최종 fallback
                chosen_encoding = None
                
                # subprocess.run 호출 시 오류가 발생해도 스크립트가 멈추지 않도록 다시 try-except로 감쌈
                try:
                    for enc in try_encodings:
                        try:
                            # stdout, stderr를 decode='unicode_escape'나 errors='ignore'로 더 강하게 처리
                            # text=True는 유니코드 디코딩을 자동으로 시도하므로, 여기서는 raw bytes를 받고 직접 디코딩 시도
                            if RUN_FILE.lower().endswith(".ps1"):
                                proc = subprocess.Popen(["powershell", "-ExecutionPolicy", "Bypass", "-File", run_file_full_path], 
                                                        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                                        text=False, # 텍스트 모드 비활성화, 바이트 스트림으로 받음
                                                        creationflags=subprocess.CREATE_NO_WINDOW # PowerShell 창 안 보이게
                                                       )
                            else: # .bat 파일 등
                                proc = subprocess.Popen([run_file_full_path], shell=True, 
                                                        stdout=subprocess.PIPE, stderr=subprocess.PIPE,
                                                        text=False, # 텍스트 모드 비활성화, 바이트 스트림으로 받음
                                                        creationflags=subprocess.CREATE_NO_WINDOW
                                                       )
                            stdout_bytes, stderr_bytes = proc.communicate(timeout=600) # 10분 타임아웃 추가

                            # 바이트 스트림을 여러 인코딩으로 수동 디코딩 시도
                            for decode_enc in try_encodings:
                                try:
                                    stdout_decoded = stdout_bytes.decode(decode_enc, errors='replace')
                                    stderr_decoded = stderr_bytes.decode(decode_enc, errors='replace')
                                    chosen_encoding = decode_enc
                                    break
                                except UnicodeDecodeError:
                                    continue # 다음 인코딩 시도
                            
                            if not chosen_encoding:
                                stdout_decoded = stdout_bytes.decode('latin-1', errors='replace') # 최종적으로 latin-1
                                stderr_decoded = stderr_bytes.decode('latin-1', errors='replace')
                                chosen_encoding = 'latin-1 (fallback)'

                            if proc.returncode != 0:
                                print(f"[ERROR] 스크립트 실행 실패 (종료 코드: {proc.returncode}) (인코딩: {chosen_encoding})")
                                print(f"[STDOUT]\n{stdout_decoded}")
                                print(f"[STDERR]\n{stderr_decoded}")
                            else:
                                print(f"[SUCCESS] 스크립트 실행 완료! (인코딩: {chosen_encoding})")
                                if stdout_decoded:
                                    print(f"[STDOUT]\n{stdout_decoded}")
                                if stderr_decoded:
                                    print(f"[STDERR]\n{stderr_decoded}")
                            break # 성공적으로 실행 및 디코딩했으니 루프 종료

                        except UnicodeDecodeError:
                            print(f"[WARNING] {enc} 인코딩으로 실행 결과 읽기 실패, 다음 인코딩 시도...")
                            continue # 다음 인코딩으로 subprocess.run 재시도
                        except subprocess.TimeoutExpired:
                            print(f"[ERROR] 스크립트 실행 시간 초과 (10분). 강제 종료합니다.")
                            proc.kill()
                            stdout_bytes, stderr_bytes = proc.communicate()
                            print(f"[STDOUT (partial)]\n{stdout_bytes.decode('latin-1', errors='replace')}")
                            print(f"[STDERR (partial)]\n{stderr_bytes.decode('latin-1', errors='replace')}")
                            break # 타임아웃 발생했으므로 더 이상 시도하지 않음
                        except FileNotFoundError:
                            print(f"[ERROR] 실행 파일을 찾을 수 없습니다. 경로를 확인해주세요.")
                            raise # 상위 예외 처리기로 전달
                        except Exception as inner_e:
                            print(f"[ERROR] 스크립트 실행 중 예기치 않은 내부 오류 발생: {inner_e}")
                            raise # 상위 예외 처리기로 전달

                except Exception as final_e: # 최상위 예외 처리
                    print(f"[CRITICAL ERROR] run_update_script 실행 중 치명적인 오류 발생: {final_e}")

            except FileNotFoundError:
                print(f"[ERROR] 스크립트 또는 PowerShell/dotnet 실행 파일을 찾을 수 없습니다. 경로를 확인해주세요.")
            except Exception as e:
                print(f"[ERROR] 예기치 않은 오류 발생: {e}")

if __name__ == "__main__":
    observer = Observer()
    
    absolute_watch_paths = []
    for path in WATCH_PATHS:
        abs_path = os.path.join(PROJECT_ROOT_PATH, path) 
        if os.path.exists(abs_path):
            observer.schedule(ChangeHandler(), abs_path, recursive=True)
            print(f"[INFO] 감시 시작: {abs_path}")
            absolute_watch_paths.append(abs_path)
        else:
            print(f"[WARNING] 감시 경로가 존재하지 않음: {abs_path}")
            print(f"[WARNING] 프로젝트 루트 ({PROJECT_ROOT_PATH}) 기준으로 경로를 확인해주세요.")
    
    if not absolute_watch_paths:
        print("[ERROR] 감시할 유효한 경로가 없습니다. 스크립트를 종료합니다. 😢")
        sys.exit(1) # 유효한 경로 없으면 종료
    else:
        observer.start()
        print(f"[INFO] 폴더 변경 감시 중... (기본: {DEFAULT_DEBOUNCE_TIME_MS_DISPLAY/1000.0}초 / 수정: {DEBOUNCE_TIME_FOR_MODIFIED_MS/1000.0}초 / 기타: {DEBOUNCE_TIME_FOR_OTHER_EVENTS_MS/1000.0}초 지연 적용) (종료: Ctrl+C)")
        try:
            while True:
                time.sleep(1)
        except KeyboardInterrupt:
            observer.stop()
            print("[INFO] 폴더 감시 중지 중...")
        except Exception as e:
            print(f"[CRITICAL ERROR] 예기치 않은 종료: {e}")
        finally:
            observer.join()
            print("[INFO] 폴더 감시가 종료되었습니다.")