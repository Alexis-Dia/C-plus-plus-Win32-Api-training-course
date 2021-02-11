//# include <windows.h>
//
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//
//HINSTANCE hInstance;
//char szMainClass[] = "MainClass";
//char szTitle[] = "Example 1.2";
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInst, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg; hInstance = hInst;
//	HWND hwnd = FindWindow(szMainClass, szTitle);
//	if (hwnd)
//	{
//		MessageBox(hwnd,
//				   "Its already opened",
//				   szTitle, MB_OK | MB_ICONSTOP);
//		if (IsIconic(hwnd))
//			ShowWindow(hwnd, SW_RESTORE);
//		SetForegroundWindow(hwnd);
//		return 0;
//	}
//	if (!RegClass(WndProc, szMainClass, COLOR_DESKTOP))
//		return FALSE;
//	int w = GetSystemMetrics(SM_CXSCREEN) - 1;
//	int h = GetSystemMetrics(SM_CYSCREEN) - 1;
//	hwnd = CreateWindow(szMainClass, szTitle,
//						WS_POPUPWINDOW | WS_CAPTION |
//						WS_MINIMIZEBOX | WS_VISIBLE,
//						0, 0, w, h, 0, 0, hInstance, NULL);
//	if (!hwnd) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0))DispatchMessage(&msg);
//	return msg.wParam;
//}
//
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc;
//	wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Proc; wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	wc.lpszClassName = szName;
//	return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam) 
//{
//	switch (msg)
//	{case WM_DESTROY:
//		{ PostQuitMessage(0); return 0;
//		}
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}