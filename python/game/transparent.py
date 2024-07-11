import cv2
import numpy as np

# 載入原始圖片
image = cv2.imread('C:/Code/python/game/resource/test4.png')

# 將圖片轉換為 RGBA 格式（添加透明通道）
rgba_image = cv2.cvtColor(image, cv2.COLOR_BGR2BGRA)

h = image.shape[0]     # 取得圖片高度
w = image.shape[1]     # 取得圖片寬度

# 依序取出圖片中每個像素
for x in range(w):
    for y in range(h):
        if 0 <= rgba_image[y, x, 2] <= 224 and rgba_image[y, x, 0] <= 200:
            rgba_image[y, x, 3] = 0
            # 如果該像素的灰階度大於 200，調整該像素的透明度
            # 使用 255 - gray[y, x] 可以將一些邊緣的像素變成半透明，避免太過鋸齒的邊緣

cv2.imwrite('C:/Code/python/game/resource/result.png', rgba_image)    # 存檔儲存為 png
cv2.waitKey(0)                        # 按下任意鍵停止
cv2.destroyAllWindows()
