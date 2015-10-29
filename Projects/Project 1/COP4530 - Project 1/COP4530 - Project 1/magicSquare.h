/* magicSquare.h -----------------------------------------------
author: Christian A. Rodriguez
Header file of the class library for the class magicSquare.
--------------------------------------------------------------*/

#ifndef MAGICSQUARE_H_
#define MAGICSQUARE_H_

#include <iostream>

using namespace std;

class MagicSquare
{

public:  //-- Constructors and Destructor(s)
   
   MagicSquare();
   /*-----------------------------------------------------------
   Default constructor
   Precondition: None.
   Postcondition: MagicSquare object has been constructed
   with a 5 x 5 matrix.
   -----------------------------------------------------------*/

   MagicSquare(const int& n);
   /*-----------------------------------------------------------
   Explicit-value constructor
   Precondition: Takes an odd integer n as a parameter.
   Postcondition: MagicSquare object has been constructed
   with a n x n matrix. (You should assume that n will
   always be an odd integer).
   -----------------------------------------------------------*/

   MagicSquare(const MagicSquare& original);
   /*-----------------------------------------------------------
   Copy constructor
   Precondition: original is a magic square to be copied and is
   received as a const reference parameter.
   Postcondition: A copy of original has been constructed.
   -----------------------------------------------------------*/

   ~MagicSquare();
   /*-----------------------------------------------------------
   Class destructor
   Precondition: None.
   Postcondition: The dynamic two dimensional matrix has been 
   deallocated.
   -----------------------------------------------------------*/

private: //-- Private Function(s)

   //-- Matrix Generator
   void generateMagicSquare();
   /*-----------------------------------------------------------
   Create a magic square
   Precondition: None.
   Postcondition: Generate an n x n matrix in which each of
   the integers 1,2,3,...,n^2 appears exactly once on all
   column sums, row sums, and diagonal sums are equal.
   -----------------------------------------------------------*/

   //-- Array Generator
   void generateMagicArray();
   /*-----------------------------------------------------------
   Create an array with all the magic square elements to help 
   with both verification and rotation.
   Precondition: None.
   Postcondition: Generate an array of length n x n.
   -----------------------------------------------------------*/


public:  //-- Public Function(s)

   //-- Overloading Operators
   friend ostream& operator<<(ostream& output, const MagicSquare& ms);
   /*-----------------------------------------------------------
   Overload the << to output the magic square to an ostream
   Precondition: MagicSquare object should exist.
   Postcondition: Magic Squares are output on n + 1 lines.
   The first list should indicate n, the size of the magic
   square.
   -----------------------------------------------------------*/

   friend istream& operator>>(istream& input, MagicSquare& ms);
   /*-----------------------------------------------------------
   Overload the >> to input a magic square from istream
   Precondition: None.
   Postcondition: Magic Square is input in the same format as
   it was output.
   -----------------------------------------------------------*/

   const MagicSquare& operator=(const MagicSquare& right);
   /*-----------------------------------------------------------
   Overload the = to assign existing magic squares to new
   magic squares.
   Precondition: None.
   Postcondition: Magic Square is input in the same format as
   it was output.
   -----------------------------------------------------------*/

   //-- Verification Function
   bool isMagicSquare();
   /*-----------------------------------------------------------
   Tests whether the object is a magic square
   Precondition: None.
   Postcondition: Function returns true if the object meets
   the criteria for a magic square and false otherwise.
   (This is useful to verify that a magic square that was
   input is using the overloaded >> is valid).
   -----------------------------------------------------------*/

   //-- Rotation Function
   MagicSquare rotate();
   /*-----------------------------------------------------------
   Creates new MagicSquare object that rotates and rotates it
   90 degrees clockwise
   Precondition: n x n matrix is a magic square.
   Postcondition: Create a new magic square object that
   rotates the calling magic square object
   -----------------------------------------------------------*/

   //-- Display Function
   void display();
   /*-----------------------------------------------------------
   Displays current magic square object
   Precondition: None.
   Postcondition: Displays magic square.
   -----------------------------------------------------------*/

   void debug();
   /*-----------------------------------------------------------
   Helps debug the program.
   Precondition: None.
   Postcondition: This function has no specific purpose
   other than to help debug the program.
   -----------------------------------------------------------*/

private: //-- Data Members

   int size;
   int **matrix;
   int *array;

   //MagicSquare *temp;

}; // end of class declaration

#endif