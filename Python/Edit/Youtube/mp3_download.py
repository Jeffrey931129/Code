import yt_dlp
import os

ydl_opts = {
    'format' : 'bestaudio[ext=m4a]/bestaudio',  # 選擇最好的音訊格式
    'outtmpl' : 'C:/Users/USER/Downloads/%(title)s.%(ext)s',  # 保存路徑和檔名
    'http_headers' : {
        'User-Agent' : 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    },
    'postprocessors' : [{
        'key': 'FFmpegExtractAudio',
        'preferredcodec' : 'mp3',  # 轉換為 MP3 格式
        'preferredquality' : '192',  # 設定音質（選擇比特率，如 192 kbps）
    }],
}

print("歡迎使用 Youtube mp3 轉換器")
command = 'y'
while command.lower() == 'y' :
    url = input("請輸入 Youtube 網站連結 : ")

    info = yt_dlp.YoutubeDL(ydl_opts).extract_info(url, download=False)
    title = info['title']
    target_file = f"C:/Users/USER/Downloads/{title}.mp3"

    # 檢查目標檔案是否存在
    if os.path.exists(target_file) :
        choice = input(f"檔案 '{title}.mp3' 已存在，是否覆蓋？ (y/n): ")
        if choice.lower() != 'y' :
            print("取消下載")
        else :
            with yt_dlp.YoutubeDL(ydl_opts) as ydl :
                ydl.download([url])
            print(f"'{title}.mp3' 下載完成！")
    else :
        with yt_dlp.YoutubeDL(ydl_opts) as ydl :
            ydl.download([url])
        print(f"'{title}.mp3' 下載完成！")
    command = input("請問是否要繼續？ (y/n): ")
