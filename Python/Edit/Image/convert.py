from PIL import Image

# 打開WEBP圖像
image = Image.open("C:/Users/USER/Downloads/drop-down-menu-icon-on-600nw-2224396841.webp")

# 轉換並保存為PNG圖像
image.save("C:/Users/USER/Downloads/image.png", 'PNG')

print("轉換完成")
