# ----------------------------------------------------
# config.json 파일 자동 업데이트 스크립트 (PowerShell)
# - 프로젝트 루트 경로 및 UE 설치 경로 자동 탐색 및 업데이트
# - UnrealEngineRootPath 필드 추가 및 저장
# - PowerShell 5.1 호환성 강화 (Contains 메서드 오류 수정)
# - 새로운 디바운싱 지연 시간 필드 초기화/업데이트
# ----------------------------------------------------

# 스크립트가 위치한 디렉토리 (AutoGenerate 폴더)를 기준으로 작업
$ScriptDir = Split-Path -Parent $MyInvocation.MyCommand.Definition
$ConfigFilePath = Join-Path -Path $ScriptDir -ChildPath "config.json"

Write-Host "--- config.json 자동 업데이트 스크립트 시작 --- 🚀" -ForegroundColor Yellow

# 기존 config.json 파일 로드 또는 새 JSON 객체 생성
$Config = $null
if (Test-Path $ConfigFilePath) {
    try {
        $Config = Get-Content $ConfigFilePath | ConvertFrom-Json -ErrorAction Stop
        Write-Host "[INFO] 기존 config.json 파일을 로드했습니다." -ForegroundColor DarkCyan
    }
    catch {
        Write-Host "[WARNING] 기존 config.json 파일을 읽거나 파싱하는데 실패했습니다. 새 파일을 생성합니다." -ForegroundColor Yellow
        $Config = New-Object PSObject
    }
} else {
    Write-Host "[INFO] config.json 파일이 없어 새 파일을 생성합니다." -ForegroundColor Cyan
    $Config = New-Object PSObject
}

# config.json에 필요한 필드가 없으면 동적으로 추가 (PowerShell 5.1 호환성 개선)
# 그리고 새로운 디바운싱 필드도 추가
if (-not ($Config | Get-Member -Name "ProjectRootPath" -MemberType NoteProperty -ErrorAction SilentlyContinue)) {
    $Config | Add-Member -MemberType NoteProperty -Name "ProjectRootPath" -Value ".."
}
if (-not ($Config | Get-Member -Name "UnrealEngineVersion" -MemberType NoteProperty -ErrorAction SilentlyContinue)) {
    $Config | Add-Member -MemberType NoteProperty -Name "UnrealEngineVersion" -Value "5.5"
}
if (-not ($Config | Get-Member -Name "UnrealEngineRootPath" -MemberType NoteProperty -ErrorAction SilentlyContinue)) {
    $Config | Add-Member -MemberType NoteProperty -Name "UnrealEngineRootPath" -Value ""
}
if (-not ($Config | Get-Member -Name "WatchPaths" -MemberType NoteProperty -ErrorAction SilentlyContinue)) {
    $Config | Add-Member -MemberType NoteProperty -Name "WatchPaths" -Value @("Source", "Plugins")
}
if (-not ($Config | Get-Member -Name "GenerateScript" -MemberType NoteProperty -ErrorAction SilentlyContinue)) {
    $Config | Add-Member -MemberType NoteProperty -Name "GenerateScript" -Value "GenerateProjectFile.ps1"
}
if (-not ($Config | Get-Member -Name "DebounceTimeMs" -MemberType NoteProperty -ErrorAction SilentlyContinue)) {
    $Config | Add-Member -MemberType NoteProperty -Name "DebounceTimeMs" -Value 1000
}
if (-not ($Config | Get-Member -Name "DebounceTimeMs" -MemberType NoteProperty -ErrorAction SilentlyContinue)) {
    $Config | Add-Member -MemberType NoteProperty -Name "DebounceTimeMs" -Value 300000 # 5분
}
if (-not ($Config | Get-Member -Name "DebounceTimeForModifiedMs" -MemberType NoteProperty -ErrorAction SilentlyContinue)) {
    $Config | Add-Member -MemberType NoteProperty -Name "DebounceTimeForModifiedMs" -Value 100 # 0.1초
}
if (-not ($Config | Get-Member -Name "DebounceTimeForOtherEventsMs" -MemberType NoteProperty -ErrorAction SilentlyContinue)) {
    $Config | Add-Member -MemberType NoteProperty -Name "DebounceTimeForOtherEventsMs" -Value 100 # 0.1초
}

# --- 1. 프로젝트 루트 경로 찾기 ---
Write-Host "[INFO] 프로젝트 루트를 탐색합니다..." -ForegroundColor Cyan
$projectRoot = $null
$currentSearchDir = $ScriptDir # AutoGenerate 폴더부터 시작

