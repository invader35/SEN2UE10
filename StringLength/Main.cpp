///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 16-06-2013
// Description : generates a sequence
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <iostream>
#include <algorithm>
#include <vector>
#include <string>
#include "StringLength.h"

using namespace std;

int main(){

    vector<string> V1;
    V1.push_back("short");
    V1.push_back("LongString");
    V1.push_back("AverageL");

    cout << "The strings to analyse" << endl;
    cout << V1[0] << endl;
    cout << V1[1] << endl;
    cout << V1[2] << endl;
    
    StringLength strLen = for_each(V1.begin(), V1.end(), StringLength() );
    
    strLen.print();

    cin.get();
    return 0;
}