// NAME BLOCK
// Lab:  05
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 05 is to demonstrate Hash Tables and their algorithms 
// in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include "HashTable.cpp"
using namespace std;

int main() {
    double arr[20] =
        {57.12, 23.44, 87.43, 68.99, 111.22, 44.55,
        77.77, 18.36, 543.21, 20.21, 345.67, 36.18,
        48.48, 101.00, 11.00, 21.00, 51.00, 1.00,
        251.00, 151.00};

    // Create Krone array
    Krone* kr[20];
    for(int i = 0; i < 20; i++) {
        kr[i] = new Krone(arr[i]);
    }

    // Create HashTable
    HashTable kroneHashTable;
    for(int i = 0; i < 20; i++) {
        kroneHashTable.hash(kr[i]);
    }
    
    int numOfItemLoaded = kroneHashTable.getNumOfItemsLoaded();
    cout << "Number of data items loaded: " << numOfItemLoaded << endl;
    cout << "Load factor: " << setprecision(4) << numOfItemLoaded*100/29.0 << "%"  << endl;
    cout << "Number of collisions: " << kroneHashTable.getNumOfCollision() << endl;
    
    char answer;
    do {
        cout << "\nPlease enter a Krone number to search for: ";
        double value;
        cin >> value;
        int i = kroneHashTable.search(new Krone(value));
        if(i == -1) cout << "Krone value " << value << " was not found." << endl;
        else cout << "Krone value " << value << " found at index " << i << "."<< endl;
        cout << "Search again (Y/N)? ";
        cin >> answer;
    } while(answer == 'Y');
    cout << "_______________________________\nThank you for using our program. "
    << "\n-Neil Dandekar and Xi Gao, 03.19.2023" << endl;
    
    for(int i = 0; i < 20; i++) {
        delete kr[i];
    }

    return 0;
}
