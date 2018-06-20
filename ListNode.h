#ifndef LISTNODE_H
#define LISTNODE_H
#include <iostream>

namespace cs20 {

template <class Object>
class ListNode {
public:
	ListNode( const Object& theElement = Object(), ListNode * node = nullptr );
	bool nextIsNull() const;

	// these accessors and mutators are called
	// from ListIterator and List classes
	// no public methods expose ListNode instances
	// outside ListIterator and List classes
	const Object& getElement() const;
	ListNode* getNext() const;
	void setNext( ListNode * node );

private:
	Object element;
	ListNode* next;

};

}
#endif