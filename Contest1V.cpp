#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

int bs(vi& v, int l, int r, int n)
{
    if (r >= l)
    {
        int mid = (r - l)/2 + l;

        if (v[mid] == n)
            return mid;
        
        if (v[mid] > n)
            return bs(v, l, mid - 1, n);
        return bs(v, mid + 1, r, n);
    }

    return -1;
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n, k;
        cin >> n >> k;
        scanf("\n");
        int j;
        vi v;
        for (int i = 0; i != n; ++i)
        {
            cin >> j;
            v.push_back(j);
        }

        int x = bs(v, 0, n - 1,  k);
        if (x >= 0) 
            cout << x + 1;
        else cout << "NO"; 
        cout << "\n";
    }

    return 0;
}