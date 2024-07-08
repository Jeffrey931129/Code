import pyautogui
import time

# 等待2秒，讓你有時間切換到你希望輸入的窗口
time.sleep(2)
X, Y = pyautogui.size()
start_time = time.time()
round = 0
run_time = 0
reward = 0

def Click(x = 960, y = 570, duration = 0.3) :
    pyautogui.moveTo(x, y, duration)
    pyautogui.click()
    print(f"點擊 ({x}, {y})")

def RightClick() :
    pyautogui.rightClick()
    print("點擊右鍵")

def Press(c, delay = 0) :
    pyautogui.press(c)
    print(f"按下 {c}")
    if delay :
        time.sleep(delay)

def Move(c, duration) :
    pyautogui.keyDown(c)  # 按下鍵
    print(f"按住 {c}")
    time.sleep(duration)  # 等待指定時間
    pyautogui.keyUp(c)  # 釋放鍵

def Turn_Left() :
    Move('A', 0.05)
    Press('H')
    Press('H')
    time.sleep(1)

def Turn_Right() :
    Move('D', 0.05)
    Press('H')
    Press('H')
    time.sleep(1)

def Turn_Around() :
    Turn_Right()
    Turn_Right()

def Check_Drop() :
    global reward
    screenshot = pyautogui.screenshot()
    drop = screenshot.getpixel((1250, 580))
    if drop[0] == 255 and drop[1] == 255 and drop[2] == 255 :
        Press('E')
        time.sleep(1)
        screenshot = pyautogui.screenshot()
        wrong1 = screenshot.getpixel((1315, 700))
        wrong2 = screenshot.getpixel((1315, 750))
        if wrong1 == (0, 0, 0) or wrong2 == (0, 0, 0):
            Press('esc')
            time.sleep(0.1)
        else : 
            print("----------------------------獲得聲骸----------------------------")
            reward += 1
            time.sleep(1)
            return True
    return False

def Go_To_Drop(distance) :
    for i in range(distance) :
        Move('W', 0.5)
        time.sleep(0.1)
        if Check_Drop() :
            return True
    return False

def Pick_Drop() :
    if Check_Drop() : return
    if Go_To_Drop(4) : return
    Turn_Left()
    if Go_To_Drop(4) : return
    Turn_Around()
    if Go_To_Drop(9) : return

# Turn_Around()
# print("complete")
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
