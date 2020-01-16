//#include <windows.h>
//
//#define ID_BUTTON1 3001
//#define ID_BUTTON2 3002
//
//BOOL RegClass(WNDPROC, LPCSTR, UINT);
//
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//HINSTANCE hInst;
//char szClassName[] = "Example";
//
//
//int WINAPI	WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg; HWND hwnd;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW)) return FALSE;
//
//	hwnd = CreateWindow(szClassName, "Example 1",
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						CW_USEDEFAULT, CW_USEDEFAULT,
//						0, 0, hInstance, NULL);
//
//	if (!hwnd)return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brBackground)
//{
//	WNDCLASS wc; wc.style = wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Proc; wc.hInstance = hInstance;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brBackground + 1);
//	wc.lpszMenuName = (LPCSTR)NULL;
//	wc.lpszClassName = szName;
//	return(RegisterClass(&wc) != 0);
//
//
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
//						 WPARAM wParam, LPARAM lParam)
//{
//	static HWND hButton1, hButton2;
//	switch (msg)
//	{
//		case WM_CREATE:
//		{ CreateWindow("button", "2 Buttons Group",
//					   WS_CHILD | WS_VISIBLE | BS_GROUPBOX,
//					   130, 75, 190, 120, hwnd,
//					   (HMENU)0, hInstance, NULL);
//		hButton1 = CreateWindow("button", "Top Button",
//								WS_CHILD | WS_VISIBLE | BS_DEFPUSHBUTTON,
//								150, 100, 150, 30, hwnd,
//								(HMENU)ID_BUTTON1, hInstance, NULL);
//		hButton2 = CreateWindow("button", "Bottom Button",
//								WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON,
//								150, 150, 150, 30, hwnd,
//								(HMENU)ID_BUTTON2, hInstance, NULL);
//		return 0;
//		}
//		case WM_COMMAND:
//		{	switch (LOWORD(wParam))
//		{
//			case ID_BUTTON1:
//			{
//				MessageBox(hwnd,
//						   "Нажата верхняя кнопка",
//						   "Сообщение от кнопки", MB_OK);
//				SendMessage((HWND)lParam, BM_SETSTATE, TRUE, 0L);
//				if (!SendMessage(hButton2,
//					BM_GETCHECK, 0, 0L))
//					SendMessage(hButton2,
//								BM_SETSTATE, FALSE, 0L);
//				return 0;
//			}
//			case ID_BUTTON2:
//			{
//				MessageBox(hwnd,
//						   "Нажата нижняя кнопка",
//						   "Сообщение от кнопки", MB_OK);
//				SendMessage((HWND)lParam,
//							BM_GETCHECK, 0, 0L);
//				if (!SendMessage(hButton1, 
//					BM_GETCHECK, 0, 0L)) 
//					SendMessage(hButton1, 
//								BM_SETSTATE, FALSE, 0L);
//				return 0;
//			}
//		}
//		return 0;
//		}
//
//		case WM_DESTROY: {PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, lParam);
//}