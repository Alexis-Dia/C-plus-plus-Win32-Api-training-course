#include <windows.h> 
#include <stdlib.h> 
#include <string.h> 
#include <tchar.h> 

#define IDC_BUT_1 150
#define IDC_EDIT_1 151

static TCHAR szWindowClass[] = _T("MyWin");

LRESULT createDaughterWindowClass(HINSTANCE, LPCTSTR, COLORREF);
HWND createDaughterDescriptor(HWND, HINSTANCE, LPCTSTR, int, int, int, int);
LRESULT CALLBACK WindowFunc(HWND, UINT, WPARAM, LPARAM);
LRESULT CALLBACK ChildProc(HWND, UINT, WPARAM, LPARAM);


HINSTANCE hInst;
int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInstance, LPSTR lpszArgs, int nWinMode) {
	hInst = hInstance;
	MSG msg;							// ��������� ��������� Windows
	HWND hwnd;							// ���������� ����
	WNDCLASSEX wcl;						// ��������� ������������ ����� ����
	wcl.hInstance = hInstance;			// ������ � ������ �����������
	wcl.lpszClassName = szWindowClass;	// ��� ������ ����
	wcl.lpfnWndProc = WindowFunc;		// ������� �������
	wcl.style = 0;						// ������������ ����� ���� �� ���������
	wcl.cbSize = sizeof(WNDCLASSEX);	// ��������� ������� WNDCLASSEX
	wcl.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));	// ������� ������
	wcl.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_WINLOGO));		// ��������� ������
	wcl.hCursor = LoadCursor(NULL, IDC_ARROW);						// ����� �������
	wcl.lpszMenuName = NULL;										// ���� ���
	wcl.cbClsExtra = 0;					// �������������� ���������� ���
	wcl.cbWndExtra = 0;					// �������������� ���������� ���
	wcl.hbrBackground = CreateSolidBrush(RGB(80, 20, 0));			// ��������� ���� ����

	/* ����������� ������ ���� */
	if (!RegisterClassEx(&wcl)) {
		return 0;
	}
	/* ������� ���� ���� */
	hwnd = CreateWindow(
		szWindowClass,			// ��� ������ ����
		"API Application1",		// ���������
		WS_OVERLAPPEDWINDOW,	// ����� ����
		CW_USEDEFAULT,			// ���������� � - �������� windows
		CW_USEDEFAULT,			// ���������� � - �������� windows
		620,					// ������ - �������� windows
		630,					// ������ - �������� windows
		HWND_DESKTOP,			// ��� ������������� ����
		NULL,					// ��� ����
		hInstance,				// ������ � ������ ����������� ���������
		NULL					// ���. ���������� ���
	);
	/* ����� ���� */
	ShowWindow(hwnd, nWinMode);
	UpdateWindow(hwnd);
	/* �������� ����� ��������� ��������� */
	while (GetMessage(&msg, NULL, 0, 0)) {
		TranslateMessage(&msg);	// ��������� ������������� ����������
		DispatchMessage(&msg);	// ������� ���������� Windows
	}
	return msg.wParam;
}
//  FUNCTION: WndProc(HWND, UINT, WPARAM, LPARAM) 
//  PURPOSE:  Processes messages for the main window. 
//  WM_PAINT    - Paint the main window  
//  WM_DESTROY  - post a quit message and return 

/* ������� ������� ��������� ���������, ���������� �� ������� ���������. */

LRESULT CALLBACK WindowFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam) {
	PAINTSTRUCT ps;
	HDC hdc;
	HWND child1, child2, child3;
	static HWND hButton;
	switch (message) {
	case WM_CREATE:
		createDaughterWindowClass(hInst, "ChildWindowClass1", RGB(255, 223, 0));
		createDaughterWindowClass(hInst, "ChildWindowClass2", RGB(150, 150, 150));
		createDaughterWindowClass(hInst, "ChildWindowClass3", RGB(55, 223, 80));
		child1 = createDaughterDescriptor(hwnd, hInst, "ChildWindowClass1", 220, 180, 200, 200);
		ShowWindow(child1, SW_NORMAL);
		UpdateWindow(child1);
		child2 = createDaughterDescriptor(hwnd, hInst, "ChildWindowClass2", 0, 180, 200, 200);
		ShowWindow(child2, SW_NORMAL);
		UpdateWindow(child2);
		child3 = createDaughterDescriptor(hwnd, hInst, "ChildWindowClass3", 440, 180, 200, 200);
		ShowWindow(child3, SW_NORMAL);
		UpdateWindow(child3);
		hButton = CreateWindow("button", "Add", WS_CHILD | WS_VISIBLE | BS_PUSHBUTTON, 400, 400, 100, 30, hwnd,
			(HMENU)IDC_BUT_1, hInst, NULL);

		return 0;
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	case WM_COMMAND:
		switch (LOWORD(wParam)) {
		case IDC_BUT_1:
			MessageBoxA(hwnd, "Message", "Msg", MB_ICONWARNING);
		}
		break;
	default:
		return DefWindowProc(hwnd, message, wParam, lParam);
		break;
	}
	return 0;
}

LRESULT CALLBACK ChildProc(HWND hwnd, UINT Message, WPARAM wparam, LPARAM lparam) {
	if (Message == WM_DESTROY)
	{
		return 0;
	}
	return DefWindowProc(hwnd, Message, wparam, lparam);
}

LRESULT createDaughterWindowClass(HINSTANCE hInstance, LPCTSTR className, COLORREF color) {
	WNDCLASSEX w;
	w.lpfnWndProc = ChildProc;
	w.hInstance = hInstance;
	w.hbrBackground = CreateSolidBrush(color);
	w.lpszClassName = className;
	w.style = 0;
	w.cbSize = sizeof(WNDCLASSEX);
	w.hIcon = LoadIcon(NULL, MAKEINTRESOURCE(IDI_APPLICATION));
	w.hIconSm = LoadIcon(NULL, MAKEINTRESOURCE(IDI_WINLOGO));
	w.hCursor = LoadCursor(NULL, IDC_ARROW);
	w.lpszMenuName = NULL;
	w.cbClsExtra = 0;
	w.cbWndExtra = 0;
	/* ����������� ������ ���� */
	if (!RegisterClassEx(&w)) {
		return 0;
	}
	return 1;
}

HWND createDaughterDescriptor(HWND parentHWND, HINSTANCE hInstance, LPCTSTR className, int x, int y, int width, int height) {
	TCHAR title[50] = "Child1";

	return CreateWindowEx(
		0,
		className,
		NULL,
		WS_CHILDWINDOW | WS_BORDER | WS_VISIBLE | WS_SYSMENU | WS_CAPTION | WS_VISIBLE | WS_CLIPCHILDREN | WS_CLIPSIBLINGS,
		x, y,
		//CW_USEDEFAULT, CW_USEDEFAULT,
		width,
		height,
		parentHWND,
		NULL,
		hInstance,
		NULL);
}
