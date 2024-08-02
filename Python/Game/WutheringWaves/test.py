import pyautogui
import time
import os
import keyboard
import threading
from function import *
import function

Delay(2)
keyboard.add_hotkey('ctrl+p', Stop)

screenshot = pyautogui.screenshot(region=(1300, 236, 550, 292))
screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
Image_Detect("Resource/Attribute/attack.jpg", screenshot, 0.8)
exit()

id = 0
round = 120
# Press('B')
# Delay(1)
# Click(80, 330)
# Click(640, 1100)
# Delay(0.3)
# pyautogui.moveTo(960, 570)
# Delay(0.3)
# pyautogui.scroll(-20)
# Delay(0.3)
# for i in range(5) :
#     for j in range(6) :
#         if function.stop : 
#             print(id)
#             exit()
#         Click(280 + 166*j, 150 + 204*i)
#         Delay(0.5)
#         screenshot = pyautogui.screenshot(region=(1300, 236, 550, 292))
#         screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
#         if Image_Detect("Resource/cost_1.jpg", screenshot, 0.9) :
#             if Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
#                 Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             elif Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             else :
#                 if Image_Detect("Resource/lock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#         elif Image_Detect("Resource/cost_3.jpg", screenshot, 0.95) :
#             if Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             elif Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
#                 Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             elif Image_Detect("Resource/Attribute/attack.jpg", screenshot, 0.9) and\
#                 not Image_Detect("Resource/Tune/hp.jpg", screenshot, 0.9) and\
#                 not Image_Detect("Resource/Tune/def.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             else :
#                 for attribute in function.attributes :
#                     if Image_Detect(f"Resource/Attribute/{attribute}.jpg", screenshot, 0.9) :
#                         if Image_Detect(f"Resource/Tune/{attribute}.jpg", screenshot, 0.9) :
#                             if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                                 Click(1806, 392)
#                             else : 
#                                 break
#         else :
#             print(id)
#             exit()
#         Delay(0.1)
#         screenshot = pyautogui.screenshot(region=(1300, 236, 550, 292))
#         screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
#         if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#             id += 1
# while True :
#     if function.stop :
#         print(id)
#         exit()
#     pyautogui.moveTo(280 + 166*5, 150 + 204*4)
#     Delay(0.3)
#     pyautogui.scroll(-900)
#     Delay(0.3)
#     while True :
#         if function.stop : 
#             print(id)
#             exit()
#         screenshot = pyautogui.screenshot(region=(310, 880, 50, 40))
#         screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
#         if Image_Detect("Resource/level_0.jpg", screenshot, 0.9) :
#             break
#         pyautogui.scroll(-20)
#         Delay(0.3)
    
#     for j in range(6) :
#         if function.stop : 
#             print(id)
#             exit()
#         Click(280 + 166*j, 150 + 204*4)
#         Delay(0.5)
#         screenshot = pyautogui.screenshot(region=(1300, 236, 550, 292))
#         screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
#         if Image_Detect("Resource/cost_1.jpg", screenshot, 0.9) :
#             if Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
#                 Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             elif Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             else :
#                 if Image_Detect("Resource/lock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#         elif Image_Detect("Resource/cost_3.jpg", screenshot, 0.95) :
#             if Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             elif Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
#                 Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             elif Image_Detect("Resource/Attribute/attack.jpg", screenshot, 0.9) and\
#                 not Image_Detect("Resource/Tune/hp.jpg", screenshot, 0.9) and\
#                 not Image_Detect("Resource/Tune/def.jpg", screenshot, 0.9) :
#                 if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                     Click(1806, 392)
#             else :
#                 for attribute in function.attributes :
#                     if Image_Detect(f"Resource/Attribute/{attribute}.jpg", screenshot, 0.9) :
#                         if Image_Detect(f"Resource/Tune/{attribute}.jpg", screenshot, 0.9) :
#                             if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#                                 Click(1806, 392)
#                             else : 
#                                 break
#         else :
#             print(id)
#             exit()
#         Delay(0.1)    
#         screenshot = pyautogui.screenshot(region=(1300, 236, 550, 292))
#         screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
#         if Image_Detect("Resource/unlock.jpg", screenshot, 0.9) :
#             id += 1

