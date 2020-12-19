#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;
// res = m * (n + 1) * ..
//m: exp max of  N % 2^m == 0
//n, ...: prime divisors excluded 2

vpii m;

int pfact(int n)
{
    int r = 0;

    while (n % 2 == 0)
    {
        ++r;
        n >>= 1;
    }

    int j = -1;
    for (int i = 3; i * i <= n; i += 2)
        if (n % i == 0)
        {
            m.push_back({i, 1});
            ++j;
            while (n % i == 0)
            {
                ++m[i].second;
                n /= i;
            }
        }
    if (n > 1)
        m.push_back(make_pair(n, 1));

    return r;
}

int div(int n)
{
    int r = 1;
    r *= pfact(n);

    for (auto i = m.begin(); i != m.end(); ++i)
        r *= i -> second + 1;

    return r;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        cout << div(n) << "\n";
        m.clear();
    }

    return 0;
}
