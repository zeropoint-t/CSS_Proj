// ------------------------------------------------ file name ------------------------------------------------------- -
// Programmer Name:             Tetsuya Hayashi
// Course Section Number:       CSS502A - Winter 2019
// Creation Date:               01/13/2019
// Date of Last Modification:   01/13/2019
// -------------------------------------------------------------------------------------------------------------------- 
// Purpose - a brief statement of the program's function
// Poly - Header file - this class represents a polynomial function that allows addition,
// subtraction and multiplication of ploynomals
// -------------------------------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions.
// 
// --------------------------------------------------------------------------------------------------------------------
#ifndef Poly_h
#define Poly_h

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

class Poly
{
    friend ostream & operator << (ostream &out, const Poly &p);
    friend istream & operator >> (istream &in, Poly &p) ;
public:
    Poly();
    // Poly(int);
    Poly(int, int = 0);
    Poly(const Poly&);
    ~Poly();

    Poly& operator=(const Poly&);
    Poly operator+(const Poly&);
    Poly operator-(const Poly&);
    Poly operator*(const Poly&);
    Poly& operator+=(const Poly&);
    Poly& operator-=(const Poly&);
    Poly& operator*=(const Poly&);
    bool operator==(const Poly&);
    bool operator!=(const Poly&);
    bool operator>>(const string);
 
    int getCoeff(int) const;
    void setCoeff(int,int);
    int getSize() const{
        return maxExponent + 1;
    }
private:
    //an array that stores coefficients at subscripts corresponding to exponents
    int* arr;
    //maximum exponent
    int maxExponent;
    //resets poly object
    void clear();
};

#endif