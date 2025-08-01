def check_sugar_level(name):
    sugar = float(input(f"{name}, please enter your sugar level (mg/dL): "))
    if sugar < 70:
        print("Low blood sugar. Please consult your doctor.")
    elif 70 <= sugar <= 140:
        print("Normal blood sugar.")
    else:
        print("High blood sugar. Please consult your doctor.")

def check_blood_pressure(name):
    bp = input(f"{name}, please enter your blood pressure (systolic/diastolic): ")
    try:
        systolic, diastolic = map(int, bp.split('/'))
        if systolic < 90 or diastolic < 60:
            print("Low blood pressure.")
        elif 90 <= systolic <= 120 and 60 <= diastolic <= 80:
            print("Normal blood pressure.")
        else:
            print("High blood pressure.")
    except:
        print("Invalid input. Please enter as systolic/diastolic (e.g., 120/80).")

def check_pulse_rate(name):
    pulse = int(input(f"{name}, please enter your pulse rate (bpm): "))
    if pulse < 60:
        print("Low pulse rate.")
    elif 60 <= pulse <= 100:
        print("Normal pulse rate.")
    else:
        print("High pulse rate.")

def check_bmi(name):
    height = float(input(f"{name}, please enter your height in meters: "))
    weight = float(input("Enter your weight in kg: "))
    bmi = weight / (height ** 2)
    print(f"Your BMI is {bmi:.2f}")
    if bmi < 18.5:
        print("Underweight")
    elif 18.5 <= bmi < 25:
        print("Normal weight")
    elif 25 <= bmi < 30:
        print("Overweight")
    else:
        print("Obese")

def check_temperature(name):
    temp = float(input(f"{name}, please enter your temperature in Celsius: "))
    if temp < 36.1:
        print("Below normal temperature.")
    elif 36.1 <= temp <= 37.2:
        print("Normal temperature.")
    else:
        print("Fever detected.")

def save_to_file(plan):
    choice = input("Do you want to save this diet plan to a file? (y/n): ").lower()
    if choice == 'y':
        with open("diet_plan.txt", "w") as file:
            file.write(plan)
        print("Diet plan saved to diet_plan.txt.")

