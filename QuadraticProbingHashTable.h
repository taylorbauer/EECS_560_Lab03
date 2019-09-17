#ifndef QUADRATIC_PROBING_HASH_TABLE_H
#define QUADRATIC_PROBING_HASH_TABLE_H
#include "Restauraunt.h"

//  A hash table data structure with quadratic probing
class QuadraticProbingHashTable{
    public:

    //  Default constructor, initializes R and m values
    QuadraticProbingHashTable();
    ~QuadraticProbingHashTable();

    //  Inserts the Restauraunt object into the hash table
    //  This uses the hash function and, if a collision exists, a 
    //  call to the recursive hash function.
    //  Returns bool if insertion is impossible, i.e. it is a duplicate
    //  value or the search loops forever.
    bool insert(Restauraunt entry);

    //  Prints the data structure in the format specified by the professor
    void print();

    //  Searches for and removes the Restauraunt object with the specified name.
    //  Returns false if the Restauraunt object cannot be found.
    bool remove(string name);

    //  Searches for the Restauraunt object by name.
    //  Returns the index of the restauraunt on the hash table.
    //  Returns -1 otherwise.
    int searchByName(string name);

    //  Searches for and prints out a list of all restauraunts with
    //  the given rating.  Displays an error if none are found.
    void searchByRating(int rating);

    //  Searches for and prints out a list of all restauraunts with
    //  the given price.  Displays an error if none are found
    void searchByPrice(int price);


    private:

    //  The hash function strictly used for insertion.
    //  Note: this class uses quadratic probing.
    int hashFunction(string name);

    //  The hash function used for search and delete.
    //  It is different because it reacts differently to whether or
    //  not a particular location is empty.  I thought of combining
    //  these into one hash function with a flag to determine which
    //  type it was, but I'm not sure it would save that much space.
    int hashFunctionForSearch(string name);

    //  Recursive versions of the above two functions.  The original
    //  function itself could be written to be recursive, but this 
    //  was much clearer for me when writing.
    int recursiveHash(string name, int orginalIndex, int iteration);
    int recursiveHashForSearch(string name, int originalIndex, int iteration);

    //  Tracks how large the hash table is.  It should remain unchanged
    //  in this application.
    int m_tableSize;

    //  Unusued in quadratic probing.
    int m_R;
    Restauraunt* m_table;

};

#endif