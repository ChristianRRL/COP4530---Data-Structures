/* circularLinkedList.h ---------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class circularLinkedList
-------------------------------------------------------------------*/

#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

#include <iostream>
#include <cstdlib>
#include <ctime>

using namespace std;

template <typename T> class List;
template <typename T> ostream& operator<<(ostream&, const List<T>&);

template <class T>
class List {
private:
   class Node {
   public:
      T data;
      Node* next;

      Node() { next = 0; }
   };

public:
   List();
   /*----------------------------------------------------------------
   Purpose: Construct a List object.
   Precondition: None.
   Postcondition: Creates an empty List object; _first is 0.
   Time Complexity: O(1)
   ----------------------------------------------------------------*/
   List(const List&);
   /*----------------------------------------------------------------
   Purpose: Construct a copy of a List object.
   Precondition: A copy of original is needed; original is a const
   reference parameter.
   Postcondition: A copy of original has been constructed.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   ~List();
   /*----------------------------------------------------------------
   Purpose: Destroys a List object.
   Precondition: The life of a List object is over.
   Postcondition: The memory dynamically allocated in linked lists by
   the constructor has been returned to the heap.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   int getSize() const;
   /*----------------------------------------------------------------
   Purpose: Get the size of a List object.
   Precondition: None.
   Postcondition: The number of elements held in the list is returned.
   Time Complexity: O(1)
   ----------------------------------------------------------------*/
   int getCapacity() const;
   /*----------------------------------------------------------------
   Purpose: Get the capacity of a List object. (Only provided for
   compatibility with other list).
   Precondition: None.
   Postcondition: -1 is returned since a pointer based linked list
   has no predefined capacity.
   Time Complexity: O(1)
   ----------------------------------------------------------------*/

   bool isEmpty() const;
   /*----------------------------------------------------------------
   Purpose: Check if list is empty.
   Precondition: None.
   Postcondition: Returns true if list is empty and false otherwise.
   Time Complexity: O(1)
   ----------------------------------------------------------------*/

   bool insert(const T&, const int&);
   /*----------------------------------------------------------------
   Purpose: Insert an item into the list at a given position.
   Precondition: item is the value to be inserted; ...
   Postcondition: item is inserted into the list at the specified
   position.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/
   bool remove(const int&);
   /*----------------------------------------------------------------
   Purpose: Remove an item from the list at a given position.
   Precondition: The list is not empty and 0 <= position < size.
   Postcondition: Element at the given position has been removed.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   T runJosephusAlgorithm();
   /*----------------------------------------------------------------
   Purpose: Implement the function to determine the node selected by
   the Josephus Algorithm. The function cannot modify the contents of
   the list object calling the function. For each iteration of the
   algorithm: randomly select a start node, from the remaining nodes,
   such that each of the nodes of the remaining linked list are
   equally likely to be selected; randomly select a count between 0
   and two times the size of the original list that you will walk to
   determine which node will be removed.
   Precondition:
   Postcondition:
   Time Complexity: ???
   ----------------------------------------------------------------*/

