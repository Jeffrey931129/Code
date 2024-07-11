from PIL import Image
import os

# 定義來源和目的資料夾
source_folder = "C:/Users/USER/Downloads/jinshi"
destination_folder = "C:/Users/USER/Downloads/jinshi_clip"

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
        left = 0
        right = left + crop_width
        upper = 200
        lower = upper + crop_height
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
