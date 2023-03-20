// NAME BLOCK
// Lab:  05
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 05 is to demonstrate Hash Tables and their algorithms 
// in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include <cmath>
#include "Krone.cpp"

class HashTable {
    private:
    static const int size = 29; // Size of array
    Krone* arr[size];     // Array to store hash elements
    int numOfItemsLoaded; // Number of Items Loaded in Hashtable
    int numOfCollisions;  // Number of Collisions while loading

    public:
    // HashTable class constructor
    HashTable() {
        for(int i = 0; i < 29; i++) {
            arr[i] = nullptr;
        }
        numOfItemsLoaded = 0;
        numOfCollisions = 0;
    }

    // HashTable class destructor
    ~HashTable() {
        
    }

    void quadraticProbing(int& i, int probe) {
        // PURPOSE: Calculates new index to insert key if there is a collision.
        // PRE:    - Method must be called using class instance.
        //         - i: the calculated index.
        //         - probe: variable used in calculation to calculate new index.
        // POST:   - The index variable is changed to the new calculation.
        // RETURN: - Nothing is returned.
        int const c1 = 2;
        int const c2 = 7;
        i += c1*probe + c2*probe*probe;
        i = i%size;
    }
    
    int pseudoRandomHashScheme(Krone* &kr) {
        // PURPOSE: Calculates index to insert key based on the value.
        // PRE:    - Method must be called using class instance.
        //         - Key's value must be initialized to an integer.
        //         - kr: Krone object pointer to be inserted into HashTable.
        //         - m, n: variable used in pseudo random generator hashing.
        //         - w, f: values of kr used in calculation.
        //         - size: size of HashTable array and used in calculation. 
        //         - probe: variable used in calculation to calculate new index.
        // POST:   - Nothing is changed.
        // RETURN: - The hash value is returned.
        int const m = 2;
        int const n = 3;
        int const size = 29;
        int w = kr->getWhole();
        int f = kr->getFraction();
        
        return (m*w + n*f)%size;
    }

    void hash(Krone* kroneToBeInserted) {
        // PURPOSE: Inserts key/value pair into HashTable.
        // PRE:    - Method must be called using class instance.
        //         - kroneToBeInserted: Krone object pointer to be 
        //           inserted into HashTable, and cannot be null.
        // POST:   - The Krone object pointer is inserted into the
        //           HashTable.
        // RETURN: - Nothing is returned.
        int i = pseudoRandomHashScheme(kroneToBeInserted);
        int n = 1;
        while(arr[i] != nullptr) {
            numOfCollisions++;
            quadraticProbing(i, n);
            n++;
        }
        arr[i] = kroneToBeInserted;
        numOfItemsLoaded++;
    }
    
    int search(Krone* kroneToBeSearched) {
        // PURPOSE: Inserts key/value pair into HashTable.
        // PRE:    - Method must be called using class instance.
        //         - kroneToBeInserted: Krone object pointer to be 
        //           inserted into HashTable, and cannot be null.
        // POST:   - The Krone object pointer is inserted into the
        //           HashTable.
        // RETURN: - Nothing is returned.
        int i = pseudoRandomHashScheme(kroneToBeSearched);
        if(arr[i] == nullptr) return -1;
        else if(arr[i]->isEqual(*kroneToBeSearched)) return i;
        else {
            int n = 1;
            while(!(arr[i]->isEqual(*kroneToBeSearched))) {  // check for cycling
                quadraticProbing(i, n);
                if(arr[i] == nullptr) return -1;
                n++;
            }
            return i;
        }
        return -1;
    }
    
    int getNumOfItemsLoaded() {
        // PURPOSE: Returns the number of items loaded.
        // PRE:    - Method must be called using class instance.
        // POST:   - Nothing is changed.
        // RETURN: - The number of items loaded is returned.
        return numOfItemsLoaded;
    }

    int getNumOfCollision() {
        // PURPOSE: Returns the number of collisions.
        // PRE:    - Method must be called using class instance.
        // POST:   - Nothing is changed.
        // RETURN: - The number of collisions loaded is returned.
        return numOfCollisions;
    }
};