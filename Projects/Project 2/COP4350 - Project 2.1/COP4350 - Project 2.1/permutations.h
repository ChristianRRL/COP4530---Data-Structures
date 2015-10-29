/* permutations.h ---------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class permutations
-------------------------------------------------------------------*/

#ifndef PERMUTATIONS_H_
#define PERMUTATIONS_H_

#include <iostream>
#include <cassert>
using namespace std;

//-- Function/Class Declarations

template <class T>
void outputArray(T* items, const int& size, ostream& out);
/*-------------------------------------------------------------------
Purpose: A generic function to output an array
Preconditions: items is a non-empty array, size is a non-zero number,
out is an ostream type.
Postconditions: Array items is output on a single line with one space
between each element.
-------------------------------------------------------------------*/

long factorial(const int& n);
/*-------------------------------------------------------------------
Purpose: A recursive function to compute n!
Preconditions: n is a non-negative integer.
Postconditions: n! is returned.
-------------------------------------------------------------------*/

template <class T>
void outputPermutations(T* items, const int& size, ostream& out);
/*-------------------------------------------------------------------
Purpose: A generic recursive solution to output all permutations of 
an array.
Preconditions: There are n! permutations of an array
Postconditions: outputArray function used to output all permutations.
-------------------------------------------------------------------*/

template <class T>
void recursivePermutations(T* items, const int size, int index, int& count, ostream& out);
/*-------------------------------------------------------------------
Purpose: Generates all permutations of array items.
Preconditions: Same preconditions as outputPermutations in addition 
to having added index and count parameters.
Postconditions: Function recursively calls itself to generate all 
permutations of an array.
-------------------------------------------------------------------*/

template <class T>
void swap(T* items, T& a, T& b);
/*-------------------------------------------------------------------
Purpose: Swaps two array elements
Preconditions: Array exists and is not empty.
Postconditions: Two elements of an array are swapped.
-------------------------------------------------------------------*/


//-- Function/Class Declarations
template <class T>
void outputArray(T* items, const int& size, ostream& out) {
   for (int i = 0; i < size; ++i) {
      out << items[i] << " ";
   }
   out << "\n";

   return;
}

long factorial(const int& n) {
   assert(n >= 0);
   if (n == 0) {
      return 1;
   }
   else {
      return n*factorial(n - 1);
   }
}

template <class T>
void outputPermutations(T* items, const int& size, ostream& out) {
   static int index = 0;
   static int count = 0;
   int factorialNum = factorial(size);

   recursivePermutations(items, size, index, count, out);

   assert(count == factorialNum);

   cin.ignore();
   return;
}

template <class T>
void recursivePermutations(T* items, const int size, int index, int& count,
   ostream& out) {
   int range = size - index;

   // checks if the range has recursively reached 0 or less
   if (range <= 0) {
      count++;
      outputArray(items, size, out);
   }
   else {
      // this loop iterates through all the elements in the given range
      // and swaps the items elements to create new permutations and then 
      // swaps them back
      for (int i = 0; i < range; ++i) {
         swap(items[index], items[index + i]);
         recursivePermutations(items, size, index + 1, count, out);
         swap(items[index], items[index + i]);
      }
   }

   return;
}

template <class T>
void swap(T* items, T& a, T& b) {
   T temp;

   temp = items[a];
   items[a] = items[b];
   items[b] = temp;
}

#endif