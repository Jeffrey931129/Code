import pyautogui
import time

# 等待2秒，讓你有時間切換到你希望輸入的窗口
time.sleep(2)
X, Y = pyautogui.size()

def Click(x, y) :
    pyautogui.moveTo(x, y, duration=0.3)
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

def Check_Drop() :
    screenshot = pyautogui.screenshot()
    drop = screenshot.getpixel((1250, 580))
    if drop[0] == 255 and drop[1] == 255 and drop[2] == 255 :
        Press('E')
        print("獲得聲骸")
        time.sleep(1)
        return True
    count = 0 
    for i in range(1600) :
        drop = screenshot.getpixel((i + 160, 440))
        if 250 <= drop[0] and 230 <= drop[1] and 170 <= drop[2] <= 180 :
            print(f"聲骸掉落 ({i + 160}, 440)")
            count += 1
        if count >= 10 :
            return True
    print("沒有聲骸掉落")
    return False

def Go_To_Drop() :
    while True :
        screenshot = pyautogui.screenshot()
        drop = screenshot.getpixel((1250, 580))
        if drop[0] == 255 and drop[1] == 255 and drop[2] == 255 :
            Press('E')
            print("獲得聲骸")
            time.sleep(1)
            return
        Move('W', 0.5)
        for i in range(1600) :
            drop = screenshot.getpixel((i + 160, 440))
            if 250 <= drop[0] and 230 <= drop[1] and 170 <= drop[2] <= 180 :
                if i <= 800 :
                    Move('A', 0.5)
                else :
                    Move('D', 0.5)
                break

# while True :
#     screenshot = pyautogui.screenshot()
#     dragon_blood = screenshot.getpixel((1668, 942))
#     print(f"顏色 ({dragon_blood})")
#     time.sleep(0.1)

# 正式開始
Press('E')
time.sleep(1)
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
Move('W', 3)
Move('A', 0.1)
Press('H')
Press('H')
while True :
    screenshot = pyautogui.screenshot()
    dragon_blood = screenshot.getpixel((967, 102))
    jinshi_Q = screenshot.getpixel((1492, 1007))
    jinshi_F = screenshot.getpixel((1668, 942))
    if time.time() - battle_time >= 4 :
        Click(960, 570)
    if dragon_blood[0] != 255 and dragon_blood[1] != 255 and dragon_blood[2] != 255 and \
        time.time() - dragon_blood_time >= 6 :
        print("角 已死亡")
        time.sleep(2)
        break
    if jinshi_Q[0] == 255 and jinshi_Q[1] == 255 and jinshi_Q[2] == 214 :
        Press('R')
        if jinshi_F[0] == 241 and jinshi_F[1] == 224 and jinshi_F[2] == 122 :
            Press('F')
            time.sleep(3)
        Press('Q')
        print("自動施放強化戰技")
        dragon_blood_time = time.time() - 2
    time.sleep(0.05)

# 聲骸
step = 4
while step :
    Press('H')
    Press('H')
    time.sleep(1)
    if Check_Drop() :
        Go_To_Drop()
        break
    Move('D', 0.5)
    step -= 1

# # 離開
# Press('esc')
# Click(1240, 690)
# while True :
#     time.sleep(1)
#     screenshot = pyautogui.screenshot()
#     lobby = screenshot.getpixel((1610, 110))
#     if lobby[0] == 224 and lobby[1] == 224 and lobby[2] == 224 :
#         print("返回主頁")
#         break
# pyautogui.rightClick()





