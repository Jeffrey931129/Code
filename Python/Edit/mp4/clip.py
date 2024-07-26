import ffmpeg

def clip_video(input_file, output_file, start_time, end_time) :
    try:
        (
            ffmpeg
            .input(input_file, ss=start_time, to=end_time)
            .output(output_file, vcodec='libx264', acodec='aac')
            .run(capture_stdout=True, capture_stderr=True)
        )
    except ffmpeg.Error as e:
        print("Error:", e)
        print("stdout:", e.stdout.decode('utf8'))
        print("stderr:", e.stderr.decode('utf8'))

input_file = 'C:/Users/USER/Downloads/bamboo.mp4'
output_file = 'C:/Users/USER/Downloads/clip_video2.mp4'
start_time = '00:00:04.250'  # 開始時間
end_time = '00:00:11.790'    # 結束時間

clip_video(input_file, output_file, start_time, end_time)
print("影片修剪完成！")
