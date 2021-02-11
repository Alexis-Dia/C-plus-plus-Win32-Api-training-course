//#include <windows.h>
//#include<tchar.h>
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM,
//						 LPARAM);
//HINSTANCE hInstance;
//char szClass[] = "TextOutClass";
//int WINAPI WinMain(HINSTANCE hInstance,
//				   HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg; HWND hwnd;	::hInstance = hInstance;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW)) return
//		FALSE;
//	hwnd = CreateWindow(szClass, "Вывод текста",
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						0, 0, hInstance, NULL);
//	if (!hwnd) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName,
//			  UINT brBackground)
//{
//	WNDCLASS wc; wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Proc;
//	wc.hInstance = hInstance;
//	wc.lpszClassName = szName;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = NULL;
//	return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
//						 WPARAM wParam, LPARAM lParam)
//{
//	char szFont[] = " Какой-либо текст";
//	static short cyClient;
//	switch (msg)
//	{
//		case WM_SIZE:
//		{cyClient = HIWORD(lParam); return 0; }
//		case WM_PAINT:
//		{
//			PAINTSTRUCT ps;
//			HDC hdc = BeginPaint(hwnd, &ps);
//			static LOGFONT lf;
//			lf.lfCharSet = DEFAULT_CHARSET;
//			lf.lfPitchAndFamily = DEFAULT_PITCH;
//			strcpy_s(lf.lfFaceName,"Times New Roman");
//			lf.lfHeight = 20; lf.lfWeight = FW_BOLD;
//			for (int i = 0; i < 10; i++)
//			{
//				lf.lfOrientation = lf.lfEscapement = i * 100;
//				HFONT hNFont = CreateFontIndirect(&lf);
//				HFONT hOFont = (HFONT)SelectObject(hdc, hNFont);
//				SetTextColor(hdc, RGB(i * 15, i * 20, i * 25));
//				SetBkColor(hdc, RGB(255 - i * 15, 255 - i * 20, 255 - i * 25));
//				TextOut(hdc, 0, cyClient - 30, szFont, _tcslen(szFont));
//				SelectObject(hdc, hOFont);
//				DeleteObject(hNFont);
//			}
//			EndPaint(hwnd, &ps); return 0;
//		}
//		case WM_DESTROY:
//		{PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}