#ifndef LISTNODE_CPP
#define LISTNODE_CPP

#include "ListNode.h"

namespace cs20 {

template <class Object>
ListNode<Object>::ListNode( const Object& theElement,
                            ListNode<Object> * node ) {
	element = theElement;
	next = node;
}

template <class Object>
bool ListNode<Object>::nextIsNull() const {
	return( next == nullptr );
}

template <class Object>
const Object& ListNode<Object>::getElement() const {
	return( element );
}

template <class Object>
ListNode<Object>* ListNode<Object>::getNext() const {
	return( next );
}

template <class Object>
void ListNode<Object>::setNext( ListNode<Object> * node ) {
	next = node;
}

}

#endif