import os
import shutil

path = 'C:/Users/USER/Downloads/image2'

# 要複製的原始檔案名稱和目標檔案名稱的對應關係
original_file = '451.jpg'
start_index = 452
end_index = 481

# 遍歷要複製的次數
for i in range(start_index, end_index + 1):
    target_file = f'{i:03d}.jpg'
    target_path = os.path.join(path, target_file)
    shutil.copyfile(os.path.join(path, original_file), target_path)
    print(f'Copied {original_file} to {target_file}')

print('Copying finished.')
