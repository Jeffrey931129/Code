import time
import os
import pyautogui
import cv2
import numpy as np

stop = False
state = 0
reward = 0

def Stop():
    global stop
    print("腳本將在下一輪結束...")
    stop = True

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

def Image_detect(image_path, screenshot, rate = 0.8) :
    # 將 PIL 圖像轉換為 OpenCV 格式
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)

    # 讀取待比對的圖片
    template = cv2.imread(image_path, cv2.IMREAD_UNCHANGED)
    
    for x_start in range(0, screenshot.shape[1] - template.shape[1] + 1) :
        for y_start in range(0, screenshot.shape[0] - template.shape[0] + 1) :
            threshold, sum = 0, 0
            for x in range(0, template.shape[1]) :
                for y in range(0, template.shape[0]) :
                    if template[y, x, 3] == 0 :
                        continue
                    if (template[y, x] == screenshot[y + y_start, x + x_start]).all() :
                        threshold += 1
                    sum += 1
            if threshold / sum >= rate :
                return True
    return False
    
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
            with open("record.txt", 'a') as file :
                file.write('V')
            time.sleep(1)
            return True
    return False

def Go_To_Drop(distance) :
    pyautogui.keyDown('W')
    rec = time.time()
    while time.time() - rec <= distance :
        if Check_Drop() :
            pyautogui.keyUp('W')
            return True
    pyautogui.keyUp('W')
    return False

def Pick_Drop() :
    if Check_Drop() : return
    if Go_To_Drop(3) : return
    Turn_Left()
    if Go_To_Drop(4) : return
    Turn_Around()
    if Go_To_Drop(8) : return

def Jinshi_Q3() :
    global state
    if state == 3 :
        time.sleep(1)
        Press('Q')
        print("施放 Q3")
        state = 4
    else : Click()

def Jinshi_Q4() :
    global state
    screenshot = pyautogui.screenshot()
    jinshi_Q = screenshot.getpixel((1492, 1007))
    if jinshi_Q == (255, 255, 214) :
        Press('Q')
        print("施放 Q4")
        state = 5