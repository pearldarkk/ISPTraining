#define M 1000000007

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

    for (int id = 1; id <= t; ++id)
    {
        int n, m;
        cin >> n >> m;
        printf("Test %d:\n", id);

        int a[100][100];
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < m; ++j)
                cin >> a[i][j];

        int p[100][100];
        memset(p, 0, sizeof(p));
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                for (int k = 0; k < m; ++k)
                    p[i][j] += a[i][k] * a[j][k];

        for (int i = 0; i < n; ++i)
            {
                for (int j = 0; j < n; ++j)
                cout << p[i][j] << ' ';
                cout << endl;
            }
    }

    return 0;
}
