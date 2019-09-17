#ifndef RESTAURAUNT_H
#define RESTAURAUNT_H

#include <string>
using namespace std;

class Restauraunt {
    public:

    //  Constructor used when building a non-empty Restauraunt.  
    //  Sets empty and oncefilled flags to false and true, respectively.
    Restauraunt(string name, int rating, int price);

    //  A default constructor necessary when building an array to be filled with Restauraunts.
    //  It is essentially an empty restauruant that occupies a space on the array waiting to be filled.
    Restauraunt(); 

    ~Restauraunt();

    //  Self-explanitory getters:
    string getName();
    int getRating();
    int getPrice();

    //  Tracks weather or not a restauraunt is "empty"
    //  i.e., nothing is occupying the space on the array
    bool empty;

    //  I actually ended up not using this, but it tracks weather or not a space on the array has ever been filled
    //  This could be used when quadratic probing to terminate the search for an object early, saving some time
    bool onceFilled;

    //  Converts 1, 2, and 3 to $, $$, and $$$, respectively
    string priceToString();
    

    private:
    string m_name;
    int m_rating;
    int m_price;

};

#endif