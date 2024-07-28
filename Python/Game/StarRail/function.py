import time
import os
import pyautogui
import cv2
import numpy as np
import threading

stop = False
state = 'None'
threading_lock = threading.Lock()

def Stop() :
    print("強制結束！！！")
    exit()

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

def Image_Detect(image_path, screenshot, rate = 0.8) :
    # 讀取待比對的圖片
    template = cv2.imread(image_path, cv2.IMREAD_UNCHANGED)

    # 使用模板匹配方法進行比對
    screenshot_gray = cv2.cvtColor(screenshot, cv2.COLOR_BGR2GRAY)
    template_gray = cv2.cvtColor(template, cv2.COLOR_BGR2GRAY)
    result = cv2.matchTemplate(screenshot_gray, template_gray, cv2.TM_CCOEFF_NORMED)
    
    # 檢查是否有相對的匹配
    loc = np.where(result >= rate)
    if len(loc[0]) > 0 :
        return True
    else:
        return False
