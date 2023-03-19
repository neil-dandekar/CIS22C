// NAME BLOCK
// Lab:  02
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 02 is to demonstrate the principles of OOP, including
// encapsulation, inheritance, and polymorphism.
///////////////////////////////////////////////////////////////////////////

// MODIFIED FOR LAB 4:
// * Line 178: print() method

#include <iostream>
#include <iomanip>
#include <typeinfo>
#ifndef CURRENCY
#define CURRENCY

inline double combineWholeAndFraction(int whole, int fraction) {
    // PURPOSE: Combine two integers into a double
    // PRE:  - whole: an integer representing the whole part
    //       - fraction: an integer representing the fractional part
    // POST:
    // RETURN: - returns a double of the combined integers

    double number;
    std::string fractionS = std::to_string(fraction);
    fractionS = "." + fractionS;
    number = whole + std::stod(fractionS);
    return number;
}

inline int divideNumIntoWholeAndFraction(double num, int& whole) {
    // PURPOSE: Convert a double into two integers representing the whole part and fractional part
    // PRE:  - whole: an integer representing the whole part
    //       - num: the double to be converted
    // POST:
    // RETURN: - returns the fractional part and uses pass-by-reference to return the whole part

    std::string s = std::to_string(num);
    
    std::string wholeS = s.substr(0, s.std::string::find("."));
    std::string fractionS = s.substr(s.std::string::find(".")+1, s.length());

    fractionS.erase(fractionS.find_last_not_of('0') + 1, std::string::npos);
    fractionS.erase(fractionS.find_last_not_of('.') + 1, std::string::npos);

    whole = std::stoi(wholeS);
    if(fractionS.length() == 0) fractionS = "0";
    int fraction = std::stoi(fractionS);

    return fraction;
}

// NegativeCurrencyException handles errors that occur when the value of
// a Currency object is negative.
class NegativeCurrencyException : public std::runtime_error {
    public:
        NegativeCurrencyException(std::string errMsg) : std::runtime_error(errMsg) {

        }
};

// IncompatibleCurrencyException handles errors that occur when multiple
// Currency objects are compared with different polymorphic types.
class IncompatibleCurrencyException : public std::runtime_error {
    public:
        IncompatibleCurrencyException(std::string errMsg) : std::runtime_error(errMsg) {

        }
};

// Currency class acts as the base class for all derived Currency types.
class Currency {
    protected:
    int whole;      // Whole number part of the Currency object value
    int fractional; // Fractional part of the Currency object value

    public:
    // add getter for whole and fraction for lab5
    int getWhole() {
        return whole;
    }
    int getFraction() {
        return fractional;
    }
    
    
    // Currency class constructor.
    Currency() {
        whole = 0;
        fractional = 0;
    }

    // Overloaded Currency constructor. Takes in (double) input.
    Currency(double num) {
        if (num < 0)
            throw NegativeCurrencyException("Invalid input: Currency can't be negative.");
        fractional = divideNumIntoWholeAndFraction(num, whole);
    }

    // Overloaded Currency constructor. This is a copy constructor
    // which takes in a (Currency) object input by reference.
    Currency(const Currency &c) {
        whole = c.whole;
        fractional = c.fractional;

    }

    // Currency class destructor
    ~Currency() {

    }
    
        // PURPOSE: These method(s) return information about the object to the caller.
        // PRE:    - Method must be called using class instance.
        // POST:   - 
        // RETURN: - Returns the specified information.
    virtual std::string getName() const = 0;
    
    void SameCurrency(const Currency& another, std::string operation) {
        // PURPOSE: This method determines if this object is the same type as the passed object
        // PRE:    - another: a reference to a Currency object
        //         - operation: a string describing the operation being performed
        // POST:   - Throws IncompatibleCurrencyException if the objects are not the same type
        // RETURN: - No return value

        if(typeid(*this).name() != typeid(another).name())
            throw IncompatibleCurrencyException("Invalid " + operation + ": can't perform operation on different currencies.");
    }

    void add(const Currency& another) {
        // Adds value of the input Currency object to the value of the
        // member Currency object.
        // Pre: another-a reference varibale of Currency object
        // fractional value of this and another has to be greater than or equal to 0 and less than 100. Whole value of this and another are greater than or equal to 0. This currency and the another currency has to be the same currency.
        // post: this value is the sum of this previous value and another's value. another is not changed.

        SameCurrency(another, "addition");
        double num1 = combineWholeAndFraction(whole, fractional);
        double num2 = combineWholeAndFraction(another.whole, another.fractional);
        double num3 = num1 + num2;
        fractional = divideNumIntoWholeAndFraction(num3, whole);
    }

    void subtract(const Currency& another) {
        // Subtracts value of the input Currency object from the value of
        // the member Currency object.
        // Pre: another-a reference varibale of Currency object
        // fractional value of this and another has to be greater than or equal to 0 and less than 100. Whole value of this and another are greater than or equal to 0. This currency and the another currency has to be the same currency.
        // Post: this value is the difference of this previous value and another's value. another is not changed.

        SameCurrency(another, "subtraction");
        double num1 = combineWholeAndFraction(whole, fractional);
        double num2 = combineWholeAndFraction(another.whole, another.fractional);
        if (num1 < num2)
            throw NegativeCurrencyException("Invalid subtraction: can't have negative value currency.");
        double num3 = num1 - num2;
        fractional = divideNumIntoWholeAndFraction(num3, whole);
    }
    
    bool isEqual(const Currency& another) {
        // Returns true if the member Currency object value is equal to
        // the the value of the input Currency object and false otherwise.
        // Pre: another-a reference varibale of Currency object
        // fractional value of this and another has to be greater than or equal to 0 and less than 100. Whole value of this and another are greater than or equal to 0. This currency and the another currency has to be the same currency.
        // Post: nothing changed. true or false

        SameCurrency(another, "comparison");
        double thisValue = combineWholeAndFraction(this->whole, this->fractional);
        double anotherValue = combineWholeAndFraction(another.whole, another.fractional);
        return thisValue == anotherValue;
    }

    bool isGreater(const Currency& another) {
        // Returns true if the member Currency object value is greater than
        // the the value of the input Currency object and false otherwise.
        // Pre: another-a reference varibale of Currency object
        // fractional value of this and another has to be greater than or equal to 0 and less than 100. Whole value of this and another are greater than or equal to 0. This currency and the another currency has to be the same currency.
        // post: nothing changed.true or false

        SameCurrency(another, "comparison");
        double thisValue = combineWholeAndFraction(this->whole, this->fractional);
        double anotherValue = combineWholeAndFraction(another.whole, another.fractional);
        return thisValue > anotherValue;
    }

    // MODIFIED - now outputs to file and console
    void print(std::ostream& s = std::cout) { // MODIFIED for file output
        // Returns the member Currency object as a std::string format.
        // Pre: fractional value has to be greater than or equal to 0 and less than 100. Whole value is greater than or equal to 0.
        // post: nothing changed.
        s << std::setprecision(2) << std::fixed << combineWholeAndFraction(whole, fractional) << " " << getName();
    }
};

#endif // CURRENCY
