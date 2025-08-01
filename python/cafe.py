from tkinter import *
from datetime import datetime

# Splash Screen Function
def show_splash(main):
    splash = Toplevel(main)
    splash.overrideredirect(True)
    splash.geometry("400x200+500+300")
    splash.configure(bg="#2c3e50")
    Label(splash, text="☕ Welcome to Café Bliss ☕", font=("Helvetica", 18, "bold"), fg="white", bg="#2c3e50").pack(expand=True)
    splash.after(2000, splash.destroy)

# Main Application Window
def start_cafe_system(root):
    root.deiconify()  # Show the main window
    root.title("Café Management System")
    root.geometry("700x700")
    root.configure(bg="#f7f0e8")  # Initial Light Mode

    light_colors = {
        "bg": "#f7f0e8", "fg": "#2e2e2e", "btn": "#8fb996", "btn_txt": "white",
        "reset": "#d96c75", "exit": "#444", "font": "black"
    }

    dark_colors = {
        "bg": "#2c3e50", "fg": "#ecf0f1", "btn": "#2980b9", "btn_txt": "white",
        "reset": "#c0392b", "exit": "#7f8c8d", "font": "white"
    }

    current_mode = {"mode": "light"}
    menu = {'Coffee': 3.00, 'Tea': 2.50, 'Sandwich': 5.00, 'Cake': 4.00, 'Juice': 3.50}
    quantities = {}

    def apply_theme(colors):
        root.configure(bg=colors['bg'])
        for widget in root.winfo_children():
            if isinstance(widget, (Frame, Label, Button, Entry, Text)):
                try:
                    widget.configure(bg=colors['bg'], fg=colors['fg'])
                except:
                    pass

    def toggle_mode():
        if current_mode['mode'] == 'light':
            apply_theme(dark_colors)
            current_mode['mode'] = 'dark'
        else:
            apply_theme(light_colors)
            current_mode['mode'] = 'light'

    def calculate_total():
        total = 0
        for item, var in quantities.items():
            qty = var.get()
            if qty.isdigit():
                total += int(qty) * menu[item]
        total_var.set(f"${total:.2f}")

    def generate_receipt():
        receipt_text.delete("1.0", END)
        receipt_text.insert(END, "      🍰 Café Receipt ☕\n", "center")
        receipt_text.insert(END, f"Date: {datetime.now().strftime('%Y-%m-%d %H:%M:%S')}\n")
        receipt_text.insert(END, "-" * 40 + "\n")
        
        total = 0
        for item, var in quantities.items():
            qty = var.get()
            if qty.isdigit() and int(qty) > 0:
                cost = int(qty) * menu[item]
                receipt_text.insert(END, f"{item:<10} x {qty} = ${cost:.2f}\n")
                total += cost

        receipt_text.insert(END, "-" * 40 + "\n")
        receipt_text.insert(END, f"Total Bill: ${total:.2f}\n")
        receipt_text.insert(END, "🌟 Thank you! Visit again. 🌟\n")

    def reset():
        for var in quantities.values():
            var.set("0")
        total_var.set("")
        receipt_text.delete("1.0", END)

    Label(root, text="Café Menu", font=("Comic Sans MS", 22, "bold"), bg=light_colors['bg'], fg="#5a3e36").pack(pady=10)

    menu_frame = Frame(root, bg=light_colors['bg'])
    menu_frame.pack()
    for item, price in menu.items():
        row = Frame(menu_frame, bg=light_colors['bg'])
        row.pack(pady=5)
        Label(row, text=f"{item} (${price:.2f})", font=("Verdana", 12), width=18, anchor='w', bg=light_colors['bg']).pack(side=LEFT)
        qty_var = StringVar(value="0")
        quantities[item] = qty_var
        Entry(row, textvariable=qty_var, width=5, font=("Verdana", 12)).pack(side=LEFT)

    btn_frame = Frame(root, bg=light_colors['bg'])
    btn_frame.pack(pady=10)
    Button(btn_frame, text="Calculate Total", command=calculate_total, width=18, bg=light_colors['btn'], fg=light_colors['btn_txt'], font=("Verdana", 10, "bold")).pack(side=LEFT, padx=5)
    Button(btn_frame, text="Generate Receipt", command=generate_receipt, width=18, bg=light_colors['btn'], fg=light_colors['btn_txt'], font=("Verdana", 10, "bold")).pack(side=LEFT, padx=5)
    Button(btn_frame, text="Toggle Dark Mode", command=toggle_mode, width=18, bg="#34495e", fg="white", font=("Verdana", 10, "bold")).pack(side=LEFT, padx=5)

    Label(root, text="Total:", font=('Verdana', 12), bg=light_colors['bg']).pack()
    total_var = StringVar()
    Entry(root, textvariable=total_var, font=('Verdana', 12), state='readonly', justify='center').pack()

    Label(root, text="Receipt", font=('Verdana', 12, 'bold'), bg=light_colors['bg'], fg="#5a3e36").pack(pady=5)
    receipt_text = Text(root, height=10, width=60, font=('Courier New', 10))
    receipt_text.tag_configure("center", justify='center')
    receipt_text.pack()

    bottom_frame = Frame(root, bg=light_colors['bg'])
    bottom_frame.pack(pady=10)
    Button(bottom_frame, text="Reset", command=reset, width=15, bg=light_colors['reset'], fg="white", font=("Verdana", 10)).pack(side=LEFT, padx=10)
    Button(bottom_frame, text="Exit", command=root.quit, width=15, bg=light_colors['exit'], fg="white", font=("Verdana", 10)).pack(side=LEFT, padx=10)

# Run splash then main
main = Tk()
main.withdraw()  # Hide main window
show_splash(main)
main.after(2200, lambda: start_cafe_system(main))  # Pass main window
main.mainloop()
