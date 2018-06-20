#ifndef LISTITERATOR_H
#define LISTITERATOR_H
#include <iostream>
#include "ListNode.h"
#include "BadIterator.h"

namespace cs20 {

template <class Object>
class List;					// forward declaration

template <class Object>
class ListIterator {
public:
	ListIterator();
	bool isValid() const;
	void advance();
	const Object& retrieve() const;
	
private:
	ListNode<Object> * current;
	
	ListIterator( ListNode<Object> *node );

	// List exposes ListIterator instances via public methods
	// no external access should be given to the current pointer
	// friend access is required by List class to ensure this information hiding
	friend class List<Object>;
};

}
#endif