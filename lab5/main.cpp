//
//  main.cpp
//  lab5
//
//  Created by Xi Gao on 3/13/23.
//

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
    HashTable kroneHashTable;
    for(int i = 0; i < 20; i++) {
        kroneHashTable.hash(kr[i]);
    }
    
    int numOfItemLoaded = kroneHashTable.getNumOfItemLoaded();
    cout << "Number of data items loaded: " << numOfItemLoaded << endl;
    cout << "Load factor: " << numOfItemLoaded*100/29 << "%"  << endl;
    cout << "Number of collisions: " << kroneHashTable.getNumOfCollision() << endl;
    
    char answer;
    do{
        cout << "Please enter a Krone number to search for: ";
        double value;
        cin >> value;
        Krone* kroneForSearch = new Krone(value);
        int i = kroneHashTable.search(kroneForSearch);
        if (i == -1) {
            cout << "Invalid Data." << endl;
        }
        else {
            cout << "Index where found in the hash table: " << i << endl;
        }
        cout << "Do you want to check again or end the program? Y for check, N for end. " << endl;
        cin >> answer;
    } while(answer == 'Y');
    
    for(int i = 0; i < 20; i++) {
        delete kr[i];
    }
    return 0;
}
