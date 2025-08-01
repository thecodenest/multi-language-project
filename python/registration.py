import tkinter as tk
from tkinter import messagebox

users = {}

# Register function
def register():
    username = reg_username.get()
    password = reg_password.get()
    if username in users:
        messagebox.showerror("Error", "Username already exists!")
    else:
        users[username] = password
        messagebox.showinfo("Success", "Registration successful!")

# Login function
def login():
    username = login_username.get()
    password = login_password.get()
    if username in users and users[username] == password:
        messagebox.showinfo("Success", f"Welcome, {username}!")
    else:
        messagebox.showerror("Error", "Invalid username or password!")

# Main window
root = tk.Tk()
root.title("Login and Registration Form")
root.geometry("400x300")

# --- Registration Frame ---
tk.Label(root, text="Register", font=("Helvetica", 16)).pack()

tk.Label(root, text="Username").pack()
reg_username = tk.Entry(root)
reg_username.pack()

tk.Label(root, text="Password").pack()
reg_password = tk.Entry(root, show='*')
reg_password.pack()

tk.Button(root, text="Register", command=register).pack(pady=5)

# --- Login Frame ---
tk.Label(root, text="Login", font=("Helvetica", 16)).pack(pady=10)

tk.Label(root, text="Username").pack()
login_username = tk.Entry(root)
login_username.pack()

tk.Label(root, text="Password").pack()
login_password = tk.Entry(root, show='*')
login_password.pack()

tk.Button(root, text="Login", command=login).pack(pady=5)

root.mainloop()
