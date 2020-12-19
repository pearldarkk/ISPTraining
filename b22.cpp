#include <bits/stdc++.h>
using namespace std;

typedef vector<int> vi;
vi v;
int n, k;

int bsearch(int l, int r, int k)
{
    if (r < l)
        return -1;
    int m = l + (r - l) / 2;
    if (v[m] == k)
        return m;
    if (v[m] > k)
        return bsearch(l, m - 1, k);
    return bsearch(m + 1, r, k);
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        cin >> n >> k;
        v.resize(n);
        for (int i = 0; i < n; ++i)
            cin >> v[i];
        int x = bsearch(0, n - 1, k);
        if (x < 0)
            cout << "NO" << endl;
        else
            cout << x + 1 << endl;
    }
}

