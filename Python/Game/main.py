import pyautogui
import time
from function import *

# 等待2秒，讓你有時間切換到你希望輸入的窗口
time.sleep(2)
X, Y = pyautogui.size()
start_time = time.time()
round = 0
run_time = 0

# while True :
#     screenshot = pyautogui.screenshot()
#     if Image_Detect('result.png', screenshot) :
#         print("Success")
#     else : print("Error")
# time.sleep(50)

# while True :
#     screenshot = pyautogui.screenshot()
#     test = screenshot.getpixel((1514, 955))
#     print(f"顏色 {test}")

while round < 50 and run_time <= 3600 :
    # 正式開始
    Press('E')
    time.sleep(1.5)
    Click(430, 370)         # Lv.60
    Click(1460, 950)        # 單人挑戰
    Click(1180, 690)        # 體力不足
    time.sleep(0.5)
    Click(1540, 1000)       # 進入戰鬥

    # 檢測進入副本
    while True :
        screenshot = pyautogui.screenshot()
        dragon_blood = screenshot.getpixel((967, 102))
        if dragon_blood == (255, 255, 255) :
            print("戰鬥開始")
            break

    # 戰鬥
    jinshi_Q_state = 3
    time.sleep(5)
    Press('R', 0.3)
    Press('Q')
    time.sleep(0.5)
    Press('space')
    Click()
    Click()
    Press('2', 1)
    Press('R')
    Press('Q', 0.1)
    while True :
        screenshot = pyautogui.screenshot()
        dragon_blood1 = screenshot.getpixel((967, 102))
        dragon_blood2 = screenshot.getpixel((190, 310))
        jinshi_Q = screenshot.getpixel((1492, 1007))
        jinshi_F = screenshot.getpixel((1668, 942))
        wifi = screenshot.getpixel((1663, 150))
        
        if jinshi_Q_state == 1 :
            Press('Q')
            print("施放 Q1")
            jinshi_Q_state = 2
        elif jinshi_Q_state == 3 :
            time.sleep(1)
            Press('Q')
            print("施放 Q3")
            jinshi_Q_state = 4
        else : Click()
        # 有隱患 可能需要詳細計算今汐動畫時間  綠色勾勾持續僅 0.5 秒  或許可以使用網路圖示
        if not dragon_blood1 == (255, 255, 255) and not dragon_blood2 == (255, 255, 255) \
            and wifi == (70, 244, 41) :
            print("角 已死亡")
            time.sleep(2)
            break

        if jinshi_Q == (255, 255, 214) :
            if 240 <= jinshi_F[0] <= 242 and 223 <= jinshi_F[1] <= 225 and 120 <= jinshi_F[2] <= 122 :
                Press('F')
                print("施放大招")
            else :
                Press('Q')
                if jinshi_Q_state == 2 :
                    jinshi_Q_state = 3
                    print("施放 Q2")
                elif jinshi_Q_state == 4 :
                    jinshi_Q_state = 1 
                    print("施放 Q4")

    # 聲骸                                     
    Pick_Drop()

    # 離開
    time.sleep(1)
    Press('1', 0.1)
    Press('Q', 0.3)
    Press('esc', 0.3)
    Click(1240, 690)
    round += 1
    run_time = time.time() - start_time
    print(f"目前為第 {round} 輪次，運行{run_time : .0f} 秒，獲得 {reward} 個聲骸")
    time.sleep(5)
    while True :
        screenshot = pyautogui.screenshot()
        lobby1 = screenshot.getpixel((1610, 110))
        lobby2 = screenshot.getpixel((180, 245))
        wifi = screenshot.getpixel((1663, 150))
        if lobby1 == (255, 255, 255) and lobby2 == (255, 255, 255) and wifi == (70, 244, 41) :
            print("返回主頁")
            break
    time.sleep(2)
    RightClick()
    time.sleep(1)

print(f"總共進行 {round} 輪次，運行{run_time : .0f} 秒，獲得 {reward} 個聲骸")