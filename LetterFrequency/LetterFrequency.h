///////////////////////////////////////
// Workfile    : LetterFrequency.h
// Author      : Matthias Schett
// Date        : 16-06-2013
// Description : analyses strings
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

#include <functional>
#include <algorithm>
#include <locale>

class CharacterComparator: public std::binary_function<char,char,bool>{
public:
    bool operator() (char const& a, char const& b) const{
        return ( tolower(a) == tolower(b) );
    }
};


class LetterFrequency : public std::unary_function<std::string, size_t> {

private:
    char mCharToCompare;

public:
    LetterFrequency(char const& c='A'):
        mCharToCompare(c){
    }

    size_t operator() (std::string const& str){
        return count_if(str.begin() , str.end(), bind1st(CharacterComparator(), mCharToCompare));
    }

};


class CompareByLetterFrequency : public std::binary_function<std::string, std::string, bool>{

private:
    std::function<size_t(std::string)> mFunctor;

public:
    CompareByLetterFrequency(std::function<size_t(std::string)> const& unaryOP = LetterFrequency()):
        mFunctor(unaryOP){
    }

    bool operator() (std::string const& strLeft, std::string const& strRight){
        return (mFunctor(strLeft) < mFunctor(strRight));
    }
};