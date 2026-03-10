from tkinter import *

window = Tk()
window.title("Place")
window.geometry("450x450")
frame_pack = LabelFrame(window, text="Place", padx=10, pady=10, width=350, height=100)
frame_pack.pack(padx=30, pady=20)
frame_pack.pack_propagate(False)

btn1 = Button(frame_pack, text="Button1")
btn2 = Button(frame_pack, text="Button2")

btn1.place(x=0, y=0)
btn2.place(x=120, y=10)

window.mainloop()