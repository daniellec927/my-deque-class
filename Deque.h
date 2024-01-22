#ifndef DEQUE_H
#define DEQUE_H
#include <iostream>
#include <string>
#include "DequeNode.h"
#include "DequeNode.cpp"


namespace cs32 {

template <typename Type>
class Deque {
public:
    Deque();
    Deque( const Deque& rhs );
	~Deque();
    const Deque& operator =( const Deque& rhs );

    // All of these methods below need to run in O( 1 )
	bool isEmpty() const;
    void addToFront( const Type & data );
    void addToRear( const Type & data );
    void deleteFront( );
    void deleteRear( );
    Type front( ) const;
    Type rear( ) const;
	
    
    // All of the methods below can run in O( n )
    // delete an item anywhere found
    bool deleteItem( const Type & data );
    void makeEmpty();
    size_t size() const;
    bool   get( int i, Type & data ) const;
    std::string printItems( ) const;
    /*std::string printItemsBackward( ) const;*/

private:
	DequeNode<Type> * head;
    DequeNode<Type> * tail;
    
    // Howard is providing a helper function to help you print your Deque elements
    std::string to_string( const Type & value ) const;
};

}
#endif
