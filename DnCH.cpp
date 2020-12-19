#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

vi v;
int n, cnt;
bitset<100001> used;

int find(int l, int r, int k) {
    int mid;
    while (l < r) {
        mid = (r-l)/2+l;
        if (v[mid] <= k)
            l = mid+1;
        else
            r = mid;
    }
    --r;
    while (used[r] && r >= 0) --r;
    return r;
}

void solve() {
    used.reset();
    cin >> n;
    v.resize(n);
    for (int i = 0; i < n; ++i)
        cin >> v[i];
    cnt = 0;
    sort(v.begin(), v.end());

    int k;
    for (int i = n - 1; i >= 0; --i) {
        if (!used[i]) {
            k = find(0, i - 1, v[i]/2);
            if (k < 0)
                break;
            else {
            ++cnt;
                used[k] = 1;
            }
        }
    }

    cout << n - cnt << endl;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--)
        solve();

    return 0;
}
