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

ll n, ans = LINF;
vll v;

void solve() {
    for (int i = 0; i < n; ++i) {
        vll tmp = v;
        ll change = 0;
        for (int j = 0; j < i; ++j) {
            tmp[j] += change;
            --change;
        }
        for (int j = i; j < n; ++j) {
            tmp[j] += change;
            ++change;
        }

        sort(tmp.begin(), tmp.end());
        ll itmp = max(max(tmp[n / 2], -change), 0LL);
        ll step = 0;
        for (int j = 0; j < i; ++j) {
            step += abs(itmp - v[j]);
            ++itmp;
        }
        for (int j = i; j < n; ++j) {
            step += abs(itmp - v[j]);
            --itmp;
        }
        ans = min(ans, step);
    }
    cout << ans;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    solve();

    return 0;
}