#include "Menu.h"
#include "QuadraticProbingHashTable.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Menu::Menu(QuadraticProbingHashTable quadTable) {
    m_quadTable = quadTable;
}

void Menu::run() {
    cout << "Running...\n\n";

    int selection = 0;

    while (selection != 7) {
        cout << "\n------------------------------------------------------------\n";
        cout << "Please choose one of the following commands:\n";
        cout << "1) Insert\n";
        cout << "2) Delete\n";
        cout << "3) FindByName\n";
        cout << "4) FindByRating\n";
        cout << "5) SearchByPrice\n";
        cout << "6) Print\n";
        cout << "7) Exit\n\n";
        cout << "Your selection: ";
        cin >> selection;

        if (selection == 1) {
                string insertString = "";
                string name = "";
                string ratingString = "";
                string priceString = "";
                int rating = 0;
                int price = 0;
                stringstream ss;
                cout << "Enter the data to be inserted:\n";
                cout << "Note: Formatting must be exactly as the following example:" << endl;
                cout << "mcdonalds 4 $$$\n";
                cin.ignore();
                getline(cin, insertString);
                ss.str(insertString);
                ss >> name;
                ss >> ratingString;
                rating = stoi(ratingString);
                ss >> priceString;                
                price = priceString.length();
                if (price > 3) {
                    price = 3;
                }
                Restauraunt tempRestauraunt(name, rating, price);
                if(m_quadTable.insert(tempRestauraunt)) {
                    cout << endl << name << " inserted successfully!\n";
                }
                else {
                    cout << endl << "Unable to insert " << name << ", either quadratic probing has failed or it is a duplicate.\n";
                }
        }
        else if (selection == 6) {
            m_quadTable.print();
        }
    }
}
