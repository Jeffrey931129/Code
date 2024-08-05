from pydub import AudioSegment

# 載入音訊檔案
audio = AudioSegment.from_mp3("C:/Users/USER/Downloads/LOVE 2000.mp3")
print(audio.dBFS)
# 調整音量
adjusted_audio = audio.apply_gain(-16.33854565016167 - audio.dBFS)
print(adjusted_audio.dBFS)
# 儲存調整後的音訊檔案
adjusted_audio.export("C:/Users/USER/Downloads/LOVE 2000.mp3", format="mp3")
