import ffmpeg

def get_video_resolution(input_file):
    probe = ffmpeg.probe(input_file)
    video_streams = [stream for stream in probe['streams'] if stream['codec_type'] == 'video']
    
    if not video_streams:
        raise ValueError("No video stream found in the file")

    # 假設我們只取第一個視頻流
    video_stream = video_streams[0]
    width = int(video_stream['width'])
    height = int(video_stream['height'])
    
    return width, height

input_file = 'C:/Steam/steamapps/workshop/content/431960/884307090/video/5-test.webm'
width, height = get_video_resolution(input_file)
print(f"解析度: {width}x{height}")
