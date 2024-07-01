#include <Windows.h>
#include <iostream>
using namespace std;

int main() {
    int X = GetSystemMetrics(SM_CXSCREEN);
    int Y = GetSystemMetrics(SM_CYSCREEN);
    POINT cursorPos;
    
    Sleep(20); // 延遲 100 毫秒
    if (GetCursorPos(&cursorPos)) {
        cout << "Current cursor position: (" << cursorPos.x << ", " << cursorPos.y << ")" << endl;
    } else {
        cerr << "Failed to get cursor position." << endl;
    }
    // 模擬按下 Q 鍵
    // keybd_event(0x51, 0, 0, 0); // 0x51 是 Q 鍵的虛擬鍵碼
    // 模擬左鍵按下
    SetCursorPos(1154, 669);
    mouse_event(MOUSEEVENTF_LEFTDOWN, 1154, 669, 0, 0);
    // cout << X << " " << Y << endl;
    // 模擬釋放 Q 鍵
    // keybd_event(0x51, 0, KEYEVENTF_KEYUP, 0);
    mouse_event(MOUSEEVENTF_LEFTUP, 1154, 669, 0, 0);

    cout << "Q key pressed and released." << endl;

    return 0;
}
