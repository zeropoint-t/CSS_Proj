// DO NOT change anything in this file. Your code must compile and give the
// correct output with this main on the linux machines.
// Make sure the file containing the member function source is: poly.cpp
// Use all lowercase in the file names.// This main does not do a thorough job of testing.  When testing arrays,
// be sure to test the middle and also all the boundary conditions.  Test
// values on the boundary and outside the boundaries, i.e., too big/small.
#include "poly.h"
#include <iostream>
using namespace std;
int main() {
    Poly A(5, 7);
    Poly B(3, 4);
    Poly D;
    cout << "A = " << A << endl;
    cout << "B = " << B << endl;
    D = A + B;
    cout << D << endl;
    return 0;
}