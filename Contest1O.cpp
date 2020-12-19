#include <bits/stdc++.h>
using namespace std;

string spacerm(string& s)
{
    string r;
    size_t p = 0;

    while (p < s.size())
    {
        r += 32;
        while (s[p] != 32 && p < s.size())
        {
            r += s[p];
            ++p;
        }
        while (s[p] == 32 && p < s.size())
            ++p;
    }

    return r;
}

inline char upc(char c)
{
    if (c >= 97 && c <= 122)
        return c - 32;
    return c;
}

inline char lowc(char c)
{
    if (c >= 65 && c <= 90)
        return c + 32;
    return c;
}

string nrm(string& s)
{
    s = spacerm(s);

    size_t p = 0;
    while (s[++p] != 32);

    string r;
    for (size_t i = p + 1; i < s.size(); ++i)
        if (s[i - 1] == 32)
            r += upc(s[i]);
        else
            r += lowc(s[i]);

    r += ',';

    for (size_t i = 0; i < p; ++i)
    r += upc(s[i]);
    while (r[r.size() - 1] == 32)
        r[r.size() - 1] = '\0';
    return r;
}

int main()
{
    int t;
    cin >> t;

    string s;
    getline(cin, s);

    while (t--)
    {
        getline(cin, s);
        cout << nrm(s) << "\n";
    }

    return 0;
}
