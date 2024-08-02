from pydub import AudioSegment
import numpy as np

# 載入音訊檔案
audio = AudioSegment.from_mp3("C:/Users/USER/我的雲端硬碟/Music/還是會想你.mp3")

print(audio.dBFS)

# 降低 3 分貝
adjusted_audio = audio + -16.02911334598148 - audio.dBFS  # 將音量降低 3 dB

# 儲存調整後的音訊檔案
adjusted_audio.export("adjusted_example.mp3", format="mp3")
