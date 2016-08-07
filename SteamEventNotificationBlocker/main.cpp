#include <windows.h>
#include <iostream>
#include <atlstr.h>
#include <psapi.h>

#pragma comment( lib, "psapi.lib" )
CString steamexe;

bool GetRegKey(HKEY hKey, CString sKey, CString & sKeyValue)
{
	DWORD length = MAX_PATH;
	return (RegQueryValueEx(hKey, sKey, 0, NULL, (PBYTE)(LPTSTR)sKeyValue.GetBuffer(MAX_PATH), &length) == ERROR_SUCCESS);
}

bool EndsWith(CString String, CString Ending)
{
	if (String.GetLength() < Ending.GetLength()) return false;
	return (String.Mid(String.GetLength() - Ending.GetLength(), String.GetLength()).Compare(Ending) == 0);
}

BOOL CALLBACK EnumWindowsProc(HWND wnd, LPARAM lParam)
{
	DWORD pid;
	GetWindowThreadProcessId(wnd, &pid);
	HANDLE process = OpenProcess(PROCESS_QUERY_INFORMATION | PROCESS_VM_READ, true, pid);
	CString filename;
	GetModuleFileNameEx(process, NULL, filename.GetBuffer(MAX_PATH), MAX_PATH);
	GetFullPathName(filename, MAX_PATH, filename.GetBuffer(MAX_PATH), NULL);
	filename.ReleaseBuffer();
	filename.MakeLower();
	CloseHandle(process);
	CString title;
	GetWindowText(wnd, title.GetBuffer(MAX_PATH), MAX_PATH);
	title.ReleaseBuffer();
	if (!title.IsEmpty() && !filename.IsEmpty() &&
		filename.Compare(steamexe) == 0 && EndsWith(title, "- event started") &&
		(GetWindowLong(wnd, GWL_STYLE) & WS_VISIBLE))
	{
		PostMessage(wnd, WM_CLOSE, 0, 0);
	}
	return true;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nCmdShow)
{
	CreateMutexA(0, FALSE, "Local\\SENB");
	if (GetLastError() == ERROR_ALREADY_EXISTS)
		return 1;
	HKEY hKey;
	LONG lRes = RegOpenKeyExW(HKEY_CURRENT_USER, L"SOFTWARE\\Valve\\Steam", 0, KEY_READ, &hKey);
	if (!GetRegKey(hKey, "SteamExe", steamexe))
	{
		return 1;
	}
	GetFullPathName(steamexe, MAX_PATH, steamexe.GetBuffer(MAX_PATH), NULL);
	steamexe.ReleaseBuffer();
	steamexe.MakeLower();
	RegCloseKey(hKey);
	while (true)
	{
		EnumWindows(EnumWindowsProc, 0);
		Sleep(1000);
	}
	return 0;
}