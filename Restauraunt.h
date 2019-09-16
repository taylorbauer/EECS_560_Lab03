#ifndef RESTAURAUNT_H
#define RESTAURAUNT_H

#include <string>
using namespace std;

class Restauraunt {
    public:
    Restauraunt(string name, int rating, int price);
    Restauraunt(); 
    ~Restauraunt();
    string getName();
    int getRating();
    int getPrice();
    bool empty;
    string priceToString();
    

    private:
    string m_name;
    int m_rating;
    int m_price;

};

#endif