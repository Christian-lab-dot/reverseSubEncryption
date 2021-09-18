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
void key(){
    string alpha = "ABCDEFGHIJKLMNOPQRSTUVWXYZ";
    string cipher; 
    int key;
    cout << "key: ";
    cin >> key; 
    //construct cipher
    for(int i = 0; i < alpha.size(); ++i){
        //check if key + i is < 0 or > 26
        if(key+i > alpha.size()){
            if(key+i % alpha.size() == 1){
                cipher += alpha[0];
            }
            else{
                cipher += alpha[key+i % alpha.size()];
        }
            } 
        else if(key+i < 0){
            cipher += alpha[25 - abs(key+i)];
        }
        else{
            cipher += alpha[key+i];
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
