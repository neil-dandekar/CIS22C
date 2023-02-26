// NAME BLOCK
// Lab:  02
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 02 is to demonstrate the principles of OOP, including
// encapsulation, inheritance, and polymorphism.
///////////////////////////////////////////////////////////////////////////

#include "Currency.cpp"

// Soum class inherits from the Currency class. Represents 'Soum'
// currency object.
class Soum: public Currency {
    protected:
    const std::string name = "Soum";

    public:
    // Soum class constructor.
    Soum() : Currency() {

    }

    // Overloaded Soum class constructor (double input).
    Soum(double num) : Currency(num) {

    }

    // Overloaded Soum constructor. This is a copy constructor
    // which takes in a (Soum) object input by reference.
    Soum(const Soum &c) : Currency(c) {
        
    }

    // Soum class destructor.
    ~Soum() {

    }
    
    virtual std::string getName() const {
        // PURPOSE: Returns the name of the object to the caller.
        // PRE:    - Method must be called using class instance.
        // POST:   - Nothing is changed.
        // RETURN: - Returns the name as a string.
        
        return name;
    }
    
};