// Laba 7.cpp: определяет точку входа для приложения.
//

#include "stdafx.h"
#include "Laba 7.h"
#include <TlHelp32.h>

#define MAX_LOADSTRING 100

// Глобальные переменные:
HINSTANCE hInst;								// текущий экземпляр
TCHAR szTitle[MAX_LOADSTRING];					// Текст строки заголовка
TCHAR szWindowClass[MAX_LOADSTRING];			// имя класса главного окна
HANDLE hFile, hExe, hMapFile;
PROCESS_INFORMATION pi;
STARTUPINFO si;
SECURITY_ATTRIBUTES sa;

// Отправить объявления функций, включенных в этот модуль кода:
ATOM				MyRegisterClass(HINSTANCE hInstance);
BOOL				InitInstance(HINSTANCE, int);
LRESULT CALLBACK	WndProc(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	About(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DlgProc_TEXT(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	DlgProc_EXE(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	ListProcess(HWND, UINT, WPARAM, LPARAM);
INT_PTR CALLBACK	ListProcVAR(HWND, UINT, WPARAM, LPARAM);

int APIENTRY _tWinMain(HINSTANCE hInstance,
                     HINSTANCE hPrevInstance,
                     LPTSTR    lpCmdLine,
                     int       nCmdShow)
{
	UNREFERENCED_PARAMETER(hPrevInstance);
	UNREFERENCED_PARAMETER(lpCmdLine);

 	// TODO: разместите код здесь.
	MSG msg;
	HACCEL hAccelTable;

	// Инициализация глобальных строк
	LoadString(hInstance, IDS_APP_TITLE, szTitle, MAX_LOADSTRING);
	LoadString(hInstance, IDC_LABA7, szWindowClass, MAX_LOADSTRING);
	MyRegisterClass(hInstance);

	// Выполнить инициализацию приложения:
	if (!InitInstance (hInstance, nCmdShow))
	{
		return FALSE;
	}

	hAccelTable = LoadAccelerators(hInstance, MAKEINTRESOURCE(IDC_LABA7));

	// Цикл основного сообщения:
	while (GetMessage(&msg, NULL, 0, 0))
	{
		if (!TranslateAccelerator(msg.hwnd, hAccelTable, &msg))
		{
			TranslateMessage(&msg);
			DispatchMessage(&msg);
		}
	}

	return (int) msg.wParam;
}



//
//  ФУНКЦИЯ: MyRegisterClass()
//
//  НАЗНАЧЕНИЕ: регистрирует класс окна.
//
//  КОММЕНТАРИИ:
//
//    Эта функция и ее использование необходимы только в случае, если нужно, чтобы данный код
//    был совместим с системами Win32, не имеющими функции RegisterClassEx'
//    которая была добавлена в Windows 95. Вызов этой функции важен для того,
//    чтобы приложение получило "качественные" мелкие значки и установило связь
//    с ними.
//
ATOM MyRegisterClass(HINSTANCE hInstance)
{
	WNDCLASSEX wcex;

	wcex.cbSize = sizeof(WNDCLASSEX);

	wcex.style			= CS_HREDRAW | CS_VREDRAW;
	wcex.lpfnWndProc	= WndProc;
	wcex.cbClsExtra		= 0;
	wcex.cbWndExtra		= 0;
	wcex.hInstance		= hInstance;
	wcex.hIcon			= LoadIcon(hInstance, MAKEINTRESOURCE(IDI_LABA7));
	wcex.hCursor		= LoadCursor(NULL, IDC_ARROW);
	wcex.hbrBackground	= (HBRUSH)(COLOR_WINDOW+1);
	wcex.lpszMenuName	= MAKEINTRESOURCE(IDC_LABA7);
	wcex.lpszClassName	= szWindowClass;
	wcex.hIconSm		= LoadIcon(wcex.hInstance, MAKEINTRESOURCE(IDI_SMALL));

	ZeroMemory(&si, sizeof(si));
	si.cb = sizeof(STARTUPINFO);
	//ZeroMemory(&pi, sizeof(pi));
	sa.nLength = sizeof(SECURITY_ATTRIBUTES);
	sa.lpSecurityDescriptor = NULL;
	sa.bInheritHandle = TRUE;

	return RegisterClassEx(&wcex);
}

//
//   ФУНКЦИЯ: InitInstance(HINSTANCE, int)
//
//   НАЗНАЧЕНИЕ: сохраняет обработку экземпляра и создает главное окно.
//
//   КОММЕНТАРИИ:
//
//        В данной функции дескриптор экземпляра сохраняется в глобальной переменной, а также
//        создается и выводится на экран главное окно программы.
//
BOOL InitInstance(HINSTANCE hInstance, int nCmdShow)
{
   HWND hWnd, hBut;

   hInst = hInstance; // Сохранить дескриптор экземпляра в глобальной переменной

   hWnd = CreateWindow(szWindowClass, szTitle, WS_OVERLAPPEDWINDOW,
      CW_USEDEFAULT, 0, CW_USEDEFAULT, 0, NULL, NULL, hInstance, NULL);

   hBut = CreateWindow(L"BUTTON", L"Текстовый файл", WS_CHILD | WS_VISIBLE,
      20, 20, 150, 50, hWnd, (HMENU)IDB_TEXTFILE, hInstance, NULL);

   hBut = CreateWindow(L"BUTTON", L"Exe файл", WS_CHILD | WS_VISIBLE,
	   20, 70, 150, 50, hWnd, (HMENU)IDB_EXEFILE, hInstance, NULL);

   hBut = CreateWindow(L"BUTTON", L"Список процессов", WS_CHILD | WS_VISIBLE,
      20, 120, 350, 50, hWnd, (HMENU)IDB_PROCESS, hInstance, NULL);

   hBut = CreateWindow(L"BUTTON", L"Список переменных окружения", WS_CHILD | WS_VISIBLE,
	   20, 170, 350, 50, hWnd, (HMENU)IDB_LOCALVAR, hInstance, NULL);

   if (!hWnd)
   {
      return FALSE;
   }

   ShowWindow(hWnd, nCmdShow);
   UpdateWindow(hWnd);

   return TRUE;
}

//
//  ФУНКЦИЯ: WndProc(HWND, UINT, WPARAM, LPARAM)
//
//  НАЗНАЧЕНИЕ:  обрабатывает сообщения в главном окне.
//
//  WM_COMMAND	- обработка меню приложения
//  WM_PAINT	-Закрасить главное окно
//  WM_DESTROY	 - ввести сообщение о выходе и вернуться.
//
//
LRESULT CALLBACK WndProc(HWND hWnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	int wmId, wmEvent;
	PAINTSTRUCT ps;
	HDC hdc;
	TCHAR cmdproc1[500];
	TCHAR cmdproc2[] = L"C:\\Users\\Alex\\Source\\Repos\\Alexis-Dk\\C-win-api-training-course\\Lab7\\7 работа\\Process 3\\Debug\\Process 3.exe";
	TCHAR cmdproc3[] = L"C:\\Users\\Alex\\Source\\Repos\\Alexis-Dk\\C-win-api-training-course\\Lab7\\7 работа\\Process 2\\Debug\\Process 2.exe";
	int j = 0;
	char envVal[10];
	
	switch (message)
	{
	case WM_COMMAND:
		wmId    = LOWORD(wParam);
		wmEvent = HIWORD(wParam);
		// Разобрать выбор в меню:
		switch (wmId)
		{
		case IDM_ABOUT:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_ABOUTBOX), hWnd, About);
			break;
		case IDM_EXIT:
			DestroyWindow(hWnd);
			break;

		case IDB_TEXTFILE:
			hFile = CreateFile(L"C:\\Users\\Alex\\Source\\Repos\\Alexis-Dk\\C-win-api-training-course\\Lab7\\7 работа\\Laba 7\\file.txt", GENERIC_READ | GENERIC_WRITE, FILE_SHARE_READ | FILE_SHARE_WRITE,
					&sa, OPEN_ALWAYS, FILE_ATTRIBUTE_NORMAL, NULL);

			j = swprintf_s(cmdproc1, 500, L"%s", L"\"C:\\Users\\Alex\\Source\\Repos\\Alexis-Dk\\C-win-api-training-course\\Lab7\\7 работа\\Process 2\\Debug\\Process 2.exe\" ");
			swprintf_s(cmdproc1 + j, 500 - j, L"%d", (int)hFile);

			CreateProcess(NULL, cmdproc3, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);
			WaitForSingleObject(pi.hProcess, INFINITE);
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG1), hWnd, DlgProc_TEXT);
			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
			CloseHandle(hFile);
			break;

		case IDB_EXEFILE:
			hExe = CreateFile(L"C:\\Users\\Alex\\Source\\Repos\\Alexis-Dk\\C-win-api-training-course\\Lab7\\7 работа\\Laba 7\\Process 3.exe", GENERIC_READ, FILE_SHARE_READ,
					&sa, OPEN_EXISTING, FILE_ATTRIBUTE_NORMAL, NULL);
			if (hExe == INVALID_HANDLE_VALUE)
				MessageBox(hWnd, L"Файл не может быть открыт/создан!!", L"Error", MB_OK | MB_ICONERROR);
			else
			{
				hMapFile = CreateFileMapping(hExe, &sa, PAGE_READONLY, 0, 0, NULL);
				if (hMapFile == NULL)
					MessageBox(hWnd, L"Проекция не может быть создана!", L"Error", MB_OK | MB_ICONERROR);
				else
				{
					_itoa((int)hMapFile, envVal, 10);
					SetEnvironmentVariableA("ExeFile", envVal);
				}
			}

			/*
			STARTUPINFO si;
			PROCESS_INFORMATION pi;

			ZeroMemory(&si, sizeof(si));
			si.cb = sizeof(si);
			ZeroMemory(&pi, sizeof(pi));

			CreateProcess(NULL, L"2", NULL, NULL, FALSE, 0, NULL, NULL, &si, &pi);  */ //ошибка с правами доступа
			


			CreateProcess(NULL,  cmdproc2, NULL, NULL, TRUE, 0, NULL, NULL, &si, &pi);			//  cmdproc2
			WaitForSingleObject(pi.hProcess, INFINITE);
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG3), hWnd, DlgProc_EXE);
			CloseHandle(pi.hThread);
			CloseHandle(pi.hProcess);
			CloseHandle(hExe);
			CloseHandle(hMapFile);
			break;

		case IDB_PROCESS:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG2), hWnd, ListProcess);
			break;

		case IDB_LOCALVAR:
			DialogBox(hInst, MAKEINTRESOURCE(IDD_DIALOG4), hWnd, ListProcVAR);
			break;
		default:
			return DefWindowProc(hWnd, message, wParam, lParam);
		}
		break;
	case WM_PAINT:
		hdc = BeginPaint(hWnd, &ps);
		// TODO: добавьте любой код отрисовки...
		EndPaint(hWnd, &ps);
		break;
	case WM_DESTROY:
		PostQuitMessage(0);
		break;
	default:
		return DefWindowProc(hWnd, message, wParam, lParam);
	}
	return 0;
}

