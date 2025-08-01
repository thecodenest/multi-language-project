import os

class User:
    def __init__(self):
        self.name = ''
        self.email = ''

    def login(self):
        self.name = input("Enter your Name: ")
        self.email = input("Enter your Email: ")

        try:
            with open("user_data.txt", "a") as file:
                file.write(f"{self.name} {self.email}\n")
            print(f"\nLogin Successful! Welcome, {self.name}!\n")
        except IOError:
            print("\u2753 Error: Unable to save user data.")


class Ticket:
    def __init__(self):
        self.bus_name = ''
        self.destination = ''
        self.time = ''
        self.date = ''
        self.payment_method = ''
        self.account_number = ''
        self.account_name = ''
        self.seat_number = 0
        self.ticket_price = 0

    def book_ticket(self):
        # Bus selection
        while True:
            print("\nAvailable Buses:")
            print("1. Daewoo Express")
            print("2. Faisal Movers")
            print("3. Metro Express")
            bus_choice = input("Select a bus (1-3): ")
            if bus_choice == '1':
                self.bus_name = "Daewoo Express"
                break
            elif bus_choice == '2':
                self.bus_name = "Faisal Movers"
                break
            elif bus_choice == '3':
                self.bus_name = "Metro Express"
                break
            else:
                print("❌ Invalid bus selection. Please choose between 1-3.")

        input("\nEnter your Departure City: ")  # Placeholder as in original code

        # Destination selection
        destinations = {
            '1': ("Islamabad", 1900),
            '2': ("Murree", 2500),
            '3': ("Multan", 1850),
            '4': ("Sahiwal", 890),
            '5': ("Faisalabad", 950),
            '6': ("Karachi", 6250)
        }
        while True:
            print("\nAvailable Destinations with Prices:")
            for key, (city, price) in destinations.items():
                print(f"{key}. {city} - Rs. {price}")
            des = input("Select a destination (1-6): ")
            if des in destinations:
                self.destination, self.ticket_price = destinations[des]
                break
            else:
                print("❌ Invalid destination. Please select between 1-6.")

        self.date = input("Enter Date (DD/MM/YYYY): ")

        # Time selection
        times = {
            '1': "09:00 AM",
            '2': "02:00 PM",
            '3': "07:00 PM"
        }
        while True:
            print("\nAvailable Timings:")
            for key, time in times.items():
                print(f"{key}. {time}")
            time_choice = input("Select a time (1-3): ")
            if time_choice in times:
                self.time = times[time_choice]
                break
            else:
                print("❌ Invalid time. Please choose between 1-3.")

        # Seat selection
        available_seats = [5, 10, 15, 10, 6, 8, 9, 20, 25, 30]
        while True:
            print(f"\nAvailable Seats: {available_seats}")
            try:
                seat = int(input("Select a seat number: "))
                if seat in available_seats:
                    self.seat_number = seat
                    break
                else:
                    print("❌ Seat not available. Choose from the list.")
            except ValueError:
                print("❌ Please enter a valid number.")

        # Payment method selection
        payments = {
            '1': "Credit Card",
            '2': "PayPal",
            '3': "JazzCash"
        }
        while True:
            print("\nPayment Methods:")
            for key, method in payments.items():
                print(f"{key}. {method}")
            pay_choice = input("Select a payment method (1-3): ")
            if pay_choice in payments:
                self.payment_method = payments[pay_choice]
                break
            else:
                print("❌ Invalid payment method. Please select between 1-3.")

        self.account_name = input("Enter Account Name: ")
        self.account_number = input("Enter Account Number: ")

        self.save_ticket()
        self.display_ticket()

    def save_ticket(self):
        try:
            with open("tickets.txt", "a") as file:
                file.write(f"Bus: {self.bus_name}, Date: {self.date}, Time: {self.time}, Seat: {self.seat_number}, Payment: {self.payment_method}, Price: Rs. {self.ticket_price}\n")
        except IOError:
            print("\u2753 Error: Unable to save ticket data.")

    def display_ticket(self):
        print("\n---------------------------------------")
        print("|         BUS TICKET RECEIPT          |")
        print("---------------------------------------")
        print(f"| Bus: {self.bus_name}")
        print(f"| Date: {self.date}")
        print(f"| Time: {self.time}")
        print(f"| Seat No: {self.seat_number}")
        print(f"| Payment: {self.payment_method}")
        print(f"| Price: Rs. {self.ticket_price}")
        print("---------------------------------------")


def main():
    user = User()
    ticket = Ticket()

    while True:
        print("                                    ----------------------------------------------")
        print("                                    |  WELCOME TO BUS TICKET RESERVATION  SYSTEM |")
        print("                                    ----------------------------------------------")
        print("1. Login")
        print("2. Book Ticket")
        print("3. Exit")

        choice = input("Select an option: ")

        if choice == '1':
            user.login()
        elif choice == '2':
            ticket.book_ticket()
        elif choice == '3':
            print("\nThank you for using the system!")
            break
        else:
            print("\n\u2753 Invalid choice. Try again.")


if __name__ == "__main__":
    main()
