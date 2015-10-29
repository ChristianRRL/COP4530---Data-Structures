/* circularLinkedList.h ---------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class circularLinkedList
-------------------------------------------------------------------*/

#ifndef CIRCULAR_LINKED_LIST_H_
#define CIRCULAR_LINKED_LIST_H_

#include <iostream>
//#include <vector>
//#include <cassert>
using namespace std;

const int NULL_VALUE = -1;

//-- Function/Class Declarations ------------------------------------

template <class T>
class List {
private:
   class Node {
   public:
      T data;
      Node* next;
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

int randomNumberGenerator();
/*-------------------------------------------------------------------
Purpose:
Precondition:
Postcondition:
Time Complexity: ???
-------------------------------------------------------------------*/


//-- Function/Class Implementations ---------------------------------

template <class T>
List<T>::List() {
   _first = 0;
}

template <class T>
List<T>::List(const List& originalList) {
   // initialize an empty list
   _first = 0;
   ////_size = originalList._size;

   // copy the original list
   copyList(originalList._first, _first);


   // Original Code
   //Node* origPtr = original._first;
   //Node* copyPtr = _first;

   //while (origPtr != 0) {
   //   copyPtr->next = origPtr->next;
   //}

}

template <class T>
List<T>::~List() {
   deleteList(_first);

   // Original Code
   //if (!isEmpty()) {
   //   Node* currentPtr = _first;
   //   Node* tempPtr;
   //   while (currentPtr != 0) {
   //      tempPtr = currentPtr;
   //      current = currentPtr->next;
   //      delete tempPtr;
   //   }
   //}
}


template <class T>
int List<T>::getSize() const {
   int size = 0;

   // Check if it is an empty list (size 0)
   if (isEmpty()) {
      return size;
   }

   // Iterate though the linked list
   Node* predPtr = _first;
   while (predPtr != _first) {
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
   return _first == 0;
}

template <class T>
bool List<T>::insert(const T& item, const int& position) {
   // verify that this is an acceptable position
   if (position < 0) {
      return false;
   }

   // create a new node with the specified data
   Node* newNode = new Node;
   newNode->data = item;
   newNode->next = 0;

   // if this is the new head, then update _first
   if (position == 0) {
      if (_first == 0) {
         _first = newNode;
         _first->next = _first;
      }
      else {
         newNode->next = _first;
         _first->next = newNode;
         _first = newNode;
      }
   }
   else {
      // go to the appropriate position in the linked list to insert item
      Node* predPtr = _first;
      for (int i = 1; i < position; ++i) {
         predPtr = predPtr->next;

         // verify that it is within an acceptable position
         // aka: if (position > _size)
         if (predPtr == _first) {
            return false;
         }
      }

      // insert the new element
      if (predPtr->next == _first) {
         predPtr->next = newNode;
         newNode->next = _first;
      }
      newNode->next = predPtr->next;
      predPtr->next = newNode;
   }

   return true;

}

template <class T>
bool List<T>::remove(const int& position) {
   // verify we can delete an element
   if (isEmpty()) {
      return false;
   }

   // verify this is a valid item to delete
   if (position < 0 || position >= _size) {
      return false;
   }

   // the first item is a special case
   if (position == 0) {
      Node* oldNode = _first;
      _first = _first->next;
      lastPtr->next = _first;
      delete oldNode;
   }
   else {
      // go to the appropriate position in the linked list to delete item
      Node* oldNode = _first;
      Node* predPtr;
      for (int i = 0; i < position; ++i) {
         predPtr = oldNode;
         oldNode = oldNode->next;

         // Check for out of bounds (i.e. if the list loops around)
         // aka: if (position > _size)
         if (oldNode == _first) {
            return false;
         }

         // bypass the item to be deleted
         predPtr->next = oldNode->next;

         // free the memory for the item to be deleted
         delete oldNode;
      }

      --_size;

      return true;
   }
}

   template <class T>
   T List<T>::runJosephusAlgorithm() {
      return *this;
   }


   template <class T>
   const List<T>& List<T>::operator=(const List<T>& rhs) {
      // verify this is not a self-assignment
      if (this == &rhs) {
         return *this;
      }

      _size = rhs._size;

      // copy rhs's elements into a new list
      copyList(rhs->_first, _first);

      return *this;
   }


   template <class T>
   void List<T>::display(ostream& out) const {
      Node* ptr = _first;
      while (ptr != 0) {
         out << ptr->data << " ";
         ptr = ptr->next;
      }
   }

   template <class T>
   ostream& operator<< (ostream& out, const List<T>& list) {
      list.display(out);

      return out;
   }

   template <class T>
   bool List<T>::copyList(Node* originalListFirst, Node* &copiedListFirst) {
      // if the original list is empty, then simply delete the anything 
      // held in the copied list
      if (originalListFirst == 0) {
         deleteList(copiedListFirst);
         return true;
      }

      // if there is already a list held where the copied list should go, 
      // then delete that list
      deleteList(copiedListFirst);

      // copy data from the first node
      copiedListFirst = new Node;
      copiedListFirst->data = originalListFirst->data;
      copiedListFirst->next = 0;

      // create a pointer to the current location in each list
      Node* originalPtr = originalListFirst;
      Node* copiedPtr = copiedListFirst;

      // copy the data in the remaining nodes
      while (originalPtr->next != 0) {
         copiedPtr->next = new Node;
         originalPtr = originalPtr->next;
         copiedPtr = copiedPtr->next;

         copiedPtr->data = originalPtr->data;
         copiedPtr->next = 0;
      }

      copiedPtr->next = 0;

      return true;
   }

   template <class T>
   bool List<T>::deleteList(Node* firstPtr) {
      if (firstPtr == 0) {
         return true;
      }

      Node* ptr = firstPtr;

      while (ptr != 0) {
         Node* tempPtr = ptr;
         ptr = ptr->next;
         delete tempPtr;
      }

      firstPtr = 0;

      return true;
   }

   int randomNumberGenerator() {
      return 0;
   }
#endif   /*CIRCULAR_LINKED_LIST_H_*/

   /*-------------------------------------------------------------------
   Purpose:
   Precondition:
   Postcondition:
   Time Complexity:
   -------------------------------------------------------------------*/
