/* bst.h ------------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class bst
Note: this binary search requires that all items be unique
-------------------------------------------------------------------*/

#ifndef BST_H_
#define BST_H_

#include <iostream>
#include <iomanip>

const int INDENT_VALUE = 8;

//== Function/Class Declarations ====================================
template <class T>

class BinarySearchTree {
private:
   class Node {
   public:
      T data;
      Node * left;
      Node * right;
      Node * parent;

      Node() :left(NULL), right(NULL), parent(NULL) {};
      Node(const T& item) {
         data = item;
         left = NULL;
         right = NULL;
         parent = NULL;
      };
   };

public:
   // Construction --------------------------------------------------
   BinarySearchTree();
   /*----------------------------------------------------------------
   Purpose: Construct a Binary Search Tree Object.
   Precondition: None.
   Postcondition: An empty BST has been constructed.
   Time Complexity: O(1).
   ----------------------------------------------------------------*/
   BinarySearchTree(const BinarySearchTree&);
   /*----------------------------------------------------------------
   Purpose: Copy constructor for a Binary Search Tree Object.
   Precondition: Original is a BST.
   Postcondition: An empty BST has been constructed.
   Time Complexity: O(1).
   ----------------------------------------------------------------*/

   // Destruction ---------------------------------------------------
   ~BinarySearchTree();
   /*----------------------------------------------------------------
   Purpose: Destructor for a Binary Search Tree.
   Precondition: The life of the BST is over.
   Postcondition: Memory used by BST is freed.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   bool isEmpty() const;
   /*----------------------------------------------------------------
   Purpose: Check if Binary Search Tree is empty and false otherwise.
   Precondition: None.
   Postcondition: Return true if the Binary Search Tree is empty and
      false otherwise.
   Time Complexity: O(1).
   ----------------------------------------------------------------*/
   bool search(const T&) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for an item.
   Precondition: None.
   Postcondition: Returns true if item found and false otherwise.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/

   T getSuccessor(const T&) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for the inorder successor
      of item. If the item is not present in the tree, then return a
      garbage value.
   Precondition: None.
   Postcondition: Returns the inorder successor of the node
      containing item.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   T getPredecessor(const T&) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search tree for the inorder predecessor
      of item. If the item is not present in the tree, then return a
      garbage value.
   Precondition: None.
   Postcondition: Returns the inorder predecessor of item.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   T getMaximum() const;
   /*----------------------------------------------------------------
   Purpose: Determine the maximum item in the Binary Search Tree
   Precondition: None.
   Postcondition: Return the maximum value held in the BST.
      If the tree is empty then a garbage value is returned.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   T getMinimum() const;
   /*----------------------------------------------------------------
   Purpose: Determine the minimum item in the Binary Search Tree
   Precondition: None.
   Postcondition: Return the minimum value held in the BST.
      If the tree is empty then a garbage value is returned.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   int getHeight() const;
   /*----------------------------------------------------------------
   Purpose: Determine the number of levels in a binary search tree. 
      For example, a binary tree with a single node has height 1 and  
      a binary tree with a root and a single child has height 2
   Precondition: None.
   Postcondition: Return the number of levels in this BST.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   int getSize() const;
   /*----------------------------------------------------------------
   Purpose: Determine the number of vertices in Binary Search Tree.
   Precondition: None.
   Postcondition: Return the number of vertices in this BST.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   void inorder(std::ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Inorder traversal of Binary Search Tree.
   Precondition: ostream out is open.
   Postcondition: BST has been inorder traversed and values in nodes
      have been output to out.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   void preorder(std::ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Preorder traversal of Binary Search Tree
   Precondition: ostream out is open.
   Postcondition: BST has been preorder traversed and values in
      nodes have been output to out.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   void postorder(std::ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Postorder traversal of Binary Search Tree.
   Precondition: ostream out is open.
   Postcondition: BST has been postorder traversed and values in
      nodes have been output to out.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   bool insert(const T&);
   /*----------------------------------------------------------------
   Purpose: Insert a value into the Binary Search Tree.
   Precondition: item is not present in the BST.
   Postcondition: BST has been modified with the item inserted at the
      proper position to maintain the BST property. Returns true if
      item is inserted into the tree and false otherwise.
   Time Complexity: O(h).
   ----------------------------------------------------------------*/
   bool remove(const T&);
   /*----------------------------------------------------------------
   Purpose: Remove item from the Binary Search Tree.
   Postcondition: BST has been modified with  the item removed, if
      present. BST property is maintained. Returns true if insertion
      is successful and false otherwise.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/

   void displayGraphic(std::ostream&) const;
   /*----------------------------------------------------------------
   Purpose: Graphic output of binary search tree.
   Precondition: ostream out is open.
   Postcondition: Graphical representation of BST has been output to 
      out.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   BinarySearchTree& operator=(const BinarySearchTree& rhs);
   /*----------------------------------------------------------------
   Purpose: Assign a copy of a Binary Search Tree object to the
      current object.
   Precondition: None.
   Postcondition: A copy of rhs has been assigned to this object. A
      const reference to this binary search tree is returned.
   Time Complexity: O(n)
   ----------------------------------------------------------------*/

private:
   Node * _root;	// pointer to the root of a tree

