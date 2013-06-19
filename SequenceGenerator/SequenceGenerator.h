///////////////////////////////////////
// Workfile    : SequenceGenerator.h
// Author      : Matthias Schett
// Date        : 16-06-2013
// Description : generates a sequence
// Remarks     : -
// Revision    : 0
///////////////////////////////////////

template <typename TValue>
class SequenceGenerator {

private:
    TValue startValue;
    TValue steps;
    bool first;

public:

    SequenceGenerator(TValue startV, TValue step = 1) : startValue(startV), steps(step), first(true) {
    }

    TValue operator() ();

};

template <typename TValue>
TValue SequenceGenerator<TValue>::operator() (){
    if(first){
        first = false;
        return startValue;
    } else {
        return startValue += steps;
    }
}