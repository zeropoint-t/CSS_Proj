
#include <iostream>

int reverse(int x) {
    // string sign = x > 0 ? "" : "-";
    // string str_num = to_string(abs(x));
    // int size = str_num.size();
    // string reverse_str = "";
    // for(int i = 1; i <= size; i++){
    //     reverse_str.push_back(str_num[size-i]);
    // }
    // return atoi((sign + reverse_str).c_str());

    int rev = 0;
    while (x != 0) {
        int pop = x % 10;
        x /= 10;
        if (rev > INT_MAX/10 || (rev == INT_MAX / 10 && pop > 7)) return 0;
        if (rev < INT_MIN/10 || (rev == INT_MIN / 10 && pop < -8)) return 0;
        rev = rev * 10 + pop;
    }
    return rev;
}

int main(){
    int a = reverse(12345);
}