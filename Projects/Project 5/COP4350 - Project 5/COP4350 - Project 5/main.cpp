/* main.h -----------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class bst
-------------------------------------------------------------------*/

#include "bst.h"

using namespace std;

void testBST();

int main() {
   testBST();

   cout << "\nfinished" << endl;

   return 0;
}

void testBST() {
   cout << "Creating bst1: " << endl;
   BinarySearchTree<int> bst1;
   cout << "Performing 21 inserts (with 3 repeating numbers): " << endl;
   bst1.insert(55);
   bst1.insert(55);
   bst1.insert(33);
   bst1.insert(33);
   bst1.insert(77);
   bst1.insert(77);
   bst1.insert(99);
   bst1.insert(44);
   bst1.insert(22);
   bst1.insert(66);
   bst1.insert(11);
   bst1.insert(5);
   bst1.insert(16);
   bst1.insert(27);
   bst1.insert(38);
   bst1.insert(49);
   bst1.insert(50);
   bst1.insert(61);
   bst1.insert(72);
   bst1.insert(83);
   bst1.insert(94);

   cout << "The minimum location is: " << bst1.getMinimum() << endl;
   cout << "The maximum location is: " << bst1.getMaximum() << endl;
   
   cout << endl;
   
   cout << "The inorder of the BST is: ";
   bst1.inorder(cout);
   cout << endl;
   cout << "The preorder of the BST is: ";
   bst1.preorder(cout);
   cout << endl;
   cout << "The postorder of the BST is: ";
   bst1.postorder(cout);
   cout << endl;

   cout << endl;

   int searchInt1 = 55;
   int searchInt2 = 123;
   char searchChar1 = 'A';
   cout << "Searching for " << searchInt1 << ": ";
   cout << bst1.search(searchInt1) << endl;
   cout << "Searching for " << searchInt2 << ": "; 
   cout << bst1.search(searchInt2) << endl;
   cout << "Searching for " << searchChar1 << ": ";
   cout << bst1.search(searchChar1) << endl;

   cout << endl;

   cout << "The size of the BST is: " << bst1.getSize() << endl;
   cout << "The height of the BST is: " << bst1.getHeight() << endl;

   cout << endl;

   bst1.displayGraphic(cout);

   cout << endl;

   cout << "Creating bst2 = bst1: " << endl;
   BinarySearchTree<int> bst2 = bst1;
   cout << "Performing 9 removes: " << endl;
   bst2.remove(33);
   bst2.remove(44);
   bst2.remove(77);
   bst2.remove(1);
   bst2.remove(22);
   bst2.remove(49);
   bst2.remove(66);
   bst2.remove(99);
   bst2.remove(11);
   bst2.remove(27);

   cout << endl;

   bst2.displayGraphic(cout);

   cout << endl;

   cout << "Creating bst3(bst2): " << endl;
   BinarySearchTree<int> bst3(bst2);

   cout << endl;

   bst2.displayGraphic(cout);

}