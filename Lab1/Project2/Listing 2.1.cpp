//#include <windows.h>
//#define ID_BUTTON 3000
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClassName[] = "Example21";
//int WINAPI WinMain(HINSTANCE hInst,
//				   HINSTANCE hPrevlnstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; hInstance = hInst;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClassName, "Приложение с кнопкой",
//						WS_OVERLAPPEDWINDOW,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						0, 0, hInstance, NULL);
//	if (!hwnd) return FALSE;
//	ShowWindow(hwnd, SW_SHOWMAXIMIZED); UpdateWindow(hwnd);
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Ргос, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Ргос; wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	wc.lpszClassName = szName;
//	return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
//						 WPARAM wParam, LPARAM lParam)
//{
//	static HWND hButton;
//	switch (msg)
//	{
//		case WM_CREATE:
//		{ hButton = CreateWindow("button", "Пример кнопки",
//								 WS_CHILD | WS_VISIBLE |
//								 BS_DEFPUSHBUTTON, 0, 0, 200, 20, hwnd,
//								 (HMENU)ID_BUTTON, hInstance, NULL);
//		return 0;
//		}
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}