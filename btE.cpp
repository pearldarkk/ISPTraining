#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int n, k, sum = 0,
          a[15][15];

vi p(15);
vvi vv;

bool used[15]{};

void gen(int x)
{
    for (int i = 1; i <= n; ++i)
        if (!used[i])
        {
            p[x] = i;
            used[i] = 1;
            sum += a[x][i];
            if (x == n)
            {
                if (k == sum)
                    vv.push_back(p);
            }
            else
                gen(x + 1);
            used[i] = 0;
            sum -= a[x][i];
        }
}

void out()
{
    int x = vv.size();
    cout << x << endl;
    for (int i = 0; i < x; ++i)
    {
        for (int j = 1; j <= n; ++j)
            cout << vv[i][j] << " ";
        cout << endl;
    }
}

int main()
{
    cin >> n >> k;
    for (int i = 1; i <= n; ++i)
        for (int j = 1; j <= n; ++j)
            cin >> a[i][j];

    gen(1);
    out();

    return 0;
}
