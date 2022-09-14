#include <iostream>
#include <windows.h>

HWND hwnd;

int x1, y1, x2, y2, w, h;

int main()
{
    hwnd = GetConsoleWindow();
    ShowWindow(hwnd, SW_HIDE);
    Sleep(1000);

    x1 = GetSystemMetrics(SM_XVIRTUALSCREEN);
    y1 = GetSystemMetrics(SM_YVIRTUALSCREEN);
    x2 = GetSystemMetrics(SM_CXVIRTUALSCREEN);
    y2 = GetSystemMetrics(SM_CYVIRTUALSCREEN);

    w = x2 - x1;
    h = y2 - y1;
    HDC hScreen = GetDC(NULL);
    HDC hDc = CreateCompatibleDC(hScreen);
    HBITMAP hBitMap = CreateCompatibleBitmap(hScreen, w, h);
    HGDIOBJ old_object = SelectObject(hDc, hBitMap);
    BOOL bRet = BitBlt(hDc, 0, 0, w, h, hScreen, x1, y1, SRCCOPY);

    OpenClipboard(NULL);
    EmptyClipboard();
    SetClipboardData(CF_BITMAP, hBitMap);
    CloseClipboard();

    // ShowWindow(hwnd, SW_SHOW);
    // system("pause");
}