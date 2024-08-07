import pyautogui
import time
import keyboard
import threading
from function import *
import function

time.sleep(2)
keyboard.add_hotkey('ctrl+p', Stop)
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

while round < 9999 and run_time <= 86400 and not function.stop :
    # 正式開始
    Press('E')
    time.sleep(1.5)
    Click(430, 370)         # Lv.60
    Click(1220, 940)        # 單人挑戰
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
    function.state = 3
    time.sleep(2)
    Move('W', 3)
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
        threading_1 = threading.Thread(target=Jinshi_Q3)   
        threading_2 = threading.Thread(target=Jinshi_Q4)
        threading_1.start()
        threading_2.start()
        threading_1.join()
        threading_2.join()
        if function.state == 5 : 
            time.sleep(4)
            break
    print("角已死亡")

    # 聲骸                                     
    Pick_Drop()
    with open("record.txt", 'a') as file :
        file.write('\n')

    # 離開
    time.sleep(1)
    Press('1', 0.1)
    Press('Q', 0.3)
    Press('esc', 0.3)
    Click(1240, 690)
    round += 1
    run_time = time.time() - start_time
    print(f"目前為第 {round} 輪次，運行{run_time : .0f} 秒，獲得 {function.reward} 個聲骸")
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

print(f"總共進行 {round} 輪次，運行{run_time : .0f} 秒，\
      獲得 {function.reward} 個聲骸，成功率為{function.reward / round : .1f} %")
