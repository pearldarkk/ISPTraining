#define M 123456789

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

ull n;

int count() {
    if (n == 1) return 1;
    --n;
    int r = 1, t = 2;
    while (n) {
        if (n & 1)
            r = (1ll * r * t) % M;
        t = (t * 1ll * t) % M;
        n >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
    cin >> n;
    cout << count() << endl;
    }

    return 0;
}
