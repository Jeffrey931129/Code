import ffmpeg

def convert_mp4_to_gif(input_file, output_file, start_time = None, duration = None) :
    try:
        stream = ffmpeg.input(input_file)
        if start_time and duration:
            stream = stream.trim(start=start_time, duration=duration).setpts('PTS-STARTPTS')
        stream = ffmpeg.output(stream, output_file, vf='fps=10,scale=320:-1:flags=lanczos')
        ffmpeg.run(stream, capture_stdout=True, capture_stderr=True)
        print("影片轉換為GIF完成！")
    except ffmpeg.Error as e:
        print("Error:", e)
        print("stdout:", e.stdout.decode('utf8'))
        print("stderr:", e.stderr.decode('utf8'))

input_file = 'C:/Users/USER/Downloads/clip_video2.mp4'
output_file = 'C:/Users/USER/Downloads/bamboo.gif'
start_time = '00:00:03.500'  # 可選：開始時間 (帶毫秒)
duration = '00:00:05'  # 可選：持續時間 (例如5秒)

convert_mp4_to_gif(input_file, output_file)
