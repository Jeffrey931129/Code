import pyautogui
import time
import keyboard
import threading
from function import *
import function

time.sleep(2)
keyboard.add_hotkey('ctrl+p', Stop)
start_time = time.time()
energy = 120
cost = 40

# screenshot = pyautogui.screenshot(region=(1094, 1058, 28, 18))
# screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
# for y in range(screenshot.shape[0]) :
#     for x in range(screenshot.shape[1]) :
#         if screenshot[y, x, 0] < 100 and screenshot[y, x, 1] < 100 and screenshot[y, x, 2] > 150 :
#             screenshot[y, x] = (0, 0, 0, 255)
#             print("modify")
# cv2.imwrite("tem.png", screenshot)
# if Image_Detect("Python/Game/StarRail/Resource/black_40.png", screenshot, 0.9) :
#     print("DETECT!")
# exit()

while True :
    screenshot = pyautogui.screenshot(region=(1209, 1055, 97, 23))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Python/Game/StarRail/Resource/again.png", screenshot, 0.9) :
        print("Again")
        energy -= cost
        if energy >= cost :
            Click(1200, 1070)
            time.sleep(2)
        else : 
            break

Click(720, 1070)
