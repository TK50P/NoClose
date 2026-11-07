#include <windows.h>
#include <stdio.h>

#define KEY_DOWN(VK_NONAME) ((GetAsyncKeyState(VK_NONAME) & 0x8000) ? 1 : 0)

bool check(char ch) {
	if (KEY_DOWN(ch)) return 1;
	return 0;
}

BOOL SetPrivilege(void)
{
	HANDLE hToken;
	TOKEN_PRIVILEGES NewState;
	LUID luidPrivilegeLUID;

	//Get process token
	if (!OpenProcessToken(GetCurrentProcess(), TOKEN_ADJUST_PRIVILEGES, &hToken) || !LookupPrivilegeValue(NULL, SE_DEBUG_NAME, &luidPrivilegeLUID))
	{
		return FALSE;
	}
	NewState.PrivilegeCount = 1;
	NewState.Privileges[0].Luid = luidPrivilegeLUID;
	NewState.Privileges[0].Attributes = SE_PRIVILEGE_ENABLED;
	//Prompt for process permissions, note that this function can also change thread permissions, if hToken points to a thread's token
	if (!AdjustTokenPrivileges(hToken, FALSE, &NewState, NULL, NULL, NULL))
	{
		return FALSE;
	}
	return TRUE;
}


int main() {
	// Forcing ANSI variant explicitly for older NT systems
	HMODULE hDll = GetModuleHandleA("ntdll.dll");
	if (hDll == NULL) {
		MessageBoxA(0, "Load Library Error", "ERROR", MB_ICONSTOP);
		return 0;
	}

	typedef VOID(WINAPI* type_RtlSetProcessIsCritical)(BOOLEAN, PBOOLEAN, BOOLEAN);
	typedef VOID(WINAPI* type_RtlSetThreadIsCritical)(BOOLEAN, PBOOLEAN, BOOLEAN);
	
	// Fixed type-casting mismatches here
	type_RtlSetProcessIsCritical RtlSetProcessIsCritical = (type_RtlSetProcessIsCritical)GetProcAddress(hDll, "RtlSetProcessIsCritical");
	type_RtlSetThreadIsCritical RtlSetThreadIsCritical = (type_RtlSetThreadIsCritical)GetProcAddress(hDll, "RtlSetThreadIsCritical");

	bool bSuccess = SetPrivilege();
	if (!bSuccess) return 0;

	/* Safety Check: Only make critical if functions exist (Windows 2000/XP). Prevents immediate crash on NT 4.0 */
	if (RtlSetProcessIsCritical != NULL && RtlSetThreadIsCritical != NULL) {
		RtlSetProcessIsCritical(TRUE, NULL, FALSE);
		RtlSetThreadIsCritical(TRUE, NULL, FALSE);
	}

	printf("Can't close window without a crash\n");
	while (1) {
		if (check('T') && check('Z') && check('H')) {
			// Safety check before unsetting critical status
			if (RtlSetProcessIsCritical != NULL && RtlSetThreadIsCritical != NULL) {
				RtlSetProcessIsCritical(FALSE, NULL, FALSE);
				RtlSetThreadIsCritical(FALSE, NULL, FALSE);
			}
			return 0;
		}
		Sleep(10);
	}
	return 0;
}
