#ifndef Rational_h
#define Rational_h

#include <iostream>
#include <algorithm>
using namespace std;

class Rational
{
	friend ostream& operator<<(ostream &outStream, const Rational &rat);
	friend istream& operator>>(istream &inStream, Rational &rat);

public:

// Constructors - Destructor
	Rational();
	Rational(int num, int den);
	~Rational();

// Getters - Setters
	int getNumerator() const;
	int getDemnominator() const;
	bool setValue(int num, int den);

// Op Overloads
	Rational operator*(const Rational &rat) const;
	Rational& operator*=(const Rational &rat);

	Rational operator/(const Rational &rat) const;
	Rational& operator/=(const Rational &rat);

	Rational operator-(const Rational &rat) const;
	Rational& operator-=(const Rational &rat);

	Rational operator+(const Rational &rat) const;
	Rational& operator+=(const Rational &rat);

	Rational operator-() const;

	bool operator==(const Rational &rat) const;
	bool operator!=(const Rational &rat) const;


private:
	int numerator;
	int denominator;
	void reduce();
};

#include "Rational.cpp"

#endif