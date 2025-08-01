#include <iostream>
#include <fstream>
#include <string>
using namespace std;

void checkSugarLevel(string name);
void checkBloodPressure(string name);
void checkPulseRate(string name);
void checkBMI(string name);
void checkTemperature(string name);

int main()
 {
    char name[100];
    char answer;
    int section;
    char a;
    string op;

    do {
       
	   cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	                                 cout<<"\n\t\t\t\t \t \t \t \t WELCOME TO HEALTH ADVISOR SYSTEM\t\t\n\t\t\t"<<endl;
	    cout<<"----------------------------------------------------------------------------------------------------------------------------------------------------------------------------"<<endl;
	    cout<<"         "<<"\t MAIN MENU\n\t"<<endl;
	    
        cout << "1-Daily routine checkup" << endl;
        cout << "2-Diet plan" << endl;
        cout << "3-Mental Health" << endl;
        cout << "4-First Aid Description"<<endl;
        cout << "5-basic medicine" << endl;
        cout << "\nEnter your name: ";
        cin.ignore();
        cin.getline(name,100);
		  cout << "\nSelect the section you want to check:";
        cin >> section;

        switch (section)
		 {
            case 1: 
			{
                int option;
                cout << "\n1-Sugar level" << endl;
                cout << "2-Blood pressure level" << endl;
                cout << "3-Pulse rate" << endl;
                cout << "4-Height & weight" << endl;
                cout << "5-Temperature" << endl;
                cout << "\nSelect any option:";
                cin >> option;

                switch (option)
				 {
                    case 1:
                        checkSugarLevel(name);
                        break;
                    case 2:
                        checkBloodPressure(name);
                        break;
                    case 3:
                        checkPulseRate(name);
                        break;
                    case 4:
                        checkBMI(name);
                        break;
                    case 5:
                        checkTemperature(name);
                        break;
                    default:
                        cout << "Invalid option" << endl;
                }
                break;
            }
            case 2:
			 {
                string sugarlevel;
                int  choice;
                string bplevel;
                cout << "\n\t** Health Advisor Diet Plan**\n\t" << endl;
                cout << "1. Heart Disease" << endl;
                cout << "2. Temperature (Fever)" << endl;
                cout << "3. Diabetes" << endl;
                cout << "4. Blood Pressure" << endl;
                cout << "5. Food Poisoning" << endl;
                cout << "6. Common Cold" << endl;
                cout << "7. Healthy Diet" << endl;
                cout << "Select a health condition: ";
                cin >> choice;
                	ofstream file("diet_plan.txt");

                switch (choice)
				 {
                    case 1:
                    	 cout << "Diet Plan for Heart Disease:\n";
                        cout << name << " Are you currently taking any medication? ";
                        cin >> op;
                        cout<<"You want specific diet plan-(y/n)";
                        cin>>op;
                         if (op == "n")
                        {
                        	 cout << "\n Diet Plan for Heart Disease:\n";
                        cout << "1. Eat lots of different fruits and veggies every day." << endl;
                        cout << "2. Choose whole grains like brown rice and whole wheat bread instead of white bread or pasta." << endl;
                        cout << "3. Pick lean proteins like chicken, fish, or beans. They're better for your heart." << endl;
                        cout << "4. Eat good fats, like the ones in fish, nuts, and avocados. They're healthy for your heart." << endl;
                        cout << "5. Cut down on salty foods and snacks like chips. They can make your heart work harder." << endl;
                        cout << "6. Also, add exercise to your routine to keep your heart healthy and strong." << endl;
                        cout<<"do you want to print that diet plan(y/n)";
cin>>a;
if(a=='y'){
	 file << "1. Eat lots of different fruits and veggies every day." << endl;
                        file << "2. Choose whole grains like brown rice and whole wheat bread instead of white bread or pasta." << endl;
                        file << "3. Pick lean proteins like chicken, fish, or beans. They're better for your heart." << endl;
                        file << "4. Eat good fats, like the ones in fish, nuts, and avocados. They're healthy for your heart." << endl;
                        file << "5. Cut down on salty foods and snacks like chips. They can make your heart work harder." << endl;
                        file << "6. Also, add exercise to your routine to keep your heart healthy and strong." << endl;
						}
						if(a=='n'){
	cout<<"okay!"<<endl;
}
}
						else
						{
							cout << "\nDiet Plan for Heart Patients:\n";
cout << "Breakfast: Start your day with a light meal like whole grain toast with avocado\n";
cout << "Mid-morning snack: A handful of unsalted nuts\n";
cout << "Lunch: Grilled fish with a side of mixed greens\n";
cout << "Afternoon snack: A small bowl of berries\n";
cout << "Dinner: Eat light and healthy dinner, such as lean protein with steamed vegetables\n";
cout << "Remember to limit salt and drink plenty of water throughout the day.\n";
	cout<<"do you want to print that diet plan(y/n)";
cin>>a;
if(a=='y'){
		file << "\nDiet Plan for Heart Patients:\n";
file<< "Breakfast: Start your day with a light meal like whole grain toast with avocado\n";
file << "Mid-morning snack: A handful of unsalted nuts\n";
file << "Lunch: Grilled fish with a side of mixed greens\n";
file << "Afternoon snack: A small bowl of berries\n";
file << "Dinner: Eat light and healthy dinner, such as lean protein with steamed vegetables\n";
file << "Remember to limit salt and drink plenty of water throughout the day.\n";
}
if(a=='n'){
	cout<<"okay!"<<endl;
}
	
break;
 
						}
                        break;
                    case 2:
                    	
                    	 cout << "Diet Plan for Fever:\n";
                    	  cout<<"You want specific diet plan-(y/n)";
                        cin>>op;
                         if (op == "n")
                        {
                        	
                  cout << "\nDiet Plan for Fever:\n";
cout << "1. Drink lots of fluids like water, herbal teas, and clear broths.\n";
cout << "2. Eat light and easy-to-digest foods like soups, plain crackers, toast, rice, and bananas.\n";
cout << "3. Include healthy foods like fruits , vegetables (cooked or steamed), and lean proteins (chicken, fish).\n";
cout << "4. Avoid heavy, greasy, spicy, or fatty foods that are hard to digest and might upset your stomach.\n";
cout << "5. Rest a lot to help your body recover and eat small, frequent meals if you don't feel very hungry.\n";

cout<<"do you want to print that diet plan(y/n)";
cin>>a;
if(a=='y'){

file << "1. Drink lots of fluids like water, herbal teas, and clear broths.\n";
file << "2. Eat light and easy-to-digest foods like soups, plain crackers, toast, rice, and bananas.\n";
file << "3. Include healthy foods like fruits , vegetables (cooked or steamed), and lean proteins (chicken, fish).\n";
file << "4. Avoid heavy, greasy, spicy, or fatty foods that are hard to digest and might upset your stomach.\n";
file << "5. Rest a lot to help your body recover and eat small, frequent meals if you don't feel very hungry.\n";	
}
if(a=='n'){
	cout<<"okay!"<<endl;
}
}
else
{

	cout << "\nDiet Plan for Fever:\n";
cout << "Breakfast: Start your day with something light and easy to digest like toast and bananas\n";
cout << "Mid-morning snack: Drink plenty of fluids like water or herbal tea\n";
cout << "Lunch: Have a bowl of clear soup or broth with some plain crackers\n";
cout << "Afternoon snack: A small serving of fruits \n";
cout << "Dinner: Opt for a light meal like steamed vegetables and lean protein such as chicken or fish\n";
cout << "Remember to rest a lot and stay hydrated throughout the day.\n";
	cout<<"do you want to print that diet plan(y/n)";
cin>>a;
if(a=='y'){
		file << "\nDiet Plan for Fever:\n";
file<< "Breakfast: Start your day with something light and easy to digest like toast and bananas\n";
file<< "Mid-morning snack: Drink plenty of fluids like water or herbal tea\n";
file<< "Lunch: Have a bowl of clear soup or broth with some plain crackers\n";
file<< "Afternoon snack: A small serving of fruits \n";
file<< "Dinner: Opt for a light meal like steamed vegetables and lean protein such as chicken or fish\n";
file<< "Remember to rest a lot and stay hydrated throughout the day.\n";
}
if(a=='n'){
	cout<<"okay!"<<endl;
}
break;
}
break;

                        
                    case 3: 
					cout << "\nDiet Plan for Diabetes:\n";
                        cout << name << " Do you have low or high sugar? ";
                        cin >> sugarlevel;
                        if (sugarlevel == "low")
						 {
						 	 cout<<"You want specific diet plan-(y/n)";
                        cin>>op;
                         if (op == "n"){
                            cout << "\n Diet Plan for Low Blood Sugar (Diabetes):\n";
                            cout << "1. Monitor carbohydrate intake, focusing on whole grains .\n";
                            cout << "2. Include lean proteins and healthy fats.\n";
                            cout << "3. Regularly monitor blood sugar levels.\n";
                            cout << "4. Also, add exercise to your routine to maintain your sugar level.\n";
                        }
                        else{
                        	cout << "Diet Plan for Low Blood Sugar :\n";
cout << "\nBreakfast: Start your day with a balanced meal like whole grain toast with avocado and a boiled egg\n";
cout << "Mid-morning snack: A small apple with a spoonful of peanut butter\n";
cout << "Lunch: Grilled chicken salad with mixed greens, cherry tomatoes, and a whole grain roll\n";
cout << "Afternoon snack: A piece of cheese with whole grain crackers\n";
cout << "Dinner: Baked  and steamed vegetables\n";
cout << "Remember to eat regular meals and snacks to maintain stable blood sugar levels. \n";
cout<<" include exercise in your routine to help manage your condition.\n";
					}
                        } 
						else if (sugarlevel == "high") 
						{
                            cout << name << " Are you currently taking any medication? ";
                            cin >> op;
                            	 cout<<"You want specific diet plan-(y/n)";
                        cin>>op;
                        
                         if (op == "n"){
                            cout << "\nDiet Plan for High Blood Sugar :\n";
                            cout << "1. Control carbohydrate intake, focusing on whole grains, vegetables, and fruits.\n";
                            cout << "2. Monitor portion sizes and avoid sugary beverages and snacks.\n";
                            cout << "3. Include lean proteins and healthy fats.\n";
                            cout << "4. Regularly monitor blood sugar levels.\n";
                            cout << "5. Also, add exercise to your routine to maintain your sugar level.\n";
							}

						else 
						{
                cout << "\nDiet Plan for High Blood Sugar :\n";
                                cout << "Breakfast: Opt for whole grain cereals with low-fat milk\n";
                                cout << "Mid-morning snack: A small handful of nuts\n";
                                cout << "Lunch: Include lean proteins like grilled chicken with a side of vegetables\n";
                                cout << "Afternoon snack: Sliced vegetables with hummus\n";
                                cout << "Dinner: Baked fish with a salad\n";
                                cout << "Regular monitoring of blood sugar levels is important.\n"; 
								cout<<"Include exercise in your routine .\n";
                        }
                    }
                        break;
                    case 4:
                    	 cout << "\nDiet Plan for Blood Pressure:\n";
                       cout << name << " Do you have low or high blood pressure? ";
                        cin >> bplevel;
                        if (bplevel == "low") {
                            cout << "You want specific diet plan-(y/n): ";
                            cin >> op;
                            if (op == "n") {
                                cout << "\nDiet Plan for Low Blood Pressure:\n";
                                cout << "1. Eat small, frequent meals to avoid drops in blood pressure.\n";
                                cout << "2. Include more salty foods in your diet.\n";
                                cout << "3. Drink plenty of fluids, especially water.\n";
                                cout << "4. Also, add exercise to your routine to maintain your pressure.\n";
                            } else {
                                cout << "\nDiet Plan for Low Blood Pressure (Hypotension):\n";
                                cout << "Breakfast: Start your day with a small portion of salted nuts and whole grain toast \n";
                                cout << "Mid-morning snack: A small glass of tomato juice with a pinch of salt\n";
                                cout << "Lunch: Grilled chicken salad with a light dressing and a side of salted whole grain crackers\n";
                                cout << "Afternoon snack: A handful of salted nuts.\n";
                                cout << "Dinner: Baked fish/chicken  with a side of vegetables seasoned with a pinch of salt\n";
                                cout << "Eat frequent meals throughout the day, drink plenty of fluids, and include more salty foods in your diet.\n ";
								cout<<" Add exercise to your routine to help maintain your blood pressure.\n";
                            }
                        } else if (bplevel == "high") {
                            cout << "You want specific diet plan-(y/n): ";
                            cin >> op;
                            if (op == "n") {
                                cout << "\n Diet Plan for High Blood Pressure:\n";
                                cout << "1. Eat a variety of fruits, vegetables, whole grains, lean proteins, and low-fat dairy.\n";
                                cout << "2. Reduce sodium intake by avoiding salty foods and snacks.\n";
                                cout << "3. Limit the intake of saturated  fats.\n";
                                cout << "4. Also, add exercise to your routine to maintain your pressure.\n";
                            } else {
                                cout << "\nDiet Plan for High Blood Pressure :\n";
                                cout << "Breakfast: Start your day with a bowl of oatmeal topped with fresh berries\n";
                                cout << "Mid-morning snack: A small handful of unsalted nuts\n";
                                cout << "Lunch: Grilled chicken breast with a side of steamed vegetables\n";
                                cout << "Afternoon snack: Sliced cucumber.\n";
                                cout << "Dinner: Baked fish with a salad\n";
                                cout << "Eat a variety of fruits, vegetables, whole grains, lean proteins, and low-fat dairy.\n";  
								 cout<<"Include exercise in your routine to help maintain your blood pressure.\n";
                            }
                        }
                        break;
                    case 5:
                        cout << "\nDiet Plan for Food Poisoning:\n";
                        cout << "1. Eat easily digestible foods like plain crackers, toast, bananas, and rice .\n";
                        cout << "2. Drink plenty of clear fluids to stay hydrated.\n";
                        cout << "3. Avoid dairy, fatty, spicy, and high-fiber foods until symptoms improve.\n";
                        cout<<"do you want to print that diet plan(y/n)";
cin>>a;
if(a=='y'){
	 file << "\nDiet Plan for Food Poisoning:\n";
                        file << "1. Eat easily digestible foods like plain crackers, toast, bananas, and rice .\n";
                       file << "2. Drink plenty of clear fluids to stay hydrated.\n";
                        file << "3. Avoid dairy, fatty, spicy, and high-fiber foods until symptoms improve.\n";
                    }
                    if(a=='n'){
	cout<<"okay!"<<endl;
}
                        break;
                    case 6:
                        cout << "\n Diet Plan for Common Cold:\n";
                        cout << "1. Focus on foods rich in vitamin C like citrus fruits (oranges, lemons), bell peppers, and strawberries.\n";
                        cout << "2. Eat  foods such as lean meats, poultry, beans, and nuts.\n";
                        cout << "3. Stay hydrated with warm fluids like herbal teas, broths, and water.\n";
						cout<<"do you want to print that diet plan(y/n)";
cin>>a;
if(a=='y'){
	 file << "\n Diet Plan for Common Cold:\n";
                        file << "1. Focus on foods rich in vitamin C like citrus fruits (oranges, lemons), bell peppers, and strawberries.\n";
                        file << "2. Eat  foods such as lean meats, poultry, beans, and nuts.\n";
                        file << "3. Stay hydrated with warm fluids like herbal teas, broths, and water.\n";
						}
	     if(a=='n'){
	    cout<<"okay!"<<endl;
}
                        break;
                    case 7:
                        cout << "\nGeneral Healthy Diet Plan:\n";
                        cout << "Breakfast: Oatmeal with fruits and nuts\n";
                        cout << "Mid-morning snack: Greek yogurt with honey/fruits \n";
                        cout << "Lunch: Grilled chicken with  salad \n";
                        cout << "Afternoon snack: Apple slices with almond butter\n";
                        cout << "Dinner: Baked salmon(fish) with steamed vegetables\n";
                        cout << "Remember to drink plenty of water throughout the day.\n";
                          cout<<"do you want to print that diet plan(y/n)";
cin>>a;
if(a=='y'){
	 file << "\nGeneral Healthy Diet Plan:\n";
                        file<< "Breakfast: Oatmeal with fruits and nuts\n";
                        file << "Mid-morning snack: Greek yogurt with honey/fruits \n";
                        file << "Lunch: Grilled chicken with  salad \n";
                        file << "Afternoon snack: Apple slices with almond butter\n";
                        file << "Dinner: Baked salmon(fish) with steamed vegetables\n";
                        file << "Remember to drink plenty of water throughout the day.\n";
                    }
                    	     if(a=='n'){
	    cout<<"okay!"<<endl;
}
                        break;
                    default:
                        cout << "Invalid option" << endl;
                }
                break;
            }
            case 3: {
                int score = 0;
                cout << "\nMental Health Test\n";
                cout << "\nLet's check your mental health. Answer the following questions with 'y' for Yes or 'n' for No.\n";

                cout <<"\n"<< name <<  "Do you often feel worried, scared, or tense?";
                cin >> answer;
                if (answer == 'y' || answer == 'Y')
				 {
                    score += 2;
                }

                cout << name << " Do you have trouble concentrating on things, such as reading or watching TV? ";
                cin >> answer;
                if (answer == 'y' || answer == 'Y')
				 {
                    score += 2;
                }

                cout << name << " Do you feel more irritable or short-tempered than usual? ";
                cin >> answer;
                if (answer == 'y' || answer == 'Y') 
				{
                    score += 2;
                }

                cout << name << "Do you have trouble calming down or relaxing after a long day?" ;
                cin >> answer;
                if (answer == 'y' || answer == 'Y')
				 {
                    score += 2;
                }

                cout << name << " Have you experienced changes in your sleep patterns, such as difficulty falling asleep or staying asleep? ";
                cin >> answer;
                if (answer == 'y' || answer == 'Y')
				 {
                    score += 2;
                }

                cout << name << " Do you often feel like you can't handle your daily tasks? ";
                cin >> answer;
                if (answer == 'y' || answer == 'Y') 
				{
                    score += 2;
                }

                if (score >= 10) 
				{
                    cout << name << " Based on your responses, it seems like you may be experiencing significant stress or anxiety.\n";
                    cout << "We recommend talking to a mental health professional for further support.\n";
                     cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
                }
				 else
				 {
                    cout << name << " Based on your responses, it seems like you may be experiencing some stress or anxiety.\n";
                    cout << "Consider practicing relaxation techniques, such as deep breathing exercises or meditation.\n";
                    cout << "If you need further support, don't hesitate to reach out to a mental health professional.\n";
                     cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
                }

                break;
        }
         case 4:
         	{
			 
            		int description;
            	
            	cout<<"1-Cuts and Scraps"<<endl;
            	cout<<"2-Burns "<<endl;
            	cout<<"3-Heatstoke"<<endl;
            	cout<<"4-Bleeding"<<endl;
            	cout<<"5-Fisrt Aid kit"<<endl;
            	cout<<"select any option: ";
            	cin>>description;
            	
      	 switch (description)
            	{
            	case 1:
            		cout<<"\nDescription for Cuts and Scraps"<<endl;
				      cout<<"Clean the wound with water:"<<endl;
                      cout<<"Apply an antiseptic:"<<endl;
                      cout<<"Cover with a sterile bandage:"<<endl;
                       cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
                        break;
		    	case 2:
		    		  cout<<"\nDescription for Burns"<<endl;
                      cout<<"Cool the burn under cool running water for at least 10 minute:"<<endl;
                      cout<<"Do not apply ice, butter, or any ointments"<<endl;
                      cout<<"Cover with a sterile, non-adhesive bandage"<<endl;
                       cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
					      break;
		        case 3:
		        	    cout<<"\nDescription for Heatstoke"<<endl;
                    	cout<<"Move the person to a cooler area away from the heat source:"<<endl;
                        cout<<"Apply cool, wet cloths to their skin and fan them to lower body temperature:"<<endl;
                        cout<<"Offer cool water to drink if they are conscious and able to swallow safely:"<<endl;
                         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
                         break;
                case 4:
                	    cout<<"\nDescription for Bleeding"<<endl;
                    	cout<<"Press firmly on the wound with a clean cloth to stop bleeding:"<<endl;
                        cout<<"levate the injury if it's on a limb:"<<endl;
                        cout<<"Seek medical attention if bleeding persists or is severe:"<<endl; 
                         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
                        break;
                        case 5:
                	cout<<"\n List of first Aid product \n"<<endl;
                	cout<<"1-Bandages (various sizes)"<<endl; 
                    cout<<"2-Gauze pads and rolls"<<endl;
                    cout<<"3-Adhesive tape"<<endl;
                    cout<<"4-Antibiotic ointment"<<endl;
                    cout<<"5-Scissors"<<endl;
                    cout<<"6-Tweezers"<<endl;
                    cout<<"7-Sterile gloves"<<endl;
                    cout<<"8-Burn cream or gel"<<endl;
                    cout<<"9-Pain relievers"<<endl;
                    break;
                    
                        default:
                                 cout<<"invalid section";
					}
						break;			
}
		  
		case 5:
			{
	
			int  disease,age;
        cout << "1. Fever" << endl;
        cout << "2. Headache" << endl;
        cout << "3. Sore throat" << endl;
        cout << "Enter your choice: ";
        cin >> disease;
        switch (disease)
        {
        case 1:
        	cout<<"Enter your age-";
        	cin>>age;

        	if(age>18)
		{
		cout<<"use panadol or Paracetamol"<<endl;
		cout<<" 500 mg to 1000 mg (1-2 tablets of 500 mg)" <<endl;
        cout<<" Every 4 to 6 hours as needed"<<endl;
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    }
    else if(age>12&&age<18)
    {
    	cout<<"use panadol or Paracetamol"<<endl;
    	cout<<"Twice in a day as needed"<<endl;
    	 cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
	}
        else
        {
        cout << "Children's Ibuprofen  for fever." << endl;
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    }
    break;

case 2:
   		cout<<"use basic medicine like panadol"<<endl;;
               	cout<<"Aspiri(500 mg)"<<endl;
               	 cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    		break;
    	
    	case 3:
    	cout<<"use Tylenol"<<endl;
    	 cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
		
		break;
	default:
cout<<"invalid section";
}
break;
}
	default:
cout<<"invalid section";
}


        cout<<"\n" << name << " Do you want to check another section? (y/n) ";
        cin >> answer;
    
	} while (answer == 'y' || answer == 'Y');
    

    cout << "\nThank you for using the Health Advisor System. Stay healthy!\n";
    return 0;
}

