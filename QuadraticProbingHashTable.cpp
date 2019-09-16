#include "QuadraticProbingHashTable.h"
#include <iostream>
using namespace std;

QuadraticProbingHashTable::QuadraticProbingHashTable() {
    m_tableSize = 31;
    m_R = 29;
    m_table = new Restauraunt[m_tableSize];
}

QuadraticProbingHashTable::~QuadraticProbingHashTable(){
    std::cout << m_table[1].getName();
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
    for (int i = 0; i < m_tableSize; i++) {
        if (!m_table[i].empty) {
            cout << i << ": " << m_table[i].getName() << ' ' << m_table[i].getRating() << ' ' << m_table[i].priceToString() << endl;
        }
    }
}