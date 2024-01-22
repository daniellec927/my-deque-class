#ifndef DEQUENODE_CPP
#define DEQUENODE_CPP


#include "DequeNode.h"
using namespace std;

namespace cs32 {

template <typename Type>
DequeNode<Type>::DequeNode( const Type& v, DequeNode * node, DequeNode * pre )
{
    value = v;
    next = node;
    previous = pre;
}

template <typename Type>
Type DequeNode<Type>::getElement() const {
	return( value );
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getNext() const {
    return( next );
}

template <typename Type>
void DequeNode<Type>::setNext( DequeNode<Type> * node ) {
    next = node;
}

template <typename Type>
DequeNode<Type> * DequeNode<Type>::getPrevious() const {
    return( previous );
}

template <typename Type>
void DequeNode<Type>::setPrevious( DequeNode<Type> * node ) {
    previous = node;
}

}


#endif
