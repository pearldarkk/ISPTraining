#include <bits/stdc++.h>
using namespace std;

const long long MOD = 1000000007LL, INF = 1e9, LINF = 1e18;
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef vector<ll> vll;

void solve() {
    int n;
    cin >> n;
    int k = n / 7 * 7;
    while ((n - k) % 4 != 0) {
        k -= 7;
        if (k < 0) {
            cout << -1 << endl;
            return;
        }
    }

    int x = (n - k) / 4;
    k /= 7;
    for (int i = 0; i < x; ++i)
        cout << 4;
    for (int i = 0; i < k; ++i)
        cout << 7;
    cout << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
