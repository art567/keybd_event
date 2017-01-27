#include "main.h"

#ifdef WIN32
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpCmdLine, int nShowCmd)
{
	int argc;
	char** argv;
	LPWSTR* lpArgv = CommandLineToArgvW( GetCommandLineW(), &argc );
	argv = (char**)malloc( argc * sizeof(char*) );
	int size, i = 0;
	for ( ; i < argc; ++i)
	{
		size = wcslen( lpArgv[i] ) + 1;
		argv[i] = (char*)malloc( size );
		wcstombs( argv[i], lpArgv[i], size );
	}
	LocalFree(NULL);
	return main(argc, argv);
}
#endif

int main(int argc, char* argv[])
{
	sendPrintScreen();
	return SUCCESS;
}

void sendPrintScreen()
{
	keybd_event(VK_MENU, 0, 0, 0); //Alt Press
	keybd_event(VK_SNAPSHOT, 0, 0, 0); //PrntScrn Press
	Sleep(50);
	keybd_event(VK_SNAPSHOT, 0, KEYEVENTF_KEYUP, 0); //PrntScrn Release
	keybd_event(VK_MENU, 0, KEYEVENTF_KEYUP, 0); //Alt Release
}