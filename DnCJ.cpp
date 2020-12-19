#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

ull fib(int n) {
    ull f[2][2] = {{1, 1}, {1, 0}}, r[2][2] = {{1, 0}, {0, 1}}, tmp[2][2] = {{0, 0}, {0, 0}};
    int i, j, k;
    if (n == -1) return 0;
    if (n == 0 || n == 1) return 1;
    while (n) {
        if (n & 1) {
            memset(tmp, 0, sizeof tmp);
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++)
                    for (k = 0; k < 2; k++)
                        tmp[i][j] += (r[i][k] * f[k][j]) % M;
            for (i = 0; i < 2; i++)
                for (j = 0; j < 2; j++) r[i][j] = tmp[i][j] % M;
        }
        memset(tmp, 0, sizeof tmp);
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++)
                for (k = 0; k < 2; k++)
                    tmp[i][j] += (f[i][k] * f[k][j]) % M;
        for (i = 0; i < 2; i++)
            for (j = 0; j < 2; j++) f[i][j] = tmp[i][j] % M;
        n = n >> 1;
    }
    return r[0][0];
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t, n;
    cin >> t;
    while (t--) {
        cin >> n;
        cout << fib(n - 1) << endl;
    }
    return 0;
}
