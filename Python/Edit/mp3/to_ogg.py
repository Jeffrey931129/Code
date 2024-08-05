from pydub import AudioSegment

# 載入 MP3 文件
mp3_audio = AudioSegment.from_mp3("C:/Users/USER/我的雲端硬碟/Music/spiral.mp3")

# 將其轉換為 OGG 格式並保存
mp3_audio.export("C:/Steam/steamapps/workshop/content/431960/884307090/audio/4-Audio.ogg", format="ogg")
