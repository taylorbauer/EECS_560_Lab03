#include "Restauraunt.h"
using namespace std;

Restauraunt::Restauraunt(string name, int rating, int price){
    m_name = name;
    m_rating = rating;
    m_price = price;
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