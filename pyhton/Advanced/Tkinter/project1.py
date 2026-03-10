from tkinter import *

window = Tk()
window.title("Vidjets and arguments")
window.geometry("400x250")

frame1 = Frame(window, width=300, height=100, bg="purple1")
frame1.place(x=10, y=10)
label1 = Label(frame1, text="Hello world", relief=RAISED, bd=5, bg="purple1", fg="white", font="helvetica 8 bold", width=50, height=5, justify="center")
label1.place(x=10, y=10)

frame2 = Frame(window, width=300, height=100, bg="purple1")
frame2.place(x=10, y=150)

button1 = Button(frame2, text="Button 1", activebackground="blue", activeforeground="yellow", )
button2 = Button(frame2, text="Button 2", activeforeground="red", activebackground="green")

button1.place(x=40, y=30)
button2.place(x=170, y=30)

window.mainloop()