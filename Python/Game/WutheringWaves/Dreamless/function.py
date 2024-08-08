import time
import os
import pyautogui
import cv2
import numpy as np
import ctypes
import tkinter as tk
import tkinter.font as tkFont

stop = False
dir_path = "Python/Game/WutheringWaves/Dreamless/Resource/"
state = 0
reward = 0
file = open("Python/Game/WutheringWaves/Dreamless/record.txt", 'w')

# tk ---------------------------------------------------------------------------
# 設置 DPI 感知
ctypes.windll.shcore.SetProcessDpiAwareness(1)
scale_factor = ctypes.windll.shcore.GetScaleFactorForDevice(0) / 100
window = tk.Tk()
window.attributes('-transparentcolor', 'white')
window.config(bg='white')
window.title("終端訊息")
width, height = 800, 75
window.geometry(f"{width}x{height}+{int(960-width/2)}+10")
# window.overrideredirect(True)  # 去除窗口邊框
window.attributes('-alpha', 0.5)
window.attributes('-topmost', True)
custom_font = tkFont.Font(family="DFKai-SB", size=int(12), weight="bold")
label_1 = tk.Label(window, text="請注意陣容！！！", font=custom_font, bg='white')
label_1.place(x=10, y=height/6, anchor="w")
label_2 = tk.Label(window, text="請注意陣容！！！", font=custom_font, bg='white')
label_2.place(x=10, y=height/2, anchor="w")
label_3 = tk.Label(window, text="請注意陣容！！！", font=custom_font, bg='white')
label_3.place(x=10, y=height/6*5, anchor="w")
label_num = 0
def Print(text) :
    global label_num
    label_num += 1
    label_1.config(text=label_2.cget("text"))
    label_2.config(text=label_3.cget("text"))
    label_3.config(text=f"{label_num}. {text}")
    print(text)
def Window_Check() :
    global stop
    if stop :
        window.destroy()
    else :
        # 每隔100毫秒檢查一次條件
        window.after(100, Window_Check)
# ------------------------------------------------------------------------------

def Stop() :
    global stop
    stop = True
    Print("強制結束！！！")

def Delay(t) :
    time.sleep(t)

def Click(x = 960, y = 570, duration = 0.3) :
    pyautogui.moveTo(x, y, duration)
    pyautogui.click()
    Print(f"點擊 ({x}, {y})")

def RightClick() :
    pyautogui.rightClick()
    Print("點擊右鍵")

def Sprint() :
    pyautogui.keyDown('W')
    Delay(0.1)
    pyautogui.rightClick()
    Delay(0.1)
    pyautogui.keyUp('W')
    Print("衝刺")

def Scroll(value) :
    pyautogui.scroll(value)

def Press(c, delay = 0) :
    pyautogui.press(c)
    Print(f"按下 {c}")
    if delay :
        Delay(delay)

def Move(c, duration) :
    pyautogui.keyDown(c)  # 按下鍵
    Print(f"按住 {c}")
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

def Image_Detect(image_name, screenshot, mask_path = False) :
    template = cv2.imread(dir_path + image_name, cv2.IMREAD_UNCHANGED)
    
    screenshot = cv2.cvtColor(screenshot, cv2.COLOR_BGR2GRAY)
    template = cv2.cvtColor(template, cv2.COLOR_BGR2GRAY)
    # cv2.imwrite("template.jpg", template)
    # cv2.imwrite("screenshot.jpg", screenshot)
    if mask_path :
        mask = cv2.imread(dir_path + mask_path, cv2.IMREAD_GRAYSCALE)
        result = cv2.matchTemplate(screenshot, template, cv2.TM_CCOEFF_NORMED, mask=mask)
    else :
        result = cv2.matchTemplate(screenshot, template, cv2.TM_CCOEFF_NORMED)
    
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
    Print(f"Detecting \"{image_name}\" at {min_loc}. (rate : {max_val:.5f})")
    return max_val

def Check_Wifi() :
    """ 直到綠色 wifi 條出現才會繼續執行主程序 """
    while True :
        screenshot = pyautogui.screenshot(region=(1779, 83, 28, 20))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
        if Image_Detect("wifi.jpg", screenshot, "wifi_mask.jpg") >= 0.9 :
            break
        time.sleep(0.1)


def Check_Drop() :
    global reward
    screenshot = pyautogui.screenshot(region=(1243, 608, 20, 20))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
    if Image_Detect("e.jpg", screenshot) >= 0.9 :
        Press('E')
        Delay(1)
        screenshot = pyautogui.screenshot()
        Print("----------------------------獲得聲骸----------------------------")
        reward += 1
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
    if Go_To_Drop(8) : return

def Jinshi_Q3() :
    global state
    if state == 3 :
        Delay(1)
        Press('Q')
        Print("施放 Q3")
        state = 4
    else : Click()

def Jinshi_Q4() :
    global state
    screenshot = pyautogui.screenshot(region=(1582, 1055, 43, 60))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
    if Image_Detect("jinshi_Q4.jpg", screenshot, "jinshi_Q4_mask.jpg") >= 0.9 :
        Press('Q')
        Print("施放 Q4")
        state = 5