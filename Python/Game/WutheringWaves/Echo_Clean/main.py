import pyautogui
import time
import os
import keyboard
import threading
from function import *
import function

Delay(2)
keyboard.add_hotkey('ctrl+p', Stop)
start_time = time.time()

# Click(1020, 775)
# Click(1020, 1100)
# Delay(0.3)
# screenshot = pyautogui.screenshot()
# screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
# cv2.imwrite("tem.jpg", screenshot)
# exit()

id = 0
Press('B')
Delay(1)
Click(80, 330)
Click(640, 1100)
Delay(0.3)
pyautogui.moveTo(960, 570)
Delay(0.3)
Scroll(-20)
Delay(0.3)
for i in range(5) :
    for j in range(6) :
        if function.stop :
            print(id)
            break
        
        Click(280 + 166*j, 150 + 204*i)
        Delay(0.1)
        Lock_Method()
        Delay(0.1)
        screenshot = pyautogui.screenshot(region=(1300, 236, 550, 292))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
        if Image_Detect("Resource/unlock.jpg", screenshot) >= 0.9 :
            id += 1
while True :
    if function.stop :
        print(id)
        break
    
    Scroll_Echo_Page()
    for j in range(6) :
        Click(280 + 166*j, 966)
        Delay(0.1)
        Lock_Method()
        if function.stop :
            break
        Delay(0.1)    
        screenshot = pyautogui.screenshot(region=(1300, 236, 550, 292))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
        if Image_Detect("Resource/unlock.jpg", screenshot) >= 0.9 :
            id += 1

function.stop = False
round = int(id / 5)
Press('esc', 0.5)
Press('esc', 0.5)
Click(1435, 500)
Delay(0.3)
Click(72, 595)
Delay(0.3)

while round :
    if function.stop :
        exit()
    Click(1020, 775)
    Click(1020, 1100)
    Delay(0.3)
    screenshot = pyautogui.screenshot(region=(420, 380, 1060, 430))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
    if Image_Detect("Resource/tip.jpg", screenshot, 0.90) :
        Click(850, 660)
        Click(1290, 740)
    while not Image_Detect("Resource/combine_success.jpg", screenshot) >= 0.9 :
        screenshot = pyautogui.screenshot(region=(900, 440, 120, 30))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
    Delay(2)
    screenshot = pyautogui.screenshot(region=(1083, 679, 84, 22))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
    if Image_Detect("Resource/combine_addtion.jpg", screenshot) >= 0.9 :
        Click(900, 600)
        Delay(1)
        Combine_Method()
        Click(1300, 600)

        Click(1030, 600)
        Delay(1)
        Combine_Method()
        Click(1300, 600)

        Click(960, 800)
    else :
        Click(960, 600)
        Delay(1)
        Combine_Method()
        Click(1300, 600)

        Click(960, 800)
    Delay(0.3)
    round -= 1
Press('esc')
Delay(1)
Press('esc')
Delay(1)
print(f"耗時 : {time.time() - start_time}")
