import win32gui
import win32ui
import win32con
import win32api
import pygetwindow as gw
from PIL import Image, ImageChops
from ctypes import windll
import numpy as np
import cv2
import time

def Capture_window_to_image(window_title) :
    # 根據視窗標題找到視窗句柄
    hwnd = win32gui.FindWindow(None, window_title)
    if not hwnd:
        print(f"找不到指定的視窗: {window_title}")
        return
    
    # 取得視窗的範圍
    x, y = 0, 0
    width, height = 1920, 1200
    
    # 取得視窗的裝置描述表 (Device Context, DC)
    window_dc = win32gui.GetWindowDC(hwnd)
    mfc_dc = win32ui.CreateDCFromHandle(window_dc)
    save_dc = mfc_dc.CreateCompatibleDC()
    # 建立位圖物件
    save_bitmap = win32ui.CreateBitmap()
    save_bitmap.CreateCompatibleBitmap(mfc_dc, x + width, y + height)
    save_dc.SelectObject(save_bitmap)
    
    # 向視窗發送 WM_PRINT 訊息，要求其繪製自己
    result = windll.user32.PrintWindow(hwnd, save_dc.GetSafeHdc(), 3)
    if result != 1:
        # 釋放所有資源
        try:
            win32gui.DeleteObject(save_bitmap.GetHandle())
            save_dc.DeleteDC()
            mfc_dc.DeleteDC()
            win32gui.ReleaseDC(hwnd, window_dc)
            del window_dc, mfc_dc, save_dc, save_bitmap
        except Exception as e:
            print(f"清理截圖資源失敗: {e}", "ERROR")

    # 從點陣圖中取得影像數據
    bmp_info = save_bitmap.GetInfo()  # 取得點陣圖訊息
    bmp_str = save_bitmap.GetBitmapBits(True)  # 獲取點陣圖數據
    im = np.frombuffer(bmp_str, dtype="uint8")  # 將點陣圖數據轉換為 numpy 陣列
    im.shape = (bmp_info["bmHeight"], bmp_info["bmWidth"], 4)  # 設定陣列形狀
    # 調整通道順序 並 去除 alpha 通道
    im = im[:, :, [2, 1, 0, 3]][:, :, :3]

    # 清理資源
    try:
        win32gui.DeleteObject(save_bitmap.GetHandle())
        save_dc.DeleteDC()
        mfc_dc.DeleteDC()
        win32gui.ReleaseDC(hwnd, window_dc)
    except Exception as e:
        print(f"清理截圖資源失敗: {e}", "ERROR")

    im_cropped = im[y : y+height, x : x+width]

    return im_cropped  # 返回擷取到的圖像

def Image_detect(image_path, screenshot) :
    # 將 PIL 圖像轉換為 OpenCV 格式
    screenshot_cv = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)

    # 讀取待比對的圖片
    template = cv2.imread(image_path)

    # 將圖片和螢幕圖像轉為灰階
    screenshot_gray = cv2.cvtColor(screenshot_cv, cv2.COLOR_BGR2GRAY)
    template_gray = cv2.cvtColor(template, cv2.COLOR_BGR2GRAY)

    # 使用模板匹配方法進行比對
    result = cv2.matchTemplate(screenshot_gray, template_gray, cv2.TM_CCOEFF_NORMED)

    # 設定匹配閾值
    threshold = 0.8
    loc = np.where(result >= threshold)

    # 檢查是否有相對的匹配
    if len(loc[0]) > 0 :
        return True
    else:
        return False

if __name__ == "__main__" :
    # 獲取視窗句柄
    window_title = "HeavenBurnsRed"
    hwnd = win32gui.FindWindow(None, window_title)  # 替換成你的視窗標題
    if hwnd == 0:
        print("找不到視窗！")
        windows = gw.getWindowsWithTitle('')
        with open("record.txt", 'w') as file :
            for window in windows :
                if window.title :
                    file.write(window.title)
                    file.write('\n')
    else:
        print("成功抓取視窗")

        rec_time = time.time()
        image = Capture_window_to_image(window_title)
        if image is not None:
            image = Image.fromarray(image)  # 將 numpy 陣列轉換為 PIL 圖像
            # image.save("capture.png")  # 保存圖像
            # 載入現有圖片

            # 比較捕捉到的圖像和現有圖像
            if Image_detect("capture.png", image) :
                print("圖像相同")
            else:
                print("圖像不同")
        print(f"{time.time() - rec_time:.2f}")
