
#include <iostream>
#include <vector>

#include "DataCompressor.h"
using namespace std;

int main(int argc, const char* argv[]){
    // cout << "Hello World" << endl;
    // vector<char> nums;
    // nums.push_back('1');
    // nums.push_back('2');
    // nums.push_back('5');
    DataCompressor dc;
    dc.compressed.push_back('a');
    dc.compressed.push_back('a');
    dc.compressed.push_back('3');
    dc.compressed.push_back('b');
    dc.compressed.push_back('4');
    dc.compressed.push_back('c');
    dc.compressed.push_back('d');
    dc.compressed.push_back('d');
    dc.compressed.push_back('e');
    dc.compressed.push_back('4');
    dc.compressed.push_back('f');
    dc.compressed.push_back('1');
    dc.compressed.push_back('3');
    dc.compressed.push_back('3');
    dc.compressed.push_back('X');

    dc.Decompress();


    return 0;
}