def diet_plan(name):
    print("\n\t** Health Advisor Diet Plan**\n")
    print("1. Heart Disease")
    print("2. Temperature (Fever)")
    print("3. Diabetes")
    print("4. Blood Pressure")
    print("5. Food Poisoning")
    print("6. Common Cold")
    print("7. Healthy Diet")
    choice = int(input("Select a health condition: "))

    plan = ""
    if choice == 1:
        op = input("Are you currently taking any medication? (y/n): ")
        specific = input("You want specific diet plan-(y/n): ")
        if specific == "n":
            plan = (
                "Diet Plan for Heart Disease:\n"
                "1. Eat lots of different fruits and veggies every day.\n"
                "2. Choose whole grains like brown rice and whole wheat bread instead of white bread or pasta.\n"
                "3. Pick lean proteins like chicken, fish, or beans. They're better for your heart.\n"
                "4. Eat good fats, like the ones in fish, nuts, and avocados. They're healthy for your heart.\n"
                "5. Cut down on salty foods and snacks like chips. They can make your heart work harder.\n"
                "6. Also, add exercise to your routine to keep your heart healthy and strong.\n"
            )
        else:
            plan = (
                "Diet Plan for Heart Patients:\n"
                "Breakfast: Start your day with a light meal like whole grain toast with avocado\n"
                "Mid-morning snack: A handful of unsalted nuts\n"
                "Lunch: Grilled fish with a side of mixed greens\n"
                "Afternoon snack: A small bowl of berries\n"
                "Dinner: Eat light and healthy dinner, such as lean protein with steamed vegetables\n"
                "Remember to limit salt and drink plenty of water throughout the day.\n"
            )
        print(plan)
        save_to_file(plan)

    elif choice == 2:
        specific = input("You want specific diet plan-(y/n): ")
        if specific == "n":
            plan = (
                "Diet Plan for Fever:\n"
                "1. Drink lots of fluids like water, herbal teas, and clear broths.\n"
                "2. Eat light and easy-to-digest foods like soups, plain crackers, toast, rice, and bananas.\n"
                "3. Include healthy foods like fruits, vegetables (cooked or steamed), and lean proteins (chicken, fish).\n"
                "4. Avoid heavy, greasy, spicy, or fatty foods that are hard to digest and might upset your stomach.\n"
                "5. Rest a lot to help your body recover and eat small, frequent meals if you don't feel very hungry.\n"
            )
        else:
            plan = (
                "Diet Plan for Fever:\n"
                "Breakfast: Start your day with something light and easy to digest like toast and bananas\n"
                "Mid-morning snack: Drink plenty of fluids like water or herbal tea\n"
                "Lunch: Have a bowl of clear soup or broth with some plain crackers\n"
                "Afternoon snack: A small serving of fruits\n"
                "Dinner: Opt for a light meal like steamed vegetables and lean protein such as chicken or fish\n"
                "Remember to rest a lot and stay hydrated throughout the day.\n"
            )
        print(plan)
        save_to_file(plan)

    elif choice == 3:
        sugarlevel = input(f"{name}, Do you have low or high sugar? ").lower()
        if sugarlevel == "low":
            specific = input("You want specific diet plan-(y/n): ")
            if specific == "n":
                plan = (
                    "Diet Plan for Low Blood Sugar (Diabetes):\n"
                    "1. Monitor carbohydrate intake, focusing on whole grains.\n"
                    "2. Include lean proteins and healthy fats.\n"
                    "3. Regularly monitor blood sugar levels.\n"
                    "4. Also, add exercise to your routine to maintain your sugar level.\n"
                )
            else:
                plan = (
                    "Diet Plan for Low Blood Sugar:\n"
                    "Breakfast: Start your day with a balanced meal like whole grain toast with avocado and a boiled egg\n"
                    "Mid-morning snack: A small apple with a spoonful of peanut butter\n"
                    "Lunch: Grilled chicken salad with mixed greens, cherry tomatoes, and a whole grain roll\n"
                    "Afternoon snack: A piece of cheese with whole grain crackers\n"
                    "Dinner: Baked and steamed vegetables\n"
                    "Remember to eat regular meals and snacks to maintain stable blood sugar levels.\n"
                    "Include exercise in your routine to help manage your condition.\n"
                )
        elif sugarlevel == "high":
            op = input("Are you currently taking any medication? (y/n): ")
            specific = input("You want specific diet plan-(y/n): ")
            if specific == "n":
                plan = (
                    "Diet Plan for High Blood Sugar:\n"
                    "1. Control carbohydrate intake, focusing on whole grains, vegetables, and fruits.\n"
                    "2. Monitor portion sizes and avoid sugary beverages and snacks.\n"
                    "3. Include lean proteins and healthy fats.\n"
                    "4. Regularly monitor blood sugar levels.\n"
                    "5. Also, add exercise to your routine to maintain your sugar level.\n"
                )
            else:
                plan = (
                    "Diet Plan for High Blood Sugar:\n"
                    "Breakfast: Opt for whole grain cereals with low-fat milk\n"
                    "Mid-morning snack: A small handful of nuts\n"
                    "Lunch: Include lean proteins like grilled chicken with a side of vegetables\n"
                    "Afternoon snack: Sliced vegetables with hummus\n"
                    "Dinner: Baked fish with a salad\n"
                    "Regular monitoring of blood sugar levels is important.\n"
                    "Include exercise in your routine.\n"
                )
        print(plan)
        save_to_file(plan)

    elif choice == 4:
        bplevel = input(f"{name}, Do you have low or high blood pressure? ").lower()
        if bplevel == "low":
            specific = input("You want specific diet plan-(y/n): ")
            if specific == "n":
                plan = (
                    "Diet Plan for Low Blood Pressure:\n"
                    "1. Eat small, frequent meals to avoid drops in blood pressure.\n"
                    "2. Include more salty foods in your diet.\n"
                    "3. Drink plenty of fluids, especially water.\n"
                    "4. Also, add exercise to your routine to maintain your pressure.\n"
                )
            else:
                plan = (
                    "Diet Plan for Low Blood Pressure (Hypotension):\n"
                    "Breakfast: Start your day with a small portion of salted nuts and whole grain toast\n"
                    "Mid-morning snack: A small glass of tomato juice with a pinch of salt\n"
                    "Lunch: Grilled chicken salad with a light dressing and a side of salted whole grain crackers\n"
                    "Afternoon snack: A handful of salted nuts.\n"
                    "Dinner: Baked fish/chicken with a side of vegetables seasoned with a pinch of salt\n"
                    "Eat frequent meals throughout the day, drink plenty of fluids, and include more salty foods in your diet.\n"
                    "Add exercise to your routine to help maintain your blood pressure.\n"
                )
        elif bplevel == "high":
            specific = input("You want specific diet plan-(y/n): ")
            if specific == "n":
                plan = (
                    "Diet Plan for High Blood Pressure:\n"
                    "1. Eat a variety of fruits, vegetables, whole grains, lean proteins, and low-fat dairy.\n"
                    "2. Reduce sodium intake by avoiding salty foods and snacks.\n"
                    "3. Limit the intake of saturated fats.\n"
                    "4. Also, add exercise to your routine to maintain your pressure.\n"
                )
            else:
                plan = (
                    "Diet Plan for High Blood Pressure:\n"
                    "Breakfast: Start your day with a bowl of oatmeal topped with fresh berries\n"
                    "Mid-morning snack: A small handful of unsalted nuts\n"
                    "Lunch: Grilled chicken breast with a side of steamed vegetables\n"
                    "Afternoon snack: Sliced cucumber and carrot sticks\n"
                    "Dinner: Baked salmon with a quinoa salad\n"
                    "Remember to avoid salty foods and snacks, and include regular exercise in your routine.\n"
                )
        print(plan)
        save_to_file(plan)

    elif choice == 5:
        plan = (
            "Diet Plan for Food Poisoning:\n"
            "1. Drink plenty of fluids to stay hydrated (water, clear broths, oral rehydration solutions).\n"
            "2. Eat bland, easy-to-digest foods like bananas, rice, applesauce, and toast (the BRAT diet).\n"
            "3. Avoid dairy, fatty, spicy, or high-fiber foods until you recover.\n"
            "4. Rest as much as possible and avoid caffeine and alcohol.\n"
        )
        print(plan)
        save_to_file(plan)
    elif choice == 6:
        plan = (
            "Diet Plan for Common Cold:\n"
            "1. Drink plenty of fluids (water, herbal teas, clear broths).\n"
            "2. Eat light, nutritious meals including fruits and vegetables rich in vitamin C.\n"
            "3. Include warm soups and broths to soothe your throat.\n"
            "4. Avoid processed foods and sugary snacks.\n"
        )
        print(plan)
        save_to_file(plan)
    elif choice == 7:
        plan = (
            "Healthy Diet Plan:\n"
            "1. Eat a variety of foods from all food groups: fruits, vegetables, grains, protein, and dairy.\n"
            "2. Limit added sugars, salt, and saturated fats.\n"
            "3. Drink plenty of water throughout the day.\n"
            "4. Include regular physical activity in your routine.\n"
        )
        print(plan)
        save_to_file(plan)
    else:
        print("Invalid choice.")

