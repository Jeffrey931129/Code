import cv2
import os
import time

def video2imgs(videoPath, imgPath):
    if not os.path.exists(imgPath):
        os.makedirs(imgPath)             # 目標資料夾不存在，則創建
    cap = cv2.VideoCapture(videoPath)    # 獲取視頻
    judge = cap.isOpened()               # 判斷是否能打開成功
    print(judge)
    fps = cap.get(cv2.CAP_PROP_FPS)      # 幀率，影片每秒展示多少張圖片

    frames = 1                           # 用於統計所有幀數
    count = 1                            # 用於統計保存的圖片數量

    while(judge):
        flag, frame = cap.read()         # 讀取每一張圖片 flag 表示是否讀取成功 frame 是圖片
        if not flag:
            print("Process finished!")
            break
        else:
            if frames % 1 == 0:         # 每隔 1 格抽一張
                imgname = str(count).rjust(4,'0') + ".jpg" 
                newPath = os.path.join(imgPath, imgname)
                print(imgname)
                cv2.imwrite(newPath, frame, [cv2.IMWRITE_JPEG_QUALITY, 100])
                # cv2.imencode('.jpg', frame)[1].tofile(newPath)
                count += 1
        frames += 1
    cap.release()
    print('fps:',fps)
    print("共有 %d 張圖片"%(count-1))
video2imgs("C:/Users/USER/Downloads/clip_video.mp4",'C:/Users/USER/Downloads/jinshi')