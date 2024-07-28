import pyautogui
import time
import os
import keyboard
import threading
from function import *
import function

Delay(2)
keyboard.add_hotkey('ctrl+p', Stop)
dir_path = "Python/Game/WutheringWaves/"
start_time = time.time()
lock = 1
start_row = 0
round = 0

# screenshot = pyautogui.screenshot(region=(700, 244, 550, 292))
# screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
# cv2.imwrite("tem.png", screenshot)
# if Image_Detect(dir_path + "Resource/Tune/atk.png", screenshot, 0.9) :
#     print("DETECT!")
# exit()

Press('B')
Delay(1)
Click(640, 1100)
Delay(0.3)
while lock :
    lock = 0
    for i in range(start_row, 5) :
        for j in range(6) :
            Click(280 + 166*j, 150 + 204*i)
            Delay(0.5)
            screenshot = pyautogui.screenshot(region=(1300, 236, 550, 292))
            screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
            if Image_Detect(dir_path + "Resource/cost_1.png", screenshot, 0.9) :
                if Image_Detect(dir_path + "Resource/Attribute/heal.png", screenshot, 0.9) or\
                Image_Detect(dir_path + "Resource/Attribute/energy.png", screenshot, 0.9) :
                    if Image_Detect(dir_path + "Resource/unlock.png", screenshot, 0.9) :
                        Click(1806, 392)
                        lock += 1
                elif Image_Detect(dir_path + "Resource/Tune/atk.png", screenshot, 0.9) :
                    if Image_Detect(dir_path + "Resource/unlock.png", screenshot, 0.9) :
                        Click(1806, 392)
                        lock += 1
            else :
                exit()
    if lock :
        Click(640, 1100)
        Delay(0.3)
        Click(640, 1100)
        Delay(0.3)
        start_row = int((30 - lock) / 6)

Press('esc', 0.5)
Press('esc', 0.5)
Click(1435, 500)
Delay(0.5)
Click(72, 595)
Delay(0.3)
while round < 6 :
    Click(1020, 775)
    Click(1020, 1100)
    Delay(1)
    while not Image_Detect(dir_path + "Resource/combine_success.png", screenshot, 0.9) :
        screenshot = pyautogui.screenshot(region=(900, 440, 120, 30))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    Delay(2)
    screenshot = pyautogui.screenshot(region=(1083, 679, 84, 22))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect(dir_path + "Resource/combine_addtion.png", screenshot, 0.9) :
        Click(900, 600)
        Delay(1)
        screenshot = pyautogui.screenshot(region=(700, 244, 550, 292))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
        if Image_Detect(dir_path + "Resource/cost_1.png", screenshot, 0.9) :
                if Image_Detect(dir_path + "Resource/Attribute/heal.png", screenshot, 0.9) or\
                Image_Detect(dir_path + "Resource/Attribute/energy.png", screenshot, 0.9) :
                    Click(1200, 400)
                elif Image_Detect(dir_path + "Resource/Tune/atk.png", screenshot, 0.9) :
                    Click(1200, 400)
        Click(1300, 600)

        Click(1030, 600)
        Delay(1)
        screenshot = pyautogui.screenshot(region=(700, 244, 550, 292))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
        if Image_Detect(dir_path + "Resource/cost_1.png", screenshot, 0.9) :
                if Image_Detect(dir_path + "Resource/Attribute/heal.png", screenshot, 0.9) or\
                Image_Detect(dir_path + "Resource/Attribute/energy.png", screenshot, 0.9) :
                    Click(1200, 400)
                elif Image_Detect(dir_path + "Resource/Tune/atk.png", screenshot, 0.9) :
                    Click(1200, 400)
        Click(1300, 600)

        Click(960, 800)
    else :
        Click(960, 600)
        Delay(1)
        screenshot = pyautogui.screenshot(region=(700, 244, 550, 292))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
        if Image_Detect(dir_path + "Resource/cost_1.png", screenshot, 0.9) :
                if Image_Detect(dir_path + "Resource/Attribute/heal.png", screenshot, 0.9) or\
                Image_Detect(dir_path + "Resource/Attribute/energy.png", screenshot, 0.9) :
                    Click(1200, 400)
                elif Image_Detect(dir_path + "Resource/Tune/atk.png", screenshot, 0.9) :
                    Click(1200, 400)
        Click(1300, 600)

        Click(960, 800)
    Delay(0.3)
    round += 1
Press('esc')
Delay(1)
Press('esc')
Delay(1)
