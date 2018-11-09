
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

//Brute Force
int sqrt1(int x) {
    ULONG a = 1;
    while (a * a <= x) {
        cout << "a=: " << a << endl;
        a ++;
    }
    return --a;
}

// We notice that a * a is expensive, how to get rid of that?
//(n+1)^2 = n^2 + 2n + 1
// Therefore, we can just add 2 to a variable delta and add it to current variable a to get 
// the square of a + 1.
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

//Binary Search
int sqrt3(int x) {
    ULONG l = 0, r = x;
    while (l <= r) {
        ULONG mid = l + (r - l) / 2; // (l + r) / 2;
        ULONG midmid = mid * mid;
        // check if x falls into [mid^2, (mid + 1)^2) 
        if ((midmid <= x) && (x < (mid + 1) * (mid + 1))) 
            return mid;

        if (midmid > x) {
            r = mid - 1;
        } else {
            l = mid + 1;
        }
    }
}

int sqrt_newton(int x) {
    if (x==0) 
        return x;

    double dividend = x;  
    double val = x;
    double last;
    
    do {  
        last = val;  
        val = (val + dividend / val) * 0.5;  
    } while(abs(val - last) > 1e-9); // precision
    return (int)val;        
}

int main(int argc, const char * argv[]) {

    int value = 248;

    int result1 = sqrt1(value);
    cout << "result is: " << result1 << endl;

    cout << endl;
    cout << endl;

    int result2 = sqrt2(value);
    cout << "result is: " << result2 << endl;

    cout << endl;
    cout << endl;

    int result3 = sqrt3(value);
    cout << "result is: " << result3 << endl;

    cout << endl;
    cout << endl;

    int result4 = sqrt_newton(value);
    cout << "result is: " << result4 << endl;

    return 0;
}

