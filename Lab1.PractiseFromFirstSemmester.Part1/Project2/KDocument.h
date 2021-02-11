#pragma once
// KDocument.h
#include <windows.h>
#include <vector>
#include <string>
using namespace std;
class KDocument {

public:
	BOOL Open(const char* file);
	void Initialize(LPTEXTMETRIC tm);
	void ScrollSettings(HWND hwnd, int width, int height);
	void UpdateHscroll(HWND hwnd, int xInc);
	void UpdateVscroll(HWND hwnd, int yInc);
	void PutText(HWND hwnd, HDC hdc);
	int cxChar; // ñðåäíÿÿ øèðèíà ñèìâîëà
	int yStep; // âûñîòà (øàã) ñòðîêè
	int lineLenMax; // ìàêñèìàëüíàÿ äëèíà ñòðîêè
	SCROLLINFO vsi; // âåðòèêàëüíûé ñêðîëëèíã
	int vertRange; // äèàïàçîí âåðòèêàëüíîé ïîëîñû ïðîêðóòêè
	SCROLLINFO hsi; // ãîðèçîíòàëüíûé ñêðîëëèíã
	int horzRange; // äèàïàçîí ãîðèçîíòàëüíîé ïîëîñû ïðîêðóòêè
private:
	vector<string> lines; // âåêòîð äëÿ õðàíåíèÿ ñòðîê äîêóìåíòà
};
//////////////////////////////////////////////////////////////////////