#include <iostream>
#include <string> 
#include <cmath>

using namespace std;

const string vowels = "aeiouAEIOU"; 

//calculate sqrt of char values in key (before appending vowels)
int magicNum(string key)
{
    int num = 0;
    for (char c : key)
    {
        num += (int)(c);
    }
    return sqrt(num); 
}

bool isInKey(char c, string key)
{
    for (char k : key)
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
    key.append(vowels);
    for (char c : s)
    {
        int distUpperLim = 126 - (int)(c);
        int distLowerLim = (int)(c) - 33;
        if (isInKey(c, key))
        {
            if ((int)c+val > 126)
            {
                eMsg += (char)(33+distUpperLim);
            }
            else if ((int)c+val < 33)
            {
                eMsg += (126 - distLowerLim);
            }
            else
            {
                eMsg += (char)((int)c+val);
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
    key.append(vowels); 
    string dMsg = "";
    for (char c : s)
    {
        int distUpperLim = 126 - (int)(c);
        int distLowerLim = (int)(c) - 33;
        int ch = (int)(c);
        int cVal = (int)(c) + val; 
        if (cVal > 126)
        {
            cVal = 33 + distUpperLim;
        }
        if (cVal < 33)
        {
            cVal = 126 - distLowerLim;
        }
        if (isInKey((char)cVal, key))
        {
            dMsg += (char)cVal; 
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
    string a = encrypt("christian nguyen", "ngc");
    cout << "encrypted: " << a << "\n";  
    string b = decrypt("thrzstzr1 1x*yv1", "ngc");
    cout << "decrypted: " << b; 
    return 0;
}