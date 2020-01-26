#include <windows.h>
#include <string.h>
#include <stdio.h>
#include "resource.h"


#define MAX_PATH	100
#define NEWLINE		"\x0D\x0A"

LRESULT CALLBACK WindowMainFunc(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK WriteFile(HWND, UINT, WPARAM, LPARAM);
BOOL CALLBACK OpenFile(HWND, UINT, WPARAM, LPARAM);

char szWinNameMain[] = "MainWindow"; 
HWND hwndMain, hlst, hedit, hadd;
HINSTANCE hInst;

HANDLE hwndText,hwndBin;

INT32 Int32;						//	4 
INT64 Int64;						//	8
UINT Uint;							//	4
bool Bool;							//	1
BYTE Byte;							//	1 
WORD Word;							//  2 
DWORD Dword;						//  4
long Long;							//	4 
float Float;						//	4
double Double;						//	8
char Char;							//	1
char String[32];					//	32

int WINAPI WinMain(HINSTANCE hThisInst, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{																	//  Дескриптор окна
	MSG msg;
	WNDCLASSEX wclMain;												//  Структура, определяющая класс окна

	/* Определение класса окна */
	wclMain.hInstance = hThisInst;									//  Работа с данным экземпляром
	wclMain.lpszClassName = szWinNameMain;							//  Имя класса окна
	wclMain.lpfnWndProc = WindowMainFunc;							//  Оконная функция
	wclMain.style = CS_DBLCLKS;										//  Использовать стиль окна по умолчанию
	wclMain.cbSize = sizeof(WNDCLASSEX);							//  Установка размера WNDCLASSEX
	wclMain.hIcon = LoadIcon(NULL, IDI_APPLICATION);				//  Большие иконки
	wclMain.hIconSm = LoadIcon(NULL, IDI_APPLICATION);				//  Маленькие иконки
	wclMain.hCursor = LoadCursor(NULL, IDC_ARROW);					//  Стиль курсора
	wclMain.lpszMenuName = "MYMENY";								//  Меню нет
	wclMain.cbClsExtra = 0;											//  Дополнительной информации нет
	wclMain.cbWndExtra = 0;											//  Дополнительной информации нет
	wclMain.hbrBackground = CreateSolidBrush(RGB(88,165,245));		//  Установка фона окна

	/* Регистрация класса окна */
	if (!RegisterClassEx(&wclMain)) return 0;

	/* вычисление координат центра экрана */
	RECT screenRect;
	GetWindowRect(GetDesktopWindow(), &screenRect);					// разрешение экрана
	int x = screenRect.right / 2 - 350;
	int y = screenRect.bottom / 2 - 250;

	/* Создаём само окно */
	hwndMain = CreateWindow(szWinNameMain,			//  Имя класса окна
		"Работа с файлами",								//  Заголовок
		WS_OVERLAPPEDWINDOW | WS_CLIPCHILDREN,		//  Стиль окна - нормальный
		x, y,								
		700, 500,
		HWND_DESKTOP,								//  Нет родительского окна
		NULL,										//  Нет меню
		hThisInst,									//  Работа с данным экземпляром программы
		NULL										//  Дополнительные аргументы отсутствуют
	);

	/* Вывод окна */
	ShowWindow(hwndMain, nWinMode);
	UpdateWindow(hwndMain);

	/* Создание цикла обработки сообщений */
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);  // Разрешить использование клавиатуры
		DispatchMessage(&msg);   // Вернуть управление Windows
	}
	return msg.wParam;
}

LRESULT CALLBACK WindowMainFunc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	HDC hdc;
	switch (message)
    {
		case WM_COMMAND:
			switch (LOWORD(wParam))
			{
				case ID_WRITE:
					DialogBox(hInst, "DIALOG_WRITE_FILE", hwnd, (DLGPROC)WriteFile);
					break;

				case ID_OPEN:
					DialogBox(hInst, "DIALOG_OPEN_FILE", hwnd, (DLGPROC)OpenFile);
					break;

				case ID_EXIT:
					PostQuitMessage(0);
					break;
			}
		break;

		case WM_CREATE :
			
		break;

		case WM_DESTROY: 		
			PostQuitMessage(0);
        break;

		case WM_PAINT:
			PAINTSTRUCT ps;
			hdc = BeginPaint(hwnd, &ps);
			
			EndPaint(hwnd, &ps);
		break;

		default:
			return DefWindowProc(hwnd, message, wParam, lParam);
    }
    return 0;
}

