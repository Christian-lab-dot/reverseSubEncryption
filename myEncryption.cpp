#include <iostream>
#include <string> 
#include <cmath>
#include <math.h>

using namespace std;

const string vowels = "aeiouAEIOU"; 

int magicNum(string key)
{
    //sum the chars of key
    int num = 0;
    for (char c : key)
    {
        num += (int)(c);
    }
    //find length of number
    int len = 0; 
    for (int i = num; i > 0; i/=10)
    {
        ++len; 
    }
    //get last digit in num
    int last = num % 10;
    if (last == 0)
    {
        last = 5; 
    }
    //return the len root of num * last digit
    int result = pow((double)num, 1.0/len) * last; 
    return result; 
}

bool isVowel(char c)
{
    for (char k : vowels)
    {
        if (c == k)
        {
            return true;
        }
    }
    return false;
}


string encrypt(string s, string key)
{
    string eMsg = "";
    int val = magicNum(key);
    int hold; 
    for (char c : s)
    {
        hold = (int)c + val;
        //check and see where I am encrypting is not a vowel
        if ((int)c + val > 126)
        {
            hold = 33 + (val - (126-(int)c));
        }
        if (!isVowel(c) && !isVowel((char)(hold)) && (int)c > 32)
        {
            if ((int)c + val > 126)
            {
                eMsg += (char)(33 + (val - (126-(int)c)));
            }
            else
            {
                eMsg += (char)((int)c + val);
            }
        }
        else
        {
            eMsg += c;
        }
    }
    return eMsg;
}

string decrypt(string s, string key)
{
    int val = -magicNum(key); 
    string dMsg = "";
    for (char c : s)
    {  
        if (!isVowel(c) && (int)c > 32)
        {
            if ((int)c + val < 33)
            {
                dMsg += (char)(126 + (((int)c - 33) + val)); 
            }
            else
            {
                dMsg += (char)((int)c + val);
            }
        }
        else
        {
            dMsg += c;
        }  
    }
    return dMsg; 
}

int main()
{
    /*string a = "";
    cin >> a;
    string b = a.substr(0,3);
    b.append(vowels);
    cout << b;*/ 
    //cout << magicNum("abc");
    /*string a = "plz work :)";
    cout << "plaintext: " << a << "\n"; 
    cout << "encrypt: " << encrypt(a, "gg") << "\n";
    string b = "62@C=o81C]L";
    cout << "decrypt: " << decrypt(b,"gg") << "\n";*/
    cout << magicNum("wow oh wow") << "\n";
    cout << -magicNum("wow oh wow") << "\n";
    cout << encrypt("how do you do", "wow oh wow") << "\n";
    cout << decrypt("Po_ Lo you Lo", "wow oh wow");
    return 0;
}