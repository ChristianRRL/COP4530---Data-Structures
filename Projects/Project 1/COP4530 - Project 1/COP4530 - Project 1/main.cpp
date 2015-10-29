/* main.cpp ----------------------------------------------------
author: Christian A. Rodriguez
Main function to test each of the member functions of
MagicSquare class
--------------------------------------------------------------*/

#include <iostream>
#include <fstream>
#include "magicSquare.h"

using namespace std;

void verification(MagicSquare);
void rotation(MagicSquare);

int main()
{

   //-- Question 2a: Create default magic square object
   MagicSquare magicSquareDefault;
   verification(magicSquareDefault);

   //-- Question 2b: Create magic squares of sizes
   //-- 7,9,11,13,15,17,19,21,23,25
   MagicSquare magicSquare7(7);
   verification(magicSquare7);
   rotation(magicSquare7);

   MagicSquare magicSquare9(9);
   verification(magicSquare9);
   rotation(magicSquare9);

   MagicSquare magicSquare11(11);
   verification(magicSquare11);
   rotation(magicSquare11);

   MagicSquare magicSquare13(13);
   verification(magicSquare13);
   rotation(magicSquare13);

   MagicSquare magicSquare15(15);
   verification(magicSquare15);
   rotation(magicSquare15);

   MagicSquare magicSquare17(17);
   verification(magicSquare17);
   rotation(magicSquare17);

   MagicSquare magicSquare19(19);
   verification(magicSquare19);
   rotation(magicSquare19);

   MagicSquare magicSquare21(21);
   verification(magicSquare21);
   rotation(magicSquare21);

   MagicSquare magicSquare23(23);
   verification(magicSquare23);
   rotation(magicSquare23);

   MagicSquare magicSquare25(25);
   verification(magicSquare25);
   rotation(magicSquare25);


   ////-- Question 2c. Test all instances of magic squares that 
   ////-- are in input file named input.txt
   //int iterations = 0;
   //int *inputArray;
   //int msSize = 0;
   //int count = 0;
   //int i = 0;
   //MagicSquare temp(5);
   //


   //ifstream inputFile;
   //inputFile.open("input.txt");

   //inputFile >> iterations;
   //while (iterations > count)
   //{
   //   inputFile >> msSize >> temp;
   //   for (i = 0; i < msSize*msSize; i++)
   //   {
   //      inputFile >> temp;
   //   }

   //   if (temp.isMagicSquare())
   //   {
   //      cout << count << ": is valid" << endl;
   //   }
   //   else
   //   {
   //      cout << count << ": is not valid" << endl;
   //   }

   //   count++;
   //}

   //inputFile.close();

   return 0;
}

void verification(MagicSquare ms)
{

   if (ms.isMagicSquare())
   {
      ofstream outputFile;
      outputFile.open("output.txt",fstream::app);
      outputFile << ms << endl;
      outputFile.close();
      //cout << ms << endl;
   }

   return;
}

void rotation(MagicSquare ms)
{
   MagicSquare temp(ms);
   temp.rotate();

   if (temp.isMagicSquare())
   {
      ofstream outputFile;
      outputFile.open("output.txt", fstream::app);

      //cout << temp << endl;
      outputFile << temp << endl;
      outputFile.close();
   }
   else
   {
      cout << temp << endl;
   }
}