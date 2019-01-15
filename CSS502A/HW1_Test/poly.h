
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
    Poly(int, int = 0);
    Poly(const Poly&);
    ~Poly();

    Poly& operator=(const Poly&);
    Poly operator+(const Poly&);
    Poly& operator+=(const Poly&);
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

#include "poly.h"

// --ostream & operator <<-----------------------------------------------------------------------
// Description: overload cout that prints out a polynomial function: ex. 15x^11 +15x^6 -15
// ----------------------------------------------------------------------------------------------
ostream & operator << (ostream &out, const Poly &p) 
{
    for(int i = p.maxExponent; i >= 0; i--)
    {
        if(p.arr[i] != 0)
        {
            if(i == p.maxExponent)//when exponent is maxExponent - no need for + sign
            {
                out << p.arr[i] << "x" << "^" << i;
            }else{
                if(i == 1)//when exponent is 1
                {
                    if(p.arr[i] < 0)
                    {
                        out << " " << p.arr[i] << "x";
                    }else
                    {
                        out << " +" << p.arr[i] << "x";
                    }
                }else if(i == 0)//when exponent is 0
                {
                    if(p.arr[i] < 0)
                    {
                        out << " " << p.arr[i];
                    }else
                    {
                        out << " +" << p.arr[i];
                    }
                }else//exponent is > 1 and < maxExponent
                {
                    if(p.arr[i] < 0)
                    {
                        out << " " << p.arr[i] << "x" << "^" << i;
                    }else{
                        out << " +" << p.arr[i] << "x" << "^" << i;
                    }
                }
            }
        }// end of if(p.arr[i] != 0)
    }//end of for loop
    return out; 
}

// --istream & operator >>-----------------------------------------------------------------------
// Description: overload cin which takes coefficient and exponent pairs from a user and 
//              set coefficient for the exponent
// ----------------------------------------------------------------------------------------------
istream & operator >> (istream &in, Poly &p) 
{
    //Loop until break is called. 
    while(true)
    {
        //take user inputs
        string line;
        cout << "Enter coefficient and exponent pairs in any order separated by a blank space." << endl;
        cout << "Enter -1 -1 to terminate loop: ";
        getline(cin, line);

        //assign coeff and exp pairs
        //if -1 -1 is in line, terminate will return true so break the loop
        bool terminate = p >> line;

        if(terminate)
            break;

        cout << endl;
    }//end while
    return in; 
}

// --default constructor-----------------------------------------------------------------------
// Description: default constructor
// --------------------------------------------------------------------------------------------
Poly::Poly():arr(NULL), maxExponent(-1){
    cout << "Default Constructor at " << this << endl;
}

// --Poly::Poly(int coeff, int exp)------------------------------------------------------------
// Description: a constructor that takes initial coefficient and exponent
// --------------------------------------------------------------------------------------------
Poly::Poly(int coeff, int exp):
    maxExponent(exp),
    arr(new int[exp + 1])
{
    cout << "Constructor Poly(int coeff, int exp) at " << this << endl;
    for(int i = 0; i <= this->maxExponent; i++)
    {
        this->arr[i] = 0;
    }
    this->arr[this->maxExponent] = coeff;
}

// --Poly::Poly(const Poly& p)-----------------------------------------------------------------
// Description: a copy constructor
// --------------------------------------------------------------------------------------------
Poly::Poly(const Poly& p)
{
    cout << "Copy Constructor Poly(const Poly& p) at " << this << endl;
    // cout << "Copy constructor called" << endl;
    maxExponent = p.maxExponent;
    arr = new int(p.maxExponent + 1);

    cout << p.maxExponent << endl;

    if(this != &p){
        // this->maxExponent = p.maxExponent;
        // this->arr = new int(this->maxExponent + 1);
        for(int i = 0; i <= this->maxExponent; i++)
        {
            cout << i << endl;
            arr[i] = p.arr[i];
        }
    }
}

// --Poly::~Poly()-----------------------------------------------------------------------------
// Description: destructor - calls clear function that releases dynamic array
// --------------------------------------------------------------------------------------------
Poly::~Poly()
{
    cout << "destructor called at " << *this << endl;
    this->clear();
}

// --Poly& Poly::operator=(const Poly& p)------------------------------------------------------
// Description: operator overload of = which deep copies the operand
// --------------------------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& p)
{
    if(this != &p)
    {
        cout << p << endl;
        cout << *this << endl;

        if(maxExponent != -1)
            this->clear();

        this->maxExponent = p.maxExponent;
        this->arr = new int[this->maxExponent + 1];
        for(int i = 0; i <= this->maxExponent; i++)
        {
            this->arr[i] = p.arr[i];
        }
    }
    return *this;
}