BOOL CALLBACK WriteFile(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static OPENFILENAME ofn;
	static char fileName[MAX_PATH] = "";
	int i;
	DWORD size, dwBytes, attribute;
	char Buffer[100] = "";
	DWORD post = 0;

	int IDC_EDIT[12] = {IDC_EDIT1, IDC_EDIT2, IDC_EDIT3, IDC_EDIT4, IDC_EDIT5, IDC_EDIT6, IDC_EDIT7, IDC_EDIT8, IDC_EDIT9, IDC_EDIT10, IDC_EDIT11, IDC_EDIT12 };

	switch (message)
	{
		case WM_INITDIALOG:
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hwnd;
			ofn.lpstrFile = fileName;		
			ofn.nMaxFile = sizeof(fileName);

			SetDlgItemText(hwnd, IDC_EDIT1, "13");
			SetDlgItemText(hwnd, IDC_EDIT2, "56");
			SetDlgItemText(hwnd, IDC_EDIT3, "33");
			SetDlgItemText(hwnd, IDC_EDIT4, "19");
			SetDlgItemText(hwnd, IDC_EDIT5, "55");
			SetDlgItemText(hwnd, IDC_EDIT6, "23");
			SetDlgItemText(hwnd, IDC_EDIT7, "17.00");
			SetDlgItemText(hwnd, IDC_EDIT8, "8.00");
			SetDlgItemText(hwnd, IDC_EDIT9, "C");
			SetDlgItemText(hwnd, IDC_EDIT10, "Тестовая строка");
			SetDlgItemText(hwnd, IDC_EDIT11, "8");
			SetDlgItemText(hwnd, IDC_EDIT12, "1");
			SetDlgItemText(hwnd, IDC_EDIT17, "Сергей Пашкевич");

			return TRUE;

		case WM_COMMAND:
				switch (LOWORD(wParam))
				{
					case IDC_BUTTON1:
						ofn.lpstrFilter = "Текстовый файл\0*.txt;\0Все\0*.*\0";
						ofn.Flags = OFN_OVERWRITEPROMPT;

          				if (GetSaveFileName(&ofn))
						{				
							hwndText = CreateFile(fileName, GENERIC_WRITE, 0, NULL, CREATE_ALWAYS,				
											FILE_ATTRIBUTE_NORMAL, NULL);

							SetWindowText(hwnd, fileName);

							if (hwndText == INVALID_HANDLE_VALUE)
								MessageBox(hwndMain, "Ошибка", "Ошибка", MB_OK | MB_ICONWARNING);
					
							Int64 = GetDlgItemInt(hwnd, IDC_EDIT4, NULL, TRUE);

							Word = GetDlgItemInt(hwnd, IDC_EDIT5, NULL, TRUE);

							Dword = GetDlgItemInt(hwnd, IDC_EDIT6, NULL, TRUE);

							for (i = 0; i < 12; i++)
							{
								HWND F = GetDlgItem(hwnd, IDC_EDIT[i]);
								size = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT[i]));
								GetWindowText(GetDlgItem(hwnd, IDC_EDIT[i]), Buffer, size + 1);
								WriteFile(hwndText, Buffer, size, &size, NULL);
								WriteFile(hwndText, &NEWLINE, 2, &dwBytes, NULL);
							}						
							CloseHandle(hwndText);
						}
						break;

					case IDC_BUTTON8:

							

							hwndBin = CreateFile(fileName, GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
							SetFilePointer(hwndBin, 0, NULL, FILE_BEGIN);

							ReadFile(hwndBin, &Byte, sizeof(BYTE), &dwBytes, NULL);

							post += dwBytes;
							
							ReadFile(hwndBin, &Long, sizeof(LONG), &dwBytes, NULL);

							post += dwBytes;

							SetFilePointer(hwndBin, sizeof(BYTE) + sizeof(LONG), NULL, FILE_BEGIN);

							Int32 = 15;
							WriteFile(hwndBin, &Int32, sizeof(Int32), &dwBytes, NULL);

							CloseHandle(hwndBin);
						break;

					case IDC_BUTTON2:                                                       
						ofn.lpstrFilter = "Бинарный файл\0*.bin;\0Все\0*.*\0";
						ofn.Flags = OFN_OVERWRITEPROMPT;
          				if (GetSaveFileName(&ofn))
						{				
							hwndBin = CreateFile(fileName, GENERIC_WRITE, 0, 0, CREATE_ALWAYS, 0, 0);	

							if (hwndBin == INVALID_HANDLE_VALUE)
								MessageBox(hwndMain, "Ошибка", "Ошибка", MB_OK | MB_ICONWARNING);
					
							Byte = GetDlgItemInt(hwnd, IDC_EDIT1, NULL, TRUE);
							WriteFile(hwndBin, &Byte, sizeof(Byte), &dwBytes, NULL);

							Long = GetDlgItemInt(hwnd, IDC_EDIT2, NULL, TRUE);
							WriteFile(hwndBin, &Long, sizeof(Long), &dwBytes, NULL);

							Int32 = GetDlgItemInt(hwnd, IDC_EDIT3, NULL, TRUE);
							WriteFile(hwndBin, &Int32, sizeof(Int32), &dwBytes, NULL);

							Int64 = GetDlgItemInt(hwnd, IDC_EDIT4, NULL, TRUE);
							WriteFile(hwndBin, &Int64, sizeof(Int64), &dwBytes, NULL);

							Word = GetDlgItemInt(hwnd, IDC_EDIT5, NULL, TRUE);
							WriteFile(hwndBin, &Word, sizeof(Word), &dwBytes, NULL);

							Dword = GetDlgItemInt(hwnd, IDC_EDIT6, NULL, TRUE);
							WriteFile(hwndBin, &Dword, sizeof(Dword), &dwBytes, NULL);

							size = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT7));
							GetWindowText(GetDlgItem(hwnd, IDC_EDIT7), Buffer, size + 1);
							Float = (float)atof(Buffer);
							WriteFile(hwndBin, &Float, sizeof(Float), &dwBytes, NULL);
							SetDlgItemInt(hwnd, IDC_EDIT7, size, TRUE);

							size = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT8));
							GetWindowText(GetDlgItem(hwnd, IDC_EDIT8), Buffer, size + 1);
							Double = atof(Buffer);
							WriteFile(hwndBin, &Double, sizeof(Double), &dwBytes, NULL);

							size = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT9));
							GetWindowText(GetDlgItem(hwnd, IDC_EDIT9), Buffer, size + 1);
							Char = Buffer[0];
							WriteFile(hwndBin, &Char, sizeof(Char), &dwBytes, NULL);

							size = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT10));
							GetWindowText(GetDlgItem(hwnd, IDC_EDIT10), Buffer, size + 1);
							sprintf(String, "%s", Buffer);
							WriteFile(hwndBin, &String, sizeof(String), &dwBytes, NULL);

							Uint = GetDlgItemInt(hwnd, IDC_EDIT11, NULL, FALSE);
							WriteFile(hwndBin, &Uint, sizeof(Uint), &dwBytes, NULL);

							Bool = GetDlgItemInt(hwnd, IDC_EDIT12, NULL, FALSE);
							WriteFile(hwndBin, &Bool, sizeof(Bool), &dwBytes, NULL);

							CloseHandle(hwndBin);
						}
						break;

					case IDC_BUTTON5:
						if (strlen(fileName) != 0)
						{
							hwndText = CreateFile(fileName, GENERIC_WRITE, 0, 0, OPEN_EXISTING, 0, 0);
							SetFilePointer(hwndText, NULL, NULL, FILE_END);
							size = GetWindowTextLength(GetDlgItem(hwnd, IDC_EDIT17));
							GetWindowText(GetDlgItem(hwnd, IDC_EDIT17), Buffer, size + 1);
							WriteFile(hwndText, Buffer, size, &size, NULL);
							CloseHandle(hwndText);
						} 
						else
						{
							MessageBox(hwndMain, "Откройте файл", "Ошибка", MB_OK);
						}
						break;

					case IDC_BUTTON7:
						if (strlen(fileName) != 0)
						{
							HWND hwndCheck = GetDlgItem(hwnd, IDC_CHECK1);
							if (SendMessage (hwndCheck, BM_GETCHECK, 0, 0))
							{
								attribute = GetFileAttributes(fileName);
								SetFileAttributes(fileName, attribute | FILE_ATTRIBUTE_READONLY);
							}

							hwndCheck = GetDlgItem(hwnd, IDC_CHECK2);
							if (SendMessage (hwndCheck, BM_GETCHECK, 0, 0))
							{
								attribute = GetFileAttributes(fileName);
								SetFileAttributes(fileName, attribute | FILE_ATTRIBUTE_HIDDEN);
							}

							hwndCheck = GetDlgItem(hwnd, IDC_CHECK3);
							if (SendMessage (hwndCheck, BM_GETCHECK, 0, 0))
							{
								attribute = GetFileAttributes(fileName);
								SetFileAttributes(fileName, attribute | FILE_ATTRIBUTE_SYSTEM);
							}
						} 
						else
						{
							SetFileAttributes(fileName, NULL);
							MessageBox(hwndMain, "Откройте файл", "Ошибка", MB_OK);
						}
						break;

					case IDC_BUTTON3:
						EndDialog(hwnd, 0);
						break;

					case IDCANCEL:
						EndDialog(hwnd, 0);
						break;						
				}
			break;
	}
	return 0;
}

