//#include <windows.h>
//
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClassName[] = "AppClass";
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevlnstance, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; hInstance = hInst;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW))
//		return FALSE;
//	if (!(hwnd = CreateWindow(szClassName, "Прокрутка окна",
//		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		0, 0, hInstance, NULL))) return FALSE;
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
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
//{
//	static HWND hScroll;
//	switch (msg)
//	{
//		case WM_CREATE:
//		{
//			hScroll = CreateWindow("scrollbar", NULL, WS_CHILD | SBS_SIZEBOX,
//								   0, 0, 16, 16, hwnd, (HMENU)0, hInstance, NULL);
//			return 0;
//		}
//		case WM_SIZE:
//		{
//			ShowWindow(hScroll, SW_HIDE); return 0; }
//		case WM_LBUTTONDOWN:
//		{
//			MoveWindow(hScroll, LOWORD(IParam) - 8, HIWORD(IParam) - 8, 16, 16,
//					   TRUE);
//			ShowWindow(hScroll, SW_NORMAL);
//			return 0;
//		}
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, IParam);
//}