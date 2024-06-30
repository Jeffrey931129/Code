import cv2
import numpy as np
import os

path = 'C:/Users/USER/Downloads/image'
img = cv2.imread(os.path.join(path,'001.jpg'))
# 获取图片尺寸
imgInfo = img.shape
size = (imgInfo[1],imgInfo[0])
print(size)
filelist = os.listdir(path)
filelist.sort()
fps = 60  # 视频每秒组成的原始帧数
fourcc = cv2.VideoWriter_fourcc(*'X264')				# 设置视频编码格式
video = cv2.VideoWriter('C:/Users/USER/Downloads/video.mp4', fourcc, fps, size)
print('loading...')
# 视频保存在当前目录下
for item in filelist:
    if item.endswith('.jpg') or item.endswith('.JPG'):
        print(item)
        item = os.path.join(path,item)
        # 路径中若存在为中文名
        # img = cv2.imdecode(np.fromfile(item, dtype=np.uint8), 1)
        # 路径为英文名
        img = cv2.imread(item)
        video.write(img)

video.release()