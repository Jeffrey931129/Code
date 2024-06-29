import os
import cv2

def cutVideos2Pictures(video_path, saveDir):
    '''
    將視頻流數據切割成圖片數據並保存
    '''
    if not os.path.exists(saveDir):
        os.makedirs(saveDir)
    
    vc = cv2.VideoCapture(video_path)
    frame_count = 1
    
    if vc.isOpened():
        rval, frame = vc.read()
        fps = vc.get(cv2.CAP_PROP_FPS)
        print(f"fps : {fps}")
    else:
        rval = False
        print(f"Error: Unable to open video file {video_path}")
        return
    
    timeF = 1  # 圖片間隔頻率        
    while rval:
        rval, frame = vc.read()
        if frame_count % timeF == 0 and rval:
            cv2.imwrite(os.path.join(saveDir, f'{frame_count}.jpg'), frame)
        frame_count += 1
        cv2.waitKey(1)
    vc.release()

if __name__ == '__main__':
    cutVideos2Pictures(video_path='C:/Users/USER/Downloads/test.webm', saveDir='C:/Users/USER/Downloads/image')
