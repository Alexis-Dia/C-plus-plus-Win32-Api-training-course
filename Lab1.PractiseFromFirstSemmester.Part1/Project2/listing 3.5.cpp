//#include <windows.h>
//
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClass[] = "MyCaption";
//
//int WINAPI WinMain(HINSTANCE hInstance,
//				   HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg; HWND hwnd;	::hInstance = hInstance;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClass, NULL,
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						0, 0, hInstance, NULL);
//	if (!hwnd) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
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
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//{
//	static short nCap, nFr; char szCap[] = "Мой заголовок окна";
//	switch (msg)
//	{
//		case WM_CREATE:
//		{
//			//Определяем высоту заголовка окна
//			nCap = GetSystemMetrics(SM_CYCAPTION);
//			//Определяем толщину рамки окна
//			nFr = GetSystemMetrics(SM_CYFRAME);
//			return 0;
//		}
//		case WM_MOVE:
//		case WM_SIZE:
//		{
//			HDC hdc = GetWindowDC(hwnd);
//			//Установка атрибутов вывода и вывод текста
//			SetTextColor(hdc, RGB(255, 50, 0));
//			SetBkMode(hdc, TRANSPARENT);
//			TextOut(hdc, nCap + nFr, 3 * nFr / 2, szCap, strlen(szCap));
//			ReleaseDC(hwnd, hdc);
//			return 0;
//		}
//		case WM_DESTROY: {PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}