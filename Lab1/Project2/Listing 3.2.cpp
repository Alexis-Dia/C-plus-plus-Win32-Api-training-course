//#include <windows.h>
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClass[] = "OutputClass2";
//char szText[50] = "Teкcт по умолчанию";
//int WINAPI WinMain(HINSTANCE hInstabce, HINSTANCE hPrevlnstance, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hInstance = hInstabce;
//	if (!RegClass(WndProc, szClass, COLOR_WINDOW))
//		return FALSE;
//	hwnd = CreateWindow(szClass, "Вывод текста",
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						0, 0, hInstabce, NULL);
//	if (!hwnd) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.cbClsExtra = wc.cbWndExtra = 0; wc.lpfnWndProc = Proc;
//	wc.hInstance = hInstance; wc.lpszClassName = szName;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = NULL; return (RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
//{
//	static short cx, cy;
//	switch (msg)
//	{
//		case WM_SIZE:
//		{
//			cx = LOWORD(IParam); cy = HIWORD(IParam);
//			return 0;
//		}
//		case WM_PAINT:
//		{
//			PAINTSTRUCT ps;
//			HDC hdc = BeginPaint(hwnd, &ps);
//			SetTextColor(hdc, RGB(255, 0, 0));
//			SetBkColor(hdc, RGB(0, 255, 255));
//			SetTextAlign(hdc, TA_CENTER);
//			TextOut(hdc, cx / 2, cy / 2, szText, strlen(szText));
//			EndPaint(hwnd, &ps);
//			return 0;
//		}
//		case WM_LBUTTONDOWN:
//		{
//			strcpy(szText, "Haжaтa левая клавиша мыши");
//			InvalidateRect(hwnd, NULL, TRUE);
//			return 0;
//		}
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, IParam);
//}