def mental_health():
    print("\n--- Mental Health Tips ---")
    print("1. Practice mindfulness and meditation.")
    print("2. Maintain a healthy sleep schedule.")
    print("3. Stay connected with friends and family.")
    print("4. Engage in regular physical activity.")
    print("5. Seek professional help if you feel persistently sad or anxious.\n")

def first_aid():
    print("\n--- First Aid Description ---")
    print("1. For minor cuts: Clean the wound, apply an antiseptic, and cover with a bandage.")
    print("2. For burns: Cool the burn under running water, cover with a sterile dressing.")
    print("3. For choking: Perform the Heimlich maneuver if needed.")
    print("4. For fainting: Lay the person down and elevate their legs.")
    print("5. In all emergencies, call for professional medical help.\n")

def basic_medicine():
    print("\n--- Basic Medicine Information ---")
    print("1. Paracetamol: Used for pain relief and fever reduction.")
    print("2. Ibuprofen: Used for pain, inflammation, and fever.")
    print("3. ORS (Oral Rehydration Solution): Used for dehydration.")
    print("4. Antihistamines: Used for allergies.")
    print("Always consult a doctor before taking any medication.\n")

def main():
    while True:
        print("-" * 120)
        print("\n\t\t\t\tWELCOME TO HEALTH ADVISOR SYSTEM\t\t\n")
        print("-" * 120)
        print("         \t MAIN MENU\n\t")
        print("1-Daily routine checkup")
        print("2-Diet plan")
        print("3-Mental Health")
        print("4-First Aid Description")
        print("5-Basic medicine")
        print("0-Exit")
        name = input("\nEnter your name: ")

        try:
            section = int(input("\nSelect the section you want to check: "))
        except ValueError:
            print("Invalid input. Please enter a number.")
            continue

        if section == 0:
            print("Thank you for using Health Advisor System. Stay healthy!")
            break

        if section == 1:
            print("\n1-Sugar level")
            print("2-Blood pressure level")
            print("3-Pulse rate")
            print("4-Height & weight")
            print("5-Temperature")
            try:
                option = int(input("\nSelect any option: "))
            except ValueError:
                print("Invalid input.")
                continue

            if option == 1:
                check_sugar_level(name)
            elif option == 2:
                check_blood_pressure(name)
            elif option == 3:
                check_pulse_rate(name)
            elif option == 4:
                check_bmi(name)
            elif option == 5:
                check_temperature(name)
            else:
                print("Invalid option")
        elif section == 2:
            diet_plan(name)
        elif section == 3:
            mental_health()
        elif section == 4:
            first_aid()
        elif section == 5:
            basic_medicine()
        else:
            print("Invalid section.")

        again = input("Do you want to perform another operation? (y/n): ").lower()
        if again != 'y':
            print("Thank you for using Health Advisor System. Stay healthy!")
            break

if __name__ == "__main__":
    main()
