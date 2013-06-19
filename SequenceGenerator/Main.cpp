///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 16-06-2013
// Description : generates a sequence
// Remarks     : -
// Revision    : 0
///////////////////////////////////////


#include "SequenceGenerator.h"
#include <algorithm>
#include <iostream>
#include <iterator>

using namespace std;

int main(){

    // Numbers from 1 to 10
    generate_n(ostream_iterator<int>(cout, " "), 10, SequenceGenerator<int>(1));
    cout << endl;
    // Numbers from 10 to 1 (descending order)
    generate_n(ostream_iterator<int>(cout, " "), 10, SequenceGenerator<int>(10, -1));
    cout << endl;
    // Numbers from 0 to 5 (increment 0.5)
    generate_n(ostream_iterator<double>(cout, " "), 11, SequenceGenerator<double>(0, 0.5));
    cout << endl;
    // Letters from A to Z
    generate_n(ostream_iterator<char>(cout, ""), 26, SequenceGenerator<char>('A'));
    cout << endl;

    generate_n(ostream_iterator<char>(cout, ""), 26, SequenceGenerator<char>(97));
    cout << endl;

    generate_n(ostream_iterator<double>(cout, " "), 5, SequenceGenerator<double>('B', 0.2));
    cout << endl;

    cin.get();
    return 0;
}