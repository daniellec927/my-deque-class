#include "Garage.h"

namespace cs32
{


Garage::Garage( size_t capacity )  : mCapacity( capacity )
{}

// put something in the garage
// silently, it purges something once the garage is full
bool Garage::tossIn( std::string s )
{
    if ( mCapacity <= mDeque.size() ) { //if the size meets the capacity
        mDeque.deleteRear(); //delete the last node
        mDeque.addToFront( s ); //add the new data to the front
        return true;
    } //if the size doesn't meet the capacity, just add the new data to the front
    mDeque.addToFront( s );
    return false;
}

bool Garage::tossOut( std::string s )
{
    if ( !mDeque.isEmpty() ) {
        if ( mDeque.deleteItem( s ) )
            return( true );
    }
    return( false );
}


// use something from the garage
// must be findable, then moved to the used pile
bool Garage::use( std::string s )
{
    if ( !mDeque.isEmpty() ) {
        if ( mDeque.deleteItem( s ) ) { //if the data is found, delete it and add it to the front
            mDeque.addToFront( s );
            return( true );
        }
    }
    return( false );
}

// is it in the garage?
bool Garage::find( std::string s )
{
    std::string data;
    for ( int i = 0; i < mDeque.size(); i++ ) {
        mDeque.get( i, data ); //get the data of each node
        if ( data == s ) //if the data meets string s, return true
            return( true );
    }
    return( false );
}

// how much can this garage maximally hold?
size_t Garage::capacity()
{
    return( mCapacity );
}
// how much is in this garage right now?
size_t Garage::size( )
{
    return( mDeque.size() );
}

std::string Garage::printItems( )
{
    std::string s = "";
    if ( mDeque.isEmpty() ) s += "---> Empty Garage";
    else {
        s += "front"; //print from the front
        for ( int i = 0; i < mDeque.size(); i++ ) {
            s += " -> ";
            std::string data;
            mDeque.get( i, data );
            s += data;
        }
        s += " -> rear";
    }
    return( s );
}


}
