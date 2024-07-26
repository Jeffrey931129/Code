import cv2
import numpy as np

# 載入原始圖片
image = cv2.imread("C:/Users/USER/Downloads/image.png", cv2.IMREAD_UNCHANGED)

h = image.shape[0]     # 取得圖片高度
w = image.shape[1]     # 取得圖片寬度

for y in range(h):
    for x in range(w):
        if image[y, x, 3] != 255 :
            print(y, x)