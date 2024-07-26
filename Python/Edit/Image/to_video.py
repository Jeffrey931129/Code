import cv2
import numpy as np
import os

path = 'C:/Users/USER/Downloads/image_clip'
img = cv2.imread(os.path.join(path,'0001.jpg'))
# 取得圖片尺寸
imgInfo = img.shape
size = (imgInfo[1],imgInfo[0])
print(size)
filelist = os.listdir(path)
filelist.sort()
fps = 30  # 影片每秒組成的原始幀數
fourcc = cv2.VideoWriter_fourcc(*'X264')				# 設定視訊編碼格式
video = cv2.VideoWriter('C:/Users/USER/Downloads/bamboo.mp4', fourcc, fps, size)
print('loading...')
# 影片保存在目前目錄下
for item in filelist:
    if item.endswith('.jpg') or item.endswith('.JPG'):
        print(item)
        item = os.path.join(path,item)
        # 路徑中若存在為中文名
        # img = cv2.imdecode(np.fromfile(item, dtype=np.uint8), 1)
        # 路徑為英文名
        img = cv2.imread(item)
        video.write(img)

video.release()