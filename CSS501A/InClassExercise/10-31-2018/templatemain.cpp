#include <iostream>
#include <string>
#include "template.h"

using namespace std;
int main(){
    Foo<string> foo("Hello World");
    string val = foo.bar();
    cout << val << endl;
}