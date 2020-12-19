#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define Pn printf("\n")

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

void inp(vpii &v, int n)
{
    int a, b;
    for (int i = 0; i != n; ++i)
    {
        cin >> a >> b;
        v.push_back(make_pair(a, b));
    }
}

bool secSort(pii& a, pii& b)
{
    return (a.second < b.second);
}

int cnt(vpii& v)
{
    int r = 0;
    sort(v.begin(), v.end(), secSort);

    int t = 0;
    for (size_t i = 0; i < v.size(); ++i)
        if (t <= v[i].first)
        {
            ++r;
            t = v[i].second;
        }
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
        vpii v;
        inp(v, n);
        cout << cnt(v);
        Pn;
    }

    return 0;
}