# Press('esc', 0.5)
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
    if Image_Detect("Resource/tip.jpg", screenshot, 0.90) :
        Click(850, 660)
        Click(1290, 740)
    while not Image_Detect("Resource/combine_success.jpg", screenshot, 0.9) :
        screenshot = pyautogui.screenshot(region=(900, 440, 120, 30))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    Delay(2)
    screenshot = pyautogui.screenshot(region=(1083, 679, 84, 22))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if Image_Detect("Resource/combine_addtion.jpg", screenshot, 0.9) :
        Click(900, 600)
        Delay(1)
        screenshot = pyautogui.screenshot(region=(700, 244, 550, 292))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
        if Image_Detect("Resource/cost_1.jpg", screenshot, 0.9) :
            if Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
                Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
                Click(1200, 400)
            elif Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
                Click(1200, 400)
        elif Image_Detect("Resource/cost_3.jpg", screenshot, 0.95) :
            if Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
                Click(1200, 400)
            elif Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
                Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
                Click(1200, 400)
            elif Image_Detect("Resource/Attribute/attack.jpg", screenshot, 0.9) and\
                not Image_Detect("Resource/Tune/hp.jpg", screenshot, 0.9) and\
                not Image_Detect("Resource/Tune/def.jpg", screenshot, 0.9) :
                Click(1200, 400)
            else :
                for attribute in function.attributes :
                    if Image_Detect(f"Resource/Attribute/{attribute}.jpg", screenshot, 0.9) :
                        if Image_Detect(f"Resource/Tune/{attribute}.jpg", screenshot, 0.9) :
                            Click(1200, 400)
                        break
        Click(1300, 600)

        Click(1030, 600)
        Delay(1)
        screenshot = pyautogui.screenshot(region=(700, 244, 550, 292))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
        if Image_Detect("Resource/cost_1.jpg", screenshot, 0.9) :
            if Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
                Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
                Click(1200, 400)
            elif Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
                Click(1200, 400)
        elif Image_Detect("Resource/cost_3.jpg", screenshot, 0.95) :
            if Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
                Click(1200, 400)
            elif Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
                Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
                Click(1200, 400)
            elif Image_Detect("Resource/Attribute/attack.jpg", screenshot, 0.9) and\
                not Image_Detect("Resource/Tune/hp.jpg", screenshot, 0.9) and\
                not Image_Detect("Resource/Tune/def.jpg", screenshot, 0.9) :
                Click(1200, 400)
            else :
                for attribute in function.attributes :
                    if Image_Detect(f"Resource/Attribute/{attribute}.jpg", screenshot, 0.9) :
                        if Image_Detect(f"Resource/Tune/{attribute}.jpg", screenshot, 0.9) :
                            Click(1200, 400)
                        break
        Click(1300, 600)

        Click(960, 800)
    else :
        Click(960, 600)
        Delay(1)
        screenshot = pyautogui.screenshot(region=(700, 244, 550, 292))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
        if Image_Detect("Resource/cost_1.jpg", screenshot, 0.9) :
            if Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
                Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
                Click(1200, 400)
            elif Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
                Click(1200, 400)
        elif Image_Detect("Resource/cost_3.jpg", screenshot, 0.95) :
            if Image_Detect("Resource/Tune/atk.jpg", screenshot, 0.9) :
                Click(1200, 400)
            elif Image_Detect("Resource/Attribute/heal.jpg", screenshot, 0.9) or\
                Image_Detect("Resource/Attribute/energy.jpg", screenshot, 0.9) :
                Click(1200, 400)
            elif Image_Detect("Resource/Attribute/attack.jpg", screenshot, 0.9) and\
                not Image_Detect("Resource/Tune/hp.jpg", screenshot, 0.9) and\
                not Image_Detect("Resource/Tune/def.jpg", screenshot, 0.9) :
                Click(1200, 400)
            else :
                for attribute in function.attributes :
                    if Image_Detect(f"Resource/Attribute/{attribute}.jpg", screenshot, 0.9) :
                        if Image_Detect(f"Resource/Tune/{attribute}.jpg", screenshot, 0.9) :
                            Click(1200, 400)
                        break
        Click(1300, 600)

        Click(960, 800)
    Delay(0.3)
    round -= 1
Press('esc')
Delay(1)
Press('esc')
Delay(1)
