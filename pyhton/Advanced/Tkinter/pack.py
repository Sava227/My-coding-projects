import tkinter as tk

window = tk.Tk()
window.title("Vidjets")
window.geometry("450x450")

frame_pack = tk.LabelFrame(window, text="Pack", padx=10, pady=10)
frame_pack.pack(padx=30, pady=20, fill="x")

btn10 = tk.Button(frame_pack, text="Button10", bg="black", fg="white", highlightbackground="black")
btn11 = tk.Button(frame_pack, text="Button11", bg="black", fg="white", highlightbackground="black")
btn12 = tk.Button(frame_pack, text="Button12", bg="black", fg="white", highlightbackground="black")

btn10.pack(side="left", expand=True, padx=5, pady=5)
btn11.pack(side="left", expand=True, padx=5, pady=5)
btn12.pack(side="left", expand=True, padx=5, pady=5)

frame_grid = tk.LabelFrame(window, text="Grid", padx=10, pady=10, height=100)
frame_grid.pack(padx=30, pady=20, fill="x")
frame_grid.pack_propagate(False)

frame_place = tk.LabelFrame(window, text="Place", padx=10, pady=10, height=100)
frame_place.pack(padx=30, pady=20, fill="x")
frame_place.pack_propagate(False)

window.mainloop()