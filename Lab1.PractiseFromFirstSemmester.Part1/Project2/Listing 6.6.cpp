//#include <windows.h>
//#define CM_GET_COLOR 1001 
//#define CM_FILE_QUIT 1003
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//HINSTANCE hlnstance;
//char szClass[] = "GetColors";
//char szTitle[] = "Âûáîð öâåòà";
//int WINAPI WinMain(HINSTANCE hlnstance,
//				   HINSTANCE hPrevlnstance, LPSTR IpszCmdLine, int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hlnstance = hlnstance; if (!RegClass(WndProc, szClass, COLOR_WINDOW)) return FALSE;
//	if (!(hwnd = CreateWindow(szClass, szTitle, WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		CW_USEDEFAULT, CW_USEDEFAULT,
//		0, 0, hlnstance, NULL))) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0)) DispatchMessage(&msg);
//	return msg.wParam;
//}
//BOOL RegClass(WNDPROC Proc, LPCTSTR szName, UINT brÂackground)
//{
//	WNDCLASS wc;
//	wc.style = CS_HREDRAW | CS_VREDRAW;
//	wc.cbClsExtra = wc.cbWndExtra = 0;
//	wc.lpfnWndProc = Proc;
//	wc.hInstance = hlnstance;
//	wc.lpszClassName = szName;
//	wc.hIcon = LoadIcon(NULL, IDI_APPLICATION);
//	wc.hCursor = LoadCursor(NULL, IDC_ARROW);
//	wc.hbrBackground = (HBRUSH)(brÂackground + 1);
//	wc.lpszMenuName = (LPCTSTR)NULL;
//	return (RegisterClass(&wc) != 0);
//}
//BOOL CreateMenultem(HMENU hMenu, char *str, UINT uIns,
//					UINT uCom, HMENU hSubMenu, BOOL flag, UINT fType)
//{
//	static MENUITEMINFO mii;
//	mii.cbSize = sizeof(MENUITEMINFO);
//	mii.fMask = MIIM_STATE | MIIM_TYPE | MIIM_SUBMENU | MIIM_ID;
//	mii.fType = fType;
//	mii.fState = MFS_ENABLED;
//	mii.dwTypeData = str;
//	mii.cch = sizeof(str);
//	mii.wID = uCom;
//	mii.hSubMenu = hSubMenu;
//	return InsertMenuItem(hMenu, uIns, flag, &mii);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg,
//						 WPARAM wParam, LPARAM IParam)
//{
//	static HMENU hMainMenu, hColorMenu; static CHOOSECOLOR cc; static COLORREF clf, clfCust[16]; static short cx, cy;
//	switch (msg)
//	{
//		case WM_SIZE:
//		{ cx = LOWORD(IParam); cy = HIWORD(IParam); return 0;
//		}
//		case WM_CREATE:
//		{
//			hMainMenu = CreateMenu();
//			hColorMenu = CreatePopupMenu(); int i = 0;
//			char str[] = "Çàäàòü öâåò";
//			CreateMenultem(hColorMenu, str, i++, CM_GET_COLOR, NULL, FALSE, MFT_STRING);
//			CreateMenultem(hColorMenu, NULL, i++, 0, NULL, FALSE, MFT_SEPARATOR);
//			char str1[] = "Âûõîä";
//			CreateMenultem(hColorMenu, str1, i++, CM_FILE_QUIT, NULL, FALSE, MFT_STRING);
//			char str2[] = " öâåò";
//			i = 0;
//			CreateMenultem(hMainMenu, str2, i++, 0, hColorMenu, FALSE, MFT_STRING);
//			SetMenu(hwnd, hMainMenu); DrawMenuBar(hwnd);
//			for (i = 0; i < 16; i++)
//				clfCust[i] = RGB(255 - i * 15, 50 + 48 * i - 3 * i*i, i * 15);
//			cc.lStructSize = sizeof(CHOOSECOLOR);
//			cc.lpCustColors = clfCust;
//			return 0;
//		}
//		case WM_PAINT:
//		{
//			PAINTSTRUCT ps;
//			HDC hdc = BeginPaint(hwnd, &ps);
//			HBRUSH hbrush = CreateSolidBrush(clf);
//			HBRUSH hOldBrush =
//				(HBRUSH)SelectObject(hdc, hbrush);
//			HPEN hpen = CreatePen(PS_SOLID, 5, clf / 2);
//			HPEN hOldPen = (HPEN)SelectObject(hdc, hpen);
//			short w = cx / 16, h = cy / 2;
//			Rectangle(hdc, 0, 0, cx, h); for (int i = 0; i < 16; i++)
//			{
//				hbrush = CreateSolidBrush(clfCust[i]);
//				SelectObject(hdc, hbrush);
//				Rectangle(hdc, w*i, h, w*i + w, cy);
//				SelectObject(hdc, hOldBrush);
//				DeleteObject(hbrush);
//			}
//			SelectObject(hdc, hOldPen); DeleteObject(hpen);
//			EndPaint(hwnd, &ps); return 0;
//		}
//		case WM_COMMAND:
//		{
//			switch (LOWORD(wParam))
//			{
//				case CM_GET_COLOR:
//				{
//					if (!ChooseColor(&cc)) clf = RGB(255, 255, 255);
//					else clf = cc.rgbResult;
//					InvalidateRect(hwnd, NULL, TRUE); return 0;
//				}
//				case CM_FILE_QUIT:
//				{ DestroyWindow(hwnd); return 0; }
//			} return 0;
//		}
//		case WM_DESTROY: {PostQuitMessage(0); return 0; }
//	} return DefWindowProc(hwnd, msg, wParam, IParam);
//}