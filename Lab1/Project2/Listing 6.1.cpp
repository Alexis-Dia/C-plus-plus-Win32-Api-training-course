//#include <windows.h>
//#include "CreateDlg.h"
//#define ID_STATIC 2000
//#define ID_BU�ON1 2001
//#define ID_BU�ON2 2002
//#define ID_BU�ON� 2003
//#define ID_HELP 2004
//BOOL RegClass(WNDPROC, LPCTSTR, UINT);
//LRESULT CALLBACK WndProc(HWND, UINT, WPARAM, LPARAM);
//LRESULT CALLBACK DlgProc(HWND, UINT, WPARAM, LPARAM);
//int CreateDlg(HWND);
//HINSTANCE hInstance;
//char szClass[] = "WindowAppClass";
//int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszCmdline, int nCmdShow)
//{
//	MSG msg; HWND hwnd; ::hInstance = hInstance;
//	if (!RegClass(WndProc, szClass, COLOR_DESKTOP))
//		return FALSE;
//	int wScreen = GetSystemMetrics(SM_CXSCREEN);
//	int hScreen = GetSystemMetrics(SM_CYSCREEN);
//	hwnd = CreateWindow(szClass, "�������� ���������� ������",
//						WS_OVERLAPPEDWINDOW | WS_VISIBLE,
//						0, 0, wScreen, hScreen, 0, 0, hInstance, NULL);
//	if (!hwnd) return FALSE;
//	while (GetMessage(&msg, 0, 0, 0))
//	{
//		TranslateMessage(&msg); DispatchMessage{ &msg };
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
//	wc.lpszMenuName = (LPCTSTR)NULL; wc.lpszClassName = szName;
//	return(RegisterClass(&wc) != 0);
//}
//LRESULT CALLBACK WndProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM IParam)
//{
//	switch (msg)
//	{
//		case WM_LBUTTONDOWN: {
//			CreateDlg(hwnd); return 0;
//		}
//		case WM_DESTROY: {
//			PostQuitMessage(0); return 0;
//		}
//	}
//	return DefWindowProc(hwnd, msg, wParam, IParam);
//}
//int CreateDlg(HWND hwnd)
//{
//	char const caption[] = " ��������� ������ ������ ����������";
//	char const stattxt[] = "������ �������:";
//	char const modeoffI ] = "��������� ������ ����������";
//	char const modedat[] = "������������� ������";
//	char const modepsw[] = "������� ��� ������������";
//	//�������� ���� ������ ��� ������ �������
//	WORD* p, *pdlgtemplate;
//	pdlgtemplate = p = (PWORD)LocalAlloc( LPTR,2000);
//	//���������� ������� ������ cxChar � ������ cyChar ������
//	int cxChar, cyChar;
//	{
//		TEXTMETRIC tm; HDC hdc = GetDC(hwnd);
//		GetTextMetrics(hdc,&tm); ReleaseDC(hwnd,hdc);
//		cxChar = tm.tmAveCharWidth + 1;
//		cyChar = tm.tmHeight + tm.tmExternalLeading;
//	}
//	//���������� ���������� ������� ������ � ������
//	DWORD dlgunit = GetDialogBaseUnits();
//	int dlgwunit = LOWORD(dlgunit), dlghunit = HIWORD(dlgunit);
//	//������������� �������,1 �������� ������
//	cxChar = cxChar * 4 / dlgwunit; cyChar = cyChar * 8 / dlghunit;
//
//	int wDlg, hDlg, wItem, hItem, left, top;
//
//	//���������� � ������ ������ ������
//	DWORD IStyle = DS_CENTER | DS_MODALFRAME | WS_POPUPWINDOW | WS_CAPTION;
//	wDlg = lstrlen(caption) * cxChar; hDlg = cyChar * 10;
//	DlgTemplate(p, IStyle, 7, 0, 0, wDlg, hDlg, (LPSTR)caption);
//
//	//����� ��������� ������ ������� ����������
//	//1
//	hItem = cyChar; top = left = hItem / 2; hItem += left;
//	wItem = (wDlg - left - left);
//	IStyle = WS_CHILD | WS_VISIBLE | BS_GROUPBOX | WS_TABSTOP;
//	DlgItemTemplate(p, IStyle, left, top, wItem, 4 * hItem + left;
//	ID_STATIC, (LPSTR)"button", (LPSTR)stattxt);
//	// 2
//	wItem = lstrlen(modeoff) * cxChar + 10; top += hItem;
//	IStyle = BS_AUTORADIOBUTTON | WS_CHILD | WS_VISIBLE | WS_TABSTOP;
//	DlgItemTemplate(p, IStyle, hItem, top, wItem, hItem, ID_BUTTON; (LPSTR)"button", (LPSTR)modeoff);
//	// 3
//	wItem = lstrlen(modedat) * cxChar + 10; top += hItem;
//	IStyle = BS_AUTORADIOBUTTON | WS_CHILD | WS_VISIBLE;
//	DlgItemTemplate(p, IStyle, hItem, top, wItem, hItem, ID_BU�ON2, "button", (LPSTR)modedat);
//	// 4
//	wItem = lstrlen(modepsw) * cxChar + 10; top += hItem;
//	IStyle = BS_AUTORADIOBUTTON | WS_CHILD | WS_VISIBLE;
//	DlgItemTemplate(p, IStyle, hltem, tbp, wltem, hlte111, ID_BU�ON�, (LPSTR)"button", (LPSTR)modepsw);
//	// 5
//	wItem = (wDlg - left - left - hItem - hItem) / 3;
//	top += hItem + hItem / 2 + left;
//	IStyle = BS_DEFPUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP;
//	DlgItemTemplate(p, IStyle, left, top, wltem, hltem,	IDOK, (LPSTR)"button",(LPSTR)"�a");
//	// 6
//	IStyle = BS_PUSHBUTTON | WS_VISIBLE | WS_CHILD | WS_TABSTOP;
//	DlgItemTemplate(p, IStyle, left + wltem + hltem, top, wltem, hltem,
//	IDCANCEL, (LPSTR)"button",(LPSTR)"O��e�a");
//	// 7
//	DlgItemTemplate(p, !Style, left + wltem + hltem + wltem + hltem, top, wltem, hltem, ID_HELP, (LPSTR)"button", (LPSTR)"C�pa��a");
//	//������� ��������� ���������� ����
//	DialogBoxIndirect(hInstance,(LPDLGTEMPLATE)pdlgtemplate,hwnd, (DLGPROC)DlgProc);
//	//����������� ������� ��� ������ ���� ������
//	LocalFree(LocalHandle(pdlgtemplate));
//	return 0;
//	}
//		LRESUL� CALLBACK DlgProc(HWND hwnd, UINT msg, WPARAM wParam, LPARAM lParam)
//	{
//		switch (msg)
//		{
//			case WM_COMMAND:
//			{ switch (LOWORD(wParam))
//			{
//				case IDOK:
//				case IDCANCEL:
//				{ EndDialog(hdlg, TRUE);
//				return TRUE; }
//			}}
//		}
//		return FALSE;
//	}