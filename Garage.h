#ifndef GARAGE_H
#define GARAGE_H

#include <string>
#include "Deque.h"
#include "Deque.cpp"


namespace cs32
{

class Garage
{
public:
    // by default, a garage that holds ten different things...
    Garage( size_t capacity = 10 );
    
    // put something in the garage
    // silently, it purges something once the garage is full
    // return true if something got purged first
    bool tossIn( std::string s );
    bool tossOut( std::string s );
    // use something from the garage
    // must be findable, then moved to the front of the used pile
    bool use( std::string s );
    // is it in the garage?
    bool find( std::string s );
    
    // how much can this garage maximally hold?
    size_t capacity();
    // how much is in this garage right now?
    size_t size( );
    
    
    std::string printItems( );
private:
    Deque<std::string> mDeque;
    size_t mCapacity;
};



}


#endif
