import time
import os
import pyautogui
import cv2
import numpy as np
import threading

stop = False
dir_path = "Python/Game/HeavenBurnsRed/"
state = 'None'
threads = []
threading_lock = threading.Lock()

def Stop() :
    global stop
    print("強制結束！！！")
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

def Image_Detect(image_path, screenshot) :
    template = cv2.imread(dir_path + image_path, cv2.IMREAD_UNCHANGED)

    screenshot = cv2.cvtColor(screenshot, cv2.COLOR_BGR2GRAY)
    template = cv2.cvtColor(template, cv2.COLOR_BGR2GRAY)
    # cv2.imwrite("template.jpg", template)
    # cv2.imwrite("screenshot.jpg", screenshot)

    result = cv2.matchTemplate(screenshot, template, cv2.TM_CCOEFF_NORMED)
    
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
    # print(f"Detecting \"{image_path}\" at {max_loc}. (rate : {max_val})")
    return max_val

def Auto_On() :
    screenshot = pyautogui.screenshot(region=(310, 52, 130, 20))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    for y in range(screenshot.shape[0]) : 
        for x in range(screenshot.shape[1]) :
            if not np.all(screenshot[y, x] == np.array([255, 255, 255, 255])) :
                screenshot[y, x] = (0, 0, 0, 255)
    return Image_Detect("Resource/auto_on.jpg", screenshot) >= 0.9

def Auto_Off() :
    screenshot = pyautogui.screenshot(region=(310, 52, 130, 20))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    for y in range(screenshot.shape[0]) : 
        for x in range(screenshot.shape[1]) :
            if not np.all(screenshot[y, x] == np.array([255, 255, 255, 255])) :
                screenshot[y, x] = (0, 0, 0, 255)
    return Image_Detect("Resource/auto_off.jpg", screenshot) >= 0.9

def Skip() :
    screenshot = pyautogui.screenshot(region=(1670, 136, 56, 52))
    # 將 PIL 圖像轉換為 OpenCV 格式
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    for y in range(screenshot.shape[0]) : 
        for x in range(screenshot.shape[1]) :
            if not np.all(screenshot[y, x] == np.array([255, 255, 255, 255])) :
                screenshot[y, x] = (0, 0, 0, 255)
    if Image_Detect("Resource/skip.jpg", screenshot) >= 0.9 :
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
    return Image_Detect("Resource/goldhopper.jpg", screenshot) >= 0.9

def Check_Battle_End() :
    global state
    screenshot = pyautogui.screenshot(region=(1260, 110, 125, 35))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Resource/point.jpg", screenshot) >= 0.95 :
        state = 'None'

def Start_Action() :
    screenshot = pyautogui.screenshot(region=(1670, 980, 180, 60))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Resource/start_action.jpg", screenshot) >= 0.9 :
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
    Click(1563, 674)
    Click(1200, 900)

def Go_To_Start() :
    Click(1600, 150)
    Click(753, 562)
    Click(1200, 900)

def Move() :
    screenshot = pyautogui.screenshot(region=(1438, 46, 1862-1438, 232-46))
    # 將 PIL 圖像轉換為 OpenCV 格式
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Resource/start.jpg", screenshot) >= 0.9 :
        Go_To_End()
        time.sleep(3)
    elif Image_Detect("Resource/end.jpg", screenshot) >= 0.9 :
        Go_To_Start()
        time.sleep(3)