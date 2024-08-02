import pyautogui
import time
import keyboard
import threading
from function import *
import function

time.sleep(2)
keyboard.add_hotkey('ctrl+p', Stop)
start_time = time.time()
round = 3

round -= 1
while round :
    if function.stop :
        exit()
    screenshot = pyautogui.screenshot(region=(1209, 1055, 97, 23))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Python/Game/StarRail/Resource/again.png", screenshot, 0.9) :
        print("Again")
        round -= 1
        Click(1200, 1070)
        time.sleep(3)

Click(720, 1070)
