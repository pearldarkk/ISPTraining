#include <bits/stdc++.h>
using namespace std;

bool palind(long long a[], int n)
{
    int r = true;

    for (int i = 0; i < n/2; ++i)
        if (a[i] != a[n - i - 1])
        {
            r = false;
            break;
        }

    return r;
}

int main()
{
    int t;
    cin >> t;

    int n;
    long long a[105];
    while (t--)
    {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> a[i];
        if (palind(a, n))
            cout << "YES" << endl;
        else cout << "NO" << endl;
    }

    return 0;
}