void checkSugarLevel(string name) 
{
    string timeofday;
    float sugarLevel;
    char op;

    cout << "Enter your blood sugar level: ";
    cin >> sugarLevel;
    cout << "Is this reading before or after breakfast? (enter 'before' or 'after'): ";
    cin >> timeofday;

    if (timeofday == "before")
	 {
        if (sugarLevel < 70)
		 {
            cout << name << " Your blood sugar level is low. Here are some tips to raise it:\n";
            cout << "1. Eat small frequent meals throughout the day.\n";
            cout << "2. Include complex carbohydrates and proteins in your diet.\n";
            cout << "Reason: Low sugar levels can be due to excessive insulin, skipped meals. .\n";
             cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
        } 
		else if (sugarLevel > 130)
		 {
            cout << name << " Your blood sugar level is high. Here are some tips to lower it:\n";
            cout << "Are you currently taking any medication? ";
            cin >> op;
            cout << "1. Exercise regularly.\n";
            cout << "2. Eat a balanced diet with controlled carbohydrates.\n";
            cout << "3. Drink plenty of water.\n";
            cout << "4. Monitor your blood sugar levels regularly.\n";
            cout << "Reason: High sugar levels can be due to lack of insulin, excessive carbohydrate intake, or lack of physical activity.\n";
             cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
        }
		 else 
		 {
            cout << name << " Your blood sugar level is good.\n";
        }
    } 
	else if (timeofday == "after")
	 {
        if (sugarLevel < 70)
		 {
            cout << name << " Your blood sugar level is low. Here are some tips to raise it:\n";
            cout << "1. Eat small frequent meals throughout the day.\n";
            cout << "2. Include complex carbohydrates and proteins in your diet.\n";
            cout << "Reason: Low sugar levels can be due to excessive insulin, skipped meals.\n";
             cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
        } 
		else if (sugarLevel > 180) 
		{
            cout << name << " Your blood sugar level is high. Here are some tips to lower it:\n";
            cout << "Are you currently taking any medication? ";
            cin >> op;
            cout << "1. Exercise regularly.\n";
            cout << "2. Eat a balanced diet with controlled carbohydrates.\n";
            cout << "3. Drink plenty of water.\n";
            cout << "4. Monitor your blood sugar levels regularly.\n";
            cout << "Reason: High sugar levels can be due to lack of insulin, excessive carbohydrate intake, or lack of physical activity.\n";
             cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
        } 
		else 
		{
            cout << name << " Your blood sugar level is good.\n";
        }
    } 
	else
	 {
        cout << "Invalid input for time of day.\n";
    }
}

    


