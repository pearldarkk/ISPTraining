#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int n, num;
ull ans;

void solve() {
    ll j;
    for (int i = 1;; ++i) {
        num = i; ans = 0; j = 1;
        while (num) {
            ans += (num % 2) * j;
            num >>= 1;
            j *= 10;
        }
        ans *= 9;
        if (ans % n == 0) {
            cout << ans << endl;
            break;
        }
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        solve();
    }

    return 0;
}
