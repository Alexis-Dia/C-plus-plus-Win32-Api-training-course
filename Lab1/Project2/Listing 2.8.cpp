//#include <windows.h>
//
//#define ID_EDIT 1000
//#define ID_COMBBOX 1001
//#define ID_BUTTON 1002
//
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hInstance;
//char szClassName[] = "Combolist";
//char szTitle[] = "Работа с комбинированным списком";
//
//int WINAPI WinMain(HINSTANCE hInst, HINSTANCE hPrevInstance, LPSTR lpszCmdLine, int nCmdShow)
//{
//	MSG msg; HWND hwnd; hInstance = hInst;
//	if (!RegClass(WndProc, szClassName, COLOR_WINDOW))
//		return FALSE;
//	if (!(hwnd = CreateWindow(szClassName, szTitle,
//		WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//		100, 50, 364, 360, 0, 0, hInstance, NULL))) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0))
//	{
//		TranslateMessage(&msg); DispatchMessage(&msg);
//	}
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
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	wc.lpszClassName = szName; return(RegisterClass(&wc) != 0);
//}
//
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
//{
//	static HWND hCombBox, hEdit, hButton, hStatic;
//	int uItem; char Buf[80];
//	switch (msg)
//	{
//		case WM_CREATE:
//		{
//			hStatic = CreateWindow("static",
//								   "Введите строку для ввода в список",
//								   WS_CHILD | WS_VISIBLE | SS_CENTER,
//								   30, 10, 300, 20, hwnd, (HMENU)0, hInstance, NULL);
//			hEdit = CreateWindow("edit", NULL,
//								 WS_CHILD | WS_VISIBLE | WS_BORDER |
//								 ES_LEFT | ES_AUTOHSCROLL, 30, 40, 300, 30,
//								 hwnd, (HMENU)ID_EDIT, hInstance, NULL);
//			hCombBox = CreateWindow("ComboBox", NULL,
//									WS_CHILD | WS_VISIBLE | WS_VSCROLL|
//									CBS_SIMPLE|CBS_SORT, 30, 80, 300, 200, 
//									hwnd, (HMENU)ID_COMBBOX, hInstance, NULL);
//			hButton = CreateWindow("button", "Добавить",
//								   WS_CHILD | WS_VISIBLE |
//								   BS_PUSHBUTTON, 130, 290, 100, 30, hwnd,
//								   (HMENU)ID_BUTTON, hInstance, NULL);
//			SetFocus(hEdit);
//			return 0;
//		}
//		case WM_COMMAND:
//		{
//			switch (LOWORD(wParam))
//			{
//				case ID_COMBBOX:
//				{
//					switch (HIWORD(wParam))
//					{
//						case CBN_ERRSPACE:
//						{
//							MessageBox(hwnd, "Мало naмяти", szTitle, MB_OK);
//							return 0;
//						}
//						case CBN_DBLCLK:
//						{
//							uItem = (int)SendMessage(hCombBox, CB_GETCURSEL, 0, 0L);
//							if (uItem != LB_ERR)
//							{
//								SendMessage(hCombBox, CB_GETLBTEXT, uItem, (LPARAM)Buf);
//								MessageBox(hwnd, (LPSTR)Buf, szTitle, MB_OK);
//							}
//							return 0;
//						}
//						default: return 0;
//					}
//					return 0;
//				}
//				case ID_BUTTON:
//				{
//					SendMessage(hEdit, EM_GETLINE, 0, (LPARAM)Buf);
//					SendMessage(hCombBox, CB_ADDSTRING, 0, (LPARAM)Buf);
//					SetWindowText(hEdit, "\0");
//					SetFocus(hEdit);
//					return 0;
//				}
//				default:return 0;
//			}
//		}
//		case WM_DESTROY: { PostQuitMessage(0); return 0; }
//	}
//	return DefWindowProc(hwnd, msg, wParam, IParam);
//}