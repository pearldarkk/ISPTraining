#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

int fstpos(vi& v, int n)
{
    int r = -1;
    set <int> m;

    for (int i = n - 1; i >= 0; --i)
    if (m.find(v[i]) == m.end())
        m.insert(v[i]);
    else r = i;

    return r;
}

void print(vi& v, int n)
{
    int fp = fstpos(v, n);
    if (fp >= 0)
        cout << v[fp] << "\n";
    else cout << "NO\n";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;

        int j;
        vi v;
        for (int i = 0; i < n; ++i)
        {
            cin >> j;
            v.push_back(j);
        }

        print(v, n);
    }

    return 0;
}