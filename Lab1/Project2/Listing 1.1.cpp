//#include <windows.h>
//
////Объявление функций
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//LRESULT CALLBACK createDaughterWindowClass(HINSTANCE, const wchar_t*, COLORREF);
////Описание глобальных переменных
//HINSTANCE hInst;
//char szClassName[] = "WindowAppClass";
////Описание главной функции
//int WINAPI WinMain(HINSTANCE hInstance,
//				   HINSTANCE hPrevlnstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; hInst = hInstance;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClassName, "Мое приложение",
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						600, 600,
//						0, 0, hInstance, NULL);
//	if (!hwnd) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
////Описание функции регистрации классов
//BOOL RegClass(WNDPROC Ргос, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Ргос; wc.hInstance = hInst;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = NULL; wc.lpszClassName = szName;
//	return (RegisterClass(&wc) != 0);
//}
////Описание функции окон
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
//{
//	switch (msg)
//	{
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, IParam);
//}