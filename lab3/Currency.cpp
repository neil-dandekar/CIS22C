// NAME BLOCK
// Lab:  02
// Name: Neil Dandekar & Xi Gao
// The purpose of lab 02 is to demonstrate the principles of OOP, including
// encapsulation, inheritance, and polymorphism.
///////////////////////////////////////////////////////////////////////////

#include <iostream>
#include <iomanip>
#include <typeinfo>
#ifndef CURRENCY
#define CURRENCY

inline double combineWholeAndFraction(int whole, int fraction) {
    // PURPOSE:  Combines two integers into a double.
    // PRE:    - whole: an integer greater than or equal to 0 representing the whole part
    //         - fraction: an integer greater than or equal to 0 and less than or equal 
    //           to 100 representing the fractional part.
    // POST:   - Nothing is changed
    // RETURN: - returns a double representing the combined integers.

    double number;
    std::string fractionS = std::to_string(fraction);
    fractionS = "." + fractionS;
    number = whole + std::stod(fractionS);
    return number;
}

inline int divideNumIntoWholeAndFraction(double num, int& whole) {
    // PURPOSE:  Convert a double into two integers representing the whole part 
    //           and fractional part
    // PRE:    - whole: an integer greater than or equal to 0 representing the whole part
    //         - num: the double to be converted which may not have more than two decimal digits
    // POST:   - Nothing is changed
    // RETURN: - returns the fractional part of the double
    //         - uses pass-by-reference to return the whole part of the double

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
        NegativeCurrencyException(std::string errMsg) : 
        std::runtime_error(errMsg) {

        }
};

// IncompatibleCurrencyException handles errors that occur when multiple
// Currency objects are compared with different polymorphic types.
class IncompatibleCurrencyException : public std::runtime_error {
    public:
        IncompatibleCurrencyException(std::string errMsg) : 
        std::runtime_error(errMsg) {

        }
};

// Currency class acts as the base class for all derived Currency types.
class Currency {
    protected:
    int whole;      // Whole number part of the Currency object value
    int fractional; // Fractional part of the Currency object value

    public:
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

    // GETTER METHOD(S)
        // PURPOSE:  These method(s) return information about the object to 
        //           the caller.
        // PRE:    - Method must be called using class instance.
        // POST:   - Nothing is changed
        // RETURN: - Returns the specified information.
    virtual std::string getName() const = 0;

    // END GETTER METHOD(S)

    void SameCurrency(const Currency& another, std::string operation) {
        // PURPOSE:  This method determines if this object is the same type as the passed 
        //           object
        // PRE:    - another: a reference to a Currency object
        //         - operation: a string describing the operation being performed
        // POST:   - Throws IncompatibleCurrencyException if the member is not the same 
        //           type as another.
        // RETURN: - No return value.

        if(typeid(*this).name() != typeid(another).name())
            throw IncompatibleCurrencyException("Invalid " + operation + 
            ": can't perform operation on different currencies.");
    }

    void add(const Currency& another) {
        // PURPOSE:  Adds value of the input Currency object to the value of the
        //           member Currency object.
        // PRE:    - another: a reference to a Currency object
        //         - The fractional value of both this and another have to be greater than or 
        //           equal to 0 and less than 100. 
        //         - The whole value of both this and another have to be greater than or equal 
        //           to 0. 
        //         - Both this and another have to be Currency objects of the same type
        // POST:   - The value of *this is the sum of *this previous value and another's value. 
        //         - another is not changed.
        // RETURN: - No return value.

        SameCurrency(another, "addition");
        double num1 = combineWholeAndFraction(whole, fractional);
        double num2 = combineWholeAndFraction(another.whole, another.fractional);
        double num3 = num1 + num2;
        fractional = divideNumIntoWholeAndFraction(num3, whole);
    }

    void subtract(const Currency& another) {
        // PURPOSE:  Subtracts value of the input Currency object to the value of the
        //           member Currency object.
        // PRE:    - another: a reference to a Currency object
        //         - The fractional value of both this and another have to be greater than or 
        //           equal to 0 and less than 100. 
        //         - The whole value of both this and another have to be greater than or equal 
        //           to 0. 
        //         - Both this and another have to be Currency objects of the same type.
        // POST:   - The value of *this is the difference of *this previous value and another's value.
        //         - Throws NegativeCurrencyException if the operation results in a negative value.
        //         - another is not changed.
        // RETURN: - No return value.

        SameCurrency(another, "subtraction");
        double num1 = combineWholeAndFraction(whole, fractional);
        double num2 = combineWholeAndFraction(another.whole, another.fractional);
        if (num1 < num2)
            throw NegativeCurrencyException("Invalid subtraction: can't have negative value currency.");
        double num3 = num1 - num2;
        fractional = divideNumIntoWholeAndFraction(num3, whole);
    }
    
    bool isEqual(const Currency& another) {
        // PURPOSE:  Checks if the value of *this is equal to the value of another
        // PRE:    - another: a reference to a Currency object
        //         - The fractional value of both this and another have to be greater than or 
        //           equal to 0 and less than 100. 
        //         - The whole value of both this and another have to be greater than or equal 
        //           to 0. 
        //         - Both this and another have to be Currency objects of the same type.      
        // POST:   - Nothing is changed. 
        // RETURN: - Returns true if both objects have the same value and false if not.

        SameCurrency(another, "comparison");
        double thisValue = combineWholeAndFraction(this->whole, this->fractional);
        double anotherValue = combineWholeAndFraction(another.whole, another.fractional);
        return thisValue == anotherValue;
    }

    bool isGreater(const Currency& another) {
        // PURPOSE:  Checks if the value of *this is greater than the value of another.
        // PRE:    - another: a reference to a Currency object
        //         - The fractional value of both this and another have to be greater than or 
        //           equal to 0 and less than 100. 
        //         - The whole value of both this and another have to be greater than or equal 
        //           to 0. 
        //         - Both this and another have to be Currency objects of the same type.  
        // POST:   - Nothing is changed.
        // RETURN: - Returns true if the value of *this is greater than the value of another
        //           and false otherwise

        SameCurrency(another, "comparison");
        double thisValue = combineWholeAndFraction(this->whole, this->fractional);
        double anotherValue = combineWholeAndFraction(another.whole, another.fractional);
        return thisValue > anotherValue;
    }

    void print() {
        // PURPOSE:  Prints the member Currency object.
        // PRE:    - *this must have a value greater than or equal to 0
        // POST:   - The value of the object is printed along with its name.
        // RETURN: - Nothing is returned.
        std::cout << std::setprecision(2) << std::fixed << combineWholeAndFraction(whole, fractional) << " " << getName();
    }
};

#endif // CURRENCY