from tkinter import *

window = Tk()
window.title("Grid")
window.geometry("450x450")
frame_pack = LabelFrame(window, text="Grid", padx=10, pady=10)
frame_pack.pack(padx=30, pady=20, fill="x")


btn1 = Button(frame_pack, text="Button1", width=20)            #change the width with width=...
btn2 = Button(frame_pack, text="Button2")
btn3 = Button(frame_pack, text="Button3")
btn4 = Button(frame_pack, text="Button4")
btn5 = Button(frame_pack, text="Button5", height=6)             #change the height with height=...


btn1.grid(row=0, column=0, padx=5, pady=5, columnspan=2)       #columnspan=... will make 1 button use ... columns
btn2.grid(row=1, column=0, padx=5, pady=5)
btn3.grid(row=2, column=0, padx=5, pady=5)
btn4.grid(row=3, column=0, padx=5, pady=5)
btn5.grid(row=1, column=1, padx=5, pady=5, rowspan=3)           #rowspan=... will make 1 button use ... rows

window.mainloop()