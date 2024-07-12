import yt_dlp
import os
import sys
import tkinter as tk
from tkinter import messagebox, simpledialog
import tkinter.font as tkFont

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

def download_video(url):
    try:
        info = yt_dlp.YoutubeDL(ydl_opts).extract_info(url, download=False)
        title = info['title']
        target_file = f"C:/Users/USER/Downloads/{title}.mp3"

        # 檢查目標檔案是否存在
        if os.path.exists(target_file):
            choice = messagebox.askyesno("檔案已存在", f"檔案 '{title}.mp3' 已存在，是否覆蓋？")
            if not choice:
                return "取消下載"
        
        with yt_dlp.YoutubeDL(ydl_opts) as ydl:
            ydl.download([url])
        return "下載成功"
    except Exception as e:
        return "下載失敗"

def on_download_button_click():
    url = url_entry.get()
    if url:
        result = download_video(url)
        result_label.config(text=result)
    else:
        messagebox.showwarning("輸入錯誤", "請輸入 YouTube 網址")

# 創建主視窗
root = tk.Tk()
root.title("YouTube MP3 轉換器")
root.geometry("400x180")
root.iconbitmap('music.ico')

custom_font = tkFont.Font(family="DFKai-SB", size=12, weight="bold")

# 創建並佈局小部件
url_label = tk.Label(root, text="請輸入 YouTube 網址 : ", font=custom_font)
url_label.pack(pady=20)

url_entry = tk.Entry(root, width=50)
url_entry.pack(pady=5)

download_button = tk.Button(root, text="下載", command=on_download_button_click, font=custom_font)
download_button.pack(pady=10)

result_label = tk.Label(root, text="", font=custom_font)
result_label.pack(pady=10)

# 啟動主事件循環
root.mainloop()
