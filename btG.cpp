#define M 1000000007
const int n = 8;  

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int s, maxs,
    b[10][10];

bool q[10][10];

bool safe(int r, int c)
{
    int i, j;
    for (i = 0; i < c; ++i)
        if (q[r][i])
            return false;

    for (i = r, j = c; i >= 0 && j >= 0; --i, --j)
        if (q[i][j])
            return false;

    for (i = r, j = c; i < n && j >= 0; ++i, --j)
        if (q[i][j])
            return false;

    return true;
}

bool queen(int c)
{
    if (c == n)
    {
        if (s > maxs)
            maxs = s;
        return true;
    }

    bool res = 0;
    for (int i = 0; i < n; ++i)
    {
        if (safe(i, c))
        {
            s += b[i][c];
            q[i][c] = 1;
            res = queen(c + 1) || res;
            s -= b[i][c];
            q[i][c] = 0;
        }
    }

    return res;
}

void sol()
{
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            q[i][j] = 0;

    if (queen(0) == false)
        return;

    return;
}

int main()
{
    int t;
    cin >> t;
    while (t--)
    {
        s = maxs = 0;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> b[i][j];

        sol();

        cout << maxs << endl;
    }

    return 0;
}
