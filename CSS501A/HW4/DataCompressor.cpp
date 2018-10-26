#include <iostream>
#include <vector>
#include <cmath>
#include "DataCompressor.h"

using namespace std;

DataCompressor::DataCompressor(){}

DataCompressor::DataCompressor(const string str){
    Compress(str);
}

void DataCompressor::Compress(const string str){

}

void DataCompressor::Decompress(){
    vector<char> nums;
    char c;
    for(auto it = compressed.begin(); it != compressed.end(); it++){
        c = *it;
        if(isdigit(c)){
            nums.push_back(c);
        }else{
            expand(getNum(nums),c);
            nums.clear();
        }
    }

    string str(decompressed.begin(),decompressed.end());
    cout << str << endl;
}

int DataCompressor::getNum(const vector<char>& nums) const{
    if(nums.size() == 0)
        return 1;
    else if(nums.size() == 1){
        return ((int)nums[0] - 48);
    }

    int num = 0;
    int p = nums.size()-1;
    for(int i = 0; i < nums.size(); i++){
        num += pow(10,p--) * ((int)nums[i] - 48);
    }
    return num;
}

void DataCompressor::expand(const int cnt, const char c){
    for(int i = 0; i < cnt; i++){
        decompressed.push_back(c);
    }
}