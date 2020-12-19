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
    int n;
    cin >> n;

    int a[205][205];
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            cin >> a[i][j];

    int k;
    cin >> k;
    pii del[k];
    int r, c;
    for (int i = 0; i < k; ++i)
    {
        cin >> r >> c;
        del[i] = make_pair(r, c);
    }


    int c1, c2;
    pii rm[205];
    for (int i = 0; i < k; ++i)
    {
        c1 = c2 = 0;
        for (int j = 0; j < i; ++j)
        {
            if (del[i].first >= del[j].first) ++c1;
            if (del[i].second >= del[j].second) ++c2;
        }
        rm[i] = make_pair(del[i].first + c1, del[i].second + c2);
    }

    for (int i = 0; i < n; ++i)
    {
        a[i][n] = 1;
        a[n][i] = 1;
    }

    for (int i = 0; i < k; ++i)
    {
        a[rm[i].first][n] = 0;
        a[n][rm[i].second] = 0;
    }

    for (int i = 0; i < n; ++i)
        if (a[i][n])
            {
                for (int j = 0; j < n; ++j)
                    if (a[n][j])
                        printf("%d ", a[i][j]);
                Pn;
            }

    return 0;
}
