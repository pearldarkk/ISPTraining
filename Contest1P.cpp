#include <bits/stdc++.h>
using namespace std;

typedef vector <string> vs;

char lowc(char c)
{
    if (c >= 65 && c <= 90) 
        return c + 32;
    return c;
}

string mail(const string& s)
{
    string mail;

    int p = s.length() - 1;
    while (s[p] == 32) --p;
    for (; s[p] != 32; --p)
        mail =  lowc(s[p]) + mail;
    
    for (int i = 0; i < p; ++i)
    if (s[i] != 32)
        if (i == 0 || s[i - 1] == 32)
            mail += lowc(s[i]);

    return mail;
}

void print(vs& em, int p)
{
    cout << em[p];
    
    int cnt = 0;
    for (int i = 0; i < p; ++i)
    if (em[p] == em[i]) 
        ++cnt;
    if (cnt != 0) 
        cout << cnt;

    cout << "@ptit.edu.vn\n";
}

int main()
{
    int n;
    scanf("%d\n", &n);

    string s;
    vs em;
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        em.push_back(mail(s));
        print(em, i);
    }

    return 0;
}
