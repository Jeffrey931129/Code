from pywinauto import Application
import pyautogui
import time
import threading

# 定義一個函數來運行自動化腳本
def automate_app():
    # 連接到目標應用程序
    app = Application().connect(path="C:/Steam/steam.exe")
    
    # 獲取應用程序的窗口
    window = app.window(title='Steam')
    
    # 確保窗口已經激活
    time.sleep(1)
    
    # 現在所有的 pyautogui 操作都會作用在這個窗口上
    while True:
        window.set_focus()  # 將窗口置於前台進行操作
        pyautogui.click(100, 100)
        pyautogui.write('Hello, World!')
        pyautogui.press('enter')
        time.sleep(25)  # 設置合適的間隔時間以避免過度操作

# 啟動自動化腳本的線程
automation_thread = threading.Thread(target=automate_app)
automation_thread.daemon = True
automation_thread.start()

# 主線程可以繼續進行其他工作
print("Automation is running in the background. You can continue working in the foreground.")

# 這裡可以是你的其他工作代碼
while True:
    time.sleep(1)
    # 在這裡做其他事情
