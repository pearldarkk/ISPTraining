#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

ull k, len;
int i;

void init() {
    cin >> k >> k;
    --k;
    i = 1, len = 0;
    while (k >= len) {
        ++i;
        len = len * 2 + 1;
    }
}

int find(ull k) {
    --i, len >>= 1;
    if (k == len) return i;
    if (k > len) return find(2*len - k);
    return find(k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        init();
        cout << find(k) << endl;
    }
    return 0;
}
