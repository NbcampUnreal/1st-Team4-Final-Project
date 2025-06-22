@echo off
SETLOCAL

REM --- 1. 현재 배치 파일이 있는 디렉토리 (AutoGenerate)를 스크립트 실행 경로로 설정 ---
SET "CURRENT_DIR=%~dp0"
CD /D "%CURRENT_DIR%"

REM --- 2. Python 실행 파일 경로 찾기 ---
SET PYTHON_EXE="C:\Users\wypka\AppData\Local\Programs\Python\Python312\python.exe" 
REM ^-- 이 경로가 정확해야 해요!

IF NOT EXIST %PYTHON_EXE% (
    ECHO 오류: 지정된 파이썬 실행 파일 경로가 올바르지 않습니다. 😢
    ECHO 현재 설정된 경로: %PYTHON_EXE%
    ECHO 'StartProjectWatcher.bat' 파일 내 PYTHON_EXE 변수를 확인해주세요.
    PAUSE
    GOTO :EOF
)

REM --- 3. 실행할 파이썬 스크립트 경로 설정 (AutoGenerate 폴더 내) ---
SET SCRIPT_NAME=auto_generate_project.py
SET SCRIPT_PATH="%CURRENT_DIR%%SCRIPT_NAME%" 

IF NOT EXIST %SCRIPT_PATH% (
    ECHO 오류: 파이썬 스크립트 '%SCRIPT_NAME%'을 찾을 수 없습니다! 😢
    ECHO '%SCRIPT_NAME%'이 AutoGenerate 폴더에 있는지 확인해주세요.
    PAUSE
    GOTO :EOF
)

ECHO 파이썬 스크립트 '%SCRIPT_NAME%'을 실행합니다...
ECHO (종료하려면 열리는 콘솔 창을 닫거나 Ctrl+C를 누르세요.)

REM --- 4. 파이썬 스크립트 실행 ---
REM 'start ""' 명령어를 사용하면 이 배치 파일 창과 별개로 새로운 콘솔 창에서 파이썬 스크립트가 실행돼요.
REM 아래 중복된 명령어를 제거했습니다. 이제 스크립트는 한 번만 실행됩니다!
start "" %PYTHON_EXE% %SCRIPT_PATH%

REM 파이썬 스크립트가 별도의 창에서 실행되므로, 이 배치 파일 창은 바로 닫히도록 PAUSE를 제거합니다.
REM (테스트용으로 오류 메시지를 확인해야 할 때는 PAUSE를 다시 추가할 수 있습니다.)
REM PAUSE 
ENDLOCAL