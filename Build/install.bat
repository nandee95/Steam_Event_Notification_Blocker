@echo off

if not exist senb.exe (
	echo senb.exe not found!
	pause>nul
	exit
)

for /F "usebackq tokens=3*" %%A in (`REG QUERY "HKEY_CURRENT_USER\SOFTWARE\Valve\Steam" /v SteamPath`) do (
    set steampath=%%A %%B
)

if not defined steampath (
	echo Steam Installition not found!
	pause>nul
	exit
) else (
	echo Steam installition found:  "%steampath%"
)


set last=%cd%
cd %steampath%
set steampath=%cd%
cd %last%

taskkill /f /im senb.exe

cp senb.exe "%steampath%"
if %errorlevel% == 1 (
	echo Failed to copy senb.exe to the Steam directory
	pause>nul
	exit
) else (
	echo senb.exe copied to the Steam directory
)

reg add "HKCU\Software\Microsoft\Windows\CurrentVersion\Run" /f /v "Steam Event Notification Blocker" /t REG_SZ /d "\"%steampath%\senb.exe\"">nul
if %errorlevel% == 1 (
	echo Failed to add senb.exe to the startup programs
	pause>nul
	exit
) else (
	echo senb.exe added to the startup programs
)

start "" "%steampath%\senb.exe"
echo Program started!


echo Installition completed!
pause>nul