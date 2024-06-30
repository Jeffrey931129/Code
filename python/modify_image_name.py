import os

path = 'C:/Users/USER/Downloads/image'

# 要改名的範圍：從 '401.jpg' 到 '800.jpg'
start_index = 401
end_index = 800

# 移動的張數
move_count = 40

# 遍歷每個要改名的檔案，進行改名操作
for i in range(start_index, end_index + 1):
    old_name = f'{i:03d}.jpg'
    new_name = f'{i + move_count:03d}.jpg'
    old_path = os.path.join(path, old_name)
    new_path = os.path.join(path, new_name)
    os.rename(old_path, new_path)
    print(f'Renamed {old_name} to {new_name}')

print('Rename finished.')
