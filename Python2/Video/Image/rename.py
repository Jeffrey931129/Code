import os

path = 'C:/Users/USER/Downloads/jinshi'

# 要改名的範圍：從 'start_index.jpg' 到 'end_index.jpg'
start_index = 709
end_index = 1123

# 移動的張數
move_count = -708

# 遍歷每個要改名的檔案，進行改名操作
for i in range(start_index, end_index + 1):
    old_name = f'{i:04d}.jpg'
    new_name = f'{i + move_count:04d}.jpg'
    old_path = os.path.join(path, old_name)
    new_path = os.path.join(path, new_name)
    os.rename(old_path, new_path)
    print(f'Renamed {old_name} to {new_name}')

print('Rename finished.')
