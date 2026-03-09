from tkinter import*

#setting the window
window=Tk()

#title
window.title("My 1st tkinter program")

#adjusting size
window.maxsize(500,500)
window.minsize(300, 300)
#window.resizable(True, False)

#widjet
close = Button(window, text="Close", command=window.destroy)
close.pack()

#finishing the program
window.mainloop()