import pyautogui
import time
import keyboard
import threading
from function import *
import function

time.sleep(1)
keyboard.add_hotkey('ctrl+p', Stop)
start_time = time.time()

Go_To_End()
while not function.stop :
    Update()
    threads.append(threading.Thread(target=Skip))
    if function.state == 'Battle' :
        threads.append(threading.Thread(target=Battle))
    threads.append(threading.Thread(target=Move))
    for thread in threads :
        thread.start()
    for thread in threads :
        thread.join()
    threads.clear()
