import pyautogui
import time
import keyboard
import threading
from function import *
import function

time.sleep(2)
keyboard.add_hotkey('ctrl+p', Stop)
start_time = time.time()
round = 0
run_time = 0

# while True :
#     screenshot = pyautogui.screenshot()
#     if Image_Detect('result.png', screenshot) :
#         print("Success")
#     else : print("Error")
# time.sleep(50)

# while True :
#     screenshot = pyautogui.screenshot()
#     test = screenshot.getpixel((1514, 955))
#     print(f"顏色 {test}")

def is_pixel_in_range(pixel):
    # pixel 是一個 (R, G, B, A) 元組
    # min_range 和 max_range 是 (R, G, B, A) 元組
    r, g, b, a = pixel
    min_r, min_g, min_b, min_a = (50, 50, 50, 255)
    max_r, max_g, max_b, max_a = (200, 200, 200, 255)
    
    # 檢查顏色是否在範圍內
    is_in_range = (min_r <= r <= max_r and
                   min_g <= g <= max_g and
                   min_b <= b <= max_b and
                   min_a <= a <= max_a)
    
    return is_in_range

while run_time <= 86400 and function.stop == False :
    rec_time = time.time()
    screenshot = pyautogui.screenshot(region=(1670, 136, 56, 52))
    if Image_detect("Python\Game\HeavenBurnsRed\Resource\skip.png", screenshot, 1) :
        Click(1700, 165)
        time.sleep(3)
    print(time.time() - rec_time)
    screenshot = pyautogui.screenshot(region=(1330, 180, 1810-1330, 46))
    if Image_detect("Python\Game\HeavenBurnsRed\Resource\goldhopper.png", screenshot, 1) :
        print("DETECT!!!")
    print(time.time() - rec_time)
