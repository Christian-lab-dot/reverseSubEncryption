#include <iostream>
#include <string>
#include <iterator>
#include <stdlib.h>
#include <algorithm>

//This program will take an input, reverse it, and apply a substitution cipher

using namespace std; 

//reverse string 
string rev(string s){
    reverse(s.begin(), s.end());
    return s;   
}

//Ask for key, shift alpha accordingly, encrypt or decrypt




int main(){
    string a;
    cout << "String to reverse: "; //To test rev function 
    getline(cin, a);
    a = rev(a);
    cout << a; 
    return 0; 
}
