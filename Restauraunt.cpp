#include "Restauraunt.h"
using namespace std;

Restauraunt::Restauraunt(string name, int rating, int price){
    m_name = name;
    m_rating = rating;
    m_price = price;
    empty = false;
    onceFilled = true;
}
Restauraunt::Restauraunt() {
    empty = true;
    onceFilled = false;
    m_rating = 0;
}
Restauraunt::~Restauraunt() {
    
}

string Restauraunt::getName() {
    return m_name;
}

int Restauraunt::getRating() {
    return m_rating;
}

int Restauraunt::getPrice() {
    return m_price;
}

bool Restauraunt::isEmpty() {
    return empty;
}

string Restauraunt::priceToString() {
    switch (m_price) {
        case 1:
            return "$";
        case 2:
            return "$$";
        case 3:
            return "$$$";
        default:
            return "";
    }
}