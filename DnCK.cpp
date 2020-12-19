#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<vector<ull>> vvull;
typedef vector<ii> vii;

ull a[10][10];
int n, m;

void solve() {
    ull r[n][n], tmp[n][n];
    memset(r, 0, sizeof r);
    int i, j, k;
    for (i = 0; i < n; ++i)
        r[i][i] = 1;
    while (m) {
        if (m & 1) {
            memset(tmp, 0, sizeof tmp);
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++)
                    for (k = 0; k < n; k++)
                        tmp[i][j] += (r[i][k] * a[k][j]) % M;
            for (i = 0; i < n; i++)
                for (j = 0; j < n; j++) r[i][j] = tmp[i][j] % M;
        }
        memset(tmp, 0, sizeof tmp);
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++)
                for (k = 0; k < n; k++)
                    tmp[i][j] += (a[i][k] * a[k][j]) % M;
        for (i = 0; i < n; i++)
            for (j = 0; j < n; j++) a[i][j] = tmp[i][j] % M;
        m >>= 1;
    }
    for (int i = 0; i < n; ++i) {
        for (int j = 0; j < n; ++j)
            cout << r[i][j] << ' ';
        cout << endl;
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> n >> m;
        for (int i = 0; i < n; ++i)
            for (int j = 0; j < n; ++j)
                cin >> a[i][j];
        solve();
    }
    return 0;
}
