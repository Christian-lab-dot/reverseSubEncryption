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
        if (isInKey(c, key))
        {
            if ((int)c+val > 126)
            {
                
            }
            eMsg += (char)((int)c+val);
        }
        else
        {
            eMsg += c;
        }
    }
    return eMsg;
}

void decrypt(string s, string key)
{

}

int main()
{
    /*string a = "";
    cin >> a;
    string b = a.substr(0,3);
    b.append(vowels);
    cout << b;*/ 
    //cout << magicNum("abc");
    string a = encrypt("encrypt me!", "cpt");
    cout << a; 
    return 0;
}