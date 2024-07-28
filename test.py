import cv2
import numpy as np

# 載入原始圖片
image = cv2.imread("C:/Users/USER/Downloads/image_clip.png", cv2.IMREAD_UNCHANGED)

h = image.shape[0]     # 取得圖片高度
w = image.shape[1]     # 取得圖片寬度

dict = {}
val = 0

file = open("record.txt", 'w')
for y in range(h):
    for x in range(w):
        pixel = tuple(image[y, x])
        if pixel == (255, 255, 255, 255) :
            file.write("1")
        # elif image[y, x, 0] >= 230 :
        #     file.write("0")
        else :
            file.write(' ')
    file.write('\n')
file.close()