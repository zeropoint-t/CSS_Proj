// -- poly.h ------------------------------------------------------------------------------------
// Programmer Name:             Tetsuya Hayashi
// Course Section Number:       CSS502A - Winter 2019
// Creation Date:               01/13/2019
// Date of Last Modification:   01/13/2019
// ---------------------------------------------------------------------------------------------- 
// Purpose - a brief statement of the program's function
// Poly - Header file - this class represents a polynomial function that allows addition,
// subtraction and multiplication of ploynomals
// ---------------------------------------------------------------------------------------------- 
// Notes on specifications, special algorithms, and assumptions.
// 
// ----------------------------------------------------------------------------------------------
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
Poly::Poly(){}

// --Poly::Poly(int coeff, int exp)------------------------------------------------------------
// Description: a constructor that takes initial coefficient and exponent
// --------------------------------------------------------------------------------------------
Poly::Poly(int coeff, int exp):
    maxExponent(exp),
    arr(new int[exp + 1])
{
    for(int i = 0; i <= this->maxExponent; i++)
    {
        this->arr[i] = 0;
    }
    this->arr[this->maxExponent] = coeff;
}

// --Poly::Poly(int coeff)---------------------------------------------------------------------
// Description: a constructor that takes only initial coefficient and exponent defaults to 0
// --------------------------------------------------------------------------------------------
Poly::Poly(int coeff):
    maxExponent(0),
    arr(new int[1])
{
    arr[0] = coeff;
}

// --Poly::Poly(const Poly& p)-----------------------------------------------------------------
// Description: a copy constructor
// --------------------------------------------------------------------------------------------
Poly::Poly(const Poly& p):
    maxExponent(p.maxExponent),
    arr(new int(p.maxExponent + 1))
{
    cout << "Copy constructor called" << endl;
    if(this != &p){
        // this->maxExponent = p.maxExponent;
        // this->arr = new int(this->maxExponent + 1);
        for(int i = 0; i <= this->maxExponent; i++)
        {
            cout << p.arr[i] << endl;
            this->arr[i] = p.arr[i];
        }
    }
}

// --Poly::~Poly()-----------------------------------------------------------------------------
// Description: destructor - calls clear function that releases dynamic array
// --------------------------------------------------------------------------------------------
Poly::~Poly()
{
    // cout << "destructor called at " << this << endl;
    this->clear();
}

// --Poly& Poly::operator=(const Poly& p)------------------------------------------------------
// Description: operator overload of = which deep copies the operand
// --------------------------------------------------------------------------------------------
Poly& Poly::operator=(const Poly& p)
{
    if(this != &p)
    {
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

// --Poly& Poly::operator-(const Poly& p)------------------------------------------------------
// Description: operator overload of "-" which performs subtraction of this & operand
//              and returns a copy of new Poly object
// --------------------------------------------------------------------------------------------
Poly Poly::operator-(const Poly& p)
{
    //find max exponent between the 2 poly objects
    int maxExponent = this->maxExponent > p.maxExponent ? this->maxExponent : p.maxExponent;
    if(maxExponent >= 0)
    {
        //create new Poly object to return
        Poly newPoly(0,maxExponent);
        //subtract like terms
        //visit each exponent subscript from 0 to max exponent
        for(int exp = 0; exp <= maxExponent; exp++)
        {
            //use 0 if exp exceeds maxExponent
            int coeff1 = this->maxExponent >= exp ? this->arr[exp] : 0;
            int coeff2 = p.maxExponent >= exp ? p.arr[exp] : 0;

            //subtract coefficient
            int new_coeff = coeff1 - coeff2;

            //set coefficient
            newPoly.setCoeff(new_coeff,exp);
        }
        return newPoly;
    }else
    {
        return Poly();
    }
}

// --Poly& Poly::operator*(const Poly& p)------------------------------------------------------
// Description: operator overload of "*" which performs multiplication of this & operand
//              and returns a copy of new Poly object
// --------------------------------------------------------------------------------------------
Poly Poly::operator*(const Poly& p)
{
    Poly newPoly;
    Poly* term = new Poly();
    for(int i = 0; i <= this->maxExponent; i++)
    {
        for(int j = 0; j <= p.maxExponent; j++)
        {
            int coeff1 = this->arr[i];
            int coeff2 = p.arr[j];
            int coeff = coeff1 * coeff2;
            int exp = i + j;
            term->setCoeff(coeff, exp);
            newPoly += *term;//Poly(coeff, exp);
            term->clear();
        }
    }

    return newPoly;
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

// --Poly& Poly::operator-=(const Poly& p)-----------------------------------------------------
// Description: operator overload of "-=" which performs subtraction of this & operand
//              and mutates this and returns a reference of this
// --------------------------------------------------------------------------------------------
Poly& Poly::operator-=(const Poly& p)
{
    *this = *this - p;
    return *this;
}

// --Poly& Poly::operator*=(const Poly& p)-----------------------------------------------------
// Description: operator overload of "*=" which performs multiplication of this & operand
//              and mutates this and returns a reference of this
// --------------------------------------------------------------------------------------------
Poly& Poly::operator*=(const Poly& p)
{
    *this = *this * p;
    return *this;
}

// --Poly& Poly::operator==(const Poly& p)-----------------------------------------------------
// Description: operator overload of "==" which compares equality of this & operand
//              true if both are initialized with default constructor or both have the same
//              number of maxExponent and all coefficients are the same
// --------------------------------------------------------------------------------------------
bool Poly::operator==(const Poly& p)
{
    //if maxExponent is different, these are 2 poly objects contain 
    //different polynomial representations
    if(this->maxExponent != p.maxExponent)
        return false;

    //both are initialized with default constructor
    //so they are the same
    if(this->maxExponent == -1)
        return true;
    
    //if any coefficients are different from one another
    //these 2 poly objects contain 2 different polynomial representations
    for(int i = 0; i <= this->maxExponent; i++)
    {
        if(this->arr[i] != p.arr[i])
            return false;
    }

    //if it reaches here, these represent the same polynomials
    return true;
}

// --Poly& Poly::operator!=(const Poly& p)-----------------------------------------------------
// Description: operator overload of "!=" which compares inequality of this & operand
//              true if they have different number of maxExponent or
//              some coefficients are different
// --------------------------------------------------------------------------------------------
bool Poly::operator!=(const Poly& p)
{
    //if maxExponent is different, these 2 poly objects contain 
    //different polynomial representations
    if(this->maxExponent != p.maxExponent)
        return true;

    //both are initialized with default constructor
    //so they are the same
    if(this->maxExponent == -1)
        return false;
    
    //if any coefficients are different from one another
    //these 2 poly objects contain 2 different polynomial representations
    for(int i = 0; i <= this->maxExponent; i++)
    {
        if(this->arr[i] != p.arr[i])
            return true;
    }

    //if it reaches here, these represent the same polynomials
    return false;
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
int Poly::getCoeff(int exp)
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
        int* newArr = new int[exp + 1]{0};
        //copy over elements
        for(int i = 0; i <= this->maxExponent; i++)
        {
            newArr[i] = this->arr[i];
        }
        //free up the space for the internal array
        if(this->arr != nullptr){
            delete[] this->arr;
            this->arr = nullptr;
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
        if(arr != nullptr){
            cout << "------clear called at " << this << "------" << endl;
            for(int i = 0; i <= maxExponent; i++){
                cout << arr[i];
            }
            cout << endl;
            delete[] arr;
        }
        arr = nullptr;
        this->maxExponent = -1;
    }
}

