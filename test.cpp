#include <windows.h>
#include <iostream>

int main() {
    HWND hwnd = FindWindow(NULL, L"鳴潮");
    if (hwnd) {
        TCHAR className[256];
        if (GetClassName(hwnd, className, sizeof(className) / sizeof(TCHAR))) {
            std::wcout << L"窗口類名: " << className << std::endl;
        } else {
            std::wcerr << L"無法獲取類名" << std::endl;
        }
    } else {
        std::wcerr << L"窗口未找到" << std::endl;
    }
    return 0;
}
