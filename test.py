import cv2
import numpy as np

# 讀取模板
template = cv2.imread('Python/Game/WutheringWaves/Dreamless/Resource/jinshi_Q4.jpg')

# 創建掩膜 (白色區域為1，黑色區域為0)
mask = np.zeros(template.shape[:2], dtype=np.uint8)
for x in range(template.shape[1]) :
    for y in range(template.shape[0]) :
        pixel = tuple(template[y, x])
        if template[y, x, 0] >= 200 and template[y, x, 1] >= 200 and template[y, x, 2] >= 200 :
            mask[y, x] = 255  # 假設要匹配的區域是這個矩形區域

# 保存掩膜到本地
cv2.imwrite('Python/Game/WutheringWaves/Dreamless/Resource/jinshi_Q4_mask.jpg', mask)
