import pyautogui
import time
import keyboard
import threading
import win32gui
import win32con
from function import *
import function

keyboard.add_hotkey('p', Stop)
Window_Check()

def Dreamless() :
    hwnd = win32gui.FindWindow(None, "鳴潮  ")
    if hwnd :
        win32gui.ShowWindow(hwnd, win32con.SW_RESTORE)
        win32gui.SetForegroundWindow(hwnd)
    else :
        return
    time.sleep(1)
    Click()
    start_time = time.time()
    round = 0
    run_time = 0

    # while not function.stop :
    #     screenshot = pyautogui.screenshot()
    #     screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
    #     Image_Detect("jinshi_Q4.jpg", screenshot, "jinshi_Q4_mask.jpg")
    #     time.sleep(1)

    # while not function.stop :
    #     screenshot = pyautogui.screenshot()
    #     test = screenshot.getpixel((1514, 955))
    #     Print(f"顏色 {test}")

    while round < 9999 and run_time <= 86400 and not function.stop :
        # 正式開始
        Press('E')
        time.sleep(1.5)
        Click(300, 450)         # Lv.70
        Click(1550, 1050)       # 單人挑戰
        Click(1260, 750)        # 體力不足
        time.sleep(0.5)
        Click(1650, 1100)       # 進入戰鬥
        
        Check_Wifi()            # 檢測進入副本
        Print("進入戰鬥")
        
        # 戰鬥
        function.state = 3
        time.sleep(3)
        Press('R', 0.3)
        Press('Q')
        time.sleep(0.5)
        Press('space')
        Click()
        Click()
        Press('2', 1)
        Press('R')
        Press('Q', 0.1)
        while not function.stop :
            threading_1 = threading.Thread(target=Jinshi_Q3)   
            threading_2 = threading.Thread(target=Jinshi_Q4)
            threading_1.start()
            threading_2.start()
            threading_1.join()
            threading_2.join()
            if function.state == 5 : 
                time.sleep(4)
                break
        Print("無妄者已死亡")

        # 聲骸                                     
        Pick_Drop()
        function.file.write('\n')

        # 離開
        time.sleep(1)
        Press('1', 0.1)
        Press('Q', 0.3)
        Press('esc', 0.3)
        Click(1300, 730)
        round += 1
        run_time = time.time() - start_time
        Print(f"目前為第 {round} 輪次，運行{run_time : .0f} 秒，獲得 {function.reward} 個聲骸")
        time.sleep(3)
        Check_Wifi()
        Print("返回主頁")
        time.sleep(2)
        while not function.stop :
            screenshot = pyautogui.screenshot(region=(1243, 608, 20, 20))
            screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
            if Image_Detect("e.jpg", screenshot) >= 0.9 :
                break
            Sprint()
        time.sleep(1)

    Print(f"總共進行 {round} 輪次，運行 {run_time :.0f} 秒")
    Print(f"獲得 {function.reward} 個聲骸，成功率為 {function.reward / round * 100 :.2f} %")

threading_main = threading.Thread(target=Dreamless)
threading_main.start()
function.window.mainloop()
function.file.close()