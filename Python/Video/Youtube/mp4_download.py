import yt_dlp
import os

ydl_opts = {
    'format' : 'bestvideo[ext=mp4]+bestaudio[ext=m4a]/best[ext=mp4]',  # 選擇 MP4 格式的影片和音訊
    'outtmpl' : 'C:/Users/USER/Downloads/%(title)s.%(ext)s',  # 保存路徑和檔名
    'http_headers' : {
        'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    },
    'postprocessors' : [{
        'key' : 'FFmpegVideoConvertor',
        'preferedformat' : 'mp4',  # 轉換為 MP4 格式
    }],
}

print("歡迎使用 Youtube mp4 轉換器")
command = 'y'
while command.lower() == 'y' :
    url = input("請輸入 Youtube 網站連結 : ")

    info = yt_dlp.YoutubeDL(ydl_opts).extract_info(url, download=False)
    title = info['title']
    target_file = f"C:/Users/USER/Downloads/{title}.mp4"

    # 檢查目標檔案是否存在
    if os.path.exists(target_file) :
        choice = input(f"檔案 '{title}.mp4' 已存在，是否覆蓋？ (y/n): ")
        if choice.lower() != 'y' :
            print("取消下載")
        else :
            with yt_dlp.YoutubeDL(ydl_opts) as ydl :
                ydl.download([url])
            print(f"'{title}.mp4' 下載完成！")
    else :
        with yt_dlp.YoutubeDL(ydl_opts) as ydl :
            ydl.download([url])
        print(f"'{title}.mp4' 下載完成！")
    command = input("請問是否要繼續？ (y/n): ")
