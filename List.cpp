#ifndef LIST_CPP
#define LIST_CPP

#include "List.h"

namespace cs20 {
template <class Object>
List<Object>::List() {
	head = new ListNode<Object>;
	end = head;
}

template <class Object>
List<Object>::List( const List<Object>& rhs ) {
	head = new ListNode<Object>;
	*this = rhs;
}

template <class Object>
List<Object>::~List() {
	makeEmpty();
    delete head;
	delete end;
}

template <class Object>
bool List<Object>::isEmpty() const {
	return( head->nextIsNull() );
}

template <class Object>
void List<Object>::makeEmpty() {
	while (!isEmpty()) {
		remove( first().retrieve() );
	}
}

template <class Object>
ListIterator<Object> List<Object>::zeroth() const {
	return( ListIterator<Object>( head ) );
}

template <class Object>
ListIterator<Object> List<Object>::first() const {
    return( ListIterator<Object>( head->getNext() ) );
}

template <class Object>
void List<Object>::insert( const Object& data,
 						   const ListIterator<Object> &iter ) {
	if (iter.isValid()) {
		ListNode<Object>* newnode = new ListNode<Object>( data, iter.current->getNext() );
		iter.current->setNext( newnode );
	}
	if(iter.current->getNext()->nextIsNull())
	{
		end = head->getNext();
	}
}

template <class Object>
void List<Object>::insert( const Object& data ) {
	// insert after the header node
	ListNode<Object>* newnode = new ListNode<Object>(data, head->getNext() );
	head->setNext( newnode );
	if(head->getNext()->nextIsNull())
	{
		end = head->getNext();
	}
}

template <class Object>
ListIterator<Object> List<Object>::findPrevious( const Object& data ) const {
	ListNode<Object>* node = head;
	while( node->getNext() != nullptr && node->getNext()->getElement() != data ) {
		node = node->getNext();
	}
	if (node->getNext() == nullptr) {
		node = nullptr;
	}
	return ListIterator<Object>( node );
}

template <class Object>
void List<Object>::remove( const Object& data ) {
	ListIterator<Object> iter = findPrevious( data );
	if (iter.isValid()) {
		ListNode<Object>* node = findPrevious( data ).current;
		if (node->getNext() != nullptr) {
			ListNode<Object> *oldNode = node->getNext();
			node->setNext( node->getNext()->getNext() );  // Skip oldNode
			if(node->nextIsNull())
			{
				end = node;
			}
			delete oldNode;
		}
	}
}

// Deep copy of linked list
template <class Object>
const List<Object>& List<Object>::operator =( const List<Object>& rhs ) {
	if (this != &rhs) {
		makeEmpty();
		
		ListIterator<Object> rightiter = rhs.first( );
		ListIterator<Object> myiterator = zeroth();
		while( rightiter.isValid() ) {
			insert( rightiter.retrieve(), myiterator );
			rightiter.advance();
			myiterator.advance();
		}
	}
	return( *this );
}

template <class Object>
void List<Object>::insert_back( const Object& data ) {
	ListNode<Object>* node = end;
	ListNode<Object>* newnode = new ListNode<Object>(data);
	node->setNext(newnode);
	end = node->getNext();
}

template <class Object> 
bool List<Object>::isIncreasing() const
{
	bool answer = true;
	ListNode<Object>* node = head;
	while( node->getNext() != nullptr )
	{
		if(node->getElement() > node ->getNext()->getElement())
		{
			return false;
		}
		else
		{	
			node = node->getNext();
		}
	}

	return answer;

}


}

#endif