#include <iostream>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <algorithm>
#include <cmath>

//This program will take an input, reverse it, and apply a substitution cipher

using namespace std; 

//reverse string 
string rev(string s){
    reverse(s.begin(), s.end());
    return s;   
}

//Ask for key, shift alpha accordingly, encrypt or decrypt
void key(){
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipher; 
    int key;
    cout << "key: ";
    cin >> key; 
    //construct cipher
    for(int i = 0; i < alpha.length(); ++i){
        int val = key + i; 
        if(val > alpha.length()-1){
            cipher += alpha[val % alpha.length()];
        }
        else if(val < 0){
            cipher += alpha[alpha.length() + val];
        }
        else{
            cipher += alpha[val];
        }
    }
    cout << cipher;
}



int main(){
    string a;
    /*cout << "String to reverse: "; //To test rev function 
    getline(cin, a);
    a = rev(a);
    cout << a;*/
    key(); 
    return 0; 
}
