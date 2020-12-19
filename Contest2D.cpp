#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;

inline int max(int a, int b)
{
    return a > b ? a : b;
}

void subs(int *a, int n)
{
    if (n == 1)
    {
        cout << a[0] << '\n';
        return;
    }

    int s = a[0];
    int r = a[0];
    int l = 0;
    for (int i = 1; i < n; ++i)
    {
        while (s <= 0 && l < i)
            s -= a[l++];
        s += a[i];
        r = max(r, s);
    }

    cout << r << "\n";
}

int main()
{
    int t;
    cin >> t;
    int n, a[100005];
    while (t--)
    {
        cin >> n;
        for (int i = 0; i != n; ++i)
            cin >> a[i];
        subs(a, n);
    }

    return 0;
}
