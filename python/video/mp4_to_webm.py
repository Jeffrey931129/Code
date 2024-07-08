from moviepy.editor import VideoFileClip

# 讀取 MP4 視頻
input_path = "C:/Users/USER/Downloads/jinshi.mp4"
video = VideoFileClip(input_path)

# 輸出 WebM 視頻
output_path = "C:/Users/USER/Downloads/test-4.webm"
video.write_videofile(output_path, codec='libvpx', audio_codec='libvorbis', bitrate='6000k')
