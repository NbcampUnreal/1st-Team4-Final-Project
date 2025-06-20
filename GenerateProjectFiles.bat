@echo off
setlocal enabledelayedexpansion

REM 현재 폴더에서 .uproject 자동 감지
set UPROJECT=.\EMBER.uproject

if not defined UPROJECT (
    echo [ERROR] .uproject 파일을 찾을 수 없습니다!
    pause
    exit /b 1
)
echo [INFO] 감지된 프로젝트 파일: !UPROJECT!

REM 최신 엔진 경로 자동 감지
set UE_BASE=%ProgramFiles%\Epic Games
set LATEST_UE=
for /f "delims=" %%d in ('dir "%UE_BASE%\UE_*" /ad /b /o-n') do (
    if not defined LATEST_UE (
        set LATEST_UE=%UE_BASE%\%%d
    )
)
if not defined LATEST_UE (
    echo [ERROR] Unreal Engine이 설치된 경로를 찾을 수 없습니다!
    pause
    exit /b 1
)
echo [INFO] 감지된 최신 엔진 경로: %LATEST_UE%

REM UnrealEditor.exe 경로 설정
set UE_EDITOR="%LATEST_UE%\Engine\Binaries\Win64\UnrealEditor.exe" -projectfiles -game -engine
if not exist %UE_EDITOR% (
    echo [ERROR] UnrealEditor.exe 파일을 찾을 수 없습니다!
    pause
    exit /b 1
)

REM 에디터 명령행으로 프로젝트 파일 생성
start "" %UE_EDITOR% "%CD%\!UPROJECT!" -projectfiles -game -engine -log
echo [INFO] 명령을 실행했습니다. 에디터 콘솔 로그를 확인하세요.
pause
