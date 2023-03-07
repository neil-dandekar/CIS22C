// NAME BLOCK
// Lab:  04
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 04 is to demonstrate Trees (Binary Search Trees) and 
// its algorithms in OOP programming.
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <fstream>
#include "BST.cpp"
#include "Currency.cpp"
#include "Krone.cpp"
#include "Queue.cpp"
#include "SinglyLinkedList.cpp"

using namespace std;

int main() {
    // Welcome message
    cout << "Welcome to Lab 4 - Binary Search Trees\nCreated by Xi and Neil\n" << endl;

    // Temp array of Krone values
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
    
    ofstream myFile;
    myFile.open("output.txt");

    // BST tree
    BST tree(myFile);
    for(int i = 0; i < 20; i++) {
        tree.insert(tree.getRoot(), kr[i]);
    }

    // BST print
    tree.print();

    // Run UI
    cout << "\nInstructions: Type a number (1-5) to select an operation:" << endl;
    cout << "\t1. Add Krone" << endl;
    cout << "\t2. Delete Krone" << endl;
    cout << "\t3. Search Krone" << endl;
    cout << "\t4. Print BST Traversals" << endl;
    cout << "\t5. Print BST Traversals & Exit Program" << endl;

    while(true) {
        int i = 0;
        while(true) {
            string input;
            cout << "\nChoose an operation: ";
            getline(cin, input);
            try {
                i = stoi(input);
            }
            catch(const std::exception& e) {
                cout << "ERROR: Operation # must be an integer. Please try again." << endl;
            }
            if(i < 1 || i > 5) cout << "ERROR: Operation # must be between 1 and 5. Please try again." << endl;
            else break;
        }

        double value = 0;
        switch(i) {
            // Add Krone:
            case 1: {
                cout << "Enter Krone value to add: ";
                cin >> value;
                if(value < 0) {
                    cout << "Ignored. Krone value \'"<< value << "\' is invalid." << endl;
                    myFile << "Ignored. Krone value \'"<< value << "\' is invalid." << endl;
                }
                else if(tree.search(new Krone(value)) != nullptr) {
                    cout << "Ignored. Krone value \'" << value << "\' already exists in tree." << endl;
                    myFile << "Ignored. Krone value \'" << value << "\' already exists in tree." << endl;
                }
                else tree.insert(tree.getRoot(), new Krone(value));
                break;
            }

            // Delete Krone:
            case 2: {
                cout << "Enter Krone value to delete: ";
                cin >> value;
                if(value < 0) {
                    cout << "Ignored. Krone value \'"<< value << "\' is invalid." << endl;
                    myFile << "Ignored. Krone value \'"<< value << "\' is invalid." << endl;
                }
                else if(tree.search(new Krone(value), *(new BSTNode())) == nullptr) {
                    cout << "Ignored. Krone value \'" << value << "\' does not exist in tree." << endl;
                    myFile << "Ignored. Krone value \'" << value << "\' does not exist in tree." << endl;
                }
                // else tree.deleteNode(new Krone(value));
                break;
            }

            // Search Krone:
            case 3: {
                cout << "Enter Krone value to search: ";
                cin >> value;
                if(value < 0) {
                    cout << "Ignored. Krone value \'"<< value << "\' is invalid." << endl;
                    myFile << "Ignored. Krone value \'"<< value << "\' is invalid." << endl;
                }
                else {
                    BSTNode* node = tree.search(new Krone(value), *(new BSTNode()));
                    if(node == nullptr) {
                        cout << "Krone value \'" << value << "\' was not found." << endl;
                        myFile << "Krone value \'" << value << "\' was not found." << endl;
                    }
                    else {
                        cout << "Found Krone value \' ";
                        node->getKr()->print();
                        cout << "'." << endl;

                        myFile << "Found Krone value \' ";
                        node->getKr()->print(myFile);
                        myFile << "'." << endl;
                    }
                }
                break;
            }

            // Print BST:
            case 4: {
                tree.print();
                break;
            }

            // Print BST & Exit:
            case 5:  {
                tree.print();
                cout << "_______________________________\nThank you for using our program. "
                << "\n-Neil Dandekar and Xi Gao, 03.04.2023" << endl;
                break;
            }

            default:
                break;
        }
        if(i == 5) break;

        string s;
        getline(cin, s);
    }
    
    myFile.close();

    // Cleanup
    for(int i = 0; i < 20; i++) {
        delete kr[i];
    }
    
    return 0;
}