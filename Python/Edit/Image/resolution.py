from PIL import Image
import os

# 輸入和輸出目錄
input_dir = 'C:/Users/USER/Downloads'
output_dir = 'C:/Users/USER/Downloads/scaled'

# 確保輸出目錄存在，如果不存在則創建
os.makedirs(output_dir, exist_ok=True)

# 處理每張圖片
for filename in os.listdir(input_dir):
    if filename.endswith('.png'):
        input_path = os.path.join(input_dir, filename)
        output_path = os.path.join(output_dir, filename)

        # 開啟圖片
        image = Image.open(input_path)

        # 進行需要的處理，例如放大、縮小、旋轉等
        # 這裡以縮放為例
        width, height = image.size
        new_width = 36  # 放大為原來的兩倍
        new_height = 36
        resized_image = image.resize((new_width, new_height), Image.LANCZOS)

        # 儲存處理後的圖片
        resized_image.save(output_path)

        # 可以選擇關閉圖片，釋放資源
        image.close()

print("圖片處理完成！")
