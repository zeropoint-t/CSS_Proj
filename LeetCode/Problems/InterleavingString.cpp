
// 97. Interleaving String

// Hard

// Given s1, s2, s3, find whether s3 is formed by the interleaving of s1 and s2.

// Example 1:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbcbcac"
// Output: true

// Example 2:
// Input: s1 = "aabcc", s2 = "dbbca", s3 = "aadbbbaccc"
// Output: false

#include <iostream>
#include <string>
#include <string.h>

using namespace std;

class Solution {
public:
    bool isInterleave1(string s1, string s2, string s3) {

        auto ps1 = s1.begin();
        auto ps2 = s2.begin();

        //interate through each char in main string
        for(auto it = s3.begin(); it != s3.end(); it++){
            cout << "main: " << *it << endl;
            if(ps1 != s1.end() && *ps1 == *it){
                cout << "s1: " << *it << endl;
                ps1++;
            }else if(ps2 != s2.end() && *ps2 == *it){
                cout << "s2: " << *it << endl;
                ps2++;
            }else{
                return false;
            }

            //swap ps1 and ps2 here to allow the other char pointer to be prioritized for the next interation
            auto tmp = ps1;
            ps1 = ps2;
            ps2 = tmp;
        }

        return true;
    }

    // A simple recursive function to check whether C is an interleaving of A and B 
    bool isInterleave2(const char *A, const char *B, const char *C) 
    { 
        // Base Case: If all strings are empty 
        if (!(*A || *B || *C)) 
            return true; 
    
        // If C is empty and any of the two strings is not empty 
        if (*C == '\0') 
            return false; 
    
        // If any of the above mentioned two possibilities is true, 
        // then return true, otherwise false 
        return ( (*C == *A) && isInterleave2(A+1, B, C+1)) 
            || ((*C == *B) && isInterleave2(A, B+1, C+1)); 
    }

    // The main function that returns true if C is 
    // an interleaving of A and B, otherwise false. 
    bool isInterleave3(const char* A, const char* B, const char* C) 
    { 
        // Find lengths of the two strings 
        int M = strlen(A), N = strlen(B); 
    
        // Let us create a 2D table to store solutions of 
        // subproblems.  C[i][j] will be true if C[0..i+j-1] 
        // is an interleaving of A[0..i-1] and B[0..j-1]. 
        bool IL[M+1][N+1]; 
        cout << sizeof(IL) << endl;
        memset(IL, 0, sizeof(IL)); // Initialize all values as false. 
    
        // C can be an interleaving of A and B only of sum 
        // of lengths of A & B is equal to length of C. 
        if ((M+N) != strlen(C)) 
        return false; 
    
        // Process all characters of A and B 
        for (int i=0; i<=M; ++i) 
        {
            for (int j=0; j<=N; ++j) 
            { 
                // two empty strings have an empty string 
                // as interleaving 
                if (i==0 && j==0) 
                    IL[i][j] = true; 
    
                // A is empty 
                else if (i==0 && B[j-1]==C[j-1]) 
                    IL[i][j] = IL[i][j-1]; 
    
                // B is empty 
                else if (j==0 && A[i-1]==C[i-1]) 
                    IL[i][j] = IL[i-1][j]; 
    
                // Current character of C matches with current character of A, 
                // but doesn't match with current character of B 
                else if(A[i-1]==C[i+j-1] && B[j-1]!=C[i+j-1]) 
                    IL[i][j] = IL[i-1][j]; 
    
                // Current character of C matches with current character of B, 
                // but doesn't match with current character of A 
                else if (A[i-1]!=C[i+j-1] && B[j-1]==C[i+j-1]) 
                    IL[i][j] = IL[i][j-1]; 
    
                // Current character of C matches with that of both A and B 
                else if (A[i-1]==C[i+j-1] && B[j-1]==C[i+j-1]) 
                    IL[i][j]=(IL[i-1][j] || IL[i][j-1]) ; 
            }
        }
        return IL[M][N]; 
    }
};

// A function to run test cases 
void test(const char *A, const char *B, const char *C) 
{ 
    Solution s;
    if (s.isInterleave3(A, B, C)) 
        cout << C <<" is interleaved of " << A <<" and " << B << endl; 
    else
        cout << C <<" is not interleaved of " << A <<" and " << B << endl; 
}

int main(){
    // char str[50] = "GeeksForGeeks is for programming geeks."; 
    // printf("\nBefore memset(): %s\n", str); 
  
    // // Fill 8 characters starting from str[13] with '.' 
    // memset(str + 13, '.', 8*sizeof(char)); 
  
    // printf("After memset():  %s", str); 

    // cout << endl;

    string s1 = "XXY", s2 = "XXZ", s3 = "XXYXXZ";
    // Solution s;
    // bool isValid = s.isInterleave1(s1,s2,s3);
    // bool isValid = s.isInterleave2(s1.c_str(),s2.c_str(),s3.c_str());
    test(s1.c_str(),s2.c_str(),s3.c_str());
    // cout << isValid << endl;
}