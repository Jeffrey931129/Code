import cv2
import numpy as np

# 載入原始圖片
image = cv2.imread("C:/Users/USER/Downloads/red.png")

# 將圖片轉換為 RGBA 格式（添加透明通道）
image = cv2.cvtColor(image, cv2.COLOR_BGR2BGRA)

h = image.shape[0]     # 取得圖片高度
w = image.shape[1]     # 取得圖片寬度

# 範圍設定
min_range = (0, 0, 0, 0)
max_range = (100, 100, 100, 255)

def is_pixel_in_range(pixel):
    # pixel 是一個 (R, G, B, A) 元組
    # min_range 和 max_range 是 (R, G, B, A) 元組
    r, g, b, a = pixel
    min_r, min_g, min_b, min_a = min_range
    max_r, max_g, max_b, max_a = max_range
    
    # 檢查顏色是否在範圍內
    is_in_range = (min_r <= r <= max_r and
                   min_g <= g <= max_g and
                   min_b <= b <= max_b and
                   min_a <= a <= max_a)
    
    return is_in_range

# 依序取出圖片中每個像素
for y in range(image.shape[0]) :
    for x in range(image.shape[1]) :
        pixel = tuple(image[y, x])
        print(pixel)
        if image[y, x, 0] >= 200 and image[y, x, 1] >= 200 and image[y, x, 2] >= 200 :
            image[y, x] = (255, 255, 255, 255)
        elif image[y, x, 0] < 50 and image[y, x, 1] < 50 and image[y, x, 2] < 50 :
            image[y, x] = (0, 0, 0, 255)
        else :
            image[y, x] = (0, 0, 255, 255)

cv2.imwrite("C:/Users/USER/Downloads/red_40.png", image)    # 存檔儲存為 png
print("完成")
