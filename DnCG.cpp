#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

ull pos[51];

int find(int k, ull l, ull r, ull n) {
    if (l == r && l == 1) return 1;
    if (l > pos[k - 1]) return find(k - 1, l - pos[k - 1], r - pos[k - 1], n / 2);
    if (r < pos[k - 1]) return find(k - 1, l, r, n / 2);
    if (l == pos[k - 1]) return find(k - 1, 1, r - pos[k - 1], n / 2) + (n & 1);
    if (r == pos[k - 1]) return find(k - 1, l, r - 1, n / 2) + (n & 1);
    return find(k - 1, l, pos[k - 1] - 1, n / 2) + find(k - 1, 1, r - pos[k - 1], n / 2) + (n & 1);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    pos[0] = 1;
    for (int i = 1; i <= 50; ++i)
        pos[i] = pos[i - 1] * 2;
    int t;
    cin >> t;
    while (t--) {
        ull n, l, r;
        cin >> n >> l >> r;
        int k = 0;
        while (n >= pos[k]) ++k;
        cout << find(k, l, r, n) << endl;
    }

    return 0;
}
