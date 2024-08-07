from PIL import Image
import os

# 設定要處理的文件夾路徑
folder_path = 'Python/Game/HeavenBurnsRed/Resource'

# 遍歷文件夾中的所有檔案
for filename in os.listdir(folder_path):
    # 檢查檔案是否是 PNG 格式
    if filename.endswith('.png'):
        # 構造完整的文件路徑
        file_path = os.path.join(folder_path, filename)
        
        # 打開 PNG 文件
        with Image.open(file_path) as img:
            # 移除透明度通道，JPG 格式不支持透明度
            img = img.convert('RGB')
            
            # 構造 JPG 文件的路徑
            new_filename = filename[:-4] + '.jpg'
            new_file_path = os.path.join(folder_path, new_filename)
            
            # 儲存為 JPG 格式
            img.save(new_file_path, 'JPEG')
        os.remove(file_path)

print("所有 PNG 文件已成功轉換為 JPG 格式。")
