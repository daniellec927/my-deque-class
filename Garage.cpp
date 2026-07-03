#include "Garage.h"
#include <vector>

namespace cs32
{

Garage::Garage( size_t capacity ) : mCapacity( capacity )
{}

// put something in the garage; silently purges the oldest item once full
bool Garage::tossIn( std::string s )
{
	if ( mCapacity <= mDeque.size() ) {
		mDeque.deleteRear();
		mDeque.addToFront( s );
		return true;
	}
	mDeque.addToFront( s );
	return false;
}

bool Garage::tossOut( std::string s )
{
	if ( !mDeque.isEmpty() )
		return( mDeque.deleteItem( s ) );
	return( false );
}

// use something from the garage; if found, move it to the front (used pile)
bool Garage::use( std::string s )
{
	if ( !mDeque.isEmpty() && mDeque.deleteItem( s ) ) {
		mDeque.addToFront( s );
		return( true );
	}
	return( false );
}

// is it in the garage?  (single O(n) pass instead of O(n^2))
bool Garage::find( std::string s )
{
	for ( const std::string & data : mDeque.toVector() )
		if ( data == s )
			return( true );
	return( false );
}

size_t Garage::capacity()
{
	return( mCapacity );
}

size_t Garage::size( )
{
	return( mDeque.size() );
}

std::string Garage::printItems( )
{
	std::string s = "";
	if ( mDeque.isEmpty() ) s += "---> Empty Garage";
	else {
		s += "front";
		for ( const std::string & data : mDeque.toVector() ) {
			s += " -> ";
			s += data;
		}
		s += " -> rear";
	}
	return( s );
}

}
