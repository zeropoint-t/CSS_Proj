// 
//  Rational class represents a rational value as "a / b" where a and b are integers
//  Operators with denominator as 0 keep the denominator as 0--not a rational.
//

#include <iostream>
#include "Rational.h"
using namespace std;


// class Check
// {
//   friend ostream& operator<<(ostream &outStream, const Check &check);

//   private:
//     int i;
//   public:
//     Check(): i(0) {  }
//     Check operator ++ ()
//     {
//         Check temp;
//         temp.i = ++i;
//         return temp;
//     }

//     // Notice int inside barcket which indicates postfix increment.
//     Check operator ++ (int)
//     {
//         Check temp;
//         temp.i = i++;
//         return temp;
//     }

//     void Display()
//     { cout << "i = "<< i <<endl; }
// };

// ostream& operator<<(ostream &outStream, const Check &check)
// {
// 	outStream << check.i;
// 	return outStream;
// }

// ostream& operator<<(ostream &outStream, const Check &check)
// {
// 	outStream << check.i;
// 	return outStream;
// }

int main()
{
    // Check obj;    
    // obj.Display(); 
    // obj++;
    // ++obj;

    // cout << obj << endl;

	int waitVar;

	// Rational rat1(3, 7), rat2(5, 10);
	// cout << "rat1: " << &rat1 << endl;
	// cout << "rat2: " << &rat2 << endl;
	// Rational rat3 = rat1 + rat2;

	// cout << "rat3: " << &rat3 << endl;

	Rational rat1(3, 7);
	cout << "rat1: " << &rat1 << endl;
	Rational rat = rat1.hi();
	cout << "rat: " << &rat << endl;
	int a = 0;

	// Rational rat1(3, 7), rat2(5, 10);
	// Rational rat3, rat4, rat5, rat6;
	// cout << "Welcome to our calculator" << endl;

    // cout << rat1 << endl;

	// cout << "rat1: " << rat1 << endl;	
	// cout << "rat2: " << rat2 << endl;
	// cout << "rat3: " << rat3 << endl;

	// cout << "rat1 + rat2 = " << (rat1 + rat2) << endl;
	// cout << "rat1 - rat2 = " << (rat1 - rat2) << endl;
	// cout << "rat1 * rat2 = " << (rat1 * rat2) << endl;
	// cout << "rat1 / rat2 = " << (rat1 / rat2) << endl;
	// cout << "-rat1 = " << -rat1 << endl;

	// rat1 -= rat2;
	// cout << "rat1 -= rat2; rat1: " << rat1 << endl;



	// cout << "Input a rational. Numerator and denomiator as two integers: ";
	// cin >> rat3;
	// cout << "You entered: " << rat3 << endl;

	// if (rat3 == rat2)
	// {
	// 	cout << "The rational you entered is equal to rat2" << endl;
	// }
	// else
	// {
	// 	cout << "The rational you entered is not equal to rat2" << endl;
	// }

	return 0;
}