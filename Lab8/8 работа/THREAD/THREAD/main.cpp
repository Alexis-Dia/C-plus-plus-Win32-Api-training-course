#include <Windows.h>
#include <string.h>
#include <stdio.h>
#include <stdlib.h>
#include <iostream>
#include <time.h>
#include "resource.h"
#include "TlHelp32.h"
#include <commctrl.h>

BOOL CALLBACK DialogProc(HWND, UINT, WPARAM, LPARAM);
HWND hDialog, hwndMain;

void setPriority(HANDLE, int);

DWORD WINAPI TrackBarThreadOne(PVOID pvParam)
{
	int count = 0;
	for ( ; ; )
	{
		for (int i = 0; i < 10000000; i++)
		{

		}
		count++;
		if (count == 100) count = 0;
		char buffer[20];
		SendMessage(GetDlgItem(hwndMain, IDC_PROGRESS1), TBM_SETPOS, (WPARAM)TRUE, (LPARAM)count);
		sprintf_s(buffer, 20, "%d", count);
		SetWindowText(GetDlgItem(hwndMain, IDC_EDIT1), buffer);
	}
	return 0;
}

DWORD WINAPI TrackBarThreadTwo(PVOID pvParam)
{
	int count = 0;
	for ( ; ; )
	{
		for (int i = 0; i < 10000000; i++)
		{

		}
		count++;
		if (count == 100) count = 0;
		char buffer[20];
		SendMessage(GetDlgItem(hwndMain, IDC_PROGRESS2), TBM_SETPOS, (WPARAM)TRUE, (LPARAM)count);
		sprintf_s(buffer, 20, "%d", count);
		SetWindowText(GetDlgItem(hwndMain, IDC_EDIT2), buffer);
	}
	return 0;
}

DWORD WINAPI TrackBarThreadThree(PVOID pvParam)
{
	int count = 0;
	for ( ; ; )
	{
		for (int i = 0; i < 10000000; i++)
		{

		}
		count++;
		if (count == 100) count = 0;
		char buffer[20];
		SendMessage(GetDlgItem(hwndMain, IDC_PROGRESS3), TBM_SETPOS, (WPARAM)TRUE, (LPARAM)count);

		sprintf_s(buffer, 20, "%d", count);
		SetWindowText(GetDlgItem(hwndMain, IDC_EDIT3), buffer);
	}
	return 0;
}

int WINAPI WinMain(HINSTANCE hInstance, HINSTANCE hPrevInst, LPSTR lpszArgs, int nWinMode)
{
	hDialog = CreateDialog(hInstance, MAKEINTRESOURCE(IDD_DIALOG1), NULL, DialogProc);
	ShowWindow(hDialog, 1);

	MSG msg;
	while (GetMessage(&msg, NULL, 0, 0))
	{
		TranslateMessage(&msg);
		DispatchMessage(&msg);	
	}
}

