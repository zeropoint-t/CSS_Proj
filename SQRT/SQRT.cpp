
/*
I want a technology to allow my mind to think of codes and type on a screen. This way, we programmers can speed up our train of thoughts.
*/

#include <iostream>
#include <string>
#include <sstream>

using namespace std;

#include <math.h>
typedef unsigned long long ULONG;


// void Rational(double d){
//     ostringstream strs;
//     strs << d;
//     string str = strs.str();
//     int digitsDec = str.length() - 1 - str.find(".");
//     int denom = 1;
//     for(int i = 0; i < digitsDec; i++){
//         d *= 10;
//         denom *= 10;
//     }
    
//     GCD(d, denom);

// }

// int GCD(int num, int denom){
//     int sqrt = Sqrt(num);
//     for(long i = 1; i <= sqrt; i++) {
//         if(num % i == 0) {
//             cout << i << endl;
//             if(i != num/i) {
//                 cout << num/i << endl;
//             }
//         }
//     }

//     cout << endl;

//     sqrt = Sqrt(denom);
//     for(long i = 1; i <= sqrt; i++) {
//         if(denom % i == 0) {
//             cout << i << endl;
//             if(i != denom/i) {
//                 cout << denom/i << endl;
//             }
//         }
//     }

//     return 0;
// }

// double Sqrt( int n )
// {
// 	// double a = (eventually the main method will plug values into a)
// 	double a = (double) n;
// 	double x = 1;
 
// 	// For loop to get the square root value of the entered number.
// 	for( int i = 0; i < n; i++)
// 	{
// 		x = 0.5 * ( x+a / x );
// 	}
 
// 	return x;
// } 

int sqrt1(int x) {
    ULONG a = 1;
    while (a * a <= x) {
        cout << "a=: " << a << endl;
        a ++;
    }
    return --a;
}

int sqrt2(int x) {
    int count = 0;
    ULONG a = 1;
    ULONG delta = 3;
    cout << "count=: " << count << endl;
    cout << "a=: " << a << endl;
    cout << "delta=: " << delta << endl;
    cout << endl;

    while (a <= x) {

        a += delta; // (a + 1)^2
        delta += 2;

        cout << "count=: " << ++count << endl;
        cout << "a=: " << a << endl;
        cout << "delta=: " << delta << endl;
        cout << endl;
    }
    return delta / 2 - 1;
}

int main(int argc, const char * argv[]) {

    int value = 248;

    int result1 = sqrt1(value);
    cout << "result is: " << result1 << endl;

    cout << endl;
    cout << endl;

    int result2 = sqrt2(value);
    cout << "result is: " << result2 << endl;

    return 0;
}