// --Poly& Poly::operator+(const Poly& p)------------------------------------------------------
// Description: operator overload of "+" which performs addition of this & operand
//              and returns a copy of new Poly object
// --------------------------------------------------------------------------------------------
Poly Poly::operator+(const Poly& p)
{
    cout << *this << endl;
    cout << p << endl;
    //find max exponent between the 2 poly objects
    int maxExponent = this->maxExponent > p.maxExponent ? this->maxExponent : p.maxExponent;
    if(maxExponent >= 0)
    {
        //create new Poly object to return
        Poly newPoly(0,maxExponent);
        //add like terms
        //visit each exponent subscript from 0 to max exponent
        for(int exp = 0; exp <= maxExponent; exp++)
        {
            //use 0 if exp exceeds maxExponent
            int coeff1 = this->maxExponent >= exp ? this->arr[exp] : 0;
            int coeff2 = p.maxExponent >= exp ? p.arr[exp] : 0;

            //add coefficient
            int new_coeff = coeff1 + coeff2;

            if(new_coeff != 0){
                //set coefficient
                newPoly.setCoeff(new_coeff,exp);
            }
        }
        return newPoly;
    }else{
        return Poly();
    }
}


// --Poly& Poly::operator+=(const Poly& p)-----------------------------------------------------
// Description: operator overload of "+=" which performs addition of this & operand
//              and mutates this and returns a reference of this
// --------------------------------------------------------------------------------------------
Poly& Poly::operator+=(const Poly& p)
{
    // cout << "operator+= called at " << &p << endl;
    *this = *this + p;
    return *this;
}



// --void Poly::operator>>(const string line)--------------------------------------------------
// Description: operator overload of ">>" which takes a string as a parameter
//              The input parameter is expected to be intergers separated by a blank space
//              and it should represent a sequence of pair(s) of coefficient and exponent pair
//              ex. "5 7 2 3 6 0"sets this poly object to represent "5x^7 +2x^3 + 6"
// --------------------------------------------------------------------------------------------
bool Poly::operator>>(const string line)
{
    // cout << "Member function >> is called with " << line << endl;
    // cout << "Mem address: " << this << endl;

    //measure the size of inputs
    int size = 0;
    string val;
    stringstream ssize(line);
    while (ssize.good())
    {
        ssize >> val;
        ++size;
    }
    ssize.clear();

    // cout << "size: " << size << endl;

    //fill in inputs array
    int inputs[size];
    for (int i = 0; i < size; i++) {
        inputs[i] = 0;    // Initialize all elements to zero.
    }

    // cout << "inputs address: " << inputs << endl;
    stringstream ssin(line);
    int i = 0;
    while (ssin.good())
    {
        ssin >> inputs[i++];
    }
    ssin.clear();

    //set coefficient and exponent
    int coeff = 0;
    int exp = 0;
    for(i = 0; i < size; i++)
    {
        coeff = inputs[i++];
        if(i < size)
            exp = inputs[i];

        //terminate flag is true if coeff and exp are both -1
        if(coeff == -1 && exp == -1)
        {
            return true;
        }
        this->setCoeff(coeff, exp);
    }

    return false;//terminate flag is false without coeff & exp are both -1
}

// --int Poly::getCoeff(int exp)---------------------------------------------------------------
// Description: returns a coefficient of a exponent. If exp is out of range, return 0
// --------------------------------------------------------------------------------------------
int Poly::getCoeff(int exp) const
{
    if(exp <= this->maxExponent && exp >= 0)
    {
        return this->arr[exp];
    }else{
        return 0;
    }
}

// --Poly::setCoeff(int coeff, int exp)--------------------------------------------------------
// Description: This is mutator function that sets a coefficient for the exponent.
//              If exp parameter is larger than current maxExponent, resize the internal array
//              and sets the new coefficient for the exponent
// --------------------------------------------------------------------------------------------
void Poly::setCoeff(int coeff, int exp)
{
    // cout << "setCoeff called" << endl;
    //resize arr if new exp is bigger than currnet exp
    if(exp > this->maxExponent)
    {
        //create a new array with the size of the new exponent
        int* newArr = new int[exp + 1];
        for(int i = 0; i <= exp; i++){
            newArr[i] = 0;
        }
        //copy over elements
        for(int i = 0; i <= this->maxExponent; i++)
        {
            newArr[i] = this->arr[i];
        }
        //free up the space for the internal array
        if(this->arr != NULL){
            delete[] this->arr;
            this->arr = NULL;
        }
        
        //assign new array to internal array
        this->arr = newArr;
        //set maxExponent to the new exp
        this->maxExponent = exp;
    }

    //if exp is in a valid range, assign new coefficient
    if(exp >= 0 && exp <= this->maxExponent)
    {
        this->arr[exp] = coeff;
    }
}

// --void Poly::clear()------------------------------------------------------------------------
// Description: resets this object by releasing dynamically allocated memory
// --------------------------------------------------------------------------------------------
void Poly::clear()
{
    if(this->maxExponent != -1)
    {
        // cout << "destructor called" << endl;
        if(arr != NULL){
            cout << "------clear called at " << this << "------" << endl;
            for(int i = 0; i <= maxExponent; i++){
                cout << arr[i];
            }
            cout << endl;
            delete[] arr;
        }
        arr = NULL;
        this->maxExponent = -1;
    }
}

#endif