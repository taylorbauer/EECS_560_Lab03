#include <iostream>
#include <fstream>
#include "QuadraticProbingHashTable.h"
#include "Restauraunt.h"

using namespace std;

int main(int argc, char *argv[]) {
    if (argc < 2) {
        cout << "\nPlease include a filename when running the program!\n";
        return 0;
    }
    fstream myFile;
    myFile.open(argv[1]);
    if (!myFile) {
        cout << "\n Error opening file! Please try again.\n";
        return 0;
    }
    string name = "";
    string ratingString = "";
    int rating = 0;
    string priceString = "";
    int price = 0;
    while(myFile.good()){
        myFile >> name;
        name.pop_back();
        myFile >> ratingString;
        ratingString.pop_back();
        myFile >> priceString;
        rating = stoi(ratingString);
        price = priceString.length();
        if (price > 3) {
            price = 3;
        }

    Restauraunt* tempRestauraunt = new Restauraunt(name, rating, price);

    }
    return 0;
}

