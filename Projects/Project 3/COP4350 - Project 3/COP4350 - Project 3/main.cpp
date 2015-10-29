/* main.h -----------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class circularLinkedList
-------------------------------------------------------------------*/

#include <iostream>
#include <cstdlib>
#include <ctime>

#include "circularLinkedList.h"

using namespace std;

const int LARGE_LIST_SIZE = 1024;

void testListClass();

using namespace std;

int main() {
   srand(time(NULL));

   testListClass();

   cout << "finished" << endl;

   return 0;
}

void testListClass() {
   int testSize = 5;

   // test the constructor
   cout << "Constructing an integer list." << endl;
   List<int> intList;
   cout << endl;

   // test the isEmpty function. Output an empty list, if applicable
   if (intList.isEmpty()) {
      cout << "Empty List: " << intList << endl;
   }
   cout << intList << endl;

   cout << endl;

   // test the copy constructor
   cout << "Constructing an integer list." << endl;
   List<int> copyList(intList);
   cout << endl;

   // test the isEmpty function on the copied list
   if (copyList.isEmpty()) {
      cout << "Empty List: " << copyList << endl;
   }
   cout << copyList << endl;

   // insert item into original list
   cout << "Inserting " << 0 << " at position " << 1 << ": ";
   if (intList.insert(0, 1)) {

      cout << "Inserting " << 5 << " at position " << 10 << ": ";
      intList.insert(5, 10);
      cout << endl;
   }
   else {
      cout << "Insertion failed!" << endl;
   }

   intList.insert(5, 0);

   // insert and remove different items
   intList.insert(7, 0);
   intList.insert(9, 2);
   intList.insert(13, 3);
   intList.remove(0);
   intList.remove(0);
   intList.remove(1);
   intList.remove(-1);
   intList.remove(0);
   intList.remove(0);
   intList.remove(-1);
   intList.remove(1);
   intList.insert(13, 0);
   intList.remove(1);
   intList.remove(2);
   intList.insert(49, 3);

   cout << "intList: " << intList << endl;
   cout << "intList.getSize(): " << intList.getSize() << endl;

   cout << endl;

   // test the copy constructor
   cout << "Making a copy of the integer list via copy constructor" << endl;
   List<int> copiedList(intList);

   cout << "Original List: " << intList << endl;
   cout << "Copied List: " << copiedList << endl;

   cout << "Perform insertion on Original" << endl;
   intList.insert(27, 1);

   cout << "Original List: " << intList << endl;
   cout << "Copied List: " << copiedList << endl;


   cout << "Perform insertion on Original" << endl;
   intList.insert(10101, 0);

   cout << "Original List: " << intList << endl;
   cout << "Copied List: " << copiedList << endl;


   cout << "Perform insertion on Original" << endl;
   intList.insert(7, 3);

   cout << "Original List: " << intList << endl;
   cout << "Copied List: " << copiedList << endl;

   cout << "Perform insertion on Original" << endl;
   intList.insert(010110, 5);

   // Testing getSize() on Copied list
   cout << "Original List: " << intList << endl;
   cout << "Original Size: " << intList.getSize() << endl;
   cout << "Copied List: " << copiedList << endl;
   cout << "Copied Size: " << copiedList.getSize() << endl;

   cout << endl;

   // Testing a list with only one item for Josephus function
   cout << "JosephusAlgorithm Result: " << copiedList.runJosephusAlgorithm();
   cout << endl;

   // Testing an empty list for Josephus function
   List<int> newList;
   cout << "JosephusAlgorithm Result: " << newList.runJosephusAlgorithm();
   cout << endl;

   // Testing a list with several items for Josephus function
   cout << "JosephusAlgorithm Result: " << intList.runJosephusAlgorithm();
   cout << endl;
}
