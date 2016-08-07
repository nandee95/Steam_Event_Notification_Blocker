@echo off
title SENB uninstaller

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

if not exist "%steampath%\senb.exe" (
	echo senb.exe not found!
	pause>nul
	exit
)

rm "%steampath%\senb.exe"
if %errorlevel% == 1 (
	echo Failed to remove senb.exe
	pause>nul
	exit
) else (
	echo senb.exe removed
)

reg delete "HKCU\Software\Microsoft\Windows\CurrentVersion\Run" /f /v "Steam Event Notification Blocker"
if %errorlevel% == 1 (
	echo Failed to remove senb.exe from startup programs
	pause>nul
	exit
) else (
	echo senb.exe removed from the startup programs
)

echo Uninstall completed!
pause>nul