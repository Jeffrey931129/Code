import ffmpeg

input_file = 'C:/Users/USER/Downloads/your_video_filename.webm'
output_file = 'C:/Users/USER/Downloads/output_video.mp4'

(
    ffmpeg
    .input(input_file)
    .output(output_file)
    .run()
)

print("轉換完成！")
