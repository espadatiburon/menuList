// Menu.cpp : Defines the entry point for the console application.
//

#include <iostream>
#include "List.h"
#include "ListNode.h"
#include "ListIterator.h"
#include "List.cpp"
#include "ListNode.cpp"
#include "ListIterator.cpp"

using namespace std;
using namespace cs20;

enum CHOICE {MAKEEMPTY, REMOVE, ISEMPTY, FINDPREVIOUS, INSERT, INSERT_BACK, INCREASING, QUIT, PRINT };

CHOICE menu();
void printList( const List<int>& l );

int main(int argc, char* argv[]) {
	int value;
	List<int> list;
	ListIterator<int> iter;

	CHOICE choice;
	do {
		choice = menu();
		switch( choice ) {
		case MAKEEMPTY:
			list.makeEmpty();
			break;
		case ISEMPTY:
			if (list.isEmpty()) {
				cout << "list is empty" << endl;
			}
			else {
				cout << "list is not empty" << endl;
			}
			break;
		case REMOVE:
			cout << "Please provide int to remove: ";
			cin  >> value; 
			list.remove( value );
			break;
		case INSERT:
			cout << "Please provide int to insert: ";
			cin  >> value; 
			list.insert( value );
			break;
		case INSERT_BACK:
			cout << "Please provide int to insert: ";
			cin >> value;
			list.insert_back( value );
			break;
		case INCREASING:
			if(list.isIncreasing()){
				cout << "The list is in increasing order." << endl;
			}
			else{
				cout << "The list is NOT in increasing order." << endl;
			}
			break;
		case FINDPREVIOUS:
			cout << "Please provide int to find: ";
			cin  >> value; 
			iter = list.findPrevious( value );
			if (iter.isValid()) {
				cout << "previous element = " << iter.retrieve() << endl;
			}
			else {
				cout << "data element was not found!" << endl;
			}
			break;
		case PRINT:
			printList( list );
			break;
        case QUIT:
            break;
	}	

	} while (choice != QUIT);

	return( 0 );
}

int sample() {
	cout << "Forming Lists" << endl;
	int one = 1, two = 2;
	List<int> l1 = List<int>();
	List<int> l2 = List<int>();

	l1.insert( one );
	l1.insert( two );

	cout << "print l1" << endl;
	printList( l1 );

	cout << "l2 = l1" << endl;
	l2 = l1;

	cout << "print l2" << endl;
	printList( l2 );	

	cout << "l1.remove(one)" << endl;
	l1.remove( one );

	cout << "print l1" << endl;
	printList( l1 );

	cout << "print l2" << endl;
	printList( l2 );
	cout << "findPrevious 1 in l2" << endl;
	ListIterator<int> iter = l2.findPrevious( one );
	if (iter.isValid()) {
		cout << "--iter valid" << endl;
		cout << iter.retrieve() << endl;
	}
	else {
		cout << "--iter not valid" << endl;
	}

	cout << "findPrevious 2 in l2" << endl;
	iter = l2.findPrevious( two );
	if (iter.isValid()) {
		cout << "--iter valid" << endl;
		cout << iter.retrieve() << endl;
	}
	else {
		cout << "--iter not valid" << endl;
	}

	cout << "findPrevious 1 in l1" << endl;
	iter = l1.findPrevious( one );
	if (iter.isValid()) {
		cout << "--iter valid" << endl;
		cout << iter.retrieve() << endl;
	}
	else {
		cout << "--iter not valid" << endl;
	}

	cout << "findPrevious 2 in l1" << endl;
	iter = l1.findPrevious( two );
	if (iter.isValid()) {
		cout << "--iter valid" << endl;
		cout << iter.retrieve() << endl;
	}
	else {
		cout << "--iter not valid" << endl;
	}

	cout << "print l1" << endl;
	printList( l1 );	

		// you can remove whatever you want, whether it exists or not
	cout << "l1.remove(one)" << endl;
	l1.remove( one );

	cout << "print l1" << endl;
	printList( l1 );	

	return( 0 );
}

void printList( const List<int>& l ) {
	if (l.isEmpty())
		cout << "Empty list" << endl;
	else {
		ListIterator<int> iter = l.first();
		while (iter.isValid()) {
			cout << iter.retrieve() << " -> ";
			iter.advance();
		}
		cout << "NULLPTR";
		cout << endl;
	}
}

CHOICE menu() {
	char choice;
	CHOICE result;
	cout << "(M)akeEmpty I(s)Empty (R)emove (I)nsert Insert_(B)ack I(N)creasing (F)indPrevious (P)rint (Q)uit: " << endl;
	cin  >> choice;
	switch( choice ) {
	case 'M':
	case 'm':
		result = MAKEEMPTY;
		break;
	case 'S':
	case 's':
		result = ISEMPTY;
		break;
	case 'R':
	case 'r':
		result = REMOVE;
		break;
	case 'I':
	case 'i':
		result = INSERT;
		break;
	case 'B':
	case 'b':
		result = INSERT_BACK;
		break;
	case 'N':
	case 'n':
		result = INCREASING;
		break;
	case 'F':
	case 'f':
		result = FINDPREVIOUS;
		break;
	case 'Q':
	case 'q':
		result = QUIT;
		break;
	case 'P':
	case 'p':
		result = PRINT;
		break;
	}

	return( result );
}
