///////////////////////////////////////
// Workfile    : Main.cpp
// Author      : Matthias Schett
// Date        : 16-06-2013
// Description : generates a sequence
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <iostream>
#include <string>
#include <functional>

class StringLength : public std::unary_function<std::string, void> {

private:

    size_t maxLength;
    size_t minLength;
    size_t averageLenght;
    size_t numOfStrings;

public:

    StringLength() : maxLength(0), minLength(0), averageLenght(0), numOfStrings(0) {}

    void operator() (std::string const &a) {

        numOfStrings++;

        averageLenght += a.length();

        if(numOfStrings == 1){
            minLength = a.length();
        }

        if(a.length() > maxLength){
            maxLength = a.length();
        } else if(a.length() < minLength){
            minLength = a.length();
        } 


    }

    void print(){
        std::cout << "Max Length: " << maxLength << std::endl;
        std::cout << "Min Length: " << minLength << std::endl;
        std::cout << "Average Length: " << (averageLenght / numOfStrings) << std::endl;
    }

};