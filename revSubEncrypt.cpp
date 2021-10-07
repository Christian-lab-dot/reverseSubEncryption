#include <iostream>
#include <algorithm>
#include <string> 
#include <cmath>
#include <map> 

using namespace std; 

//encrypt via atbash
string atbash(string plain)
{
    map<char, char> m;

    m.insert(pair<char, char> ('A', 'Z'));
    m.insert(pair<char, char> ('B', 'Y'));
    m.insert(pair<char, char> ('C', 'X'));
    m.insert(pair<char, char> ('D', 'W'));
    m.insert(pair<char, char> ('E', 'V'));
    m.insert(pair<char, char> ('F', 'U'));
    m.insert(pair<char, char> ('G', 'T'));
    m.insert(pair<char, char> ('H', 'S'));
    m.insert(pair<char, char> ('I', 'R'));
    m.insert(pair<char, char> ('J', 'Q'));
    m.insert(pair<char, char> ('K', 'P'));
    m.insert(pair<char, char> ('L', 'O'));
    m.insert(pair<char, char> ('M', 'N'));
    m.insert(pair<char, char> ('N', 'M'));
    m.insert(pair<char, char> ('O', 'L'));
    m.insert(pair<char, char> ('P', 'K'));
    m.insert(pair<char, char> ('Q', 'J'));
    m.insert(pair<char, char> ('R', 'I'));
    m.insert(pair<char, char> ('S', 'H'));
    m.insert(pair<char, char> ('T', 'G'));
    m.insert(pair<char, char> ('U', 'F'));
    m.insert(pair<char, char> ('V', 'E'));
    m.insert(pair<char, char> ('W', 'D'));
    m.insert(pair<char, char> ('X', 'C'));
    m.insert(pair<char, char> ('Y', 'B'));
    m.insert(pair<char, char> ('Z', 'A'));
    m.insert(pair<char, char> ('a', 'z'));
    m.insert(pair<char, char> ('b', 'y'));
    m.insert(pair<char, char> ('c', 'x'));
    m.insert(pair<char, char> ('d', 'w'));
    m.insert(pair<char, char> ('e', 'v'));
    m.insert(pair<char, char> ('f', 'u'));
    m.insert(pair<char, char> ('g', 't'));
    m.insert(pair<char, char> ('h', 's'));
    m.insert(pair<char, char> ('i', 'r'));
    m.insert(pair<char, char> ('j', 'q'));
    m.insert(pair<char, char> ('k', 'p'));
    m.insert(pair<char, char> ('l', 'o'));
    m.insert(pair<char, char> ('m', 'n'));
    m.insert(pair<char, char> ('n', 'm'));
    m.insert(pair<char, char> ('o', 'l'));
    m.insert(pair<char, char> ('p', 'k'));
    m.insert(pair<char, char> ('q', 'j'));
    m.insert(pair<char, char> ('r', 'i'));
    m.insert(pair<char, char> ('s', 'h'));
    m.insert(pair<char, char> ('t', 'g'));
    m.insert(pair<char, char> ('u', 'f'));
    m.insert(pair<char, char> ('v', 'e'));
    m.insert(pair<char, char> ('w', 'd'));
    m.insert(pair<char, char> ('x', 'c'));
    m.insert(pair<char, char> ('y', 'b'));
    m.insert(pair<char, char> ('z', 'a'));

    string encrypt = "";
    for (char c : plain)
    {
        if(isalpha(c))
        {
            std::map<char,char>::iterator it = m.find(c);
            encrypt += it->second; 
        }
        else
        {
            encrypt += c; 
        }
    }
    return encrypt; 
}

//encrypt using caesar cipher, then reverse
string encrypt(string s, int key)
{
    //shift elements of s based on key
    string str = "";
    if (key > 26 || key < -26)
    {
        key = key % 26; 
    } 
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

    return atbash(revStr);
}

string decrypt(string s, int key)
{
    string decrypt = encrypt(s, key);
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

