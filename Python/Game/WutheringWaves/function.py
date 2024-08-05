import time
import os
import pyautogui
import cv2
import numpy as np

stop = False
dir_path = "Python/Game/WutheringWaves/"
state = 0
reward = 0
attributes = ['attack', 'dark', 'electric', 'energy', 'fire', 'heal', 'ice', 'light', 'wind']
tunes = {
    'attack'    : ['atk', 'critic_damage', 'critic_rate', 'dark', 'electric', 'fire', 'ice', 'light', 'wind'], 
    'dark'      : ['atk', 'critic_damage', 'critic_rate', 'dark'], 
    'electric'  : ['atk', 'critic_damage', 'critic_rate', 'electric'], 
    'energy'    : ['all'], 
    'fire'      : ['atk', 'critic_damage', 'critic_rate', 'fire'], 
    'heal'      : ['all'], 
    'ice'       : ['atk', 'critic_damage', 'critic_rate', 'ice'], 
    'light'     : ['atk', 'critic_damage', 'critic_rate', 'light'], 
    'wind'      : ['atk', 'critic_damage', 'critic_rate', 'wind']
}

def Stop() :
    global stop
    stop = True
    print("強制結束！！！")

def Delay(t) :
    time.sleep(t)

def Click(x = 960, y = 570, duration = 0.3) :
    pyautogui.moveTo(x, y, duration)
    pyautogui.click()
    # print(f"點擊 ({x}, {y})")

def RightClick() :
    pyautogui.rightClick()
    print("點擊右鍵")

def Scroll(value) :
    pyautogui.scroll(value)

def Press(c, delay = 0) :
    pyautogui.press(c)
    print(f"按下 {c}")
    if delay :
        Delay(delay)

def Move(c, duration) :
    pyautogui.keyDown(c)  # 按下鍵
    print(f"按住 {c}")
    Delay(duration)  # 等待指定時間
    pyautogui.keyUp(c)  # 釋放鍵

def Turn_Left() :
    Move('A', 0.05)
    Press('H')
    Press('H')
    Delay(1)

def Turn_Right() :
    Move('D', 0.05)
    Press('H')
    Press('H')
    Delay(1)

def Turn_Around() :
    Turn_Right()
    Turn_Right()

def Image_Detect(image_path, screenshot, rate = 0.8) :
    template = cv2.imread(dir_path + image_path, cv2.IMREAD_UNCHANGED)

    screenshot = cv2.cvtColor(screenshot, cv2.COLOR_BGR2GRAY)
    template = cv2.cvtColor(template, cv2.COLOR_BGR2GRAY)
    # cv2.imwrite("template.jpg", template)
    # cv2.imwrite("screenshot.jpg", screenshot)

    result = cv2.matchTemplate(screenshot, template, cv2.TM_CCOEFF_NORMED)
    
    min_val, max_val, min_loc, max_loc = cv2.minMaxLoc(result)
    # print(f"Detecting \"{image_path}\" at {max_loc}. (rate : {max_val})")
    return max_val

def Check_Drop() :
    global reward
    screenshot = pyautogui.screenshot()
    drop = screenshot.getpixel((1250, 580))
    if drop[0] == 255 and drop[1] == 255 and drop[2] == 255 :
        Press('E')
        Delay(1)
        screenshot = pyautogui.screenshot()
        wrong1 = screenshot.getpixel((1315, 700))
        wrong2 = screenshot.getpixel((1315, 750))
        if wrong1 == (0, 0, 0) or wrong2 == (0, 0, 0):
            Press('esc')
            Delay(0.1)
        else : 
            print("----------------------------獲得聲骸----------------------------")
            reward += 1
            with open("record.txt", 'a') as file :
                file.write('V')
            Delay(1)
            return True
    return False

def Go_To_Drop(distance) :
    pyautogui.keyDown('W')
    rec = time.time()
    while time.time() - rec <= distance :
        if Check_Drop() :
            pyautogui.keyUp('W')
            return True
    pyautogui.keyUp('W')
    return False

def Pick_Drop() :
    if Check_Drop() : return
    if Go_To_Drop(3) : return
    Turn_Left()
    if Go_To_Drop(4) : return
    Turn_Around()
    if Go_To_Drop(8) : return

def Jinshi_Q3() :
    global state
    if state == 3 :
        Delay(1)
        Press('Q')
        print("施放 Q3")
        state = 4
    else : Click()

def Jinshi_Q4() :
    global state
    screenshot = pyautogui.screenshot()
    jinshi_Q = screenshot.getpixel((1492, 1007))
    if jinshi_Q == (255, 255, 214) :
        Press('Q')
        print("施放 Q4")
        state = 5

def Scroll_Echo_Page() :
    pyautogui.moveTo(1110, 966)
    Delay(0.3)
    Scroll(-900)
    Delay(0.3)
    while True :
        screenshot = pyautogui.screenshot(region=(310, 880, 50, 40))
        screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
        if Image_Detect("Resource/addtion.jpg", screenshot) >= 0.9 :
            break
        Scroll(-20)
        Delay(0.3)

def Lock_Method() :
    """
    截圖聲骸資訊並選擇是否上鎖
    """
    global stop
    screenshot = pyautogui.screenshot(region=(1300, 236, 550, 292))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    if not Image_Detect("Resource/level_0.jpg", screenshot) >= 0.9 :
        stop = True
        return
    for attribute in attributes :
        if Image_Detect(f"Resource/Attribute/{attribute}.jpg", screenshot) >= 0.9 :
            print(f"--------------------\nThe echo is {attribute}.")
            for tune in tunes[attribute] :
                if tune == 'all' or Image_Detect(f"Resource/Tune/{tune}.jpg", screenshot) >= 0.9 :
                    print(f"The tune is {tune}.\n--------------------")
                    if Image_Detect("Resource/unlock.jpg", screenshot) >= 0.9 :
                        Click(1806, 392)
                    return
            print(f"The tune is unwanted.\n--------------------")
            if Image_Detect("Resource/lock.jpg", screenshot) >= 0.9 :
                Click(1806, 392)
            return

def Combine_Method() :
    """
    截圖聲骸資訊並選擇是否上鎖
    """
    screenshot = pyautogui.screenshot(region=(700, 244, 550, 292))
    screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGRA)
    attribute_selected, max_rate = 'None', 0
    for attribute in attributes :
        rate = Image_Detect(f"Resource/Attribute/{attribute}.jpg", screenshot)
        if rate > max_rate :
            attribute_selected, max_rate = attribute, rate
    print(f"--------------------\nThe echo is {attribute_selected}.")
    for tune in tunes[attribute_selected] :
        if tune == 'all' or Image_Detect(f"Resource/Tune/{tune}.jpg", screenshot) >= 0.9 :
            Click(1200, 400)
            print(f"The tune is wanted.\n--------------------")
            return
    print(f"The tune is unwanted.\n--------------------")