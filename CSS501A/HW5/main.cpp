
#include <iostream>
#include <cstdlib>
#include "Set.h"
#include "Data.h"

using namespace std;

int main(){
    Set<Data<int>> s;
    for(int i = 0; i < 30; i++){
        int val = i%(rand()%5+1);
        Data<int> intData(val);
        s.Add(intData);
    }

    s.PrintItems();
}