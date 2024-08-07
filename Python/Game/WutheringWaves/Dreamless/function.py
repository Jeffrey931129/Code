import time
import os
import pyautogui
import cv2
import numpy as np
import ctypes
import tkinter as tk
import tkinter.font as tkFont

stop = False
dir_path = "Python/Game/WutheringWaves/Dreamless/"
state = 0
reward = 0

# tk ---------------------------------------------------------------------------
# 設置 DPI 感知
ctypes.windll.shcore.SetProcessDpiAwareness(1)
scale_factor = ctypes.windll.shcore.GetScaleFactorForDevice(0) / 100
window = tk.Tk()
window.attributes('-transparentcolor', 'white')
window.config(bg='white')
window.title("終端訊息")
width, height = 300, 75
window.geometry(f"{width}x{height}+{int(960-width/2)}+10")
# window.overrideredirect(True)  # 去除窗口邊框
window.attributes('-alpha', 0.5)
window.attributes('-topmost', True)
custom_font = tkFont.Font(family="DFKai-SB", size=int(12), weight="bold")
label_1 = tk.Label(window, text="1", font=custom_font, bg='white')
label_1.place(x=width/2, y=height/6, anchor="center")
label_2 = tk.Label(window, text="2", font=custom_font, bg='white')
label_2.place(x=width/2, y=height/2, anchor="center")
label_3 = tk.Label(window, text="3", font=custom_font, bg='white')
label_3.place(x=width/2, y=height/6*5, anchor="center")
label_num = 0
def print(text) :
    label_1.config(text=label_2.cget("text"))
    label_2.config(text=label_3.cget("text"))
    label_3.config(text=text)
def Window_Check() :
    global stop
    if stop:
        window.destroy()
    else:
        # 每隔100毫秒檢查一次條件
        window.after(100, Window_Check)
# ------------------------------------------------------------------------------

def Stop() :
    global stop
    stop = True
    print("強制結束！！！")

def Delay(t) :
    time.sleep(t)

def Click(x = 960, y = 570, duration = 0.3) :
    pyautogui.moveTo(x, y, duration)
    pyautogui.click()
    # print(f"點擊 ({x}, {y})")

def RightClick() :
    pyautogui.rightClick()
    print("點擊右鍵")

def Scroll(value) :
    pyautogui.scroll(value)

def Press(c, delay = 0) :
    pyautogui.press(c)
    print(f"按下 {c}")
    if delay :
        Delay(delay)

def Move(c, duration) :
    pyautogui.keyDown(c)  # 按下鍵
    print(f"按住 {c}")
    Delay(duration)  # 等待指定時間
    pyautogui.keyUp(c)  # 釋放鍵

def Turn_Left() :
    Move('A', 0.05)
    Press('H')
    Press('H')
    Delay(1)

def Turn_Right() :
    Move('D', 0.05)
    Press('H')
    Press('H')
    Delay(1)

def Turn_Around() :
    Turn_Right()
    Turn_Right()

def Image_Detect(image_path, screenshot) :
    template = cv2.imread(os.path.join(dir_path + image_path), cv2.IMREAD_UNCHANGED)

    screenshot = cv2.cvtColor(screenshot, cv2.COLOR_BGR2GRAY)
    template = cv2.cvtColor(template, cv2.COLOR_BGR2GRAY)
    # cv2.imwrite("template.jpg", template)
    # cv2.imwrite("screenshot.jpg", screenshot)

    result = cv2.matchTemplate(screenshot, template, cv2.TM_CCOEFF_NORMED)
    
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
    # print(f"Detecting \"{image_path}\" at {max_loc}. (rate : {max_val})")
    return max_val

def Check_Wifi() :
    """ 直到綠色 wifi 條出現才會繼續執行主程序 """
    screenshot = pyautogui.screenshot(region=(1801, 85, 4, 16))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
    while Image_Detect("Resource/wifi.jpg", screenshot) <= 0.9 :
        time.sleep(0.1)
        screenshot = pyautogui.screenshot(region=(1801, 85, 4, 16))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)

def Check_Drop() :
    global reward
    screenshot = pyautogui.screenshot()
    drop = screenshot.getpixel((1250, 580))
    if drop[0] == 255 and drop[1] == 255 and drop[2] == 255 :
        Press('E')
        Delay(1)
        screenshot = pyautogui.screenshot()
        wrong1 = screenshot.getpixel((1315, 700))
        wrong2 = screenshot.getpixel((1315, 750))
        if wrong1 == (0, 0, 0) or wrong2 == (0, 0, 0):
            Press('esc')
            Delay(0.1)
        else : 
            print("----------------------------獲得聲骸----------------------------")
            reward += 1
            with open("record.txt", 'a') as file :
                file.write('V')
            Delay(1)
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
        Delay(1)
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