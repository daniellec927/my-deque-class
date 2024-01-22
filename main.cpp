// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include <string>
#include <cassert>
#include "Deque.h"
#include "Deque.cpp"
#include "DequeNode.h"
#include "DequeNode.cpp"
#include "Garage.h"




int main()
{
    using namespace std;
    using namespace cs32;
    
    // TODO: CS 32 students should add testing code here
    DequeNode< int > sampleNode( 5 );
    Deque< string > sampleDeque;
    Deque< int > otherDeque;
    Garage otherg( 12 );

    // Deque Tests
    Deque< int > dInt;
    int x;
    Deque< std::string > dString;
    std::string s;
    
    dInt.deleteFront( );
    dInt.deleteRear( );
    x = 12;
    assert( dInt.deleteItem( x ) == false );
    assert( dInt.size( ) == 0 );
    assert( dInt.get( -10, x ) == false );
    assert( dInt.isEmpty( )  );
    
    s = "Hello";
    dString.addToFront( s );
    s = "World!";
    dString.addToRear( s );
    s = "Howard";
    assert( dString.deleteItem( s ) == false );
    assert( dString.size( ) == 2 );
    assert( dString.get( -10, s ) == false );
    assert( dString.isEmpty( ) == false );
    assert( dString.get( 0, s ) && s == "Hello" );
    assert( dString.get( 1, s ) && s == "World!" );
    assert( dString.front() == "Hello" );
    assert( dString.rear() == "World!" );
    dString.deleteFront( );
    s = "Hello";
    assert( dString.deleteItem( s ) == false );
    assert( dString.size( ) == 1 );
    assert( dString.get( 0, s ) && s == "World!" );
    assert( dString.isEmpty( ) == false );
    dString.deleteRear( );
    s = "World!";
    assert( dString.deleteItem( s ) == false );
    assert( dString.size( ) == 0 );
    assert( dString.get( 0, s ) == false );
    assert( dString.isEmpty( ) );
    
    s = "E";
    dString.addToFront( s );
    s = "D";
    dString.addToFront( s );
    s = "C";
    dString.addToFront( s );
    s = "B";
    dString.addToFront( s );
    s = "A";
    dString.addToFront( s );
    s = "F";
    dString.addToRear( s );
    s = "G";
    dString.addToRear( s );
    s = "H";
    dString.addToRear( s );
    s = "I";
    dString.addToRear( s );
    s = "J";
    dString.addToRear( s );
    assert( dString.size() == 10 );
    cout<<dString.printItems()<<endl;
    //cout<<dString.printItemsBackward()<<endl;
    dString.deleteFront();
    dString.deleteFront();
    dString.deleteRear();
    dString.deleteRear();
    assert( dString.size() == 6 );
    cout<<dString.printItems()<<endl;
    //cout<<dString.printItemsBackward()<<endl;
    assert( dString.front() == "C" );
    assert( dString.rear() == "H" );
    assert( dString.isEmpty() == false );
    assert( dString.deleteItem( "F" ) );
    assert( dString.deleteItem( "A" ) == false );
    assert( dString.get( 0, s ) && s == "C" );
    assert( dString.get( 3, s ) && s == "G" );
    assert( dString.get( 5, s ) == false );
    assert( dString.size() == 5 );
    dString.makeEmpty();
    assert( dString.size() == 0 );
    s = "Hi";
    dString.addToRear( s );
    dString.addToRear( "Bye" );
    cout<<dString.printItems()<<endl;
    
    // Garage Tests
    Garage g;
    Garage gSix( 6 );
    
    assert( g.size( ) == 0 );
    assert( g.capacity( ) == 10 );
    
    assert( gSix.size( ) == 0 );
    assert( gSix.capacity( ) == 6 );
    gSix.tossIn( "shoes" );
    gSix.tossIn( "shirts" );
    gSix.tossIn( "books" );
    assert( gSix.size( ) == 3 );
    assert( gSix.capacity( ) == 6 );
    gSix.tossIn( "suitcases" );
    assert( gSix.tossIn( "tables" ) == false );  // nothing thrown away
    assert( gSix.tossIn( "chairs" ) == false );  // nothing thrown away
    assert( gSix.size( ) == 6 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "shoes" ) );
    assert( gSix.find( "shirts" ) );
    assert( gSix.find( "books" ) );
    assert( gSix.find( "suitcases" ) );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "chairs" ) );
    assert( gSix.size( ) == 6 );
    
    assert( gSix.tossIn( "boxes" ) );  // shoes thrown away...
    assert( gSix.size( ) == 6 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "boxes" ) );
    assert( gSix.find( "shoes" )  == false );
    assert( gSix.find( "shirts" ) );
    assert( gSix.find( "books" ) );
    assert( gSix.find( "suitcases" ) );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "chairs" ) );
    
    assert( gSix.tossOut( "shoes" ) == false );   // shoes not found...
    assert( gSix.use( "shoes" ) == false );       // shoes not found...
    assert( gSix.use( "tables" ) );
    
    assert( gSix.tossIn( "records" ) );     // shirts thrown away...
    assert( gSix.size( ) == 6 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "records" ) );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "boxes" ) );
    assert( gSix.find( "shoes" ) == false );
    assert( gSix.find( "shirts" ) == false );
    assert( gSix.find( "books" ) );
    assert( gSix.find( "suitcases" ) );
    
    assert( gSix.tossOut( "books" ) );
    assert( gSix.tossOut( "records" ) );
    assert( gSix.tossOut( "shoes" ) == false);
    assert( gSix.size( ) == 4 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "records" ) == false );
    assert( gSix.find( "tables" ) );
    assert( gSix.find( "chairs" ) );
    assert( gSix.find( "boxes" ) );
    assert( gSix.find( "shoes" ) == false );
    assert( gSix.find( "shirts" ) == false );
    assert( gSix.find( "books" ) == false );
    assert( gSix.find( "suitcases" ) );
    
    assert( gSix.tossOut( "tables" ) );
    assert( gSix.tossOut( "boxes" ) );
    assert( gSix.tossOut( "suitcases" ) );
    assert( gSix.size( ) == 1 );
    assert( gSix.capacity( ) == 6 );
    assert( gSix.find( "records" ) == false );
    assert( gSix.find( "tables" ) == false );
    assert( gSix.find( "boxes" ) == false );
    assert( gSix.find( "shoes" ) == false );
    assert( gSix.find( "shirts" ) == false );
    assert( gSix.find( "books" ) == false );
    assert( gSix.find( "suitcases" ) == false );
    assert( gSix.find( "chairs" ) );
    
    cout << "all tests passed!" << endl;
    
    return( 0 );
}
