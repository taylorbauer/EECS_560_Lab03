#ifndef MENU_H
#define MENU_H

#include "QuadraticProbingHashTable.h"

// The class that handles all user interaction and managing of hash table
class Menu {
public:

    //  A constructor that needs a pointer to the table its working with
    Menu(QuadraticProbingHashTable quadTable);

    //  Called by main, this function handles all user interaction and manipulation of the hash table
    void run();
private:
    QuadraticProbingHashTable m_quadTable;
};

#endif