void checkBloodPressure(string name) 
{
    int systolic, diastolic;
    char op;

    cout << "Enter your systolic blood pressure (upper number): ";
    cin >> systolic;
    cout << "Enter your diastolic blood pressure (lower number): ";
    cin >> diastolic;

    if (systolic < 90 || diastolic < 60)
	 {
        cout << name << " Your blood pressure is low.\n";
        cout << "Tips to maintain your blood pressure:\n";
        cout << "1. Eat more salt.\n";
        cout << "2. Drink more water.\n";
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    }
	 else if (systolic > 140 || diastolic > 90) 
	 {
        cout << name << " Your blood pressure is high.\n";
        cout << "Are you currently taking any medication? ";
        cin >> op;
        cout << "Tips to maintain your blood pressure:\n";
        cout << "1. Reduce salt intake.\n";
        cout << "2. Exercise regularly.\n";
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    } 
	else 
	{
        cout << name << " Your blood pressure is normal.\n";
        cout << "Maintain a healthy lifestyle to keep it that way!\n";
    }
}

void checkPulseRate(string name) 
{
    int pulseRate;

    cout << "Please enter your pulse rate: ";
    cin >> pulseRate;

    if (pulseRate < 60)
	 {
        cout << name << " Your pulse rate is low.\n";
        cout << "Staying hydrated, getting regular exercise, and eating a balanced diet can help maintain a healthy pulse rate.\n";
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    }
	 else if (pulseRate >= 60 && pulseRate <= 100)
	  {
        cout << name << " Your pulse rate is normal.\n";
        cout << "To maintain it, continue with regular exercise, a healthy diet, staying hydrated, and managing stress levels.\n";
    }
	 else 
	 {
        cout << name << " Your pulse rate is high.\n";
        cout << "It's important to consult a healthcare provider to determine the cause. Regular exercise, stress management, and staying hydrated can help lower your pulse rate.\n";
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    }
}
 void checkBMI(string name) 
{
   float weight, height, bmi;
    int age;
    char gender;

    cout << "Please enter your weight in kilograms: ";
    cin >> weight;
    cout << "Please enter your height in meters: ";
    cin >> height;
    cout << "Please enter your age: ";
    cin >> age;
    cout << "Please enter your gender (M/F): ";
    cin >> gender;

    bmi = weight / (height * height);

    if (bmi < 18.5)
	 {
        cout << name << " (Age: " << age << " Gender: " << gender << ") You are underweight.\n";
        cout << "Consider a balanced diet with more calories, including protein-rich foods and healthy fats.\n";
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    }
	 else if (bmi >= 18.5 && bmi < 24.9) 
	 {
        cout << name << " (Age: " << age << " Gender: " << gender << ") You have normal weight.\n";
        cout << "Maintain it by continuing with a balanced diet, regular exercise, staying hydrated, and managing stress levels.\n";
    }
	 else 
	 {
        cout << name << " (Age: " << age << " Gender: " << gender << ") You are overweight.\n";
        cout << "Consider a balanced diet with controlled portions, regular exercise, and reducing intake of sugary and fatty foods.\n";
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    }
}


void checkTemperature(string name)
 {
     float temperature;

    cout << "Please enter your body temperature in Fahrenheit: ";
    cin >> temperature;

    if (temperature < 97.0) 
	{
        cout << name << " Your temperature is below normal.\n";
        cout << "Ensure you are warm, hydrated, and consider seeing a doctor if you feel unwell.\n";
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    }
	 else if (temperature >= 97.0 && temperature <= 99.0) 
	 {
        cout << name << " Your temperature is normal.\n";
        cout << "Stay healthy by maintaining a balanced diet, regular exercise, and staying hydrated.\n";
    } else
	 {
        cout << name << " You have a fever.\n";
        cout << "Stay hydrated, rest, and consider seeing a doctor if your fever persists.\n";
         cout<<"\n"<<name <<" "<<"In serious cases, consult with your doctor."<<endl;
    }
}
