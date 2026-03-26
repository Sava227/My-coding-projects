import tkinter as tk
from tkinter import filedialog

n = 1

def add():
    global n
    w = e1.get()
    t = e2.get()
    if w and t:
        todolist.insert(tk.END, str(n) + ". " + w + " " + t + "\n")
        n += 1
        e1.delete(0, tk.END)
        e2.delete(0, tk.END)

def clear():
    todolist.delete("1.0", tk.END)

def save():
    f = filedialog.asksaveasfile(mode="w", defaultextension=".txt")
    if f:
        f.write(todolist.get("1.0", tk.END))
        f.close()

def load():
    f = filedialog.askopenfile(mode="r")
    if f:
        todolist.delete("1.0", tk.END)
        todolist.insert(tk.END, f.read())
        f.close()

root = tk.Tk()
root.title("List")

e1 = tk.Entry(root)
e1.pack()

e2 = tk.Entry(root)
e2.pack()

tk.Button(root, text="Add", command=add).pack()

todolist = tk.Text(root)
todolist.pack()

tk.Button(root, text="Clear", command=clear).pack()
tk.Button(root, text="Save", command=save).pack()
tk.Button(root, text="Load", command=load).pack()

root.mainloop()