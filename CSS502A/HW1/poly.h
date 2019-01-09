
#ifndef House_h
#define House_h

#include <iostream>
#include <string>

using namespace std;

class poly
{
    friend ostream & operator << (ostream &out, const poly &c);
public:
    poly(int);
    poly(int,int);
    poly(const poly&);
    ~poly();

    poly& operator=(const poly&);
    poly& operator+=(const poly&);
    poly& operator-=(const poly&);
    poly& operator*=(const poly&);
    bool operator==(const poly&);
    bool operator!=(const poly&);
    void operator>>(const poly&);

    int getCoeff(int);
private:
    int* arr;
    size_t size;
};

ostream & operator << (ostream &out, const poly &p) 
{
    for(int i = 0; i < p.size; i++)
    {
        out << p.arr[i] << " ";
    }
    return out; 
} 

poly::poly(int coeff, int exp)
{
    this->size = exp + 1;
    arr = new int[this->size]{0};
    arr[this->size - 1] = coeff;
}

poly::~poly()
{
    delete[] arr;
}

int poly::getCoeff(int exp)
{
    if(exp < this->size && exp >= 0){
        return this->arr[exp];
    }else{
        return 0;
    }
}

#endif