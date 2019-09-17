#include "DoubleHashTable.h"
#include <iostream>
using namespace std;

DoubleHashTable::DoubleHashTable() {
    m_tableSize = 31;
    m_R = 29;
    m_table = new Restauraunt[m_tableSize];
}

DoubleHashTable::~DoubleHashTable() {

}

bool DoubleHashTable::insert(Restauraunt entry){
    string name = entry.getName();
    int index = hashFunction(name);
    if (index < 0) {
        return false;
    }
    m_table[index] = entry;
    return true;
}

bool DoubleHashTable::remove(string name) {
    int index = hashFunctionForSearch(name);
    cout << "HASH FUNCTION IS RETURNING " << index;
    if (index != -1) {
        Restauraunt tempstauraunt;
        m_table[index] = tempstauraunt;
        m_table[index].onceFilled = true;

        return true;
    }
    else {
        return false;
    }

}

int DoubleHashTable::searchByName(string name) {
    return hashFunctionForSearch(name);
}

void DoubleHashTable::searchByRating(int rating) {
    if (rating > 5 || rating < 1) {
        cout << "That is not a valid rating.  Please read the instructions and try again.\n";
        return;
    }
    cout << "\nDouble Hashing: ";
    int numFound = 0;
    for (int i = 0; i < m_tableSize; i++) {
        if (m_table[i].getRating() == rating) {
            if (numFound == 0) {
                cout << m_table[i].getName();
            }
            else {
                cout << ", " << m_table[i].getName();
            }
            numFound ++;
        }
    }
    if (numFound == 0) {
        cout << "No restauraunts were found with a rating of " << rating << '.' << endl;
    }
    cout << endl;
}

void DoubleHashTable::searchByPrice(int price) {
    cout << "\nDouble Hashing: ";
    int numFound = 0;
    for (int i = 0; i < m_tableSize; i++) {
        if (m_table[i].getPrice() == price) {
            if (numFound == 0) {
                cout << m_table[i].getName();
            }
            else {
                cout << ", " << m_table[i].getName();
            }
            numFound ++;
        }
    }
    if (numFound == 0) {
        cout << "No restauraunts were found with this price range.\n";
    }
    cout << endl;
}

int DoubleHashTable::hashFunction(string name) {
    int index = 0;
    for (int i = 0; i < name.length(); i++) {
        index += int(name[i]);
    }
    int originalHash = index;

    index = index % m_tableSize;

    if (m_table[index].empty) {
        return index;
    }
    else if (m_table[index].getName() == name) {
        return -2;
    }
    else {
        return (recursiveHash(name, index, 1, originalHash));
    }
}

int DoubleHashTable::hashFunctionForSearch(string name) {
    int index = 0;
    for (int i = 0; i < name.length(); i++) {
        index += int(name[i]);
    }
    int originalHash = index;

    index = index % m_tableSize;

    //cout << "CHECKING AT INDEX " << index << endl;
    if (m_table[index].getName() == name) {
        return index;
    }
    else {
        return (recursiveHashForSearch(name, index, 1, originalHash));
    }
}

int DoubleHashTable::recursiveHash(string name, int originalIndex,int iteration, int originalHash) {
    int newIndex = (originalIndex + iteration * (m_R - originalHash % m_R)) & m_tableSize;
    //cout << "CHECKING AT INDEX " << newIndex << endl;
    if (iteration > m_tableSize) {
        return -1;
    }
    else if (m_table[newIndex].getName() == name) {
        return -2;
    }
    else if (m_table[newIndex].empty) {
        return newIndex;
    }
    else {
        return (recursiveHash(name, originalIndex, iteration + 1, originalHash));
    }
}

int DoubleHashTable::recursiveHashForSearch(string name, int originalIndex,int iteration, int originalHash) {
    int newIndex = (originalIndex + iteration * (m_R - originalHash % m_R)) & m_tableSize;
    if (iteration > m_tableSize) {
        return -1;
    }
    else if (m_table[newIndex].getName() == name) {
        return newIndex;
    }
    else {
        return (recursiveHashForSearch(name, originalIndex, iteration + 1, originalHash));
    }
}

void DoubleHashTable::print() {
    cout << "Double hashing table:\n";
    for (int i = 0; i < m_tableSize; i++) {
        if (!m_table[i].empty) {
            cout << i << ": " << m_table[i].getName() << ' ' << m_table[i].getRating() << ' ' << m_table[i].priceToString() << endl;
        }
    }
}