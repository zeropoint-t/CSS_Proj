

#include <iostream>
using namespace std;

int findMaxV1(int* arr, int size){
    if(size == 1){
        return *arr;
    }
    int max = findMaxV1(arr+1, size-1);

    if(max > *arr){
        return max;
    }else{
        return *arr;
    }
}

int main(int argc, const char* argv[]){
    int arr[10] = {1,5,6,3,10,4,8,9,7,2};
    int max = findMaxV1(arr,10);
    cout << "Hello WOrld" << endl;
}