BOOL CALLBACK DialogProc(HWND hwnd, UINT message, WPARAM wParam, LPARAM lParam)
{
	DWORD dTs[3];
	static HANDLE hThread[3];
	HWND progressBar[] = {
		GetDlgItem(hwnd, IDC_PROGRESS1),
		GetDlgItem(hwnd, IDC_PROGRESS2),
		GetDlgItem(hwnd, IDC_PROGRESS3)
	},
	editText[] = {
		GetDlgItem(hwndMain, IDC_EDIT1),
		GetDlgItem(hwndMain, IDC_EDIT2),
		GetDlgItem(hwndMain, IDC_EDIT3)
	};
	char*  textPriority[3] = { "Низкий", "Обычный", "Высокий" };
	int comboPosition = 0, Offset = 0, j = 0;
	char* String = new char[1024];
	char buffer[1024];
	CONTEXT ct;

	FILETIME pftCreationTime[3], pftExitTime[3], pftKernelTime[3], pftUserTime[3];
	SYSTEMTIME creattime[3], exittime[3], stLocal[3], stLocal1[3];
	char *buf = new char[1024];

	switch (message)
	{
		case WM_INITDIALOG:
			hwndMain = hwnd;

			for (int i = 0; i < 3; i++)
			{
				SendMessage(progressBar[i], PBM_SETRANGE, 0, (LPARAM)MAKELONG(0, 1000));
				SendMessage(GetDlgItem(hwnd, IDC_COMBO1), CB_ADDSTRING, 0, (LPARAM)textPriority[i]);
			}
			SendMessage(GetDlgItem(hwnd, IDC_COMBO1), CB_SETCURSEL, 0, 0);
			SendMessage(GetDlgItem(hwnd, IDC_RADIO1), BM_SETCHECK, 1, 0);
			return TRUE;

		case WM_COMMAND:
				switch (LOWORD(wParam))
				{
					case IDC_BUTTON1:
						for (int i = 0; i < 3; i++)
						{
							hThread[i] = CreateThread(NULL, 0,
								(i == 0) ? TrackBarThreadOne : 
								(i == 1) ? TrackBarThreadTwo : 
								TrackBarThreadThree, 
								NULL, CREATE_SUSPENDED, &dTs[i]
							);
						}
						MessageBox(hwnd, "Потоки успешно созданы!", "Создание потоков", 0);
						break;

					case IDC_BUTTON2:
						for (int i = 0; i < 3; i++)
							ResumeThread(hThread[i]);
						break;

					case IDC_BUTTON3:
						for (int i = 0; i < 3; i++)
							SuspendThread(hThread[i]);
						break;

					case IDC_BUTTON4:
						for (int i = 0; i < 3; i++)
						{
							TerminateThread(hThread[i], 0);
							SendMessage(progressBar[i], PBM_SETPOS, 0, 0);
							SetWindowText(editText[i], "0");

							GetThreadTimes(hThread[i], &pftCreationTime[i], &pftExitTime[i], &pftKernelTime[i], &pftUserTime[i]);
							
							FileTimeToSystemTime(&pftCreationTime[i], &creattime[i]);
							SystemTimeToTzSpecificLocalTime(NULL, &creattime[i], &stLocal[i]);
							j += wsprintf(buf + j, "Время создания %d-го потока: %02d:%02d:%02d\r\n", i + 1, stLocal[i].wHour, stLocal[i].wMinute, stLocal[i].wSecond);

							FileTimeToSystemTime(&pftExitTime[i], &exittime[i]);
							SystemTimeToTzSpecificLocalTime(NULL, &exittime[i], &stLocal1[i]);
							j += wsprintf(buf + j, "Время завершения %d-го потока: %02d:%02d:%02d\r\n\n", i + 1, stLocal1[i].wHour, stLocal1[i].wMinute, stLocal1[i].wSecond);
						}

						MessageBox(hwnd, buf, "Время выполнения потоков", 0);						
						break;

					case IDC_BUTTON5:
						comboPosition = SendMessage(GetDlgItem(hwnd, IDC_COMBO1), CB_GETCURSEL, 0, 0);	

						if (SendMessage(GetDlgItem(hwnd, IDC_RADIO1), BM_GETCHECK, 0, 0))
							setPriority(hThread[0], comboPosition);
						else if (SendMessage(GetDlgItem(hwnd, IDC_RADIO2), BM_GETCHECK, 0, 0))
							setPriority(hThread[1], comboPosition);
						else
							setPriority(hThread[2], comboPosition);
						break;

					case IDC_BUTTON6:
						if (SendMessage(GetDlgItem(hwnd, IDC_RADIO1), BM_GETCHECK, 0, 0))
							SuspendThread(hThread[0]);
						else if (SendMessage(GetDlgItem(hwnd, IDC_RADIO2), BM_GETCHECK, 0, 0))
							SuspendThread(hThread[1]);
						else
							SuspendThread(hThread[2]);
						break;

					case IDC_BUTTON7:
						if (SendMessage(GetDlgItem(hwnd, IDC_RADIO1), BM_GETCHECK, 0, 0))
							ResumeThread(hThread[0]);
						else if (SendMessage(GetDlgItem(hwnd, IDC_RADIO2), BM_GETCHECK, 0, 0))
							ResumeThread(hThread[1]);
						else
							ResumeThread(hThread[2]);
						break;

					case IDC_BUTTON8:
						ct.ContextFlags = CONTEXT_FULL;
						if (SendMessage(GetDlgItem(hwnd, IDC_RADIO1), BM_GETCHECK, 0, 0))
						{
							GetThreadContext(hThread[0], &ct);
							Offset += sprintf(String + Offset, "%s\r\n", "КОНТЕКСТ 1-ГО ПОТОКА");
						}
						else if (SendMessage(GetDlgItem(hwnd, IDC_RADIO2), BM_GETCHECK, 0, 0))
						{
							GetThreadContext(hThread[1], &ct);
							Offset += sprintf(String + Offset, "%s\r\n", "КОНТЕКСТ 2-ГО ПОТОКА");
						}
						else
						{
							GetThreadContext(hThread[2], &ct);
							Offset += sprintf(String + Offset, "%s\r\n", "КОНТЕКСТ 3-ГО ПОТОКА");
						}

						sprintf_s(buffer, 1024, "%s 0x%x", "ContextFlags: ", (LPARAM)ct.ContextFlags);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024,"%s 0x%x","Dr0: ", (LPARAM)ct.Dr0);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Dr1: ", ct.Dr1);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Dr2: ", ct.Dr2);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Dr3: ", ct.Dr3);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Dr6: ", ct.Dr6);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Dr7: ", ct.Dr7);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Eax: ", ct.Eax);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Ebp: ", ct.Ebp);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Ecx: ", ct.Ecx);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Edi: ", ct.Edi);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Edx: ", ct.Edx);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","EFlags: ", ct.EFlags);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Eip: ", ct.Eip);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Esi: ", ct.Esi);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","Esp: ", ct.Esp);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","SegCs: ", ct.SegCs);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","SegDs: ", ct.SegDs);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","SegEs: ", ct.SegEs);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","SegFs: ", ct.SegFs);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","SegGs: ", ct.SegGs);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						sprintf_s(buffer, 1024, "%s 0x%x","SegSs: ", ct.SegSs);
						Offset += sprintf(String + Offset, "%s\r\n", buffer);

						SetWindowText(GetDlgItem(hwnd, IDC_EDIT4), String);
						break;

					case IDCANCEL:
						delete String;
						PostQuitMessage(0);
						break;						
				}
			break;
	}
	return 0;
}

void setPriority(HANDLE hThread, int comboPosition)
{
	if (comboPosition == 0)
		SetThreadPriority(hThread, THREAD_PRIORITY_HIGHEST);
	else if (comboPosition == 1)
		SetThreadPriority(hThread, THREAD_PRIORITY_LOWEST);
	else
		SetThreadPriority(hThread, THREAD_PRIORITY_NORMAL);
};