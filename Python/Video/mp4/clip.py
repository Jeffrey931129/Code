import ffmpeg

def clip_video(input_file, output_file, start_time, end_time) :
    (
        ffmpeg
        .input(input_file, ss=start_time, to=end_time)
        .output(output_file, vcodec='libx264', acodec='aac')
        .run()
    )

input_file = 'C:/Users/USER/Downloads/video.mp4'
output_file = 'C:/Users/USER/Downloads/clip_video.mp4'
start_time = '00:03:00'  # 開始時間
end_time = '00:03:20'    # 結束時間

clip_video(input_file, output_file, start_time, end_time)
print("影片修剪完成！")