# 최대 5단계 상위 디렉토리까지 탐색
for ($i = 0; $i -lt 5; $i++) {
    $uprojectFiles = Get-ChildItem -Path $currentSearchDir -Filter "*.uproject" -ErrorAction SilentlyContinue | Select-Object -First 1
    if ($uprojectFiles) {
        $projectRoot = $currentSearchDir
        break
    }
    $parentDir = Split-Path -Parent $currentSearchDir
    if ($parentDir -eq $currentSearchDir) { # 최상위 디렉토리에 도달
        break
    }
    $currentSearchDir = $parentDir
}

if ($projectRoot) {
    # PowerShell 5.1 호환성을 위해 단순화된 상대 경로 계산
    $relativePath = ".." # 기본값: AutoGenerate 폴더가 프로젝트 루트 바로 아래에 있다고 가정
    if ($projectRoot -eq $ScriptDir) {
        $relativePath = "."
    } elseif ($projectRoot.StartsWith($ScriptDir + "\")) {
        $relativePath = (Get-Item -Path $projectRoot).Name
    }
    
    $Config.ProjectRootPath = $relativePath
    Write-Host "[INFO] 프로젝트 루트를 찾았습니다: $projectRoot (config.json에 '$($Config.ProjectRootPath)'로 저장)" -ForegroundColor Green
} else {
    Write-Host "[WARNING] 프로젝트 루트 ('.uproject' 파일 포함 디렉토리)를 찾을 수 없습니다. config.json의 ProjectRootPath를 수동으로 확인해주세요." -ForegroundColor Yellow
    if (-not $Config.ProjectRootPath) {
        $Config.ProjectRootPath = ".." 
    }
}

# --- 2. 언리얼 엔진 설치 경로 찾기 ---
Write-Host "[INFO] 언리얼 엔진 설치 경로를 탐색합니다... (버전: $($Config.UnrealEngineVersion))" -ForegroundColor Cyan
$detectedEnginePath = $null
$engineVersion = $Config.UnrealEngineVersion

try {
    $regPath = "HKLM:\SOFTWARE\EpicGames\Unreal Engine\$engineVersion"
    $detectedEnginePath = Get-ItemPropertyValue -Path $regPath -Name InstalledDirectory -ErrorAction SilentlyContinue
    if (-not (Test-Path $detectedEnginePath)) {
        $detectedEnginePath = $null
    }
}
catch {
    Write-Host "[INFO] 레지스트리에서 UE $engineVersion 경로를 찾을 수 없습니다. 기본 경로를 시도합니다." -ForegroundColor DarkCyan
}

if (-not $detectedEnginePath) {
    $defaultPath = "C:\Program Files\Epic Games\UE_$engineVersion"
    if (Test-Path $defaultPath) {
        $detectedEnginePath = $defaultPath
    } else {
        Write-Host "[WARNING] 기본 경로에서도 UE $engineVersion 설치 경로를 찾을 수 없습니다. config.json의 UnrealEngineRootPath를 수동으로 설정해야 할 수 있습니다." -ForegroundColor Yellow
    }
}

# 찾은 엔진 경로를 config.json의 UnrealEngineRootPath에 저장
if ($detectedEnginePath) {
    $Config.UnrealEngineRootPath = $detectedEnginePath
    Write-Host "[INFO] 감지된 UE 엔진 경로: $($Config.UnrealEngineRootPath) (config.json에 저장)" -ForegroundColor Green
} else {
    $Config.UnrealEngineRootPath = ""
    Write-Host "[WARNING] Unreal Engine Root Path를 config.json에 저장하지 못했습니다. 수동으로 입력해주세요." -ForegroundColor Yellow
}

# --- 3. 업데이트된 설정 저장 ---
Write-Host "`n[INFO] config.json 파일을 업데이트합니다..." -ForegroundColor Yellow
try {
    $Config | ConvertTo-Json -Depth 4 | Set-Content -Path $ConfigFilePath -Encoding UTF8 -Force
    Write-Host "[SUCCESS] config.json 파일이 성공적으로 업데이트되었습니다: $ConfigFilePath" -ForegroundColor Green
    Write-Host "설정 파일 내용을 확인하고 필요에 따라 수정해주세요." -ForegroundColor Green
}
catch {
    Write-Host "[ERROR] config.json 파일 저장 중 오류 발생: $($_.Exception.Message) 😢" -ForegroundColor Red
}

Write-Host "`n--- config.json 자동 업데이트 스크립트 종료 ---" -ForegroundColor Yellow