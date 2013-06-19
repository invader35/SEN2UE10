///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 16-06-2013
// Description : analyses strings
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <iostream>
#include <functional>
#include <iterator>
#include <vector>
#include <string>
#include "LetterFrequency.h"

using namespace std;

int main(){
    // 
    size_t const n = 5;
    string strarr[n] = {"one", "two", "three", "four", "five"};
    
    char input;
    
    vector<string> test;
    copy(strarr, strarr+n, back_inserter(test));

    cout << "Please input the character you want to search for: ";
    cin >> input;
    cin.ignore();

    cout << "Strings: "; 
    copy(test.begin(), test.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    cout << "Character: " << input << endl;

    cout << "Frequency: ";
    transform(test.begin(), test.end(), ostream_iterator<size_t>(cout, " "), 
              LetterFrequency(input));
    cout << endl;

    cout << "Frequency sorted: ";
    sort(test.begin(), test.end(), CompareByLetterFrequency(LetterFrequency(input)));
    copy(test.begin(), test.end(), ostream_iterator<string>(cout, " "));
    cout << endl;

    cin.get();
    return 0;
}