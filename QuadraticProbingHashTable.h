#ifndef QUADRATIC_PROBING_HASH_TABLE_H
#define QUADRATIC_PROBING_HASH_TABLE_H
#include "Restauraunt.h"

class QuadraticProbingHashTable{
    public:
    QuadraticProbingHashTable();
    ~QuadraticProbingHashTable();
    bool insert(Restauraunt entry);
    void print();
    bool remove(string name);
    int searchByName(string name);
    void searchByRating(int rating);
    void searchByPrice(int price);


    private:
    int hashFunction(string name);
    int hashFunctionForSearch(string name);
    int recursiveHash(string name, int orginalIndex, int iteration);
    int recursiveHashForSearch(string name, int originalIndex, int iteration);
    int m_tableSize;
    int m_R;
    Restauraunt* m_table;

};

#endif