#include <bits/stdc++.h>
using namespace std;

string gen(string& s1, string& s2, int n)
{
    string r;

    for (int i = 0; i < n; ++i)
    {
        r += s2[i];
        r += s1[i];
    }

    return r;
}

void part(string& s, string& s1, string& s2, int n)
{
    s1 = "";
    s2 = "";

    for (int i = 0; i < n; ++i)
    {
        s1 += s[i];
        s2 += s[i + n];
    }
}

int main()
{
    int n;

    while (scanf("%d\n", &n) != 0)
    {
        string s1, s2, s, temp;
        cin >> s1 >> s2 >> s;
        int cnt = 0;
        int check;
        
        string temp1 = s1;
        string temp2 = s2;
        while (1)
        {
            if (temp == s) 
            {
                check = 1;
                break;
            }
            if (temp == s1 + s2)
            {
                check = 0;
                break;
            }
            
            temp = gen(temp1, temp2, n);
            part(temp, temp1, temp2, n);
            ++cnt;
        }

        if (check) cout << cnt << "\n";
            else cout << "-1\n";
    }

    return 0;
}