BOOL CALLBACK OpenFile(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	static OPENFILENAME ofn;
	static char fileName[MAX_PATH] = "";

	int i, end, k;
	DWORD size, dwBytes, attribute;
	char Buffer[100] = "";
	char TxtFile[200] = "";
	char dump[300] = "";
	char BinFile[200] = "";
	char BinnFile[200] = "";
	char q[200] = "";

	switch (message)
	{
		case WM_INITDIALOG:
			ofn.lStructSize = sizeof(OPENFILENAME);
			ofn.hwndOwner = hwnd;
			ofn.lpstrFile = fileName;		
			ofn.nMaxFile = sizeof(fileName);

			return TRUE;

		case WM_COMMAND:
				switch (LOWORD(wParam))
				{
					case IDC_BUTTON4:
						ofn.lpstrFilter = "Текстовый файл\0*.txt;\0Все\0*.*\0";
						if (GetOpenFileName(&ofn))
						{
							SetDlgItemText(hwnd, IDC_EDIT15, " ");
							SetDlgItemText(hwnd, IDC_EDIT16, " ");

							hwndText = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);

							if (hwndText == INVALID_HANDLE_VALUE)
								MessageBox(hwndMain, "Ошибка", "Ошибка", MB_OK | MB_ICONWARNING);

							attribute = GetFileAttributes(fileName);
							//if (attribute & FILE_ATTRIBUTE_HIDDEN)
							//	MessageBox(hwndMain, "Ошибка", "FILE_ATTRIBUTE_HIDDEN", MB_OK);

							if (attribute & FILE_ATTRIBUTE_READONLY)
								MessageBox(hwndMain, "Ошибка", "FILE_ATTRIBUTE_READONLY", MB_OK);
								
							//SetFileAttributes(fileName, attribute | FILE_ATTRIBUTE_ARCHIVE); 
							
							end = GetFileSize(hwndText, NULL);

							SetFilePointer(hwndText, 0, NULL, FILE_BEGIN);

							ReadFile(hwndText, TxtFile, end, &dwBytes, NULL);
							CloseHandle(hwndText);
							
							SetDlgItemTextA(hwnd, IDC_EDIT15, TxtFile);

							i = 0;
							k = 0;
							while (i < end)
							{
								if (i % 16 == 0 && i != 0)
									k += sprintf(dump + k, "\r\n");
								k += sprintf(dump + k, "%.2X ", (unsigned char)TxtFile[i]);
								i++;
							}

							SetDlgItemText(hwnd, IDC_EDIT16, dump); 
						}
						break;

					case IDC_BUTTON5:                                                       
						ofn.lpstrFilter = "Бинарный файл\0*.bin;\0Все\0*.*\0";
          				if (GetOpenFileName(&ofn))

						{
							SetDlgItemText(hwnd, IDC_EDIT13, " ");
							SetDlgItemText(hwnd, IDC_EDIT14, " ");

							hwndBin = CreateFile(fileName, GENERIC_READ, FILE_SHARE_READ, NULL, OPEN_EXISTING, NULL, NULL);

							if (hwndBin == INVALID_HANDLE_VALUE)
									MessageBox(hwndMain, "Ошибка", "Ошибка", MB_OK | MB_ICONWARNING);

							attribute = GetFileAttributes(fileName);
								if (attribute & FILE_ATTRIBUTE_HIDDEN) 
									MessageBox(hwndMain, "Ошибка", "FILE_ATTRIBUTE_HIDDEN", MB_OK);

								if(attribute & FILE_ATTRIBUTE_READONLY)
									MessageBox(hwndMain, "Ошибка", "FILE_ATTRIBUTE_READONLY", MB_OK);

							end = GetFileSize(hwndBin, NULL);

							SetFilePointer(hwndBin, 0, NULL, FILE_BEGIN);

							ReadFile(hwndBin, BinFile, end, &dwBytes, NULL);

							SetFilePointer(hwndBin, 0, NULL, FILE_BEGIN);


							ReadFile(hwndBin, &Byte, sizeof(BYTE), &dwBytes, NULL);								
							sprintf_s(q, "%d ", Byte);
							strcat_s(BinnFile, q);
							
							ReadFile(hwndBin, &Long, sizeof(LONG), &dwBytes, NULL);
							sprintf_s(q, "%d ", Long);
							strcat_s(BinnFile, q);
								
							ReadFile(hwndBin, &Int32,sizeof(INT32), &dwBytes, NULL);
							sprintf_s(q, "%d ", Int32);
							strcat_s(BinnFile, q);
							
							ReadFile(hwndBin, &Int64, sizeof(INT64), &dwBytes, NULL);
							sprintf_s(q, "%d ",Int64);
							strcat_s(BinnFile, q);
								
							ReadFile(hwndBin, &Word,sizeof(WORD), &dwBytes, NULL);
							sprintf_s(q, "%d ",Word);
							strcat_s(BinnFile, q);
								
							ReadFile(hwndBin, &Dword, sizeof(DWORD), &dwBytes, NULL);
							sprintf_s(q, "%d ", Dword);
							strcat_s(BinnFile, q);
								
							ReadFile(hwndBin, &Float, sizeof(float), &dwBytes, NULL);
							sprintf_s(q, "%.2f ",Float);
							strcat_s(BinnFile, q);
								
							ReadFile(hwndBin, &Double, sizeof(double), &dwBytes,NULL);
							sprintf_s(q, "%.2f ", Double);
							strcat_s(BinnFile, q);


							ReadFile(hwndBin, &Char, sizeof(char), &dwBytes,NULL);
							sprintf_s(q, "%c ", Char);
							strcat_s(BinnFile, q);

							ReadFile(hwndBin, &String, sizeof(String), &dwBytes,NULL);
							sprintf_s(q, "%s", String);
							strcat_s(BinnFile, q);

							ReadFile(hwndBin, &Uint, sizeof(Uint), &dwBytes,NULL);
							sprintf_s(q, "%d", Uint);
							strcat_s(BinnFile, q);

							ReadFile(hwndBin, &Bool, sizeof(Bool), &dwBytes,NULL);
							sprintf_s(q, "%d", Bool);
							strcat_s(BinnFile, q);
													
							SetDlgItemTextA(hwnd, IDC_EDIT13, BinnFile); 

							CloseHandle(hwndBin);

							i = 0;
							k = 0;
							while (i < end)
							{
								if (i % 16 == 0 && i != 0)
									k += sprintf(dump + k, "\r\n");
						 		k += sprintf(dump + k,  "%.2X ", (unsigned char)BinFile[i]);
								i++;
							}
							SetDlgItemTextA(hwnd, IDC_EDIT14, dump);				
			 			}
						break;

					case IDC_BUTTON3:
						EndDialog(hwnd, 0);
						break;

					case IDCANCEL:
						EndDialog(hwnd, 0);
						break;						
				}
			break;
	}
	return 0;
}