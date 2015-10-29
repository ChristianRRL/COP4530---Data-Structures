/* main.h -----------------------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class functions
-------------------------------------------------------------------*/

#include <iostream>
#include <vector>
#include <stack>
#include <queue>
#include <string>
#include <iterator>
#include "functions.h"


void testGetInfixExpression();
void testRadixSort();

int main() {
   cout << "Testing getInfixExpression function: " << endl;
   testGetInfixExpression();
   cout << endl;

   cout << "Testing radixSort function: " << endl;
   testRadixSort();
   cout << endl;

   cout << "\nfinished" << endl;

   cin.ignore();

   return 0;
}

void testGetInfixExpression() {
   // getInfixExpression variable(s)
   string infix1 = "ab+";
   string infix2 = "ab+cd-*";
   string infix3 = "*";

   // Display infix expression
   cout << "Test 1: " << getInfixExpression(infix1) << endl;
   cout << "Test 2: " << getInfixExpression(infix2) << endl;
   cout << "Test 3: " << getInfixExpression(infix3) << endl;
}

void testRadixSort() {
   // radixSort input variable(s)
   vector<string> numbers1;
   
   numbers1.push_back("ABC");
   numbers1.push_back("13");
   numbers1.push_back("ZYX");
   numbers1.push_back("777");   
   numbers1.push_back("007");
   numbers1.push_back("A1");
   //vector<string> numbers2;
   //numbers2.resize(7);
   //numbers2 = { "13", "27", "1", "99", "86", "123", "007" };
   //vector<string> numbers3;
   //numbers3.resize(8);
   //numbers3 = { "METAL", "GEAR", "SOLID", "HALO", "5", "CIV", "BEYOND", "EARTH" };
   int digitsPerNumber1 = 3;
   //int digitsPerNumber2 = 4;
   //int digitsPerNumber3 = 6;
   int radix1 = 36;
   //int radix2 = 10;
   //int radix3 = 35;

   // Display original vector
   cout << "Test 1 Unsorted: " << radixVector(numbers1) << endl;
   // Sort vector
   radixSort(numbers1, digitsPerNumber1, radix1);
   // Display sorted vector
   cout << "Test 1 Sorted:   " << radixVector(numbers1) << endl;

   //// Display original vector
   //cout << "Test 2 Unsorted: " << radixVector(numbers2) << endl;
   //// Sort vector
   //radixSort(numbers2, digitsPerNumber2, radix2);
   //// Display sorted vector
   //cout << "Test 2 Sorted:   " << radixVector(numbers2) << endl;

   //// Display original vector
   //cout << "Test 3 Unsorted: " << radixVector(numbers3) << endl;
   //// Sort vector
   //radixSort(numbers3, digitsPerNumber3, radix3);
   //// Display sorted vector
   //cout << "Test 3 Sorted:   " << radixVector(numbers3) << endl;

   return;
}
