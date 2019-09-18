#include "QuadraticProbingHashTable.h"
#include <iostream>
using namespace std;

QuadraticProbingHashTable::QuadraticProbingHashTable() {
    m_tableSize = 31;
    m_R = 29;
    m_table = new Restauraunt[m_tableSize];
    for (int i = 0; i < m_tableSize; i ++) {
        Restauraunt tempRestauraunt;
        m_table[i] = tempRestauraunt;
    }
}

QuadraticProbingHashTable::~QuadraticProbingHashTable(){
    delete[] m_table;
}

bool QuadraticProbingHashTable::insert(Restauraunt entry) {
    string name = entry.getName();
    int index = hashFunction(name);
    if (index < 0) {
        return false;
    }
    m_table[index] = entry;
    return true;
}

int QuadraticProbingHashTable::hashFunction(string name) {
    int index = 0;
    for (int i = 0; i < name.length(); i++) {
        index += int(name[i]);
    }

    index = index % m_tableSize;

    if (m_table[index].empty) {
        return index;
    }
    else if (m_table[index].getName() == name) {
        return -2;
    }
    else {
        return (recursiveHash(name, index, 1));
    }
}

int QuadraticProbingHashTable::recursiveHash(string name, int originalIndex, int iteration) {
    int newIndex = (originalIndex + iteration * iteration) % m_tableSize;
    if (m_table[newIndex].empty) {
        return newIndex;
    }
    else if (m_table[newIndex].getName() == name) {
        return -2;
    }
    else if (iteration > m_tableSize) {
        return -1;
    }
    else {
        return (recursiveHash(name, originalIndex, iteration + 1));
    }
}

void QuadraticProbingHashTable::print() {
    cout << "Quadratic probing table:\n";
    int lastPrint = 0;
    for (int i = 1; i < m_tableSize; i++) {  // TODO: Solve bug when i = 0
        if (!m_table[i].isEmpty() && m_table[i].getRating() != 0) { 
            if (i - lastPrint > 1) {
                cout << ".\n.\n";
            }
            lastPrint = i;
            cout << i << ": " << m_table[i].getName() << ' ' << m_table[i].getRating() << ' ' << m_table[i].priceToString() << endl;
        }
    }
}

bool QuadraticProbingHashTable::remove(string name) {
    int index = hashFunctionForSearch(name);
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

int QuadraticProbingHashTable::searchByName(string name) {
    return hashFunctionForSearch(name);
}

void QuadraticProbingHashTable::searchByRating(int rating) {
    if (rating > 5 || rating < 1) {
        cout << "That is not a valid rating.  Please read the instructions and try again.\n";
        return;
    }
    cout << "\nQuadratic Probing: ";
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
        cout << "No restauraunts were found with a rating of " << rating << endl;
    }
    cout << endl;
}

void QuadraticProbingHashTable::searchByPrice(int price) {
    cout << "\nQuadratic Probing: ";
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

int QuadraticProbingHashTable::hashFunctionForSearch(string name) {
    int index = 0;
    for (int i = 0; i < name.length(); i++) {
        index += int(name[i]);
    }

    index = index % m_tableSize;

    if (m_table[index].getName() == name) {
        return index;
    }
    else if ((m_table[index].empty && m_table[index].onceFilled) || (m_table[index].getName() != name)) {
        return (recursiveHashForSearch(name, index, 1));
    }
    else {
        cout << "\nSomething has gone wrong with search and the recursive hash function was not called!\n";
        return index;
    }
}

int QuadraticProbingHashTable::recursiveHashForSearch(string name, int originalIndex, int iteration) {
    int newIndex = (originalIndex + iteration * iteration) % m_tableSize;

    if (m_table[newIndex].getName() == name) {
        return newIndex;
    }
    else if (iteration > m_tableSize) {
        return -1;
    }
    else {
        return (recursiveHashForSearch(name, originalIndex, iteration + 1));
    }
}