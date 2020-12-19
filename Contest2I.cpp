#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

bitset <52> m;

void mark(string& s)
{
    int a[26];
    m.reset();
    set <int> mk;
    int j = 0;
    for (int i = 0; i < s.size(); ++i)
        if (mk.find(s[i]) != mk.end())
        {
            m[i] = 1;
            s[i] = a[s[i] - 65] + 48;
        }
        else 
        {
            mk.insert(s[i]);
            a[s[i] - 65] = j;
            s[i] = j++ + 48;
        }
}

int nd(string& s)
{
    mark(s);
    int r = 0;
    for (int i = 0; i < s.size(); ++i)
        if (m[i] == 0)
            for (int j = i + 1; s[j] != s[i]; ++j)
                if (s[j] > s[i])
                    if (m[j])
                        --r;
                    else 
                        ++r;
    return r;
}

int main()
{
    string s;
    cin >> s;
    cout << nd(s) << '\n';

    return 0;
}
