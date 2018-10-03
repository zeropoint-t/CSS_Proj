#include "Rational.h"

Rational::Rational()
{
	numerator = 0;
	denominator = 1;
}

Rational::Rational(int num, int den)
{
	if (den == 0)
	{
		numerator = 0;
		denominator = 1;
	}
	else
	{
		numerator = num;
		denominator = den;
	}
	reduce();
}

Rational::~Rational()
{
}

int Rational::getNumerator() const
{
	return numerator;
}

int Rational::getDemnominator() const
{
	return denominator;
}

bool Rational::setValue(int num, int den)
{
	if (den == 0)
	{
		return false;
	}
	numerator = num;
	denominator = den;
	reduce();
	return true;
}

void Rational::reduce()
{
	if (numerator == 0)
	{
		denominator = 1;
	}
	if ((numerator < 0) && (denominator < 0))
	{
		numerator = -numerator;
		denominator = -denominator;
	}
	int gcd = 1;
	int minimum = min(abs(numerator), abs(denominator));
	for (int i = 2; i <= minimum; i++)
	{
		if (((numerator % i) == 0) && ((denominator % i) == 0))
		{
			gcd = i;
		}
	}

	if (gcd > 1)
	{
		numerator /= gcd;
		denominator /= gcd;
	}
}

Rational Rational::operator*(const Rational &rat) const
{
	Rational result = *this;
	result *= rat;
	return result;
}

Rational& Rational::operator*=(const Rational &rat)
{
	numerator = numerator * rat.numerator;
	denominator = denominator * rat.denominator;
	reduce();
	return *this;
}

Rational Rational::operator/(const Rational &rat) const
{
	Rational result = *this;
	result /= rat;
	return result;
}

Rational& Rational::operator/=(const Rational &rat)
{
	numerator = numerator * rat.denominator;
	denominator = denominator * rat.numerator;
	reduce();
	return *this;
}

Rational Rational::operator+(const Rational &rat) const
{
	Rational result = *this;
	result += rat;
	return result;
}

Rational& Rational::operator+=(const Rational &rat)
{
	numerator = (numerator * rat.denominator) + (rat.numerator * denominator);
	denominator = denominator * rat.denominator;
	reduce();
	return *this;
}

Rational Rational::operator-(const Rational &rat) const
{
	Rational result = *this;
	result -= rat;
	return result;
}

Rational& Rational::operator-=(const Rational &rat)
{
	numerator = (numerator * rat.denominator) - (rat.numerator * denominator);
	denominator = denominator * rat.denominator;
	reduce();
	return *this;
}

Rational Rational::operator-() const
{
	Rational temp;
	temp.numerator = -numerator;
	temp.denominator = denominator;
	return temp;
}

bool Rational::operator==(const Rational &rat) const
{
	return((numerator == rat.numerator) && (denominator == rat.denominator));
}

bool Rational::operator!=(const Rational &rat) const
{
	return ((numerator != rat.numerator) || (denominator != rat.denominator));
}

ostream& operator<<(ostream &outStream, const Rational &rat)
{
	outStream << rat.numerator << "/" << rat.denominator;
	return outStream;
}

istream& operator>>(istream &inStream, Rational &rat)
{
	inStream >> rat.numerator >> rat.denominator;
	if (rat.denominator == 0)
	{
		rat.numerator = 0;
		rat.denominator = 1;
	}
	else
	{
		rat.reduce();
	}
	return inStream;
}