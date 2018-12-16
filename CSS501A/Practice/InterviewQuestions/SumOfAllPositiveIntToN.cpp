#include <vector>
#include <iostream>

using namespace std;

int SumPositiveNums(int n, int curNum){
    if(curNum <= n)
        return curNum + SumPositiveNums(n, curNum + 1);
    else
        return 0;
}

int main(){
    int sum = SumPositiveNums(6,1);
}