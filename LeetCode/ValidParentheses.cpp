#include <iostream>
#include <string>
#include <stack>
#include <set>
#include <map>

using namespace std;

bool isValid(string s){
    stack<char> stk;
    for(int i = 0; i < s.length(); i++){
        if(s[i] == '(' || s[i] == '[' ||s[i] == '{'){
            stk.push(s[i]);
        }else{
            if(stk.empty())
                return false;

            char c = stk.top();
            stk.pop();
            if((s[i] == ')' && c != '(')
                || (s[i] == ']' && c != '[')
                ||(s[i] == '}' && c != '{'))
            {
                return false;
            }
        }
    }
    
    return stk.empty();
}

int main(int argc, const char** argv){
    std::map<char,int> mymap;

    std::map<char,int>::key_compare mycomp = mymap.key_comp();

    mymap['c']=100;
    mymap['a']=200;
    mymap['b']=300;

    std::cout << "mymap contains:\n";
    // bool exists = mymap.find('a') != mymap.end();
    // cout << exists << endl;

    // exists = mymap.find('d') != mymap.end();
    // cout << exists << endl;

    char highest = mymap.rbegin()->first;     // key value of last element

    std::map<char,int>::iterator it = mymap.begin();
    do {
        std::cout << it->first << " => " << it->second << '\n';
    } while ( mycomp((*it++).first, highest) );

    std::cout << '\n';

    // std::set<std::string> setOfNumbers;
 
	// // Lets insert four elements
	// setOfNumbers.insert("first");
	// setOfNumbers.insert("second");
	// setOfNumbers.insert("third");
	// setOfNumbers.insert("first");
 
	// // Only 3 elements will be inserted
	// std::cout<<"Set Size = "<<setOfNumbers.size()<<std::endl;
 
	// // Iterate through all the elements in a set and display the value.
	// for (std::set<std::string>::iterator it=setOfNumbers.begin(); it!=setOfNumbers.end(); ++it)
	//     std::cout << ' ' << *it;
	// std::cout<<"\n";
    
    // string s = "((()(())))";
    // bool valid = isValid(s);
    // cout << "Is this valid? " << valid << endl;
}


