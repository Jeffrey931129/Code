import cv2
import os
import time

videoPath = "C:/Users/USER/Downloads/video.mp4"

cap = cv2.VideoCapture(videoPath)    # 獲取視頻
judge = cap.isOpened()               # 判斷是否能打開成功
fps = cap.get(cv2.CAP_PROP_FPS)      # 幀率，影片每秒展示多少張圖片
cap.release()
print('fps :', fps)
