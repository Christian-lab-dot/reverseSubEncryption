#include <iostream>
#include <string>
#include <cmath>
#include <math.h>

using namespace std;

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

bool isSpace(char c)
{
    if ((int)c == 32)
    {
        return true;
    }
    return false;
}

string encrypt(string plain, string key)
{
    int val =  magicNum(key);
    string eMsg = "";
    for (char c: plain)
    {
        if (!isSpace(c))
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

string decrypt(string plain, string key)
{
    int val = -magicNum(key);
    string dMsg = "";
    for (char c : plain)
    {
        if (!isSpace(c))
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
    int c;
    string str;
    string key;
    char choice = 'y';
    while (choice == 'y' || choice == 'Y')
    {
        cout << "what do you want to do?\n" << "1:encrypt\n" << "2:decrypt\n";
        cin >> c;
        cin.ignore();
        if (c == 1)
        {
            cout << "message to be encrypted: ";
            getline(cin, str);
            cout << "key (keyword or phrase): ";
            getline(cin, key);
            cout << encrypt(str, key) << "\n"; 
        }
        if (c == 2)
        {
            cout << "message to be decrypted: ";
            getline(cin, str);
            cout << "key (keyword or phrase): ";
            getline(cin, key);
            cout << decrypt(str, key) << "\n";
        }
        cout << "would you like to continue (y or n)\n";
        cin >> choice; 
    }
    
    return 0;
}