   const List& operator=(const List&);
   /*----------------------------------------------------------------
   Purpose: Assign a copy of a List object to the current object.
   Precondition: None.
   Postcondition: A copy of rhs has been assigned to this object. A
   const reference to this list is returned.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

   void display(ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Output the list.
   Precondition: The ostream, out, is open.
   Postcondition: The list represented by this List object has been
   inserted into out.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/
   friend ostream& operator<< <>(ostream&, const List<T>&);
   /*----------------------------------------------------------------
   Purpose: Output operator for a List object.
   Precondition: The ostream, out, is open.
   Postcondition: The list represented by this List object has been
   inserted into out.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/
   //friend T& operator->* <>(ostream&, const List<T>&);

private:
   Node* _first;  // pointer to the first element of the linked list

   bool copyList(Node *, Node * &);
   /*----------------------------------------------------------------
   Purpose: Copy a linked list.
   Precondition: original is the list to be copied.
   Postcondition: copy points to a copy of original
   Time Complexity: O(n)
   ----------------------------------------------------------------*/
   bool deleteList(Node *);
   /*----------------------------------------------------------------
   Purpose: Delete a linked list.
   Precondition: The life of the linked list is over.
   Postcondition: The memory dynamically allocated by each node of the
   linked list is returned to the heap.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

};

/*******************************************************************/
/********************** Constructors *******************************/
/*******************************************************************/

template <class T>
List<T>::List() {
   // Initialize an empty list
   _first = new Node();
   _first->next = _first;
}

template <class T>
List<T>::List(const List& originalList) {
   // Initialize an empty list
   _first = new Node();
   _first->next = _first;

   // Copy the original list
   copyList(originalList._first, _first);
}

/*******************************************************************/
/********************** Destruction ********************************/
/*******************************************************************/

template <class T>
List<T>::~List() {
   deleteList(_first);
}

/*******************************************************************/
/********************** Accessors **********************************/
/*******************************************************************/

template <class T>
int List<T>::getSize() const {
   int size = 0;

   // Check if it is an empty list (size = 0)
   if (isEmpty()) {
      return size;
   }

   // Iterate through the linked list and increment size
   Node* predPtr = _first;
   while (predPtr->next != _first) {
      predPtr = predPtr->next;
      ++size;
   }

   return size;
}

template <class T>
int List<T>::getCapacity() const {
   return -1;
}

template <class T>
bool List<T>::isEmpty() const {
   return _first->next == _first;
}

/*******************************************************************/
/********************** Functions **********************************/
/*******************************************************************/

template <class T>
bool List<T>::insert(const T& item, const int& position) {
   // Verify this is a valid item to delete
   if (position < 0) {
      return false;
   }

   // Create a new node with the specified data
   Node* newNode = new Node;
   newNode->data = item;
   newNode->next = 0;

   // Iterate through the linked list
   Node* predPtr = _first;
   for (int i = 0; i < position; ++i) {
      // Verify this is a valid item to delete
      if (predPtr->next == _first) {
         return false;
      }

      predPtr = predPtr->next;
   }

   // Insert the new element
   newNode->next = predPtr->next;
   predPtr->next = newNode;

   return true;
}

template <class T>
bool List<T>::remove(const int& position) {
   // Verify we can delete an element
   if (isEmpty()) {
      return false;
   }

   // Verify this is a valid item to delete
   if (position < 0) {
      return false;
   }

   // Iterate through the linked list
   Node * oldNode = _first->next;
   Node * predPtr = _first;
   for (int i = 0; i < position; ++i) {
      predPtr = oldNode;
      oldNode = oldNode->next;

      // Verify this is a valid item to delete
      if (predPtr->next == _first) {
         return false;
      }
   }

   // Bypass the item to be deleted
   predPtr->next = oldNode->next;

   // Free the memory for the item to be deleted
   delete oldNode;

   return true;
}

template <class T>
T List<T>::runJosephusAlgorithm() {
   // Seed random with time
   srand(time(NULL));

   // Create a copy of the original list
   List copy(*this);

   // Create a start node
   Node* startNode = _first;

   // Verify that the list is not empty
   if (copy.isEmpty()) {
      return T();  // Garbage Value
      // Alternative Return Garbage:
      // T garbage;
      // return garbage;
   }

   // Return list item if there is only one element
   if (copy.getSize() == 1) {
      return startNode->data;
   }

   // Initialize original size, count, and start
   const int originalSize = copy.getSize();
   int count = 0;
   int start = 0;

   // Iterate through list and delete correct Node
   while (copy.getSize() > 1) {
      // Randomly select a start node
      start = rand() % copy.getSize();
      for (int i = 0; i < start; ++i) {
         startNode = startNode->next;
      }

      // Randomly select a count that is twice original size
      count = rand() % (2 * originalSize);

      // Remove count
      copy.remove(count);
   }

   return copy._first->next->data;
}


/*******************************************************************/
/********************** Operators **********************************/
/*******************************************************************/

template <class T>
const List<T>& List<T>::operator=(const List& rhs) {
   // Verify this is not a self-assignment
   if (this == &rhs) {
      return *this;
   }

   // Copy rhs's elements into a new list
   copyList(rhs._first, _first);

   return *this;
}

/*******************************************************************/
/********************** Input/Output *******************************/
/*******************************************************************/

template <class T>
void List<T>::display(ostream& out) const {
   // Iterate through the linked list
   Node * ptr = _first->next;
   while (ptr != _first) {
      out << ptr->data << " ";
      ptr = ptr->next;
   }
}

template <typename T>
ostream& operator<<(ostream& out, const List<T>& list) {
   list.display(out);

   return out;
}

/*******************************************************************/
/********************** Private Functions **************************/
/*******************************************************************/

template <class T>
bool List<T>::copyList(Node * originalListFirst, Node * &copiedListFirst) {
   // if the original list is followed by itself, then simply delete 
   //anything held in the copied list
   if (originalListFirst->next == originalListFirst) {
      deleteList(copiedListFirst);
      return true;
   }

   // If there is already a list held where the copied list should go, then 
   // delete that list
   deleteList(copiedListFirst);

   // Copy the data from the first node
   copiedListFirst = new Node;
   copiedListFirst->data = originalListFirst->data;
   copiedListFirst->next = copiedListFirst;

   // Create a pointer to the current location in each list
   Node * originalPtr = originalListFirst;
   Node * copiedPtr = copiedListFirst;

   // Copy the data in the remaining nodes
   while (originalPtr->next != originalListFirst) {
      copiedPtr->next = new Node;
      originalPtr = originalPtr->next;
      copiedPtr = copiedPtr->next;

      copiedPtr->data = originalPtr->data;
      copiedPtr->next = copiedListFirst->next;
   }

   originalPtr->next = originalListFirst;
   copiedPtr->next = copiedListFirst;

   return true;
}

template <class T>
bool List<T>::deleteList(Node * firstPtr) {
   if (firstPtr->next == firstPtr) {
      return true;
   }

   Node * ptr = firstPtr;

   while (ptr != firstPtr) {
      Node * tempPtr = ptr;
      ptr = ptr->next;
      delete tempPtr;
   }

   firstPtr = 0;

   return true;
}

#endif /*CIRCULAR_LINKED_LIST_H_*/
