#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

const int p[10] = {0, 2, 3, 5, 7, 11, 13, 17, 19, 23};
const ll oo = LLONG_MAX;
ll n, r;

void solve(int i, ll ans, int cnt) {
    if (cnt > n) return;
    if (cnt == n)
        r = min(r, ans);
    
    for (int j = 1; ; ++j) {
        if (ans * p[i] > r) break;
        ans *= p[i];
        if (ans < 0) break;
        solve(i + 1, ans, cnt*(j + 1));
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    
    int t;
    cin >> t;
    
    while (t--) {
        cin >> n;
        r = oo;
        solve(1, 1, 1);
        cout << r << endl;
    }
    
    return 0;
}
