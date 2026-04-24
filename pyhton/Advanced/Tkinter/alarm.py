import tkinter as tk
from tkinter import END, ACTIVE
import random


def generate_alarms():
    alarmbox.delete(0, END)
    alarms = []
    a = 0
    b = 5
    for _ in range(10):
        minutes = random.randint(a, b)
        time_str = f"07:{minutes:02d}"
        alarms.append(time_str)
        a = b
        b = a + 5
    alarmbox.insert(END, *alarms)
    update_status()


def delete_alarms():
    selected = alarmbox.curselection()
    for index in reversed(selected):
        alarmbox.delete(index)
    update_status()


def open_change_window():
    global newalarm, change_window, selected_index

    selected = alarmbox.curselection()
    if not selected:
        return

    selected_index = selected[0]
    current_alarm = alarmbox.get(selected_index)

    change_window = tk.Toplevel(root)
    change_window.title("Change Alarm")
    change_window.geometry("300x125")
    change_window.iconbitmap('alarm.ico')

    tk.Label(change_window, text="Enter new alarm value:", font=("Arial", 10)).pack(pady=10)

    newalarm = tk.Entry(change_window, width=15, font=("Consolas", 12), justify="center")
    newalarm.insert(0, current_alarm)
    newalarm.pack(pady=5)

    tk.Button(change_window, text="Save", width=15, command=change_alarm).pack(pady=10)


def change_alarm():
    global newalarm, change_window, selected_index

    new_value = newalarm.get().strip()

    if new_value:
        alarmbox.delete(selected_index)
        alarmbox.insert(selected_index, new_value)

    change_window.destroy()
    update_status()


def update_status():
    count = alarmbox.size()
    status_label.config(text=f"Total alarms: {count}")


root = tk.Tk()
root.title("Alarm Clock")
root.geometry("400x500")
root.iconbitmap('alarm.ico')

tk.Label(root, text="Alarm Clock", font=("Arial", 16, "bold")).pack(pady=10)

alarmbox = tk.Listbox(root, width=30, height=10, justify="center",
                      selectmode=tk.EXTENDED, font=("Consolas", 12))
alarmbox.pack(pady=10)

status_label = tk.Label(root, text="Total alarms: 0", font=("Arial", 11))
status_label.pack(pady=5)

btn_generate = tk.Button(root, text="Random alarms", width=25, height=2,
                         command=generate_alarms)
btn_generate.pack(pady=8)

btn_delete = tk.Button(root, text="Delete alarm", width=25, height=2,
                       command=delete_alarms)
btn_delete.pack(pady=8)

btn_change = tk.Button(root, text="Change alarm", width=25, height=2,
                       command=open_change_window)
btn_change.pack(pady=8)

update_status()

root.mainloop()