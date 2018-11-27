// 71. Simplify Path
// Medium

// Given an absolute path for a file (Unix-style), simplify it. 

// For example,
// path = "/home/", => "/home"
// path = "/a/./b/../../c/", => "/c"
// path = "/a/../../b/../c//.//", => "/c"
// path = "/a//b////c/d//././/..", => "/a/b/c"

// In a UNIX-style file system, a period ('.') refers to the current directory, so it can be ignored in a simplified path. Additionally, a double period ("..") moves up a directory, so it cancels out whatever the last directory was. For more information, look here: https://en.wikipedia.org/wiki/Path_(computing)#Unix_style

// Corner Cases:

// Did you consider the case where path = "/../"?
// In this case, you should return "/".
// Another corner case is the path might contain multiple slashes '/' together, such as "/home//foo/".
// In this case, you should ignore redundant slashes and return "/home/foo".

#include <iostream>
#include <string>
#include <stack>

using namespace std;

string simplifyPath(string path) {
    stack<char> s;
    for(auto it = path.begin(); it != path.end(); it++){
        cout << *it << endl;

        if(s.empty()) {
            s.push(*it);
        }else if(s.top() == '/' && *it == '/'){
            //do nothing
        }else if(s.top() == '.' && *it == '.'){
            //pop until the first alphabet
            while(!s.empty() && isalpha(s.top()) == false)
                s.pop();
            //then pop until the first non alphabet
            while(!s.empty() && isalpha(s.top()) == true)
                s.pop();
            //pop until the first alphabet
            while(!s.empty() && isalpha(s.top()) == false)
                s.pop();
            s.push('/');
        }
        else if(s.top() == '.' && *it == '/'){
            while(!s.empty() && isalpha(s.top()) == false)
                s.pop();
            s.push('/');
        }else{
            s.push(*it);
        }
    }

    //remove last back slash
    while(s.top() == '/')
        s.pop();

    string str;
    stack<char> ss;
    while(s.empty() == false){
        ss.push(s.top());
        s.pop();
    }
    while(ss.empty() == false){
        str += ss.top();
        ss.pop();
    }

    return str;
}

int main(){
    string path = "/a//../b////c/d//././/..";
    string simpPath = simplifyPath(path);
    cout << simpPath << endl;
}