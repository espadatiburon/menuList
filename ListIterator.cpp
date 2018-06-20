#ifndef LISTITERATOR_CPP
#define LISTITERATOR_CPP

#include "ListIterator.h"

namespace cs20 {
template <class Object>
ListIterator<Object>::ListIterator() : current( nullptr ) {
	// all assignments occurred above
}

template <class Object>
ListIterator<Object>::ListIterator( ListNode<Object> *node ) : current( node ) {
	// all assignments occurred above
}

template <class Object>
bool ListIterator<Object>::isValid( ) const {
	return( (current != nullptr) );
}


template <class Object>
void ListIterator<Object>::advance( ) {
	if (isValid()) {
		current = current->getNext();
	}
}

template <class Object>
const Object& ListIterator<Object>::retrieve( ) const {
	if (!(isValid())) throw BadIterator();
	return( current->getElement() );
}
}

#endif