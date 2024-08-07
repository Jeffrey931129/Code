from PIL import Image
import os
import time
import pyautogui
import cv2
import numpy as np

def Batch_Clip() :
    # 定義來源和目的資料夾
    source_folder = "C:/Users/USER/Downloads/image"
    destination_folder = "C:/Users/USER/Downloads/image_clip"

    # 確保目的資料夾存在，若不存在則創建
    if not os.path.exists(destination_folder):
        os.makedirs(destination_folder)

    # 定義要處理的圖片範圍
    start_index = 1
    end_index = 415  # 根據你的圖片數量調整

    # 目標裁剪尺寸
    crop_width = 3840
    crop_height = 1960 - 200

    # 處理每張圖片
    for i in range(start_index, end_index + 1):
        # 構建文件名
        file_name = f"{i:04d}.jpg"
        source_path = os.path.join(source_folder, file_name)
        
        try:
            # 讀取圖片
            image = Image.open(source_path)

            # 設定裁剪區域（left, upper, right, lower）
            left = 1032
            upper = 1048
            right = 1086
            lower = 1372
            crop_area = (left, upper, right, lower)

            # 裁剪圖片
            cropped_image = image.crop(crop_area)

            # 儲存裁剪後的圖片
            cropped_file_name = f"{file_name}"
            destination_path = os.path.join(destination_folder, cropped_file_name)
            cropped_image.save(destination_path)
            imgname = str(i).rjust(4,'0') + ".jpg"
            print(f"{imgname}")

        except Exception as e:
            print(f"Error processing {file_name}: {e}")

def Clip() :
    try:
        # 讀取圖片
        image = Image.open("C:/Users/USER/Downloads/image.png")

        # 設定裁剪區域（left, upper, right, lower）
        left = 1438
        upper = 46
        right = left+424
        lower = upper+186
        print(f"({left}, {upper}, {right - left}, {lower - upper})")
        crop_area = (left, upper, right, lower)

        # 裁剪圖片
        cropped_image = image.crop(crop_area)
        cropped_image = cropped_image.convert("RGB")

        # 儲存裁剪後的圖片
        cropped_image.save("C:/Users/USER/Downloads/image_clip.jpg")
        print("完成")

    except Exception as e:
        print(f"Error processing : {e}")

# time.sleep(1)
# screenshot = pyautogui.screenshot()
# screenshot = cv2.cvtColor(np.array(screenshot), cv2.COLOR_RGB2BGR)
# cv2.imwrite("tem.jpg", screenshot)
Clip()
