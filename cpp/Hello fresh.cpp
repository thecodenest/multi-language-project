#include <iostream> 
using namespace std;
class Company {
private:
    string dishes[10]; 
    int quantities[10]; 
    int count; 
    int totalBill;
    int  meals[10];
    string name, address, mail, accountName;
    int pm, ac;
    long long accountNumber;
public:
    Company()
	 {
	count=0;
	} 
    void menu() {                            //function to display menu
        char addMore;
        cout<<"                                                  "<<"--------------------------" << endl;
        cout <<"                                                  "<< "| WELCOME TO HELLO FRESH |" << endl;
        cout << "                                                  "<<"--------------------------" << endl;
        cout << "Bringing Freshness to Your Table!" << endl;
         cout <<"                                                   " <<"Displaying Menu:"<<endl<<endl;

 cout << "            " << "---------------------------------------------------------------------------------------------------\n";
cout << "            " << "| DesiFood              | Price  | Fast Food           | Price  | Sweet Dish              | Price |\n"; 
cout << "            " << "---------------------------------------------------------------------------------------------------\n"; 
cout << "            " << "| Biryani(1plate)       | 200-Rs | Zinger Burger       | 350-Rs | Chocolate Cake (1 pond) | 500-Rs|\n";       
cout << "            " << "| Chicken Karahi(1-p)   | 250-Rs | Fries               | 200-Rs | Simple Cake (1 pond)    | 400-Rs|\n"; 
cout << "            " << "| Chicken Roast(1-p)    | 300-Rs | Shawarma            | 200-Rs | Chocolate Cookies(20)   | 500-Rs|\n"; 
cout << "            " << "| Nihari(beef)(1-p)     | 500-Rs | Pasta(medium)       | 450-Rs | Custard Trifffle(b.bowl)| 400-Rs|\n";
 cout << "            " <<"| Haleem(chicken)(1-p)  | 150-Rs | Chicken soup(s.bowl)| 200-Rs | Kheer(big.bowl)         | 400-Rs|\n"; 
cout << "            " << "| Mutton Karahi(1-p)    | 300-Rs | Pizza(medium)       | 800-Rs | Rasmalai(small.bowl)    | 200-Rs|\n"; 
cout << "            " << "| Beef Kebab(5)         | 500-Rs | Spaghetic (medium)  | 500-Rs | Fruit Salad(small bowl) | 200-Rs|\n";
cout << "            " << "---------------------------------------------------------------------------------------------------\n";
 system("pause");
 cout<<endl;
        cout<<"              "<<"--------------------------" << endl;
        cout <<"              "<<"|     DEALS OF TODAY    |" << endl;
        cout <<"              "<<"--------------------------" << endl;
 cout<< "1. 10% off on order over 2000Rs\n";
 cout << "2. 20% Off on Orders Over 5000Rs\n";
 cout<<  "3.No Applicable\n";

cout<<endl<<endl;
        do {
            string dish;
            int per,meal;
while(true){
                cout << "Select dish:";
                getline(cin,dish);
                    if (dish == "Biryani" ||dish == "biryani" || dish == "Chicken karahi" || dish == "chickenkarahi" || dish == "Chicken roast"|| dish == "chickenroast"  || dish == "Nihari" ||dish == "nihari" ||
        dish == "Haleem" ||dish == "haleem" || dish == "Mutton karahi" || dish == "muttonkarahi" || dish == "Beef kebab" ||dish == "beefkebab" || dish == "Zinger burger" ||dish == "zingerburger" ||
        dish == "Fries" || dish == "fries" || dish == "Shawarma" || dish == "shawarma" || dish == "Pasta" || dish == "pasta" || dish == "Chicken soup" ||dish == "chickensoup" ||
        dish == "Pizza" ||  dish == "pizza" || dish == "Spaghetic" || dish == "spaghetic" || dish == "Chocolate cake" || dish == "chocolatecake" || dish == "Simple cake" || dish == "simplecake" ||
        dish == "Chocolate cookies" ||   dish == "chocolatecookies"|| dish == "Custard triffle" || dish == "custardtriffle" || dish == "Kheer"||dish == "kheer" || dish == "Rasmalai"||dish == "rasmalai" ||
        dish == "Fruit salad"||dish == "fruitsalad"){
		break; 
    } else {
         cout << "Invalid dish! Do you want to try again? (y/n): ";
            char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                cout << "Exiting the program...\n";
                exit(0);  
            } else {
                continue;  
            }
}
}
if (count < 10) {
	     cout<<"             "<<"----------------------------" << endl;
         cout <<"            "<<"| Customize Your Plan size |" << endl;
         cout <<"            "<<"----------------------------" << endl;
                cout << "Enter the number of persons: ";
                cin >> per;
                cin.ignore();
                cout<<"Enter number of meals:";
                cin>>meal;
                cin.ignore();
                dishes[count] = dish;
                quantities[count] = per;
                                meals[count] = meal;
                count++;
                cout << "want to add more dishes? (maximum limit is 10)(y/n): ";
                cin >> addMore;
                cin.ignore();
            } else {
                cout << "\nYou cannot add more than 10 dishes.\n";
                break;
            }
        } while (addMore == 'y' || addMore == 'Y');
        cout << "\nYour Order:\n";
        for (int i = 0; i < count; i++) {
            cout << "Dish: " << dishes[i] << ", Person: " << quantities[i] << ", Meals per person: " << meals[i]<< endl;
        }
    }
    void showIngredients() {            //function to display ingredients
    	     system("pause");
			system("cls");
		    string dishName;
    char choice;  
    cout<<endl<<endl<<endl;
        cout << "Do you want to see ingredients? (y/n): ";
        cin >> choice;
    do {
        if (choice == 'y' || choice == 'Y') {
            cout << "Enter the dish name for ingredients:";
            cin.ignore();  
            getline(cin, dishName); 
            bool validDish = false;  // Flag to check if the dish is valid
 
    if (dishName == "biryani"||dishName=="Biryani") {
        cout << "Ingredients for Biryani are:" << endl;
        cout << "1. Rice\n"<<"2.Chicken\n"<<"3.Tomatoes\n" <<"4.Onion\n"<<"5.Yogurt\n"<<"6.Ginger-Garlic paste\n"<<"7.Biryani spices\n"<<"8.Green chilies\n"<<"9.food coloring\n"<<"10.Fresh coriander\n" <<"11.Mint leaves\n"<<"12.oil\n"<<endl;
                        validDish = true;

    } else if (dishName == "chickenkarahi"||dishName == "Chicken karahi") {
        cout << "Ingredients for Chicken karahi are:" << endl;
      cout << "   1. Chicken\n   2. Tomatoes\n   3. Ginger\n   4. Garlic \n   5. Green chilies\n   6. Fresh coriander\n   7. Karahi masala\n   8. Oil" << endl;
                         validDish = true;

     
	} else if (dishName == "chickenroast"||dishName == "Chicken roast") {
        cout << "Ingredients for Chicken roast are:" << endl;
      cout << "   1. Whole chicken\n   2. Yogurt\n   3. Lemon juice\n   4. Ginger-Garlic paste\n   5.Spices\n   6. Fresh coriander\n   7.butter" << endl;
                validDish = true;

    }
     else if (dishName == "nihari"||dishName == "Nihari") {
        cout << "Ingredients for Nihari are:" << endl;
          cout << "   1. Beef\n   2. Ginger-garlic paste\n   3. Onion\n   4. Tomatoes\n   5. Nihari masala\n   6. Wheat flour\n   7. Oil or ghee\n   8. Lemon juice\n   9. Fresh coriander\n   10. Green chilies" << endl;
                   validDish = true;
    }
     else if (dishName == "haleem"||dishName == "Haleem") {
        cout << "Ingredients for Haleem are:" << endl;
    cout << "   1. Chicken (boneless)\n   2. Wheat\n   3. Daal, chickpeas\n   4. Ginger-Garlic paste\n   5. Onions\n   6. Green chilies\n   7. Haleem masala\n   8. Ghee or oil\n   9. Fresh coriander\n   10. Mint leaves\n   11. Lemon juice" << endl;	
                validDish = true;

}else if (dishName == "muttonkarahi"||dishName == "Mutton karahi") {
    cout << "Ingredients for Mutton karahi are:" << endl;
    cout << "   1. Mutton\n   2. Tomatoes\n   3. Green chilies\n   4. Ginger and garlic paste\n   5. Fresh coriander\n   6. Spices\n   7. Oil or ghee" << endl;
                validDish = true;

	}
     else if (dishName == "beefkebab"||dishName == "Beef kebab") {
      cout << "Ingredients for Beef kebab are: 1. Beef 2. Onions 3. Ginger-Garlic paste 4. Fresh coriander 5. Mint leaves 6. Green chilies 7. Spices 8. Cumin seeds 9. Lemon juice" << endl;
                validDish = true;

	}
     else if (dishName == "zingerburger"||dishName == "Zinger burger") {
        cout << "Ingredients for Zinger burger are:" << endl;
cout << "   1. Chicken breast\n   2. Burger buns\n   3. Lettuce leaves\n   4. Tomatoes\n   5. Mayonnaise\n   6. Ketchup\n   7. Fried chicken batter\n   8. Oil" << endl;
                validDish = true;
}
else if (dishName == "fries"||dishName == "Fries") {
        cout << "Ingredients for Fries are:" << endl;
 cout << "   1. Potatoes\n   2. Salt\n   3. Oil\n   4. Sauce" << endl;
                 validDish = true;
}
     else if (dishName == "shawarma"||dishName == "Shawarma") {
        cout << "Ingredients for Shawarma are:" << endl;
      cout << "   1. Chicken\n   2. Yogurt\n   3. Garlic gingerpaste\n   4. Lemon juice\n   5. Shawarma spices\n   6. Pita bread\n\n   8. Cucumber\n   9. Lettuce\n   10. Sauce" << endl;
	                  validDish = true;
}
    
	 else if (dishName == "chickensoup"||dishName == "Chicken soup") {
        cout << "Ingredients for Chicken soup are:" << endl;
       cout << "   1. Chicken\n   4. Garlic\n   5. Carrot\n   6. Cabbage\n   7. Shimla Mirch\n   8. Spices\n   13. Sauces\n   14. Crackers" << endl;
	
	                validDish = true;
}
     else if (dishName == "pasta"||dishName == "Pasta") {
        cout << "Ingredients for Pasta are:" << endl;
    cout << "   1. Pasta\n   2. Chicken\n   3. Tomatoes\n   4. Garlic ginger paste\n   5. White sauce\n   6. Oil\n   7. Spices   8. cream\n   9. Cheese\n   10. Cabbage\n   11. Carrot\n   12. Shimla Mirch" << endl;
                    validDish = true;

	}
     else if (dishName == "pizza"||dishName == "Pizza") {
        cout << "Ingredients for Pizza are:" << endl;
      cout << "   1. Pizza dough\n   2. Pizza sauce\n   3. Mozzarella cheese\n   4. Chicken\n   5. Olives\n   6. Shimla Mirch\n   7. Ketchup" << endl;
                validDish = true;

}
     else if (dishName == "spaghetti"||dishName == "Spaghetti") {
        cout << "Ingredients for Spaghetti are:" << endl;
    cout << "   1. Spaghetti noodles\n   2. Chicken\n   3. Tomatoes\n   4. Garlic ginger paste\n   5. Oil\n   6. Cabbage\n   7. Shimla Mirch\n   8. Carrot\n   9. Oregano\n   10. Parmesan cheese" << endl;
                validDish = true;

}
     else if (dishName == "chocolatecake"||dishName == "Chocolate cake") {
        cout << "Ingredients for Chocolate cake are:" << endl;
    cout << "      1. Flour\n   2. Cocoa powder\n   3. Baking powder\n   4. Sugar\n   5. Eggs\n   6. Butter\n   7. Milk\n   8. Vanilla essence\n   9. Dark chocolate" << endl;
                validDish = true;

}
     else if (dishName == "simplecake"||dishName == "Simple cake") {
        cout << "Ingredients for Simple cake are:" << endl;
         cout << "   1. Flour\n   2. Sugar\n   3. Eggs\n   4. Butter\n   5. Milk\n   6. Baking powder\n   7. Vanilla essence" << endl;
                    validDish = true;

	}
    else if (dishName == "chocolatecookies"||dishName == "Chocolate cookies") {
        cout << "Ingredients for Chocolate cookies are:" << endl;
    cout << "   1. Flour\n   2. Cocoa powder\n   3. Baking powder\n   4. Sugar\n   5. Butter\n   6. Eggs\n   7. Dark chocolate chunks\n   8. Vanilla essence" << endl;
                validDish = true;

}
    else if (dishName == "custardtriffle"||dishName == "Custard triffle") {
        cout << "Ingredients for Custard trifle are:" << endl;
        cout << "   1. Custard powder\n   2. Milk\n   3. Sugar\n   4. Cake pieces\n   5. Fresh fruit\n   6. Whipped cream" << endl;
    }
    else if (dishName == "kheer"||dishName == "Kheer") {
        cout << "Ingredients for Kheer are:" << endl;
      cout << "   1. Rice\n   2. Milk\n   3. Sugar\n   4. Cardamom\n   5. Cashews and almonds\n   6. (Missing item)\n   7. Lazeeza kheer pack" << endl;
                   validDish = true;

   } else if (dishName == "rasmalai"||dishName == "Rasmalai") {
        cout << "Ingredients for Rasmalai are:" << endl;
        cout << "   1. Milk\n   2. Sugar\n   3. Cardamom\n   4. Rasmali box\n   5. Chopped pistachios and almonds" << endl;
                    validDish = true;

	}
    else if (dishName == "fruitsalad"||dishName == "Fruit salad") {
        cout << "Ingredients for Fruit salad are:" << endl;
         cout << "   1. Mixed fresh fruits\n   2. Fresh cream\n   3. Honey\n   4. Chopped nuts" << endl;
    }
    if (validDish) {
                cout << "------------------------------------------------------------------------------------" << endl;
                cout << "|We also deliver a recipe card that guides you step by step to make a delicious meal|" << endl;
                cout << "------------------------------------------------------------------------------------" << endl;
            }
	 else {
        cout << "Dish not found!" << endl;
    }

         
       cout << "Do you want to check ingredients for another dish? (y/n): ";
        cin >> choice;}

    } while (choice == 'y' || choice == 'Y');
     system("cls");
}
  
     void calculateBill() {     //funtion for calculate the bill
             
			 totalBill = 0;
            for (int i = 0; i < count; i++) {
            	 int mealMultiplier = meals[i];
                if (dishes[i] == "biryani"||dishes[i] == "Biryani") {
                    totalBill += quantities[i] * 200*mealMultiplier; 
                } else if (dishes[i] == "chickenkarahi"||dishes[i] == "Chicken karahi") {
                    totalBill += quantities[i] * 250*mealMultiplier; 
                } else if (dishes[i] == "chickenroast"||dishes[i] == "Chicken roast") {
                    totalBill += quantities[i] * 300*mealMultiplier; 
                } else if (dishes[i] == "nihari"||dishes[i] == "Nihari") {
                    totalBill += quantities[i] * 500*mealMultiplier; 
                } else if (dishes[i] == "haleem"||dishes[i] == "Haleem") {
                    totalBill += quantities[i] * 150*mealMultiplier; 
                } else if (dishes[i] == "muttonkarahi"||dishes[i] == "Mutton karahi") {
                    totalBill += quantities[i] * 300*mealMultiplier; 
                } else if (dishes[i] == "beefkebab"||dishes[i] == "Beef kebab") {
                    totalBill += quantities[i] * 500*mealMultiplier; 
                } else if (dishes[i] == "zingerburger"||dishes[i] == "Zinger burger") {
                    totalBill += quantities[i] * 350*mealMultiplier; 
                } else if (dishes[i] == "fries"||dishes[i] == "Fries") {
                    totalBill += quantities[i] * 200*mealMultiplier; 
                } else if (dishes[i] == "shawarma"||dishes[i] == "Shawarma") {
                    totalBill += quantities[i] * 200*mealMultiplier; 
                } else if (dishes[i] == "pasta"||dishes[i] == "Pasta") {
                    totalBill += quantities[i] * 450*mealMultiplier; 
                } else if (dishes[i] == "chickensoup"||dishes[i] == "Chicken soup") {
                    totalBill += quantities[i] * 200*mealMultiplier; 
                    } else if (dishes[i] == "pizza"||dishes[i] == "Pizza") {
                    totalBill += quantities[i] * 800*mealMultiplier; 
                } else if (dishes[i] == "spaghetic"||dishes[i] == "Spaghetic") {
                    totalBill += quantities[i] * 500*mealMultiplier; 
                } else if (dishes[i] == "chocolatecake"||dishes[i] == "Chocolate cake") {
                    totalBill += quantities[i] * 500*mealMultiplier;
				}	 else if (dishes[i] == "simplecake"||dishes[i] == "Simple cake") {
                    totalBill += quantities[i] * 400*mealMultiplier; 
                } else if (dishes[i] == "chocolatecookies"||dishes[i] == "Chocolate cookies") {
                    totalBill += quantities[i] * 500*mealMultiplier; 
                } else if (dishes[i] == "custardtriffle"||dishes[i] == "Custard triffle") {
                    totalBill += quantities[i] * 400*mealMultiplier;  
                  }   else if (dishes[i] == "kheer"||dishes[i] == "Kheer") {
                    totalBill += quantities[i] * 400*mealMultiplier; 
                } else if (dishes[i] == "rasmalai"||dishes[i] == "Rasmalai") {
                    totalBill += quantities[i] * 200*mealMultiplier; 
                } else if (dishes[i] == "fruitsalad"||dishes[i] == "Fruit salad") {
                    totalBill += quantities[i] * 200*mealMultiplier; 
                } else {
                    cout << "Unknown dish: " << dishes[i]<<endl;
                }
            }
            cout << "\nTotal Bill: Rs" << totalBill << endl;
        }
         void dish() {    //function for editing dishes
    char changeOrDelete;
    cout <<"Do you want to update your order by changing, deleting, or adding a dish? (y/n): ";
    cin >> changeOrDelete;
    if (changeOrDelete == 'y' || changeOrDelete == 'Y') {
        int choice;
        cout << "1. Change a dish\n";
        cout << "2. Delete a dish\n";
        cout << "3. Add a new dish\n"; 
        cout << "Enter your choice: ";
        cin >> choice;
        if (choice == 1) {
            int dishIndex;
            cout << "Enter the dish number you want to change (1 to " << count << "): ";
            cin >> dishIndex;
            dishIndex -= 1; 
            if (dishIndex >= 0 && dishIndex < count) {
                string newDish;
                int newQuantity,newmeal;
                while(true)
				{	
                cout << "Enter the new dish name: ";
                cin >> newDish;
                   if (newDish == "Biryani"||newDish == "biryani" || newDish == "Chicken Karahi"|| newDish == "chickenkarahi" || newDish == "Chicken Roast"|| newDish == "chickenroast" || newDish == "Nihari" || newDish == "nihari" ||
        newDish == "Haleem" ||newDish == "haleem"|| newDish == "Mutton Karahi" || newDish == "muttonkarahi" || newDish == "Beef Kebab"|| newDish == "beefkebab"  || newDish == "Zinger Burger" || newDish == "zingerburger" ||
        newDish == "Fries"||newDish == "fries" || newDish == "Shawarma" || newDish == "shawarma" || newDish == "Pasta"|| newDish == "pasta" || newDish == "Chicken soup"|| newDish == "chickensoup" ||
        newDish == "Pizza" || newDish == "Spaghetic" || newDish == "Chocolate Cake" || newDish == "Simple Cake" ||
        newDish == "Chocolate Cookies"||newDish == "chocolatecookies" || newDish == "Custard Triffle"|| newDish == "custardtriffle" || newDish == "Kheer"||newDish == "kheer" || newDish == "Rasmalai"|| newDish == "rasmalai" ||
        newDish == "Fruit Salad"||newDish == "fruitsalad") {
        	break;
    } else {
        cout << "Invalid dish! Do you want to try again? (y/n):" << endl;
        char choice;
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                cout << "Exiting the program...\n";
                exit(0);  
            } else {
                continue;  
				         }
    }
}               cout << "Enter the new number of person: ";
                cin >> newQuantity;
                cout<<"Enter the number of meal:";
                cin>>newmeal;
                dishes[dishIndex] = newDish;
                quantities[dishIndex] = newQuantity;
                meals[dishIndex]=newmeal;
            } else {
                cout << "Invalid dish number.\n";
            }
        } else if (choice == 2) {
            int dishIndex;
            cout << "Enter the dish number you want to delete (1 to " << count << "): ";
            cin >> dishIndex;
            dishIndex -= 1; 
            if (dishIndex >= 0 && dishIndex < count) {
                for (int i = dishIndex; i < count - 1; i++) {
                    dishes[i] = dishes[i + 1];
                    quantities[i] = quantities[i + 1];
                }
                count--;
        totalBill = 0;
        for (int i = 0; i < count; i++) {
            if (dishes[i] == "biryani"||dishes[i] == "Biryani") {
                totalBill += quantities[i] * 200;
            } else if (dishes[i] == "chickenkarahi"||dishes[i] == "Chicken karahi") {
                totalBill += quantities[i] * 250;
            } else if (dishes[i] == "chickenroast"||dishes[i] == "Chicken roast") {
                totalBill += quantities[i] * 300;
            } else if (dishes[i] == "nihari"||dishes[i] == "Nihari") {
                totalBill += quantities[i] * 500;
            } else if (dishes[i] == "haleem"||dishes[i] == "Haleem") {
                totalBill += quantities[i] * 150;
            } else if (dishes[i] == "muttonkarahi"||dishes[i] == "Mutton karahi") {
                totalBill += quantities[i] * 300;
            } else if (dishes[i] == "beefkebab"||dishes[i] == "Beefkebab") {
                totalBill += quantities[i] * 500;
            } else if (dishes[i] == "zingerburger"||dishes[i] == "Zinger burger") {
                totalBill += quantities[i] * 350;
            } else if (dishes[i] == "fries"||dishes[i] == "Fries") {
                totalBill += quantities[i] * 200;
            } else if (dishes[i] == "shawarma"||dishes[i] == "Shawarma") {
                totalBill += quantities[i] * 200;
            } else if (dishes[i] == "pasta"||dishes[i] == "Pasta") {
                totalBill += quantities[i] * 450;
            } else if (dishes[i] == "chickensoup"||dishes[i] == "Chicken soup") {
                totalBill += quantities[i] * 200;
            } else if (dishes[i] == "pizza"||dishes[i] == "Pizza") {
                totalBill += quantities[i] * 800;
            } else if (dishes[i] == "spaghetic"||dishes[i] == "Spaghetic") {
                totalBill += quantities[i] * 500;
            } else if (dishes[i] == "chocolatecake"||dishes[i] == "Chocolate cake") {
                totalBill += quantities[i] * 500;
            } else if (dishes[i] == "simplecake"||dishes[i] == "Simple cake") {
                totalBill += quantities[i] * 400;
            } else if (dishes[i] == "chocolatecookies"||dishes[i] == "Chocolate cookies") {
                totalBill += quantities[i] * 500;
            } else if (dishes[i] == "custardtriffle"||dishes[i] == "Custard triffle") {
                totalBill += quantities[i] * 400;
            } else if (dishes[i] == "kheer"||dishes[i] == "Kheer") {
                totalBill += quantities[i] * 400;
            } else if (dishes[i] == "rasmalai"||dishes[i] == "Rasmalai") {
                totalBill += quantities[i] * 200;
            } else if (dishes[i] == "fruitsalad"||dishes[i] == "Fruitsalad") {
                totalBill += quantities[i] * 200;
            }
        }
    if (totalBill == 0) {
            cout << "Your total bill is zero. Exiting program...\n";
            exit(0); 
        }
                cout << "Dish deleted successfully.\n";
            } else {
                cout << "Invalid dish number.\n";
            }
        } else if (choice == 3) {
            if (count < 10) { 
                string dish;
                int per;
                int meal;
                while(true){
                cout << "Enter the new dish name: ";
                cin >> dish;
                 if (dish == "Biryani" ||dish == "biryani" || dish == "Chicken karahi" || dish == "chickenkarahi" || dish == "Chicken roast"|| dish == "chickenroast"  || dish == "Nihari" ||dish == "nihari" ||
        dish == "Haleem" ||dish == "haleem" || dish == "Mutton karahi" || dish == "muttonkarahi" || dish == "Beef kebab" ||dish == "beefkebab" || dish == "Zinger burger" ||dish == "zingerburger" ||
        dish == "Fries" || dish == "Shawarma" || dish == "Pasta" || dish == "Chicken soup" ||dish == "chickensoup" ||
        dish == "Pizza" ||  dish == "pizza" || dish == "Spaghetic" || dish == "spaghetic" || dish == "Chocolate cake" || dish == "chocolatecake" || dish == "Simple cake" || dish == "simplecake" ||
        dish == "Chocolate cookies" ||   dish == "chocolatecookies"|| dish == "Custard triffle" || dish == "custardtriffle" || dish == "Kheer"||dish == "kheer" || dish == "Rasmalai"||dish == "rasmalai" ||
        dish == "Fruit salad"||dish == "fruitsalad"){
           break;
        } else {
        	char choice;
            cout << "Invalid dish selected!  Do you want to try again? (y/n):" << endl;
            cin >> choice;
            if (choice == 'n' || choice == 'N') {
                cout << "Exiting the program...\n";
                exit(0);  
            } else {
                continue;  
            }
        }}
                cout << "Enter the number of persons: ";
                cin >> per;
                cout<<"Enter number of meals:";
                cin>>meal;
                dishes[count] = dish;
                quantities[count] = per;
                meals[count]=meal;
                count++;
                cout << "New dish added successfully.\n";
            } else {
                cout << "You cannot add more than 10 dishes.\n";
            }
        } else {
            cout << "Invalid choice.\n";
        }
    }
    cout << "\nFinal Order: ";
    for (int i = 0; i < count; i++) {
        cout << dishes[i] << " person:" << quantities[i]<<"   "<< "Meals:"<<meals[i]<<endl;
    }
    calculateBill();               //recalculating the bill after editing 
     deal(totalBill);
}
  void deal(int& totalBill) {              //function for applying deal
            int deal;
            char op;
            cout << "Apply deal? (y/n): ";
            cin >> op;
            if (op == 'Y' || op == 'y') {
                cout << "Select the deal: ";
                cin >> deal;
                         switch (deal) {
                    case 1:
                        if (totalBill > 2000){
                        totalBill = totalBill *0.90;
                         cout << "\nTotal Bill after applying the deal:" << totalBill << endl;
						}
						else { 
						cout<<"This deal is for above 2000Rs"<<endl;
						}
                        break;
                    case 2:
                        if (totalBill > 5000) {
                            totalBill = totalBill * 0.80; 
                             cout << "\nTotal Bill after applying the deal: " << totalBill << endl;
                        }
                        else {
                    cout << "\nThis deal is only valid for orders over 5000Rs.\n";
                }
                        break;
                        case 3:{
                        	cout<<"Try another day"<<endl;
                        }
                        break;
                    default:
                        cout << "\nInvalid deal choice.\n";
                        return;
                }
            }
           cout<<"Total Bill-"<<totalBill<<endl;}
    void orderconfirm() {            //functio for order confirmation 
        char ch;
        cout<<endl<<endl;
        cout << "\nDo you want to confirm the order? (Y/N): ";
        cin >> ch;
        cin.ignore();  
        if (ch == 'y' || ch == 'Y') {
            cout << "Enter your name: ";
            getline(cin, name);
            cout << "Enter your address: ";
            getline(cin, address);
            cout << "Enter your e-mail: ";
            getline(cin, mail);
            cout << "Payment method:\n";
            cout << "1 - Cash on delivery\n";
            cout << "2 - Online\n";
            cout << "Select the payment method: ";
            cin >> pm;
            if (pm == 2) {
                cout << "Select account method:\n";
                cout << "1 - JazzCash\n";
                cout << "2 - Credit Card\n";
                cout << "3 - Easypaisa\n";
                cout << "Enter choice: ";
                cin >> ac;
                cout << "Enter your account name: ";
                cin.ignore();
                getline(cin, accountName);
                 cout << "Enter your account number: ";
                cin >> accountNumber;
            }
        } else if (ch == 'n' || ch == 'N') {
            cout << "Order cancelled. \n";
            cout<<"One day, you'll find the perfect fit with our product, and we can't wait to serve you!"<<endl;
            exit(0);
        }
          else {
            cout << "Invalid input! Exiting program...\n";
            exit(0);  
        }
    }
    void editDetails() {     //function for editing personal details 
        cout << "What do you want to edit?\n";
        cout << "1. Name\n2. Address\n3. Email\nEnter choice: ";
        int choice;
        cin >> choice;
        cin.ignore();
        switch (choice) {
            case 1:
                cout << "Enter new name: ";
                getline(cin, name);
                break;
            case 2:
                cout << "Enter new address: ";
                getline(cin, address);
                break;
            case 3:
                cout << "Enter new email: ";
                getline(cin, mail);
                break;
            default:
                cout << "Invalid choice!\n";
        }
    }
       void output() {    //function for displaying all order details 
        system("pause");
        system("cls");
cout<<endl<<endl;
         cout<<"                                                   "<<"--------------------------" << endl;
        cout <<"                                                   "<< "| WELCOME TO HELLO FRESH |" << endl;
        cout <<"                                                   "<<"--------------------------" << endl;
cout<<endl;
        cout<<"                 "<<"--------------------------" << endl;
        cout <<"                 "<<"|  Your Order Details    |" << endl;
        cout <<"                 "<<"--------------------------" << endl;
        cout<<endl;
        for (int i = 0; i < count; i++) {
cout<<"                  "<< "Dish: " << dishes[i] <<endl;
cout<<"                  "<<"Person: " << quantities[i]<<endl;
cout<<"                  "<< "Meals:"<<meals[i]<< endl;
        }
cout<<endl;
        cout<<"                 "<<"--------------------------" << endl;
        cout <<"                 "<<"|   Customer Details     |" << endl;
        cout <<"                 "<<"--------------------------" << endl;
cout<<"                   "<< "Name: " << name << endl;
cout<<"                   "<< "Address: " << address << endl;
cout<<"                   "<< "E-mail: " << mail << endl;
        if (pm == 1) {
cout<<"                   "<< "Payment Method: Cash on Delivery" << endl;
} else if (pm == 2) {
cout<<"                   "<< "Payment Method: Online" << endl;
cout<<"                   "<< "Account Type: " << (ac == 1 ? "JazzCash" : ac == 2 ? "Credit Card" : "Easypaisa") << endl;
cout<<"                   "<< "Account Name: " << accountName << endl;
cout<<"                   "<< "Account Number: " <<accountNumber<<endl;
}
 cout <<"                   "<<"Total Bill: Rs" << totalBill << endl; 
 cout<<endl<<endl;
  cout<<"      "<<name<<" "<< "Your order will be delivered in 15 minutes!\n";
  cout<<"      "<< "Thank you for choosing HelloFresh; we're excited to bring fresh, delicious meals to your table!\n";
    }
};
int main() {
    Company customer;                  
    char choice;
    string dish;
    customer.menu();                               //function calls 
    customer.calculateBill();
    customer.dish(); 
    customer.showIngredients();     
    customer.orderconfirm();
    char editChoice;
        cout << "Do you want to edit your details? (y/n): ";
        cin >> editChoice;
        cin.ignore();
        if (editChoice == 'y' || editChoice == 'Y') {
            customer.editDetails();
			}
    cout << "\nYour order is confirmed!\n";       
    customer.output();
    return 0;
}
