#ifndef DEQUE_CPP
#define DEQUE_CPP

#include "Deque.h"
#include <string>
#include <sstream>

namespace cs32 {

template <typename Type>
Deque<Type>::Deque()
{
    head = nullptr;
    tail = nullptr;
}

template <typename Type>
Deque<Type>::Deque( const Deque& rhs ) {
    if (rhs.head == nullptr)
    {
        head = nullptr;
        tail = nullptr;
    }
    else
    {
        head = new DequeNode<Type>( rhs.head->getElement() );
        tail = head;
        DequeNode<Type> *q = head;
        DequeNode<Type> *p = rhs.head->getNext();
        while (p != nullptr) {
            q->setNext( new DequeNode<Type>( p->getElement() ) );
            q->getNext()->setNext( nullptr );
            q->getNext()->setPrevious( q );
            tail = q->getNext();
            p = p->getNext();
            q = q->getNext();
        }
    }
}

template <typename Type>
Deque<Type>::~Deque() {
	makeEmpty();
}

template <typename Type>
bool Deque<Type>::isEmpty() const {
    return( head == nullptr && tail == nullptr );
}

template <typename Type>
void Deque<Type>::makeEmpty() {
    while ( !isEmpty() ){
        deleteItem( head->getElement() ); //delete the first item until Deque is empty
    }
}

template <typename Type>
void Deque<Type>::addToFront( const Type & data )
{
    DequeNode<Type> * newnode = new DequeNode<Type>( data );
    newnode->setPrevious( nullptr );
    if( isEmpty() ){ //if empty, set both head and tail as the new node
        head = newnode;
        tail = newnode;
    } else {
        newnode->setNext( head ); //place the new node in front of the previous head node
        head->setPrevious( newnode ); //to connect the nodes correctly
        head = newnode; //change the head to the new node
    }
    
}

template <typename Type>
void Deque<Type>::addToRear( const Type & data )
{
    DequeNode<Type> * newnode = new DequeNode<Type>( data );
    newnode->setNext( nullptr );
    if ( isEmpty() ){ //if empty, set both head and tail as the new node
        head = newnode;
        tail = newnode;
    } else {
        tail->setNext( newnode ); //place the new node behind of the previous tail node
        newnode->setPrevious( tail ); //to connect the nodes correctly
        tail = newnode; //change the tail to the new node
    }
}

template <typename Type>
void Deque<Type>::deleteFront( )
{
    if( !isEmpty() ) {
        DequeNode<Type> * tempnode = head;
        if ( head == tail ) { //if there is only one node
            head = nullptr;
            tail = nullptr;
        } else {
            head = tempnode->getNext(); //set the head to the second node
            head->setPrevious( nullptr ); //cut the connection between the nodes
        }
        delete( tempnode );
    }
}

template <typename Type>
bool Deque<Type>::deleteItem( const Type & data )
{
    DequeNode<Type> * node = head;
    DequeNode<Type> * priornode = nullptr;
    while( node != nullptr ){
        if (node->getElement() == data ){ //if it finds the right node to delete
            if ( node == head && node == tail ) { //if "node" is the only node
                head = nullptr;
                tail = nullptr;
            } else if ( node == head ) { //if "node" is the first node
                head = node->getNext();
                head->setPrevious( nullptr );
            } else if ( node == tail ) { //if "node" is the last node
                tail = priornode;
                tail->setNext( nullptr );
            } else {
                priornode->setNext( node->getNext() );
                node->getNext()->setPrevious( priornode );
            }
            delete( node );
            return( true );
        }
        priornode = node; //if the right node to delete is not found, move to the next node
        node = node->getNext();
    }
    
    return( false );
}


template <typename Type>
Type Deque<Type>::front( ) const
{
    Type result = Type();
    if ( !isEmpty() )
        result = head->getElement();
    return( result );
}

template <typename Type>
Type Deque<Type>::rear( ) const
{
    Type result = Type();
    if ( !isEmpty() )
        result = tail->getElement();
    return( result );
}

template <typename Type>
void Deque<Type>::deleteRear( )
{
    if ( !isEmpty() ){
        DequeNode<Type> * tempnode = tail;
        if ( head == tail ) { //if there is only one node
            head = nullptr;
            tail = nullptr;
        } else {
            tail = tempnode->getPrevious(); //set the tail to the second from the back node
            tail->setNext( nullptr ); //cut the connection between the nodes
        }
        delete( tempnode );

    }
}

// Howard is supplying code to convert a Type to a string using its operator <<
template <typename Type>
std::string Deque<Type>::to_string( const Type & value ) const
{
    using namespace std;
    stringstream s;
    // call the Type's operator <<
    s << value;
    return( s.str() );
}


template <typename Type>
std::string Deque<Type>::printItems( ) const
{
    string s = "";
    if ( isEmpty() ) s += "--->Empty List";
    else {
        s += "head:"; //start from the head
        DequeNode<Type> * node = head;
        while( node != nullptr ){
            s += " -> ";
            s += to_string( node->getElement() );
            node = node->getNext();
        }
        s += " -> nullptr ";
    }
    return( s );
}

/*
template <typename Type>
std::string Deque<Type>::printItemsBackward( ) const
{
    string s = "";
    if ( isEmpty() ) s += "--->Empty List";
    else {
        s += "tail:";
        DequeNode<Type> * node = tail;
        while( node != nullptr ){
            s += " <- ";
            s += to_string( node->getElement() );
            node = node->getPrevious();
        }
        s += " <- nullptr ";
    }
    return( s );
}
*/

// Deep copy of linked list
template <typename Type>
const Deque<Type> & Deque<Type>::operator =( const Deque<Type> & rhs ) {
    // TODO: CS 32 Students to complete code here
    if ( this != &rhs ){
        makeEmpty();
        
        DequeNode<Type> * right = rhs.head;
        while( right != nullptr ){
            addToRear( right->getElement() );
            right = right->getNext();
        }
    }
	return( *this );
}

template <typename Type>
size_t Deque<Type>::size() const
{
    size_t result = 0;
    DequeNode<Type> * node = head;
    while ( node != nullptr ) {
        result++; //increase result by 1 until the node meets the nullptr
        node = node->getNext();
    }
    return( result );
}


template <typename Type>
bool   Deque<Type>::get( int i, Type & data ) const
{
    DequeNode<Type> * node = head;
    int index = 0;
    while( node != nullptr ){
        if(index == i ){ //if the index is found
            data = node->getElement(); //insert the element to the data
            return( true );
        }
        index++; //if the index not found, move to next node
        node = node->getNext();
    }
    return( false );
}

}


#endif
