// NAME BLOCK
// Lab:  02
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 02 is to demonstrate the principles of OOP, including
// encapsulation, inheritance, and polymorphism.
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include "Currency.cpp"
#include "Soum.cpp"
#include "Krone.cpp"

using namespace std;

int main() {
    Currency* currArray[2] = {new Soum(), new Krone()}; // Array of Currency pointers
    Currency* c;        // Temp currency pointer used for operations
    int index = -1;     // Index of Currency pointer to change in currArray
    char operation;     // The operation (add or subtract) to be performed
    char object;        // The type of the object that will be manipulated
    double amount;      // The value (amount) of the object performing the operation
    string type;        // The type of the object performing the operation

    while(true) {
        try {
            // Printing current object state:
            currArray[0]->print();
            cout << " ";
            currArray[1]->print();
            cout << endl;
            cout << endl << "Input: ";

            // Quit program if 'q' is entered:
            cin >> operation;
            if(operation == 'q') break;

            // Otherwise, collect other data.
            cin >> object >> amount >> type;

            if(type == "Soum") index = 0;
            else if(type == "Krone") index = 1;

            if(object == 'k') c = new Krone(amount);
            else if(object == 's') c = new Soum(amount);

            if(operation == 'a') currArray[index]->add(*c);
            else if(operation == 's') currArray[index]->subtract(*c);
            
        }

        // Catch exception that occurs when a Currency object has a negative value
        catch(const NegativeCurrencyException &e) {
            cout << e.what() << endl;
        }

        // Catch exception that occurs when two Currency objects are compared with different
        // types
        catch(const IncompatibleCurrencyException &e) {
            cout << e.what() << endl;
        }
    }
}