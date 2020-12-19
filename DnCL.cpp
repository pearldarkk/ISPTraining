#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
const int M = 1000000007;

ull opr[3];  //a b c in range
ull f[5];

inline ull sqr(ull x) { return x * x; }

ull pwr(ull base, ll exp) {
    ull r = 1;
    base %= M;
    while (exp) {
        if (exp & 1)
            r = (r * base) % M;
        base = (base * base) % M;
        exp >>= 1;
    }
    return r;
}

void find() {
    ull prd, s, tmp;
    double delta, s1;
    for (opr[0] = 0;; ++opr[0]) {
        //bc
        tmp = ((sqr(f[2] - sqr(opr[0]))) - (f[4] - sqr(sqr(opr[0])))) / 2;
        prd = sqrt(tmp);
        if (prd * prd != tmp) continue;
        //opr[2] + opr[1]
        tmp = (f[2] - sqr(opr[0])) + 2 * prd;
        s = sqrt(tmp);
        if (s * s != tmp) continue;
        //Giải opr[2] opr[1]
        s1 = (float)s / 2;
        delta = s1 * s1 - prd;
        delta = sqrt(delta);
        opr[2] = s1 - delta;
        opr[1] = s1 + delta;
        if (sqr(opr[2]) * opr[2] + sqr(opr[1]) * opr[1] + sqr(opr[0]) * opr[0] == f[3]) break;
    }
}

void solve() {
    ll l, r;
    for (int i = 2; i < 5; ++i)
        cin >> f[i];
    cin >> l >> r;
    memset(opr, 0, sizeof opr);
    //Tìm opr[2] opr[1] opr[0]
    find();
    //S = Sr - Sl
    ull S = 0;  //sum from 1 to l-1 and sum from 1 to r
    for (int i = 0; i < 3; ++i)
        if (opr[i] == 0)
            continue;
        else if (opr[i] == 1)
            S += (r - l + 1);
        else
            S += ((pwr(opr[i], r + 1) - pwr(opr[i], l) + M) % M * pwr(opr[i] - 1, M - 2) % M);
    cout << S % M << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        solve();
    }

    return 0;
}