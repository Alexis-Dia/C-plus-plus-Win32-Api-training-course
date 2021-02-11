//#define _CRT_SECURE_NO_WARNINGS
//#include <windows.h>
//
//#define CM_FILE_OPEN 1001 
//#define CM_FILE_SAVE 1002 
//#define CM_FILE_QUIT 1003
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClass[] = "OpenSaveFile";
//char szTitle[] = "Открытие и закрытие файла";
//
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevlnstance, LPSTR IpszCmdLine, int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hInstance = hInstance;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	if (!(hwnd = CreateWindow(szClass, szTitle,
//		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		0, 0, hInstance, NULL)))
//		return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground) {
//	WNDCLASS wc; wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Proc; wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	wc.lpszClassName = szName; return (RegisterClass(&wc) != 0);
//}
//
//
//BOOL CreateMenuItem(HMENU hMenu, char* str, UINT uIns, UINT uCom, HMENU hSubMenu, BOOL flag, UINT fType)
//{
//
//
//	static MENUITEMINFO mii;
//	mii.cbSize = sizeof(MENUITEMINFO);
//	mii.fMask = MIIM_STATE | MIIM_TYPE | MIIM_SUBMENU | MIIM_ID;
//	mii.fType = fType;
//	mii.fState = MFS_ENABLED;
//	mii.dwTypeData = str;
//	mii.cch = sizeof(str);
//	mii.wID = uCom;
//	mii.hSubMenu = hSubMenu;
//	return InsertMenuItem(hMenu, uIns, flag, &mii);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static HMENU hMainMenu, hFileMenu;
//	static OPENFILENAME ofn;
//	static char szFile[256];
//	static char szFileTitle[256];
//	static char CustomFilter[256];
//	switch (msg)
//	{
//		case WM_CREATE:
//		{
//			hMainMenu = CreateMenu();
//			hFileMenu = CreatePopupMenu();
//			int i = 0;
//			char str[] = "Open";
//			CreateMenuItem(hFileMenu, str, i++, CM_FILE_OPEN, NULL, FALSE, MFT_STRING);
//			char str1[] = "save";
//			CreateMenuItem(hFileMenu, str1, i++, CM_FILE_SAVE, NULL, FALSE, MFT_STRING);
//			CreateMenuItem(hFileMenu, NULL, i++, 0, NULL, FALSE, MFT_SEPARATOR);
//			char str2[] = "Close";
//			CreateMenuItem(hFileMenu, str2, i++, CM_FILE_QUIT, NULL, FALSE, MFT_STRING);
//			i = 0;
//			CreateMenuItem(hMainMenu, str1, i++, 0, hFileMenu, FALSE, MFT_STRING);
//			SetMenu(hwnd, hMainMenu);
//			DrawMenuBar(hwnd);
//			ofn.lStructSize = sizeof(OPENFILENAME);
//			ofn.hwndOwner = hwnd;
//			ofn.nFilterIndex = 1;
//			ofn.lpstrFile = szFile;
//			ofn.nMaxFile = sizeof(szFile);
//			ofn.lpstrFileTitle = szFileTitle;
//			ofn.nMaxFileTitle = sizeof(szFileTitle);
//			ofn.lpstrCustomFilter = CustomFilter;
//			return 0;
//		}
//		case WM_COMMAND:
//		{
//			switch (LOWORD(wParam))
//			{
//				/*case CM_FILE_OPEN:
//				{
//					ofn.Flags = OFN_EXPLORER | OFN_CREATEPROMPT | OFN_ALLOWMULTISELECT;
//					ofn.lpstrTitle =
//						"Панель выбора имени открываемого файла";
//					char szFilter[256] =
//						"Файлы C++ и С\0*.cpp;*.c\0" "Заголовочные файлы\0*.h;*.hрр\0"
//						"Все файлы\0*.*\0";
//					ofn.lpstrFilter = szFilter;
//					szFileTitle[0] = '\0';
//					szFile[0] = '\0';
//					if (GetOpenFileName(&ofn))
//					{
//						char str[512];
//						strcpy(str, "Список имен файлов:\t");
//						for (int i = 0; i < 255; i++)
//						{
//							if (szFile[i] == '\0' && szFile[i + 1] == '\0') break;
//							if (szFile[i] == '\0') szFile[i] = '\n';
//						}
//						strcat(str, szFile);
//						strcat(str, "\n\n Имя файла без указания пути:\t");
//						strcat(str, szFileTitle);
//						MessageBox(hwnd, str,
//								   "Результаты выбора имени открываемого файла", MB_OK);
//					}
//					return 0;
//				}*/
//				/*case CM_FILE_OPEN:
//				{
//					ofn.lStructSize = sizeof(OPENFILENAME);
//					ofn.hwndOwner = hwnd;
//					ofn.hInstance = hInstance;
//					ofn.lpstrFilter = "Applications (*.ехе)\0*.ехе\0"
//						"Application Extension(*.dll)\0 *.dll\0\0";
//					ofn.lpstrCustomFilter = NULL;
//					ofn.nFilterIndex = 0;
//					ofn.lpstrFile = szFile;
//					ofn.nMaxFile = MAX_PATH;
//					ofn.lpstrFileTitle = NULL;
//					ofn.lpstrInitialDir = NULL;
//					ofn.lpstrTitle = "Open PE-files for viewing of section tаblе ... ";
//					ofn.Flags = OFN_EXPLORER | OFN_FILEMUSTEXIST |
//						OFN_HIDEREADONLY | OFN_LONGNAMES |
//						OFN_PATHMUSTEXIST;
//					ofn.lpstrDefExt = -NULL;
//
//					if (!GetOpenFileName(&ofn))
//						MessageBox(hwnd, "Cannot open file", "Еггог of file opening",
//								   MB_OK);
//					return 0;
//				}
//*/
//				case CM_FILE_SAVE:
//				{
//					ofn.Flags = OFN_OVERWRITEPROMPT;
//					ofn.lpstrTitle =
//						"Панель выбора имени для сохранения файла";
//					char szFilter[256] = "Все файлы\0*.*\0";
//					ofn.lpstrFilter = szFilter;
//					szFile[0] = '\0';
//					if (GetSaveFileName(&ofn))
//					{
//						char str[512];
//						strcpy(str, "Полное имя файла:\t");
//						strcat(str, szFile);
//						strcat(str, "\n\n Имя файла без указания пути:\t");
//						strcat(str, szFileTitle);
//						MessageBox(hwnd, str,
//								   "Результаты выбора имени для сохранения файла", MB_OK);
//					}
//					return 0;
//				}
//				case CM_FILE_QUIT:
//				{ DestroyWindow(hwnd); return 0; }
//			}
//			return 0;
//		}
//		case WM_DESTROY: {PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}