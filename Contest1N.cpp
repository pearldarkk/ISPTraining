#include <bits/stdc++.h>
using namespace std;

string spacerm(string& s)
{
    string r;
    size_t p = 0;

    while (p < s.size())
    {
        while (s[p] != 32 && p < s.size())
        {
            r += s[p];
            ++p;
        }
        while (s[p] == 32 && p < s.size())
            ++p;
        r += 32;
    }

    return r;
}

inline void upcase(string &s, int p)
{
    if (s[p] >= 97 && s[p] <= 122) s[p] -= 32;
}

inline void lowcase(string& s, int p)
{
    if (s[p] >= 65 && s[p] <= 90) s[p] += 32;
}

void normalize(string& s)
{
    s = spacerm(s);
    
    size_t i = 0;
    while (i < s.size())
    {
        if (i==0 || s[i - 1] == 32) 
            upcase(s, i);
        else
            lowcase(s, i);
        ++i;
    }
}

int main()
{
    int t;
    scanf("%d\n", &t);

    string s;
    while (t--)
    {
        getline(cin, s);
        normalize(s);
        cout << s << '\n';
    }

    return 0;
}
