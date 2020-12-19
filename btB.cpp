#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<ii> vii;

vector<string> v;
string kA;
int n, k, x, m = 0;

void kAgen()
{
    for (int i = 0; i < k; ++i)
        kA += 'A';
}

void gen(string s)
{
    if (s.size() == x)
    {
        string s1 = s;
        for (int i = 0; i <= x; ++i)
        {
            if (s[i - 1] != 'A' && s[i] != 'A')
            {
                s.insert(i, kA);
                v.push_back(s);
            }
            s = s1;
        }
    }
    else
    {
        if (m >= k - 1)
        {
            ++m;
            gen(s + 'A');
        }
        m = 0;
        gen(s + 'B');
    }
}

int main()
{
    cin >> n >> k;
    x = n - k;
    kAgen();
    gen("");
    cout << v.size() << endl;
    for (auto it = v.begin(); it != v.end(); ++it)
        cout << *it << endl;

    return 0;
}
