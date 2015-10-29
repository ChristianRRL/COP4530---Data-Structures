/* main.cpp ---------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class permutations
-------------------------------------------------------------------*/

#include <iostream>
//#include <cstdlib>
#include "permutations.h"
using namespace std;

int main() {
   int size = 5;
   int* intArray = new int[size];
   
   for (int i = 0; i < size; ++i) {
      intArray[i] = i;
   }

   cout << "Testing factorial of size " << size << ": ";
   cout << factorial(size) << endl;

   ostream& yolo = cout;

   cout << "Testing outputArray function of size " << size << ": ";
   outputArray(intArray, size, yolo);

   size = 3;
   intArray = new int[size];

   for (int i = 0; i < size; ++i) {
      intArray[i] = i + 1;
   }

   cout << "Testing outputArray function of size " << size << ": ";
   outputArray(intArray, size, yolo);
   
   cout << "Testing outputPermutations function of size " << size << ": \n";
   outputPermutations(intArray, size, yolo);

   return 0;
}