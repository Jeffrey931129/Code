import os

def download_bilibili_video(url, download_path, cookies_path):
    command = f'yt-dlp --cookies {cookies_path} -f mp4 -o "{download_path}/%(title)s.%(ext)s" {url}'
    os.system(command)

# 使用範例
video_url = 'https://www.bilibili.com/video/BV1MW421R7t1/?spm_id_from=333.1007.tianma.1-1-1.click'
download_path = 'C:/Users/USER/Downloads'
cookies_path = 'C:/Code/python/video/cookie.txt'  # 修改為你的 cookies.txt 路徑
download_bilibili_video(video_url, download_path, cookies_path)
