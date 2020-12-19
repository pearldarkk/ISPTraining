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

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    priority_queue<int, vi, greater<int>> q;
    int n, total = 0, a, b;
    cin >> n;
    for (int i = 0; i < n; ++i) {
        cin >> a;
        q.push(a);
    }

    while (!q.empty()) {
        a = q.top();
        q.pop();
        b = q.top();
        q.pop();
        total += (a + b) % MOD;
        if (!q.empty()) 
            q.push((a + b) % MOD);
    }

    cout << total << endl;

    return 0;
}
