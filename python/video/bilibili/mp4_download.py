import yt_dlp

ydl_opts = {
    'cookiefile': 'C:/Code/python/video/bilibili/cookie.txt',  # 指定 cookies 文件路徑
    'format': 'bestvideo[ext=mp4]+bestaudio[ext=m4a]/bestvideo',  # 選擇最高解析度的影片和 M4A 格式的音訊
    'outtmpl': 'C:/Users/USER/Downloads/%(title)s.%(ext)s',  # 保存路徑和檔名
    'http_headers': {
        'User-Agent': 'Mozilla/5.0 (Windows NT 10.0; Win64; x64) AppleWebKit/537.36 (KHTML, like Gecko) Chrome/91.0.4472.124 Safari/537.36'
    },
    'postprocessors': [{
        'key': 'FFmpegVideoConvertor',
        'preferedformat': 'mp4',  # 轉換為 MP4 格式
    }],
}

with yt_dlp.YoutubeDL(ydl_opts) as ydl:
    ydl.download(['https://www.bilibili.com/video/BV1GZ421u7hg/?spm_id_from=333.1007.tianma.1-1-1.click&vd_source=6fa279cde64157932f7bb9ff3aaac83b'])  # 將此URL替換為Bilibili視頻的URL

print("影片下載完成！")