// Обработчик сообщений для окна "О программе".
INT_PTR CALLBACK About(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);
	switch (message)
	{
	case WM_INITDIALOG:
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		if (LOWORD(wParam) == IDOK || LOWORD(wParam) == IDCANCEL)
		{
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK DlgProc_TEXT(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	DWORD size, NumB;
	char buf[1000];
	char date[200];

	switch (message)
	{
	case WM_INITDIALOG:
		size = GetFileSize(hFile, NULL);
		SetFilePointer(hFile, 0, NULL, FILE_BEGIN);
		ReadFile(hFile, buf, size, &NumB, NULL);
		buf[size] = '\0';
		SetDlgItemTextA(hDlg, IDC_EDIT4, buf);

		FILETIME timeCreation, timeExit, Time, timeKernel, timeUser;
		SYSTEMTIME timeSys; 
		GetProcessTimes(pi.hProcess, &timeCreation, &timeExit, &timeKernel, &timeUser);
		Time.dwHighDateTime = timeExit.dwHighDateTime - timeCreation.dwHighDateTime;
		Time.dwLowDateTime = timeExit.dwLowDateTime - timeCreation.dwLowDateTime;
		FileTimeToLocalFileTime(&timeCreation, &timeCreation);
		FileTimeToSystemTime(&timeCreation, &timeSys); //время создания
		sprintf(date, "%d:%d:%d:%d", timeSys.wHour, timeSys.wMinute, timeSys.wSecond, timeSys.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT3, date);
		FileTimeToLocalFileTime(&timeExit, &timeExit);
		FileTimeToSystemTime(&timeExit, &timeSys); //время завершения
		sprintf(date, "%d:%d:%d:%d", timeSys.wHour, timeSys.wMinute, timeSys.wSecond, timeSys.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT5, date);
		FileTimeToLocalFileTime(&Time, &Time);
		FileTimeToSystemTime(&Time, &timeSys); 
		sprintf(date, "%d:%d:%d", timeSys.wMinute, timeSys.wSecond, timeSys.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT8, date);
		FileTimeToSystemTime(&timeUser, &timeSys);  //время в режиме пользователя 
		sprintf(date, "%d:%d:%d", timeSys.wMinute, timeSys.wSecond, timeSys.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT7, date);
		FileTimeToSystemTime(&timeKernel, &timeSys); //время в режиме ядра
		sprintf(date, "%d:%d:%d", timeSys.wMinute, timeSys.wSecond, timeSys.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT6, date);

		SetDlgItemInt(hDlg, IDC_EDIT1, pi.dwProcessId, FALSE);
		SetDlgItemInt(hDlg, IDC_EDIT2, pi.dwThreadId, FALSE);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK ListProcess(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	HANDLE hs;
	TCHAR name[500];
	HWND listbox;
	int j;

	switch (message)
	{
	case WM_INITDIALOG:
		listbox = GetDlgItem(hDlg, IDC_LIST1);

		hs = CreateToolhelp32Snapshot(TH32CS_SNAPPROCESS, 0);
		PROCESSENTRY32 P;
		P.dwSize = sizeof(PROCESSENTRY32);
		if (Process32First(hs, &P))
		{
			do
			{
				j = swprintf_s(name, 500, L"Имя: %s", P.szExeFile);			
				j += swprintf_s(name + j, 500 - j, L"      ID процесса: %d", P.th32ProcessID);
				swprintf_s(name + j, 500 - j, L"      ID родителя: %d", P.th32ParentProcessID);
				SendMessage(listbox, LB_ADDSTRING, 0, (LPARAM)name);
			}
			while (Process32Next(hs, &P));
		}
		CloseHandle(hs);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK DlgProc_EXE(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

	//DWORD  NumB, size;
//	char buf[1000];
	char date[200];

	switch (message)
	{
	case WM_INITDIALOG:
		FILETIME timeCreation, timeExit, timeKernel, timeUser, Time;
		SYSTEMTIME timeSys, timeSys1;
		GetProcessTimes(pi.hProcess, &timeCreation, &timeExit, &timeKernel, &timeUser);
		Time.dwHighDateTime = timeExit.dwHighDateTime - timeCreation.dwHighDateTime;
		Time.dwLowDateTime = timeExit.dwLowDateTime - timeCreation.dwLowDateTime;
		FileTimeToLocalFileTime(&timeCreation, &timeCreation);
		FileTimeToSystemTime(&timeCreation, &timeSys);
		sprintf(date, "%d:%d:%d:%d", timeSys.wHour, timeSys.wMinute, timeSys.wSecond, timeSys.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT3, date);
		FileTimeToLocalFileTime(&timeExit, &timeExit);
		FileTimeToSystemTime(&timeExit, &timeSys1);
		sprintf(date, "%d:%d:%d:%d", timeSys1.wHour, timeSys1.wMinute, timeSys1.wSecond, timeSys1.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT5, date);
		sprintf(date, "%d:%d:%d", timeSys.wMinute, timeSys.wSecond, timeSys.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT8, date);
		FileTimeToSystemTime(&timeUser, &timeSys);
		sprintf(date, "%d:%d:%d", timeSys.wMinute, timeSys.wSecond, timeSys.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT7, date);
		//FileTimeToLocalFileTime(&timeKernel, &timeKernel);
		FileTimeToSystemTime(&timeKernel, &timeSys);
		sprintf(date, "%d:%d:%d", timeSys.wMinute, timeSys.wSecond, timeSys.wMilliseconds);
		SetDlgItemTextA(hDlg, IDC_EDIT6, date);

		SetDlgItemInt(hDlg, IDC_EDIT1, pi.dwProcessId, FALSE);
		SetDlgItemInt(hDlg, IDC_EDIT2, pi.dwThreadId, FALSE);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}

INT_PTR CALLBACK ListProcVAR(HWND hDlg, UINT message, WPARAM wParam, LPARAM lParam)
{
	UNREFERENCED_PARAMETER(lParam);

//	HANDLE hs;
//	TCHAR name[500];
	HWND listbox;
	LPCTSTR lpszVariable;
	LPVOID lpvEnv;
//	int j;
	char envVal[10];

	switch (message)
	{
	case WM_INITDIALOG:
		listbox = GetDlgItem(hDlg, IDC_LIST1);

		_itoa(128, envVal, 10);
		SetEnvironmentVariableA("ExeFile", envVal);

		lpvEnv = GetEnvironmentStrings();
		lpszVariable = (LPCTSTR)lpvEnv;
		while (lpszVariable[0] != '\0')
		{
			SendMessage(listbox, LB_ADDSTRING, 0, (LPARAM)lpszVariable);
			lpszVariable = lpszVariable + _tcslen(lpszVariable) + 1;
		}
		FreeEnvironmentStrings((LPTSTR)lpvEnv);
		return (INT_PTR)TRUE;

	case WM_COMMAND:
		switch (LOWORD(wParam))
		{
		case IDCANCEL:
			EndDialog(hDlg, LOWORD(wParam));
			return (INT_PTR)TRUE;
		}
		break;
	}
	return (INT_PTR)FALSE;
}