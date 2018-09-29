#include <iostream>

using namespace std;

class Calculator{
    public:
    int Calcualate(int, int, char);
};

int main(){
    int x, y, result;
    char oper;
    cout << "Hello World" << endl;
    cout  << "Enter" << endl;
    cin >> x >> y >> oper;
    Calculator c;
    result = c.Calcualate(x, y, oper);

    cout << "Result is: " << result << endl;

    cin.ignore();
    cin.get();

    return 0;
}

int Calculator::Calcualate(int x, int y, char oper){
    switch(oper){
        case '+':
            return x + y;
        case '-':
            return x - y;
        case '*':
            return x * y;
        case '/':
            return x / y;
        default:
            return 0;
    }
}