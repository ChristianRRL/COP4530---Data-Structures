#ifndef AHISTOGRAM_H
#define AHISTOGRAM_H

#include <iostream>
#include <cstdlib>
#include <vector>

using namespace std;

class aHistogram {
public:
   aHistogram(void);
   void update(int face) const;
   void display(int maxLengthOfLine) const;
   int count(int face) const;
   void clear() const;

private:
   const int dieFace;
   const int hScase;
   vector<int> counter(int dieFace);

};

#endif