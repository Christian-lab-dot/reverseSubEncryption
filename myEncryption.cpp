#include <iostream>
#include <string> 
#include <cmath>

using namespace std;

const string vowels = "aeiouAEIOU"; 

int magicNum(string key)
{
    int num = 0;
    for (char c : key)
    {
        num += (int)(c);
    }
    return sqrt(num); 
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

int whereToMod(int i, int val)
{
    int sum = i + val;
    int r = sum;
    if (sum > 126)
    {
        r = 33 + (126-sum);
    }
    if (sum < 33)
    {
        r = 126 -  (sum - 33);
    }
    return r;
}

string encrypt(string s, string key)
{
    string eMsg = "";
    int val = magicNum(key); 
    for (char c : s)
    {
        int whereTo = whereToMod((int)c, val);
        if (!isVowel(c) && !(isVowel((char)(whereTo))))
        {
            if ((int)c+val > 126)
            {
                eMsg += (char)(33 +  whereTo);
            }
            else if ((int)c+val < 33)
            {
                eMsg += (char)(126 - whereTo);
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
    int val = magicNum(key); 
    string dMsg = "";
    for (char c : s)
    {   
        int whereTo = whereToMod((int)c, val);
        if (!isVowel(c) && !(isVowel((char)(whereTo))))
        {
            if ((int)c+val > 126)
            {
                dMsg += (char)(33 + whereTo);
            }
            else if ((int)c+val < 33)
            {
                dMsg += (33 - whereTo);
            }
            else
            {
                dMsg += (char)((int)c+val);
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
    string b = "PlRwRoPkwB|";
    cout << "decrypt: " << decrypt(b,"gg") << "\n";
    //cout << magicNum("this is the key");*/
    cout << magicNum("hoWdy");
    return 0;
}