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
    Krone* arr[29];
    int numOfItemLoaded = 0;
    int numOfCollision = 0;

    public:
    HashTable() {
        for(int i = 0; i < 29; i++) {
            arr[i] = nullptr;
        }
    }
    ~HashTable(){
        
    }
    void quadraticProbing(int& i, int& probe) {  // update for less collison time
        i += pow(probe, 2);
        if(i > 28) {
            i = i -29;
            numOfCollision++;
        }
        
    }
    
    int pseudorandomHashScheme(Krone*& krone) {
        int const m = 2;
        int const n = 3;
        int const size = 29;
        int w = krone->getWhole();
        int f = krone->getFraction();
        int i = 0;
        i = (m*w + n*f)%size;
        return i;
    }
    void hash(Krone* kroneToBeInserted) {
        int i = pseudorandomHashScheme(kroneToBeInserted);
        if (arr[i] == nullptr) {
            arr[i] = kroneToBeInserted;
            numOfItemLoaded++;
        }
        else {
            int n = 1;
            while(arr[i] != nullptr) {
                quadraticProbing(i, n);
                n++;
            }
            arr[i] = kroneToBeInserted;
            numOfItemLoaded++;
        }
    }
    
    int search(Krone* kroneToBeSearched) {
        int i = pseudorandomHashScheme(kroneToBeSearched);
        if (arr[i] == nullptr) {
            return -1;
        }
        else if (arr[i]->isEqual(*kroneToBeSearched)) {
            return i;
        }
        else {
            int n = 1;
            while(!(arr[i]->isEqual(*kroneToBeSearched))) {  // check for cycling
                quadraticProbing(i, n);
                if (arr[i] == nullptr) {
                    return -1;
                }
                n++;
            }
            return i;
        }
        
        
        return -1;
    }
    
    int getNumOfItemLoaded() {
        return numOfItemLoaded;
    }
    int getNumOfCollision() {
        return numOfCollision;
    }
    
};
