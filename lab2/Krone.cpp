// NAME BLOCK
// Lab:  02
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 02 is to demonstrate the principles of OOP, including
// encapsulation, inheritance, and polymorphism.
///////////////////////////////////////////////////////////////////////////

#include "Currency.cpp"

// Krone class inherits from the Currency class. Represents 'Krone'
// currency object.
class Krone: public Currency {
    protected:
    const std::string name = "Krone";

    public:
    // Krone class constructor.
    Krone() : Currency() {

    }

    // Overloaded Krone class constructor (double input).
    Krone(double num) : Currency(num) {

    }
    
    // Overloaded Krone constructor. This is a copy constructor
    // which takes in a (Krone) object input by reference.
    Krone(const Krone &c) : Currency(c) {
        
    }

    // Krone class destructor.
    ~Krone() {

    }

    virtual std::string getName() const {
        // PURPOSE: Returns the name of the object to the caller.
        // PRE:    - Method must be called using class instance.
        // POST:   - Nothing is changed.
        // RETURN: - Returns the name as a string.
        
        return name;
    }

};