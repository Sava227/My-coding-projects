import tkinter as tk
from tkinter import ttk

def color_generate(value=None):
    red = red_scale.get()
    green = green_scale.get()
    blue = blue_scale.get()

    color = f'#{red:02x}{green:02x}{blue:02x}'

    frame_color.config(bg=color)
    color_label.config(text=color, fg=get_inverted_color(red, green, blue))

    color_entry.delete(0, tk.END)
    color_entry.insert(0, color)

def get_inverted_color(r, g, b):
    inverted_r = 255 - r
    inverted_g = 255 - b
    inverted_b = 255 - g
    return f'#{inverted_r:02x}{inverted_g:02x}{inverted_b:02x}'

root = tk.Tk()
root.title("Color picker")
root.geometry("580x320")
root.resizable(False, False)

frame_RGB = tk.LabelFrame(root, text="Choose colors", height=250, width=250)
frame_RGB.place(x=20, y=20)

frame_color = tk.LabelFrame(root, text="Color: ", height=250, width=250)
frame_color.place(x=300, y=20)

color_label = tk.Label(frame_color,
                       text="#000000",
                       font=('Arial', 15, 'bold'),
                       height=8,
                       width=16)
color_label.place(relx=0.5, rely=0.4, anchor='center')

color_entry = tk.Entry(frame_color, font=('Consolas', 12), width=20, justify='center')
color_entry.place(relx=0.5, rely=0.8, anchor='center')

red_scale = tk.Scale(frame_RGB, from_=0, to=255, orient=tk.HORIZONTAL,
                     length=200, width=20, label="Red", command=color_generate)
red_scale.place(x=20, y=20)

green_scale = tk.Scale(frame_RGB, from_=0, to=255, orient=tk.HORIZONTAL,
                       length=200, width=20, label="Green", command=color_generate)
green_scale.place(x=20, y=90)

blue_scale = tk.Scale(frame_RGB, from_=0, to=255, orient=tk.HORIZONTAL,
                      length=200, width=20, label="Blue", command=color_generate)
blue_scale.place(x=20, y=160)

red_scale.set(153)
green_scale.set(255)
blue_scale.set(139)

color_generate()
root.mainloop()