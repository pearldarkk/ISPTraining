#include <bits/stdc++.h>
using namespace std;

typedef long long ll;

ll gcd(ll a, ll b);
ll lcm(ll a, ll b);

int main()
{
    int t;
    scanf("%d", &t);

    ll a, b;
    while (t--)
    {
        cin >> a >> b;
        cout << gcd(a, b) << ' ' << lcm(a, b) << endl;
    }

    return 0;
}

ll gcd(ll a, ll b)
{
    ll r;
    while (b)
    {
        r = b;
        b = a % b;
        a = r;
    }
    return a;
}

ll lcm(ll a, ll b)
{
    return abs(a * b) / gcd(a, b);
}
