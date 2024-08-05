import pyautogui
import time
import keyboard
import threading

stop = False
def Stop() :
    global stop
    stop = not stop

time.sleep(2)
keyboard.add_hotkey('p', Stop)

while True :
    if not stop :
        pyautogui.press('space')
        time.sleep(0.1)
