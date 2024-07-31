import pyautogui
import time
import os
import keyboard
import threading

stop = False
def Stop() :
    global stop
    stop = True
    print("STOP")
def thread() :
    while True :
        if stop :
            print("EXIT")
            exit()
keyboard.add_hotkey('ctrl+p', Stop)
dir_path = "Python/Game/WutheringWaves/"
start_time = time.time()

while True :
    if stop :
        exit()
    print("process...")
    time.sleep(1)