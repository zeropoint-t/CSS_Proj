
#include <iostream>
#include "SelectionSort.h"

using namespace std;

int main(int argc, const char * argv[]){
    cout << "Hello World" << endl;
    int items[9] = {6,8,2,4,5,1,3,9,7};
    SelectionSort<int> srt(items);
    srt.Sort(items,sizeof(items)/sizeof(items[0]));
    srt.Display(items,sizeof(items)/sizeof(items[0]));
    return 0;
}