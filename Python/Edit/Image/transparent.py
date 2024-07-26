import cv2
import numpy as np

# 載入原始圖片
image = cv2.imread("C:/Users/USER/Downloads/image_clip.png")

# 將圖片轉換為 RGBA 格式（添加透明通道）
rgba_image = cv2.cvtColor(image, cv2.COLOR_BGR2BGRA)

h = image.shape[0]     # 取得圖片高度
w = image.shape[1]     # 取得圖片寬度

# 範圍設定
min_range = (50, 50, 50, 255)
max_range = (254, 254, 254, 255)

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
for y in range(h):
    for x in range(w):
        pixel = tuple(rgba_image[y, x])
        if is_pixel_in_range(pixel) :
            rgba_image[y, x, 3] = 0

cv2.imwrite("C:/Users/USER/Downloads/goldhopper.png", rgba_image)    # 存檔儲存為 png
print("完成")
