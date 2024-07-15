import subprocess

# 構建 PyInstaller 命令
command = [
    'pyinstaller',
    '--icon=C:/Code/Project/music.ico',
    'C:/Code/Project/music.py',
    '--onefile',
    '--windowed',
    '--add-binary',
    'C:/ffmpeg/bin/ffmpeg.exe;ffmpeg'
]

# 執行命令
result = subprocess.run(command, capture_output=True, text=True)

# 輸出結果
print(result.stdout)
print(result.stderr)
