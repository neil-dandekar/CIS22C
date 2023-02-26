// NAME BLOCK
// Lab:  01
// Name: Neil Dandekar
// The purpose of lab 01 is to demonstrate our knowledge of data management, loops,
// conditional statements, and recursion to produce efficient algorithms.

#include <iostream>
#include <sstream>
#include <cmath>

using namespace std;

bool isArrayPrimeIter(int *arr, int size) {
    // PURPOSE: This algorithm determines if an array only contains primes by iteration.
    // PRE:    - arr:  a pointer to an array of positive integers.
    //         - size: a positive integer representing the length of arr.
    // POST:   - Prints a statement when entering and one when leaving the function.
    // RETURN: - Returns true if arr only contains prime numbers.
    //         - Returns false if arr contains at least one non-prime number.
    // PSEUDOCODE:
    // 1. PRINT entering function message
    // 2. FOR each number in arr
    //     1. IF number <= 1 OR number is even OR number % 3 is 0 THEN
    //         1. PRINT leaving function message
    //         2. RETURN false
    //        END_IF
        
    //     2. FOR i = 5 to (number)^1/2, every 6th i
    //         1. IF number % i is 0 OR number % (i + 2) is 0 THEN
    //             1. PRINT leaving function message
    //             2. RETURN false
    //            END_IF
    //        END_FOR
    //    END_FOR
    // 3. PRINT leaving function message
    // 4. RETURN true
    
    cout << "\nEntering isArrayPrimeIter" << endl;

    for(int i = 0; i < size; i++) {
        if(*(arr + i) <= 1 || *(arr + i) % 2 == 0 || *(arr + i) % 3 == 0) {
            cout << "Leaving isArrayPrimeIter" << endl;
            return false;
        }

        for(int j = 5; j * j <= *(arr + i); j += 6) {
            if((*(arr + i) % j == 0 || *(arr + i) % (j + 2) == 0)) {
                cout << "Leaving isArrayPrimeIter" << endl;
                return false;
            }
        }
    }

    cout << "Leaving isArrayPrimeIter" << endl;
    return true;
}

bool isPrimeRecur(int num, int div) {
    // PURPOSE: This algorithm determines if a number (>3) is prime by recursion.
    // PRE:    - num: a positive integer representing the possible prime number.
    //                must use num > 3 when calling function.
    //         - div: a positive integer representing the divisor for testing. 
    //                must use div = 5 when calling function.
    // POST:   - Prints a statement when entering and one when leaving the function.
    // RETURN: - Returns true if num is prime.
    //         - Returns false if num is not prime.
    // PSEUDOCODE:
    // 1. PRINT entering function message
    // 2. IF div > num^1/2 THEN
    //     1. PRINT leaving function message
    //     2. RETURN true
    //    ELSE IF num % div is 0 OR num % (div + 2) is 0 THEN
    //     1. PRINT leaving function message
    //     2. RETURN false
    //    END_IF
    // 3. PRINT leaving function message
    // 4. (RECURSION) CALL isPrimeRecur(num, div + 6)

    cout << "\tEntering isPrimeRecur" << endl;

    if((div * div) > num) {
        cout << "\tLeaving isPrimeRecur" << endl;
        return true;
    }

    else if(num % div == 0 || num % (div + 2) == 0) {
        cout << "\tLeaving isPrimeRecur" << endl;
        return false;
    }

    cout << "\tLeaving isPrimeRecur" << endl;
    return isPrimeRecur(num, div + 6);
}

bool isArrayPrimeRecur(int *arr, int size) {
    // PURPOSE: This algorithm determines if an array only contains primes by recursion.
    // PRE:    - arr:  a pointer to an array of positive integers.
    //         - size: a positive integer representing the length of arr.
    // POST:   - Prints a statement when entering and one when leaving the function.
    // RETURN: - Returns true if arr only contains prime numbers.
    //         - Returns false if arr contains at least one non-prime number.
    // PSEUDOCODE:
    // 1. PRINT entering function message
    // 2. IF size is 0 THEN
    //     1. PRINT leaving function message
    //     2. RETURN true
    //    END_IF
    // 3. IF *arr <= 1 OR *arr is even OR *arr % 3 is 0 OR NOT isPrimeRecur(*arr, 5) THEN
    //     1. PRINT leaving function message
    //     2. RETURN false
    //    END_IF
    // 2. PRINT leaving function message
    // 3. IF size is 1 THEN
    //     1. RETURN true
    //    ELSE
    //     1. (RECURSION) CALL isArrayPrimeRecur(arr + 1, size - 1)
    //    END_IF

    cout << "\nEntering isArrayPrimeRecur" << endl;

    if(size == 0) {
        cout << "Leaving isArrayPrimeRecur" << endl;
        return true;
    }

    if(*arr <= 1 || *arr % 2 == 0 || *arr % 3 == 0 || !isPrimeRecur(*arr, 5)) {
        cout << "Leaving isArrayPrimeRecur" << endl;
        return false;
    }

    cout << "Leaving isArrayPrimeRecur" << endl;
    if(size == 1) return true;
    else return isArrayPrimeRecur(arr + 1, size - 1);
}

int main() {
    const int SORT_MAX_SIZE = 8;        // Global integer constant
    
    // Prompt user for input:
    cout << "Please enter your input data on one line only: ";

    int size;                           // Size of array
    cin >> size;                        // Read input for size
    int* array = new int[size];         // Initialize array (dynamically/pointer),
                                        // using size from input

    for(int i = 0; i < size; i++) {     // Loop through array
        int num;                        // Temp variable to store input
        cin >> num;                     // Read input for next array element
        array[i] = num;                 // Append value to array
    }

    // The following code calls each of the isArrayPrime (iteration & recursion), feeding
    // array and size as input parameters. Then, a statement is printed corresponging to
    // the output of the function calls.
    if(isArrayPrimeIter(array, size)) cout << "\nArray was found to be prime " 
        << "using iteration." << endl;
    else cout << "\nNot a prime array using iteration." << endl;
    
    if(isArrayPrimeRecur(array, size)) cout << "\nArray was found to be prime "
        << "using recursion." << endl;
    else cout << "\nNot a prime array using recursion." << endl;

    // Thank you message.
    cout << "_______________________________\nThank you for using my program. "
         << "\n-Neil Dandekar, 01.18.2023" << endl;
}