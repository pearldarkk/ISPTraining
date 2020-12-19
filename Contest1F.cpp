#define MAX 32000
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

void sieve(vi& prime)
{
    bitset <32001> m;
    m.set();
    m[0] = 0;
    m[1] = 0;

    prime.push_back(2);
    for (int i = 3; i <= MAX; i += 2)
        if (m[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= MAX; j += i)
                m[j] = 0;
        }
}

void pf(const vi &prime, ll n)
{
    int pi = 0, cnt;
    int cp = prime[pi];

    while (cp * cp <= n)
    {
        cnt = 0;
        while (n % cp == 0)
        {
            ++cnt;
            n /= cp;
        }
        if (cnt != 0) cout <<' ' << cp << '(' << cnt << ") ";
        cp = prime[++pi];
    }

    if (n != 1) cout << ' ' << n << "(1)";
}

int main()
{
    int t;
    cin >> t;

    vi prime;
    sieve(prime);

    ll n;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n;
        printf("Test %d:", i);
        pf(prime, n);
        cout << endl;
    }

    return 0;
}