   // Private Functions
   void searchHelper(const T&, Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for an item.
   Precondition: subtreePtr points to a subtree of this BST.
   Postcondition: Set itemLocation to point to the item if it is found
      and to NULL otherwise.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   void searchParent(const T&, Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for the parent of an item.
   Precondition: subtreePtr points to a subtree of this BST.
   Postcondition: Sets itemLocation to point to the direct parent of
      the node that contains item OR sets itemLocation to point to
      the node that will be the parent of a node that contains item
      if item is inserted into the tree.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   void getMaximumHelper(Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Determine the maximum item for the subtree rooted at
      subtreeRoot.
   Precondition:subtreeRoot is a node in the BST.
      maxLocation points to null.
   Postcondition: maxLocation points to the maximum item in the
      subtree rooted at subtreeRoot (points to NULL for an empty
      subtree)
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   void getMinimumHelper(Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Determine the minimum item for the subtree rooted at
      subtreeRoot.
   Precondition: subtreeRoot is a node in the BST.
      minLocation points to null.
   Postcondition: minLocation points to the minimum item in the
      subtree rooted at subtreeRoot (points to NULL for an empty
      subtree).
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/

   int getHeightHelper(Node *) const;
   /*----------------------------------------------------------------
   Purpose: Determine the height for the subtree rooted at
   subtreeRoot.
   Precondition: subtreeRoot is a node in the BST.
   Postcondition: calculate left height and right height and get max.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   int max(int, int) const;
   /*----------------------------------------------------------------
   Purpose: Compare two values and return higher number.
   Precondition: None.
   Postcondition: return maximum height.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   int getSizeHelper(Node *) const;
   /*----------------------------------------------------------------
   Purpose: Determine the height for the subtree rooted at
   subtreeRoot.
   Precondition: subtreeRoot is a node in the BST.
   Postcondition: calculate the size of the BST.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/

   void inorderHelper(std::ostream&, Node *) const;
   /*----------------------------------------------------------------
   Purpose: Inorder traversal helper function
   Precondition: ostream out is open. subtreePtr points to a subtree 
      of this BST.
   Postcondition: subtree with root pointed to by subtreePtr has been
      output to output.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   void preorderHelper(std::ostream&, Node *) const;
   /*----------------------------------------------------------------
   Purpose: Preorder traversal helper function.
   Precondition: ostream out is open. subtreePtr points to a subtree
      of this BST.
   Postcondition: subtree with root pointed to by subtreePtr has been
      output to output
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   void postorderHelper(std::ostream&, Node *) const;
   /*----------------------------------------------------------------
   Purpose: Postorder traversal helper function.
   Precondition: ostream out is open. subtreePtr points to a subtree
      of this BST.
   Postcondition: subtree with root pointed to by subtreePtr has been
      output to output.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

   void displayGraphicHelper(std::ostream&, const int&, Node *) const;
   /*----------------------------------------------------------------
   Purpose: Graphic output of Binary Search Tree helper function.
   Precondition: ostream out is open. subtreePtr points to a subtree
      of this BST.
   Postcondition: Graphical representation of subtree with root
      pointed to by subtreePtr has been output to out, indented indent
      spaces.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/


   void getSuccessorHelper(Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for the inorder successor
      of the node, item.
   Precondition: item points to a node in the BST. succLocation
      points to NULL.
   Postcondition: succLocation points to the inorder successor of
      item in the BST.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/
   void getPredecessorHelper(Node *, Node * &) const;
   /*----------------------------------------------------------------
   Purpose: Search the Binary Search Tree for the inorder predecessor
      of the node, item.
   Precondition: item points to a node in the BST. predLocation
      points to NULL.
   Postcondition: predLocation points to the inorder predecessor of
      item in the BST.
   Time Complexity: O(h), where h is the height of the tree.
   ----------------------------------------------------------------*/

   void copyBinarySearchTree(Node *, Node * &);
   /*----------------------------------------------------------------
   Purpose: Copy the Binary Search Tree rooted at original.
   Precondition: original is a BST.
   Postcondition: copy holds a copy of the BST.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/
   void deleteBinarySearchTree(Node * &);
   /*----------------------------------------------------------------
   Purpose: Delete the Binary Search Tree rooted at bstRoot.
   Precondition: he life of the BST rooted at bstRoot is over.
   Postcondition: Memory used by the BST rooted at bstRoot is freed.
   Time Complexity: O(n).
   ----------------------------------------------------------------*/

};

// Function/Class Implementations ===================================

/*******************************************************************/
/********************** Constructors *******************************/
/*******************************************************************/

/*----------------------------------------------------------------
Purpose: Construct a Binary Search Tree Object.
Precondition: None.
Postcondition: An empty BST has been constructed.
Time Complexity: O(1).
----------------------------------------------------------------*/
template<class T>
BinarySearchTree<T>::BinarySearchTree() {
   // Initialize an empty tree
   _root = NULL;
}

/*----------------------------------------------------------------
Purpose: Copy constructor for a Binary Search Tree Object.
Precondition: Original is a BST.
Postcondition: An empty BST has been constructed.
Time Complexity: O(1).
----------------------------------------------------------------*/
template<class T>
BinarySearchTree<T>::BinarySearchTree(const BinarySearchTree& originalTree) {
   // Initialize an empty tree
   _root = new Node();

   // Copy the original tree
   copyBinarySearchTree(originalTree._root, _root);
}

/*******************************************************************/
/********************** Destructor *********************************/
/*******************************************************************/

/*----------------------------------------------------------------
Purpose: Destructor for a Binary Search Tree.
Precondition: The life of the BST is over.
Postcondition: Memory used by BST is freed.
Time Complexity: O(n).
----------------------------------------------------------------*/
template<class T>
BinarySearchTree<T>::~BinarySearchTree() {
   // Delete the tree
   deleteBinarySearchTree(_root);
}

/*******************************************************************/
/********************** Accessors **********************************/
/*******************************************************************/

/*----------------------------------------------------------------
Purpose: Check if Binary Search Tree is empty and false otherwise.
Precondition: None.
Postcondition: Return true if the Binary Search Tree is empty and
false otherwise.
Time Complexity: O(1).
----------------------------------------------------------------*/
template <class T>
bool BinarySearchTree<T>::isEmpty() const {
   return (_root == NULL);
}

/*----------------------------------------------------------------
Purpose: Search the Binary Search Tree for an item.
Precondition: None.
Postcondition: Returns true if item found and false otherwise.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
bool BinarySearchTree<T>::search(const T& item) const {
   // Check if the BST is empty
   if (isEmpty()) {
      return false;
   }

   // create a new node
   Node * rootNode = _root;

   while (rootNode != NULL) {
      if (item == rootNode->data) {
         return true;
      }
      else if (item < rootNode->data) {
         rootNode = rootNode->left;
      }
      else if (item > rootNode->data) {
         rootNode = rootNode->right;
      }
   }

   return false;
}

/*----------------------------------------------------------------
Purpose: Search the Binary Search Tree for an item.
Precondition: subtreePtr points to a subtree of this BST.
Postcondition: Set itemLocation to point to the item if it is found
and to NULL otherwise.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::searchHelper(const T& item,
   Node * subtreePtr,
   Node * &itemLocation) const {
   // if this is an empty binary search tree, return null 
   if (subtreePtr == NULL) {
      itemLocation = NULL;
      return;
   }

   // if this is the item we are looking for, return this item
   if (subtreePtr->data == item) {
      itemLocation = subtreePtr;
      return;
   }

   // look for the parent of the specified item
   Node * parent = NULL;
   searchParent(item, subtreePtr, parent);

   // return the appropriate child
   if (item < parent->data) {
      itemLocation = parent->left;
   }
   else {
      itemLocation = parent->right;
   }
}

/*----------------------------------------------------------------
Purpose: Search the Binary Search Tree for the parent of an item.
Precondition: subtreePtr points to a subtree of this BST.
Postcondition: Sets itemLocation to point to the direct parent of
the node that contains item OR sets itemLocation to point to
the node that will be the parent of a node that contains item
if item is inserted into the tree.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::searchParent(const T& item,
   Node * subtreePtr,
   Node * &parentLocation) const {
   // if this is an empty tree return NULL
   if (subtreePtr == NULL) {
      parentLocation = NULL;
      return;
   }

   // if we have found what we are looking for, then return
   if (item == subtreePtr->data) {
      parentLocation = subtreePtr->parent;
      return;
   }

   // holds a pointer to the next subtree that we will look at
   Node * nextSubtree = NULL;

   if (item < subtreePtr->data) { // smaller items in left subtree
      nextSubtree = subtreePtr->left;
   }
   else { // larger items in right subtree
      nextSubtree = subtreePtr->right;
   }

   if (nextSubtree == NULL) {
      parentLocation = subtreePtr;
   }
   else {
      searchParent(item, nextSubtree, parentLocation);
   }
}

/*----------------------------------------------------------------
Purpose: Search the Binary Search Tree for the inorder successor
of item. If the item is not present in the tree, then return a
garbage value.
Precondition: None.
Postcondition: Returns the inorder successor of the node
containing item.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
T BinarySearchTree<T>::getSuccessor(const T& item) const {
   // find the item in the tree
   Node * location = NULL;
   searchHelper(item, _root, location);

   if (location == NULL) { // item not in BST
      T garbage;
      return garbage;
   }

   Node * successor = NULL;
   getSuccessorHelper(location, successor);

   if (successor != NULL) {
      return successor->data;
   }
   else {
      T garbage;
      return garbage;
   }
}

/*----------------------------------------------------------------
Purpose: Search the Binary Search Tree for the inorder successor
of the node, item.
Precondition: item points to a node in the BST. succLocation
points to NULL.
Postcondition: succLocation points to the inorder successor of
item in the BST.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::getSuccessorHelper(Node * item,
   Node * &succLocation) const {
   if (item->right == NULL) { // successor is an ancestor
      succLocation = item->parent;
      while (succLocation != NULL && succLocation->data<item->data) {
         succLocation = succLocation->parent;
      }
   }
   else { // successor is a descendant
      getMinimumHelper(item->right, succLocation);
   }
}

/*----------------------------------------------------------------
Purpose: Search the Binary Search tree for the inorder predecessor
of item. If the item is not present in the tree, then return a
garbage value.
Precondition: None.
Postcondition: Returns the inorder predecessor of item.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
T BinarySearchTree<T>::getPredecessor(const T& item) const {
   // find the item in the tree
   Node * location = NULL;
   searchHelper(item, _root, location);

   if (location == NULL) { // item not in BST
      T garbage;
      return garbage;
   }

   Node * predecessor = NULL;
   getPredecessorHelper(location, predecessor);

   if (predecessor != NULL) {
      return predecessor->data;
   }
   else {
      T garbage;
      return garbage;
   }
}

/*----------------------------------------------------------------
Purpose: Search the Binary Search Tree for the inorder predecessor
of the node, item.
Precondition: item points to a node in the BST. predLocation
points to NULL.
Postcondition: predLocation points to the inorder predecessor of
item in the BST.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::getPredecessorHelper(Node * item,
   Node * &predLocation) const {
   if (item->left == NULL) { // predecessor is an ancestor
      predLocation = item->parent;
      while (predLocation != NULL && predLocation->data>item->data) {
         predLocation = predLocation->parent;
      }
   }
   else { // predecessor is a descendant
      getMaximumHelper(item->left, predLocation);
   }
}

/*----------------------------------------------------------------
Purpose: Determine the maximum item in the Binary Search Tree
Precondition: None.
Postcondition: Return the maximum value held in the BST.
If the tree is empty then a garbage value is returned.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
T BinarySearchTree<T>::getMaximum() const {
   // check if the tree is empty
   if (isEmpty()) {
      return T(NULL);   // garbage value
   }

   // find the minimum location
   Node * maxLocation = NULL;
   getMaximumHelper(_root, maxLocation);

   return maxLocation->data;
}

/*----------------------------------------------------------------
Purpose: Determine the maximum item for the subtree rooted at
subtreeRoot.
Precondition:subtreeRoot is a node in the BST.
maxLocation points to null.
Postcondition: maxLocation points to the maximum item in the
subtree rooted at subtreeRoot (points to NULL for an empty
subtree)
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::getMaximumHelper(Node * subtreeRoot,
   Node * &maxLocation) const {
   // check if maximum location reached
   if (subtreeRoot->right == NULL) {
      maxLocation = subtreeRoot;
   }
   // otherwise keep checking
   else {
      subtreeRoot = subtreeRoot->right;
      getMaximumHelper(subtreeRoot, maxLocation);
   }
}

/*----------------------------------------------------------------
Purpose: Determine the minimum item in the Binary Search Tree
Precondition: None.
Postcondition: Return the minimum value held in the BST.
If the tree is empty then a garbage value is returned.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
T BinarySearchTree<T>::getMinimum() const {
   // check if the tree is empty
   if (isEmpty()) {
      return T(NULL);   // garbage value
   }

   // find the minimum location
   Node * minLocation = NULL;
   getMinimumHelper(_root, minLocation);

   return minLocation->data;
}

/*----------------------------------------------------------------
Purpose: Determine the minimum item for the subtree rooted at
subtreeRoot.
Precondition: subtreeRoot is a node in the BST.
minLocation points to null.
Postcondition: minLocation points to the minimum item in the
subtree rooted at subtreeRoot (points to NULL for an empty
subtree).
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::getMinimumHelper(Node * subtreeRoot,
   Node * &minLocation) const {
   // check if minimum location reached
   if (subtreeRoot->left == NULL) {
      minLocation = subtreeRoot;
   }
   // otherwise keep checking
   else {
      subtreeRoot = subtreeRoot->left;
      getMinimumHelper(subtreeRoot, minLocation);
   }
}

/*----------------------------------------------------------------
Purpose: Determine the number of levels in a binary search tree.
For example, a binary tree with a single node has height 1 and
a binary tree with a root and a single child has height 2
Precondition: None.
Postcondition: Return the number of levels in this BST.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
int BinarySearchTree<T>::getHeight() const {
   if (isEmpty()) {
      return 0;
   }

   return getHeightHelper(_root);

}

/*----------------------------------------------------------------
Purpose: Determine the height for the subtree rooted at
subtreeRoot.
Precondition: subtreeRoot is a node in the BST.
Postcondition: calculate left height and right height and get max.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
int BinarySearchTree<T>::getHeightHelper(Node * subtreeRoot) const {
   // left and right heights
   int hLeft = 0;
   int hRight = 0;

   // iterate through left until reaching NULL
   if (subtreeRoot->left != NULL) {
      hLeft = getHeightHelper(subtreeRoot->left);
   }

   // iterate through right until reaching NULL
   if (subtreeRoot->right != NULL) {
      hRight = getHeightHelper(subtreeRoot->right);
   }

   // return maximum height
   return max(hLeft, hRight);
}

/*----------------------------------------------------------------
Purpose: Compare two values and return higher number.
Precondition: None.
Postcondition: return maximum height.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
int BinarySearchTree<T>::max(int hLeft, int hRight) const {
   if (hLeft >= hRight) {
      hLeft++;
      return hLeft;
   }
   else {
      hRight++;
      return hRight;
   }
}

/*----------------------------------------------------------------
Purpose: Determine the number of vertices in Binary Search Tree.
Precondition: None.
Postcondition: Return the number of vertices in this BST.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
int BinarySearchTree<T>::getSize() const {
   if (isEmpty()) {
      return 0;
   }

   return getSizeHelper(_root);
}

/*----------------------------------------------------------------
Purpose: Determine the height for the subtree rooted at
subtreeRoot.
Precondition: subtreeRoot is a node in the BST.
Postcondition: calculate the size of the BST.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
int BinarySearchTree<T>::getSizeHelper(Node * subtreeRoot) const {
   // if the subtreeRoot reaches NULL return 0
   if (subtreeRoot == NULL) {
      return 0;
   }
   // otherwise continue adding the left and right sides by 1
   else {
      return 1 + getSizeHelper(subtreeRoot->left) + getSizeHelper(subtreeRoot->right);
   }
}

/*******************************************************************/
/********************** Traversals *********************************/
/*******************************************************************/

/*----------------------------------------------------------------
Purpose: Inorder traversal of Binary Search Tree.
Precondition: ostream out is open.
Postcondition: BST has been inorder traversed and values in nodes
have been output to out.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::inorder(std::ostream& out) const {
   // check if the tree is empty
   if (isEmpty()) {
      return;
   }

   inorderHelper(out, _root);

   return;
}

/*----------------------------------------------------------------
Purpose: Inorder traversal helper function
Precondition: ostream out is open. subtreePtr points to a subtree
of this BST.
Postcondition: subtree with root pointed to by subtreePtr has been
output to output.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::inorderHelper(std::ostream& out,
   Node * subtreePtr) const {
   // Check if the node has reached null
   if (subtreePtr == NULL) {
      return;
   }
   // Otherwise keep recursing
   else {
      inorderHelper(out, subtreePtr->left);
      out << subtreePtr->data << " ";
      inorderHelper(out, subtreePtr->right);
   }
}

/*----------------------------------------------------------------
Purpose: Preorder traversal of Binary Search Tree
Precondition: ostream out is open.
Postcondition: BST has been preorder traversed and values in
nodes have been output to out.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::preorder(std::ostream& out) const {
   // check if the tree is empty
   if (isEmpty()) {
      return;
   }

   preorderHelper(out, _root);

   return;
}

/*----------------------------------------------------------------
Purpose: Preorder traversal helper function.
Precondition: ostream out is open. subtreePtr points to a subtree
of this BST.
Postcondition: subtree with root pointed to by subtreePtr has been
output to output
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::preorderHelper(std::ostream& out,
   Node * subtreePtr) const {
   // Check if the node has reached null
   if (subtreePtr == NULL) {
      return;
   }
   // Otherwise keep recursing
   else {
      out << subtreePtr->data << " ";
      preorderHelper(out, subtreePtr->left);
      preorderHelper(out, subtreePtr->right);
   }
}

/*----------------------------------------------------------------
Purpose: Postorder traversal of Binary Search Tree.
Precondition: ostream out is open.
Postcondition: BST has been postorder traversed and values in
nodes have been output to out.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::postorder(std::ostream& out) const {
   // check if the tree is empty
   if (isEmpty()) {
      return;
   }

   postorderHelper(out, _root);

   return;
}

/*----------------------------------------------------------------
Purpose: Postorder traversal helper function.
Precondition: ostream out is open. subtreePtr points to a subtree
of this BST.
Postcondition: subtree with root pointed to by subtreePtr has been
output to output.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::postorderHelper(std::ostream& out,
   Node * subtreePtr) const {
   // Check if the node has reached null
   if (subtreePtr == NULL) {
      return;
   }
   // Otherwise keep recursing
   else {
      postorderHelper(out, subtreePtr->left);
      postorderHelper(out, subtreePtr->right);
      out << subtreePtr->data << " ";
   }
}

/*******************************************************************/
/********************** Operations *********************************/
/*******************************************************************/

/*----------------------------------------------------------------
Purpose: Insert a value into the Binary Search Tree.
Precondition: item is not present in the BST.
Postcondition: BST has been modified with the item inserted at the
proper position to maintain the BST property. Returns true if
item is inserted into the tree and false otherwise.
Time Complexity: O(h).
----------------------------------------------------------------*/
template <class T>
bool BinarySearchTree<T>::insert(const T& item) {
   // create a new node
   Node * newNode = new Node(item);

   // if we are inserting into an empty tree
   if (isEmpty()) {
      _root = newNode;
      return true;
   }

   // if the item is the root of the tree
   if (_root->data == item) {
      delete newNode;
      return false;
   }

   // find the parent of the item
   Node * parentLocation = NULL;
   searchParent(item, _root, parentLocation);

   // add the new node to the tree, if it is not already there
   if (item < parentLocation->data) { // left child
      if (parentLocation->left != NULL) {
         delete newNode;
         return false;
      }
      parentLocation->left = newNode;
   }
   else { // right child
      if (parentLocation->right != NULL) {
         delete newNode;
         return false;
      }
      parentLocation->right = newNode;
   }

   // set the parent of the new node
   newNode->parent = parentLocation;

   return true;
}

/*----------------------------------------------------------------
Purpose: Remove item from the Binary Search Tree.
Postcondition: BST has been modified with  the item removed, if
present. BST property is maintained. Returns true if insertion
is successful and false otherwise.
Time Complexity: O(h), where h is the height of the tree.
----------------------------------------------------------------*/
template <class T>
bool BinarySearchTree<T>::remove(const T& item) {
   // find the item in the binary search tree
   Node * itemLocation = NULL;
   searchHelper(item, _root, itemLocation);

   // determine the item is in the binary search tree
   if (itemLocation == NULL) {
      return false;
   }

   // get the parent of the item to be deleted
   Node * itemParent = itemLocation->parent;

   // The node containing item has 2 children
   if (itemLocation->left != NULL && itemLocation->right != NULL) {
      // Find the inorder successor node of item
      Node * itemSuccessor = NULL;
      getSuccessorHelper(itemLocation, itemSuccessor);

      // copy the data
      itemLocation->data = itemSuccessor->data;

      // redirect the itemLocation pointer to the successor
      // since that is now what will be deleted
      itemParent = itemSuccessor->parent;
      itemLocation = itemSuccessor;

      itemLocation->data = -1;
   }

   // We now know that the item being deleted has 0 or 1 children

   // determine which subtree, if any, has children
   Node * itemSubtree = itemLocation->left;
   if (itemSubtree == NULL) {
      itemSubtree = itemLocation->right;
   }

   if (itemParent == NULL) { // root being deleted
      _root = itemSubtree;
      if (_root != NULL) {
         _root->parent = NULL;
      }
   }
   else if (itemParent->left == itemLocation) {
      itemParent->left = itemSubtree;
   }
   else {
      itemParent->right = itemSubtree;
   }

   if (itemSubtree != NULL) {
      itemSubtree->parent = itemParent;
   }

   // free the memory for this item
   delete itemLocation;

   return true;
}

/*******************************************************************/
/********************** Input/Output *******************************/
/*******************************************************************/

/*----------------------------------------------------------------
Purpose: Graphic output of binary search tree.
Precondition: ostream out is open.
Postcondition: Graphical representation of BST has been output to
out.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::displayGraphic(std::ostream& out) const {
   displayGraphicHelper(out, 0, _root);
}

/*----------------------------------------------------------------
Purpose: Graphic output of Binary Search Tree helper function.
Precondition: ostream out is open. subtreePtr points to a subtree
of this BST.
Postcondition: Graphical representation of subtree with root
pointed to by subtreePtr has been output to out, indented indent
spaces.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::displayGraphicHelper(std::ostream& out,
   const int& indent,
   Node * subtreePtr) const {
   if (subtreePtr == NULL) {
      return;
   }

   displayGraphicHelper(out, indent + INDENT_VALUE, subtreePtr->right);
   out << std::setw(indent) << " " << subtreePtr->data << std::endl;
   displayGraphicHelper(out, indent + INDENT_VALUE, subtreePtr->left);
}

/*******************************************************************/
/********************** Operators **********************************/
/*******************************************************************/

/*----------------------------------------------------------------
Purpose: Assign a copy of a Binary Search Tree object to the
current object.
Precondition: None.
Postcondition: A copy of rhs has been assigned to this object. A
const reference to this binary search tree is returned.
Time Complexity: O(n)
----------------------------------------------------------------*/
template <class T>
BinarySearchTree<T>& BinarySearchTree<T>::operator=(const BinarySearchTree&
   rhs) {
   if (this == &rhs) {
      return *this;
   }

   copyBinarySearchTree(rhs._root, _root);

   return *this;
}

/*******************************************************************/
/********************** Functions **********************************/
/*******************************************************************/

/*----------------------------------------------------------------
Purpose: Copy the Binary Search Tree rooted at original.
Precondition: original is a BST.
Postcondition: copy holds a copy of the BST.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::copyBinarySearchTree(Node * originalTreeRoot,
Node * &copyTreeRoot) {
   // ensure that any memory allocated by the copy is properly freed
   deleteBinarySearchTree(copyTreeRoot);

   // Check if the node has reached null
   if (originalTreeRoot == NULL) {
      copyTreeRoot = NULL;
   }
   // Copy item from original node
   else {
      // Create a new node
      copyTreeRoot = new Node(originalTreeRoot->data);

      // recursively iterate through the left/right nodes
      if (originalTreeRoot->left != NULL) {
         copyBinarySearchTree(originalTreeRoot->left, copyTreeRoot->left);

         (copyTreeRoot->left)->parent = copyTreeRoot;
         //copyTreeRoot = copyLeft;
      }
      if (originalTreeRoot->right != NULL) {
         copyBinarySearchTree(originalTreeRoot->right, copyTreeRoot->right);

         (copyTreeRoot->right)->parent = copyTreeRoot;
         //copyTreeRoot = copyRight;
      }
   }
}

/*----------------------------------------------------------------
Purpose: Delete the Binary Search Tree rooted at bstRoot.
Precondition: he life of the BST rooted at bstRoot is over.
Postcondition: Memory used by the BST rooted at bstRoot is freed.
Time Complexity: O(n).
----------------------------------------------------------------*/
template <class T>
void BinarySearchTree<T>::deleteBinarySearchTree(Node * &bstRoot) {   
   // Setting the root node to delete
   Node * rootPtr = bstRoot;

   // Check if the node has reached null
   if (rootPtr == NULL) {
      return;
   }
   // Otherwise keep recursing
   else {
      deleteBinarySearchTree(rootPtr->left);
      deleteBinarySearchTree(rootPtr->right);
      remove(rootPtr->data);
   }
}

#endif /* BST_H_ */
