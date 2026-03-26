import tkinter as tk

#check password func
def show_password():
    password = inputbox.get()

    #cgeck
    has_lower = False
    has_upper = False
    has_digit = False

    #check
    for char in password:
        if char.islower():
            has_lower = True
        if char.isupper():
            has_upper = True
        if char.isdigit():
            has_digit = True

    #clear output
    outputbox.delete(0, tk.END)

    # Check conditions one by one
    if has_lower and has_upper and has_digit:
        label2.config(text="passworsd is ok", fg="green")
        outputbox.insert(0, password)
    else:
        label2.config(fg="red")

        if not has_lower:
            label2.config(text="no lowercase letters")
        elif not has_upper:
            label2.config(text="no uppercase letters")
        elif not has_digit:
            label2.config(text="no numbers")

        outputbox.insert(0, "errot")

#theme
def switch_theme():
    root.config(bg="gray")

    passwordbox.config(bg="gray", fg="white")
    label1.config(bg="gray", fg="white")
    label2.config(bg="gray")

    inputbox.config(bg="black", fg="white")
    outputbox.config(bg="white", fg="black")

    showbutton.config(bg="lightgray")
    theme_button.config(bg="lightgray", state=tk.DISABLED)


root = tk.Tk()
root.title("Check password")
root.geometry("350x400")

#frm
passwordbox = tk.LabelFrame(root, text="Password", padx=10, pady=10)
passwordbox.pack(padx=20, pady=20)

#lbl
label1 = tk.Label(passwordbox, text="Password in:")
label1.pack()

#input
inputbox = tk.Entry(passwordbox, width=25, show="*")
inputbox.pack(pady=5)

#resilt
label2 = tk.Label(passwordbox, text="Data")
label2.pack()

#output
outputbox = tk.Entry(passwordbox, width=25)
outputbox.pack(pady=5)

#btn
showbutton = tk.Button(passwordbox, text="check", command=show_password)
showbutton.pack(pady=5)

#thm
theme_button = tk.Button(passwordbox, text="change theme", command=switch_theme)
theme_button.pack(pady=10)

root.mainloop()