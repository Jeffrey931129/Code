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

# pyautogui.scroll(-950)
# exit()

while True :
    id = 1
    start_row = 0
    round = 6
    Press('B')
    Delay(1)
    Click(80, 330)
    Click(640, 1100)
    Delay(0.3)
    while id :
        id = 0
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
                            id += 1
                    elif Image_Detect(dir_path + "Resource/Tune/atk.png", screenshot, 0.9) :
                        if Image_Detect(dir_path + "Resource/unlock.png", screenshot, 0.9) :
                            Click(1806, 392)
                            id += 1
                    else :
                        if Image_Detect(dir_path + "Resource/lock.png", screenshot, 0.9) :
                            Click(1806, 392)
                else :
                    exit()
        if id :
            Click(640, 1100)
            Delay(0.3)
            Click(640, 1100)
            Delay(0.3)
            start_row = int((30 - id) / 6)

    Press('esc', 0.5)
    Press('esc', 0.5)
    Click(1435, 500)
    Delay(0.5)
    Click(72, 595)
    Delay(0.3)
    while round :
        Click(1020, 775)
        Click(1020, 1100)
        Delay(1)
        screenshot = pyautogui.screenshot(region=(420, 380, 1060, 430))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
        if Image_Detect(dir_path + "Resource/tip.png", screenshot, 0.90) :
            Click(850, 660)
            Click(1290, 740)
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
        round -= 1
    Press('esc')
    Delay(1)
    Press('esc')
    Delay(1)
