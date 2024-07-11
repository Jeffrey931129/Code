import yt_dlp

ydl_opts = {
    'format': 'bestaudio[ext=m4a]/bestaudio',  # 選擇最好的音訊格式
    'outtmpl': 'C:/Users/USER/Downloads/%(title)s.%(ext)s',  # 保存路徑和檔名
    'http_headers': {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    },
    'postprocessors': [{
        'key': 'FFmpegExtractAudio',
        'preferredcodec': 'mp3',  # 轉換為 MP3 格式
        'preferredquality': '192',  # 設定音質（選擇比特率，如 192 kbps）
    }],
}

with yt_dlp.YoutubeDL(ydl_opts) as ydl:
    ydl.download(['https://www.youtube.com/watch?v=mLW35YMzELE'])

print("音訊下載完成！")
