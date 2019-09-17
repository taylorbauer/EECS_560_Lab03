#include "Menu.h"
#include "QuadraticProbingHashTable.h"
#include <iostream>
#include <string>
#include <sstream>

using namespace std;

Menu::Menu(QuadraticProbingHashTable quadTable, DoubleHashTable doubleTable) {
    m_quadTable = quadTable;
    m_doubleTable = doubleTable;
}

void Menu::run() {
    cout << "Running...\n\n";

    int selection = 0;

    while (selection != 7) {
        cin.clear();
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

                //Everything below is just converting user input to a Restauraunt entry
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
                    cout << endl << name << " inserted successfully using quadratic probing!\n";
                }
                else {
                    cout << endl << "Unable to insert " << name << " using quadratic probing, either quadratic probing has failed or it is a duplicate.\n";
                }
                
                if(m_doubleTable.insert(tempRestauraunt)) {
                    cout << endl << name << " inserted successfully using double hashing!\n";
                }
                else {
                    cout << endl << "Unable to insert " << name << " using double hashing, either quadratic probing has failed or it is a duplicate.\n";
                }
        }
        else if (selection == 2) {
            string deletion = "";
            cout << "Enter the name of the entry you would like to delete: ";
            cin >> deletion;

            if (m_quadTable.remove(deletion)) {
                cout << deletion << " has been successfully deleted from quadratic probing table.\n";
            }
            else {
                cout << deletion << " was unable to be found on quadratic probing table, and was not deleted.\n";
            }

            if (m_doubleTable.remove(deletion)) {
                cout << deletion << " has been successfully deleted from double hashing table.\n";
            }
            else {
                cout << deletion << " was unable to be found on double hashing table, and was not deleted.\n";
            }

        }
        else if (selection == 3) {
            string searchKey = "";
            cout << "Enter the name of the restauraunt you would like to search for: ";
            cin >> searchKey;
            int searchResult = m_quadTable.searchByName(searchKey);

            if (searchResult != -1) {
                cout << searchKey << " was found at position " << searchResult << " on the quadratic probing table.\n";
            }
            else {
                cout << searchKey << " was not found on the quadratic probing table";
            }

            searchResult = m_doubleTable.searchByName(searchKey);
            if (searchResult != -1) {
                cout << searchKey << " was found at position " << searchResult << " on the double hashing table.\n";
            }
            else {
                cout << searchKey << " was not found on the double hashing table";
            }
        }

        else if (selection == 4) {
            int searchKey = 0;
            cout << "There are 5 possible ratings: the integers 1 through 5.  Enter the rating you would like to search for: ";
            cin >> searchKey;

            m_quadTable.searchByRating(searchKey);
            m_doubleTable.searchByRating(searchKey);

        }
        else if (selection == 5) {
            int searchKey = 0;
            string input = "";
            cout << "There are 3 possible prices: $, $$, or $$$.  Enter the price you would like to search for: ";
            cin >> input;
            searchKey = input.length();

            m_quadTable.searchByPrice(searchKey);
            m_doubleTable.searchByPrice(searchKey);
        }

        else if (selection == 6) {
            m_quadTable.print();
            cout << endl;
            m_doubleTable.print();
        }
    }
}
