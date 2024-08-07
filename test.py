from tkinter import *
 
window = Tk()
 
# 设置窗口属性
window.attributes('-transparentcolor', 'white')
window.config(bg='white')#颜色
window.title("字屏")#设置标题
 
window.geometry("300x50")
#window.overrideredirect(True)  # 去除窗口边框
window.attributes('-alpha', 0.5)  # 设置窗口透明度为50%
window.attributes('-topmost', True)  # 将窗口置顶
 
# 文本内容
text = "这是一段需要循环滚动的文本！这是一段需要循环滚动的文本！"
 
# 创建Label组件
label = Label(window, text=text, font=("华文新魏", 25), bg='white')
label.pack(fill=BOTH, expand=1)
 
# 滚动文本
def scroll_text():
    text = label['text'][1:] + label['text'][0]
    label.config(text=text)
    window.after(800, scroll_text)
 
# 启动滚动
window.after(100, scroll_text)
window.mainloop()