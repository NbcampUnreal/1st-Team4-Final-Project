import time
import os
import subprocess
from watchdog.observers import Observer
from watchdog.events import FileSystemEventHandler

# 감시할 폴더 리스트(오빠 프로젝트에 맞게 수정!)
WATCH_PATHS = [
    "./Source/Ember/Public",
    "./Source/Ember/Private"
]
# 실행할 bat 파일 (bat 파일도 프로젝트 루트에 둘 것!)
BAT_FILE = "GenerateProjectFiles.bat"

class ChangeHandler(FileSystemEventHandler):
    def on_any_event(self, event):
        # 파일 추가/삭제/이름변경 감지 시만 실행
        if event.event_type in ['created', 'deleted', 'moved']:
            print(f"변경 감지됨: {event.src_path} → bat 실행 중!")
            subprocess.run([BAT_FILE], shell=True)

if __name__ == "__main__":
    observer = Observer()
    for path in WATCH_PATHS:
        abs_path = os.path.abspath(path)
        if os.path.exists(abs_path):
            observer.schedule(ChangeHandler(), abs_path, recursive=True)
            print(f"[INFO] 감시 시작: {abs_path}")
        else:
            print(f"[WARNING] 경로가 존재하지 않음: {abs_path}")
    observer.start()
    print("[INFO] 폴더 변경 감시 중... (종료: Ctrl+C)")
    try:
        while True:
            time.sleep(1)
    except KeyboardInterrupt:
        observer.stop()
    observer.join()
