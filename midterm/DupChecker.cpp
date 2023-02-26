#include <iostream>
#include <sstream>

using namespace std;

bool sortAlpha(string s1, string s2) {
    int len = 0;
    if(s1 == s2) return true;
    if(s1.length() < s2.length()) len = s1.length();
    else len = s2.length();

    for(int i = 0; i < len; i++) {
        if(s1[i] < s2[i]) return true;
    }
    return false;
}

string* insertionSort(string arr[], int n) {
    for (int i = 1; i < n; i++) {

        string nextWord = arr[i];
        int loc = i;

        while((loc > 0) && (!sortAlpha(nextWord, arr[loc-1]))) {
            cout << nextWord << " " << arr[loc-1] << endl;
            arr[loc] = arr[loc - 1];
        }
        
        arr[loc] = nextWord;
        loc--;
    }
    return arr;
}


void insertionSort1(int theArray[], int n) {
    for ( int unsorted = 1; unsorted < n; unsorted++)
 {
 // At this point, theArray[0..unsorted-1] is sorted.
 // Find the right position (loc) in theArray[0..unsorted]
 // for theArray[unsorted], which is the first entry in the
 // unsorted region; shift, if necessary, to make room
 int nextItem = theArray[unsorted];
 int loc = unsorted;
 while ((loc > 0) && (theArray[loc - 1] > nextItem))
 {
 // Shift theArray[loc - 1] to the right
 theArray[loc] = theArray[loc - 1];
 } // end for
 // At this point, theArray[loc] is where nextItem belongs
 theArray[loc] = nextItem; // Insert nextItem into sorted region
 loc--;
 } // end while
}




int main() {
    string input;
    getline(cin, input);
    stringstream ss(input);  

    string tempWord;
    string tempArr[64];
    int len = 0;
    while (ss >> tempWord) {
        tempArr[len] = tempWord;
        len++;
    }

    // for(int i = 0 ; i < 64; i++) {
    //     if(arr[i].length() != 0) cout << arr[i] << endl;
    // }
    
    string* arr = insertionSort(tempArr, len);

    int count = 1;
    bool dup = false;
    for(int i = 1; i < len; i++) {
        cout << "." << *(arr+i) << " " << *(arr+i-1) << endl;
        if(*(arr+i) == *(arr+i-1)) {
            count++;
            dup = true;
        }
        else {
            cout << *(arr+i-1) << " " << count << endl;
            count = 1;
        }
    }
    if(count) cout << *(arr+len-1) << " " << count << endl;
    if(!dup) cout << "There are no duplicates" << endl;
}