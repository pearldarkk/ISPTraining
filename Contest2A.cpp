#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        int n, m, p, x;
        cin >> n >> m >> p;
        vi a;
        for (int i = 0; i != n; ++i)
        {
            cin >> x;
            a.push_back(x);
        }

        vi b;
        for (int i = 0; i != m; ++i)
        {
            cin >> x;
            b.push_back(x);
        }

        vi :: iterator i = a.begin();
        advance(i, p);
        copy(b.begin(), b.end(), inserter(a, i));

        for (auto i = a.begin(); i != a.end(); ++i)
            cout << *i << " ";
        Pn;
    }

    return 0;
}
