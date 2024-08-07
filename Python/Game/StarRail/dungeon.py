import pyautogui
import time
import keyboard
import threading
from function import *
import function

Delay(1)
keyboard.add_hotkey('ctrl+p', Stop)
round = 1

while True :
    if function.stop :
        exit()
    screenshot = pyautogui.screenshot(region=(1209, 1055, 97, 23))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Python/Game/StarRail/Resource/again.png", screenshot, 0.9) :
        Delay(1)
        screenshot = pyautogui.screenshot(region=(1114, 1073, 1, 1))
        color = screenshot.getpixel((0, 0))
        print(f"第{round}輪的 color : {color}.")
        round += 1
        if color == (37, 37, 37) :
            Click(1200, 1070)
            Delay(3)
        else :
            Delay(1)
            break
Click(720, 1070)
