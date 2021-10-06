#include <iostream>
#include <algorithm>
#include <string> 
#include <cmath>

using namespace std; 

//encrypt using caesar cipher, then reverse
string encrypt(string s, int key)
{
    //shift elements of s based on key
    string str = "";
    if (key > 26 || key < -26)
    {
        key = key % 26; 
    }
    key = key * -1;
    for (char c : s)
    {
        if (isalpha(c))
        {
            int upperZDist = 90 - (int)(c);
            int upperADist = (int)(c) - 65;
            int lowerZDist = 122 - (int)(c);
            int lowerADist = (int)(c) - 97; 
            //for capital letters
            if (isupper(c))
            {
                if ((int)(c) + key > 90)
                {
                    str += (char)(64 + (key - upperZDist));
                }
                else if ((int)(c) + key < 65)
                {
                    str += (char)(91 + (key + upperADist));
                }
                else
                {
                    str += char(key + (int)(c));
                }
            }
            //for lower letters
            if (islower(c))
            {
                if ((int)(c) + key > 122)
                {
                    str += char(96 + (key - lowerZDist));
                }
                else if ((int)(c) + key < 97)
                {
                    str += char(123 + (key + lowerADist));
                }
                else
                {
                    str += (key + (int)(c));
                }
            }
        }
        else
        {
            str += c;
        }
    }
    //reverse string before returning 
    string revStr = "";
    for(int i = str.length()-1; i >= 0; --i)
    {
        revStr += str[i];
    }
    return revStr;
}

string decrypt(string s, int key)
{
    string decrypt = encrypt(s, -key);
    return decrypt;
}

int main()
{
    int c;
    string str;
    int key;
    cout << "what do you want to do?\n" << "1:encrypt\n" << "2:decrypt\n";
    cin >> c;
    cin.ignore();
    if (c == 1)
    {
        cout << "message to be encrypted: ";
        getline(cin, str);
        cout << "key (numeric value): ";
        cin >> key;
        cout << encrypt(str, key); 
    }
    if (c == 2)
    {
        cout << "message to be decrypted: ";
        getline(cin, str);
        cout << "key (numeric value): ";
        cin >> key;
        cout << decrypt(str, key);
    }
    return 0;
}

