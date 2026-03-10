from tkinter import *

window = Tk()
window.title("Vidjets and arguments")
window.geometry("400x250")
frame_pack = LabelFrame(window, text="Project1", padx=10, pady=10, width=350, height=100)
frame_pack.grid(padx=30, pady=20)

label1 = Label(window, text="Hello world", relief=SUNKEN, bd=5, bg="gray59", fg="white", font="helvetica 8 bold", width=50, height=5)
label1.grid()

button1 = Button(frame_pack, text="Button 1")

button1.place(x=10, y=6)

window.mainloop()