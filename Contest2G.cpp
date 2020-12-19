#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

int dec(char& c)
{
    switch (c)
    {
        case 'I': 
            return 1;
        case 'V': 
            return 5;
        case 'X': 
            return 10;
        case 'L': 
            return 50;
        case 'C': 
            return 100;
        case 'D': 
            return 500;
        case 'M': 
            return 1000;
        
        default:
            return 0;
    }
}

int decRom(string& s)
{
    int r = 0;
    int i = 0;
    while (s[i])
    {
        if (dec(s[i]) >= dec(s[i + 1]))
            r += dec(s[i]);
        else 
        {
            r += dec(s[i + 1]) - dec(s[i]);
            ++i;
        }
        ++i;
    }
    return r;
}

int main()
{
    int t;
    cin >> t;    
    string s;
    while (t--)
    {
        cin >> s;
        cout << decRom(s);
        Pn;
    }

    return 0;
}
