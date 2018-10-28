
#include <iostream>
#include <vector>

#include "CompressedString.h"
using namespace std;

int main(int argc, const char* argv[]){

    cout << endl;

    //---------------------------------------
    //string to compress 1
    cout << "---Demonstration of short string---" << endl;
    string strToCompress1 = "abc";
    cout << "String to compress: \t" << strToCompress1 << endl;

    CompressedString cs1(strToCompress1);
    cs1.DisplayCompressed();
    cout << cs1 << endl << endl;
    //---------------------------------------


    //---------------------------------------
    //string to compress 2
    cout << "---Demonstration of long string---" << endl;
    string strToCompress2 = "abbbbccccccddeeefgg";
    cout << "String to compress: \t" << strToCompress2 << endl;

    CompressedString cs2(strToCompress2);
    cs2.DisplayCompressed();
    cout << cs2 << endl << endl;
    //---------------------------------------


    //---------------------------------------
    //string to compress 3
    cout << "---Demonstration of loooooooooong string---" << endl;
    string strToCompress3 = "abbbbccccccddeeefffffffffffffffffffffghhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhhh";//"abcdefghijklmn";
    cout << "String to compress: \t" << strToCompress3 << endl;

    CompressedString cs3(strToCompress3);
    cs3.DisplayCompressed();
    cout << cs3 << endl << endl;
    //---------------------------------------


    //---------------------------------------
    cout << "***Big-O Analysis***" << endl;
    cout << "Compress method: It loops through each character in a str parameter n times." << endl;
    cout << "Vector.push_back has amotized time complexity of O(1)." << endl;
    cout << "Therefore, compress function operates at O(n) time complexity" << endl << endl;

    cout << "Decompress method: It loops through each character in the \"compressed\" vector once." << endl;
    cout << "Since the original string contains \"n\" characters and the characters are recreated n times." << endl;
    cout << "Therefore, decompress function operates at O(n) time complexity" << endl;
    //----------------------------------------
    return 0;
}