#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> pii;
typedef vector<int> vi;
typedef vector<pii> vpii;

inline int mx(int a, int b) { return a > b ? a : b; }

inline int m(int a, int b) { return a < b ? a : b; }

inline pii swp(pii& p) {
    pii r;
    r.first = p.second;
    r.second = p.first;
    return r;
}

bool mxs(pii& a, pii& b) {
    if (mx(a.first, a.second) == mx(b.first, b.second))
        return (m(a.first, a.second) > m(b.first, b.second));
    return (mx(a.first, a.second) > mx(b.first, b.second));
}

bool check(vpii& v) {
    sort(v.begin(), v.end(), mxs);
    int max = mx(v[0].first, v[0].second);
    pii p = {max, max};
    bool c;
    for (int i = 0; i < 2; ++i) {
        c = 0;
        if (p.second == v[i].second) {
            p = swp(p);
            v[i] = swp(v[i]);
        }
        if (p.first == v[i].second) v[i] = swp(v[i]);
        if (p.second == v[i].first) p = swp(p);
        if (p.first == v[i].first) {
            p.second -= v[i].second;
            c = 1;
        }
        if (c == 0) return 0;
    }
    if (p == v[2] || p == swp(v[2])) return 1;
    return 0;
}

int main() {
    vpii v;
    int x, y;
    for (int i = 0; i < 3; ++i) {
        cin >> x >> y;
        v.push_back({x, y});
    }
    if (check(v))
        cout << "YES";
    else
        cout << "NO";

    return 0;
}
