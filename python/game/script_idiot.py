import pyautogui
import time

# 等待2秒，讓你有時間切換到你希望輸入的窗口
time.sleep(2)
X, Y = pyautogui.size()
start_time = time.time()
round = 0
reward = 0

def Click(x = 960, y = 570, duration = 0.3) :
    pyautogui.moveTo(x, y, duration)
    pyautogui.click()
    print(f"點擊 ({x}, {y})")

def Press(c) :
    pyautogui.press(c)
    print(f"按下 {c}")

def Move(c, duration) :
    pyautogui.keyDown(c)  # 按下鍵
    print(f"按住 {c}")
    time.sleep(duration)  # 等待指定時間
    pyautogui.keyUp(c)  # 釋放鍵

def Turn_Right() :
    Move('D', 0.05)
    Press('H')
    Press('H')
    time.sleep(1)

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
    Turn_Right()
    if Go_To_Drop(4) : return
    Turn_Right()
    if Go_To_Drop(9) : return
    Turn_Right()
    if Go_To_Drop(9) : return
    Turn_Right()
    if Go_To_Drop(9) : return
    Turn_Right()
    if Go_To_Drop(4) : return

# while True :
#     screenshot = pyautogui.screenshot()
#     wrong2 = screenshot.getpixel((1315, 750))
#     print(f"顏色 {wrong2}")

while round < 50 and time.time() - start_time <= 3600 :
    # 正式開始
    Press('E')
    time.sleep(1.5)
    Click(430, 310)
    Click(1460, 950)
    Click(1180, 690)
    time.sleep(0.5)
    Click(1540, 1000)

    # 檢測進入副本
    while True :
        time.sleep(0.1)
        screenshot = pyautogui.screenshot()
        dragon_blood = screenshot.getpixel((967, 102))
        if dragon_blood[0] == 255 and dragon_blood[1] == 255 and dragon_blood[2] == 255 :
            print("戰鬥開始")
            battle_time = time.time()
            dragon_blood_time = time.time()
            break

    # 戰鬥
    Move('W', 2.5)
    Move('A', 0.1)
    Press('H')
    Press('H')
    jinshi_Q_state = 1
    while True :
        screenshot = pyautogui.screenshot()
        dragon_blood1 = screenshot.getpixel((967, 102))
        dragon_blood2 = screenshot.getpixel((860, 100))
        jinshi_Q = screenshot.getpixel((1492, 1007))
        jinshi_F = screenshot.getpixel((1668, 942))
        
        if time.time() - battle_time >= 7 :
            if jinshi_Q_state == 1 :
                Press('Q')
                jinshi_Q_state = 2
            elif jinshi_Q_state == 3 :
                time.sleep(1)
                Press('Q')
                jinshi_Q_state = 4
            else : Click()
        
        if not dragon_blood1 == (255, 255, 255) and not dragon_blood2 == (255, 255, 255) \
            and time.time() - dragon_blood_time >= 6 :
            print("角 已死亡")
            time.sleep(2)
            break
        
        if jinshi_Q == (255, 255, 214) :
            Press('R')
            if 240 <= jinshi_F[0] <= 242 and 223 <= jinshi_F[1] <= 225 and 120 <= jinshi_F[2] <= 122 :
                Press('F')
                print("施放大招")
                time.sleep(3.5)
            else :
                Press('Q')
                print("施放強化戰技")
                if jinshi_Q_state == 2 :
                    jinshi_Q_state = 3
                elif jinshi_Q_state == 4 :
                    jinshi_Q_state = 1
                    dragon_blood_time = time.time() - 2
        
        time.sleep(0.05)

    # 聲骸                                     
    Pick_Drop()

    # 離開
    time.sleep(1)
    Press('esc')
    time.sleep(0.3)
    Click(1240, 690)
    print(f"目前為第 {round} 輪次，獲得 {reward} 個聲骸")
    while True :
        time.sleep(1)
        screenshot = pyautogui.screenshot()
        lobby1 = screenshot.getpixel((1610, 110))
        lobby2 = screenshot.getpixel((180, 245))
        if lobby1 == (255, 255, 255) and lobby2 == (255, 255, 255) :
            print("返回主頁")
            break
    time.sleep(0.5)
    Press('Q')
    time.sleep(0.3)
    Press('space')
    Click()
    time.sleep(0.3)
    pyautogui.rightClick()
    time.sleep(1)
    round += 1

print(f"總共進行了 {round} 輪次，獲得 {reward} 個聲骸")
