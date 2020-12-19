#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int n, k, s, cnt, curs,
    ss[15];

void gen(int x)
{
    for (int i = ss[x - 1] + 1; curs < s && i <= n; ++i)
    {
        ss[x] = i;
        curs += i;
        if (x == k)
        {
            if (curs == s)
                ++cnt;
        }
        else
            gen(x + 1);
        curs -= i;
    }
}

int main()
{
    while (cin >> n >> k >> s)
    {
        cnt = 0, curs = 0, cnt = 0;
        ss[0] = 0;
        gen(1);
        cout << cnt << endl;
    }

    return 0;
}
