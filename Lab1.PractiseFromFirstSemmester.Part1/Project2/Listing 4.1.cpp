//#include <windows.h>
//#define CM_FILE_OPEN 1001
//#define CM_FILE_SAVE 1002
//#define CM_FILE_QUIT 1003
//#define CM_EDIT_FIND 2001
//#define CM_EDIT_REPLC 2002
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT,
//						 WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClass[] = "MenuWindow";
//int WINAPI WinMain(HINSTANCE hInstance,
//				   HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg;
//	HWND hwnd;
//	::hInstance = hInstance;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClass,
//						"Приложение со статическим меню",
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, 0, 0, hInstance, NULL);
//	if (!hwnd)
//		return FALSE;
//	while (GetMessage(&msg, 0, 0, 0))
//	{
//		TranslateMessage(&msg);
//		DispatchMessage(&msg);
//	}
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName,
//			  UINT brBackground)
//{
//	WNDCLASS wc;
//	wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Proc;
//	wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = NULL;
//	wc.lpszClassName = szName;
//	return (RegisterClass(&wc) != 0);
//}
//BOOL CreateMenuItem(HMENU hMenu, char* str, UINT ulns,
//					UINT uCom, HMENU hSubMenu, BOOL flag, UINT fType) {
//	MENUITEMINFO mii;
//	mii.cbSize = sizeof(MENUITEMINFO);
//	mii.fMask = MIIM_STATE | MIIM_TYPE | MIIM_SUBMENU |
//		MIIM_ID;
//	mii.fType = fType;
//	mii.fState = MFS_ENABLED;
//	mii.dwTypeData = str;
//	mii.cch = sizeof(str);
//	mii.wID = uCom;
//	mii.hSubMenu = hSubMenu;
//	return InsertMenuItem(hMenu, ulns, flag, &mii);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static HMENU hMainMenu, hFileMenu, hEditMenu;
//	switch (msg)
//	{
//		case WM_CREATE:
//		{
//			hMainMenu = CreateMenu();
//			//Создаем временное меню для раздела "Файлы"
//			hFileMenu = CreatePopupMenu();
//			int i = 0;
//			//Инициализация позиции в меню hFileMenu
//			char str[] = "Открыть";
//			char str1[] = "Сохранить";
//			char str2[] = "Выход";
//			CreateMenuItem(hFileMenu, str, i++, CM_FILE_OPEN, NULL, FALSE, MFT_STRING);
//			CreateMenuItem(hFileMenu, str1, i++, CM_FILE_SAVE, NULL, FALSE, MFT_STRING);
//			CreateMenuItem(hFileMenu, NULL, i++, 0, NULL, FALSE, MFT_SEPARATOR);
//			CreateMenuItem(hFileMenu, str2, i++, CM_FILE_QUIT, NULL, FALSE, MFT_STRING);
//			//Создаем временное меню для раздела "Правка"
//			hEditMenu = CreatePopupMenu();
//			i = 0;
//			//Инициализация позиции в меню
//			CreateMenuItem(hEditMenu, str2, i++, CM_EDIT_FIND, NULL, FALSE, MFT_STRING);
//			CreateMenuItem(hEditMenu, str2, i++, CM_EDIT_REPLC, NULL, FALSE, MFT_STRING);
//			//Подключаем временные меню к главному меню i=0;
//			//Инициализация позиции в меню
//			CreateMenuItem(hMainMenu, str2, i++, 0, hFileMenu, FALSE, MFT_STRING);
//			CreateMenuItem(hMainMenu, str2, i++, 0, hEditMenu, FALSE, MFT_STRING);
//			SetMenu(hwnd, hMainMenu);
//			DrawMenuBar(hwnd);
//			return 0;
//		}
//		case WM_COMMAND:
//		{
//			switch (LOWORD(wParam))
//			{
//				case CM_FILE_OPEN:
//				{
//					MessageBox(hwnd,
//							   "Команда CM_FILE_OPEN",
//							   "Меню", MB_OK); return 0;
//				}
//				case CM_FILE_SAVE:
//				{
//					MessageBox(hwnd, "Команда CM_FILE_SAVE",
//							   "Меню", MB_OK); return 0;
//				}
//				case CM_EDIT_FIND:
//				{
//					MessageBox(hwnd, "Команда CM_EDIT_FIND",
//							   "Меню", MB_OK); return 0;
//				}
//				case CM_EDIT_REPLC:
//				{ MessageBox(hwnd, "Команда CM_EDIT_REPLC",
//							 "Меню", MB_OK); return 0;
//				}
//				case CM_FILE_QUIT:
//				{ DestroyWindow(hwnd); return 0; }
//			} return 0;
//		}
//		case WM_DESTROY: {PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}