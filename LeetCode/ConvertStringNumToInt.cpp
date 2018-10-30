

#include <iostream>
#include <string>
using namespace std;

int main(){

    
    int intNum = 0;
    string strNum = "56213";
    int lg = strNum.size();
    for(int i = 0; i < lg; i++){
        cout << (int)strNum[i]-'0' << endl;
        intNum = (intNum * 10) + (int)strNum[i]-'0';
    }


}