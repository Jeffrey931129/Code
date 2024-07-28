import time
import os
import pyautogui
import cv2
import numpy as np
import threading

state = 'None'
threads = []
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

def Auto_On() :
    screenshot = pyautogui.screenshot(region=(310, 52, 130, 20))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    for y in range(screenshot.shape[0]) : 
        for x in range(screenshot.shape[1]) :
            if not np.all(screenshot[y, x] == np.array([255, 255, 255, 255])) :
                screenshot[y, x] = (0, 0, 0, 255)
    return Image_Detect("Python/Game/HeavenBurnsRed/Resource/auto_on.png", screenshot, 0.9)

def Auto_Off() :
    screenshot = pyautogui.screenshot(region=(310, 52, 130, 20))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    for y in range(screenshot.shape[0]) : 
        for x in range(screenshot.shape[1]) :
            if not np.all(screenshot[y, x] == np.array([255, 255, 255, 255])) :
                screenshot[y, x] = (0, 0, 0, 255)
    return Image_Detect("Python/Game/HeavenBurnsRed/Resource/auto_off.png", screenshot, 0.9)

def Skip() :
    screenshot = pyautogui.screenshot(region=(1670, 136, 56, 52))
    # 將 PIL 圖像轉換為 OpenCV 格式
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    for y in range(screenshot.shape[0]) : 
        for x in range(screenshot.shape[1]) :
            if not np.all(screenshot[y, x] == np.array([255, 255, 255, 255])) :
                screenshot[y, x] = (0, 0, 0, 255)
    if Image_Detect("Python/Game/HeavenBurnsRed/Resource/skip.png", screenshot, 0.9) :
        Click(1700, 165)
        pyautogui.moveTo(1700, 500, 0.3)
        time.sleep(3)

def Update() :
    global state
    if Auto_On() or Auto_Off() :
        state = 'Battle'

def GoldHopper() :
    screenshot = pyautogui.screenshot(region=(1330, 180, 480, 46))
    # 將 PIL 圖像轉換為 OpenCV 格式
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    for y in range(screenshot.shape[0]) : 
        for x in range(screenshot.shape[1]) :
            if not np.all(screenshot[y, x] == np.array([255, 255, 255, 255])) :
                screenshot[y, x] = (0, 0, 0, 255)
    return Image_Detect("Python/Game/HeavenBurnsRed/Resource/goldhopper.png", screenshot, 0.9)

def Check_Battle_End() :
    global state
    screenshot = pyautogui.screenshot(region=(1260, 110, 125, 35))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Python/Game/HeavenBurnsRed/Resource/point.png", screenshot, 1) :
        state = 'None'

def Start_Action() :
    screenshot = pyautogui.screenshot(region=(1670, 980, 180, 60))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Python/Game/HeavenBurnsRed/Resource/start_action.png", screenshot, 0.9) :
        Click(1800, 1000)

def Battle() :
    print("Battle Start")
    time.sleep(1)
    if Auto_On() :
        Click(400, 60)
    time.sleep(2.5)
    if GoldHopper() :
        Click(1780, 90)
        while state == 'Battle' :
            threading_1 = threading.Thread(target=Check_Battle_End)
            threading_2 = threading.Thread(target=Start_Action)
            threading_1.start()
            threading_2.start()
            threading_1.join()
            threading_2.join()
    else :
        Click(400, 60)
        Click(570, 60)
        while state == 'Battle' :
            Check_Battle_End()
    print("Battle End")

def Go_To_End() :
    Click(1600, 150)
    Click(200, 400)
    Click(1050, 425)
    Click(1200, 900)

def Go_To_Start() :
    Click(1600, 150)
    Click(200, 280)
    Click(750, 720)
    Click(1200, 900)

def Move() :
    screenshot = pyautogui.screenshot(region=(1438, 46, 1862-1438, 232-46))
    # 將 PIL 圖像轉換為 OpenCV 格式
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Python/Game/HeavenBurnsRed/Resource/start.png", screenshot, 0.9) :
        Go_To_End()
        time.sleep(3)
    elif Image_Detect("Python/Game/HeavenBurnsRed/Resource/end.png", screenshot, 0.9) :
        Go_To_Start()
        time.sleep(3)