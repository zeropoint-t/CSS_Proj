
#include<iostream>
using namespace std;

int SearchInsertPosition(int* arr, int left, int right, int val){
    if(left >right)
        return right + 1;

    int mid = (right-left)/2 + left;
    if(arr[mid] == val)
        return mid;
    else if(arr[mid] < val){
        left = mid+1;
    }else{
        right = mid-1;
    }

    return SearchInsertPosition(arr, left, right, val);
}

int main(){
    int arr[4] = {1,3,5,6};
    int size = 4;
    int left = 0;
    int right = size-1;
    int searchVal = 0;

    int pos = SearchInsertPosition(arr, left, right, searchVal);
    cout << pos << endl;
}