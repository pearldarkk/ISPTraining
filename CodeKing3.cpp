#include <algorithm>
#include <bitset>
#include <cassert>
#include <cmath>
#include <cstdio>
#include <cstring>
#include <deque>
#include <functional>
#include <iomanip>
#include <iostream>
#include <map>
#include <queue>
#include <set>
#include <sstream>
#include <string>
#include <vector>
using namespace std;

#define EL printf("\n")
#define Fill(a, x) memset(a, x, sizeof a)
#define fill(a, x) fill(a.begin(), a.end(), x)
#define sort(v) sort(v.begin(), v.end())
#define sortd(v) sort(v.begin(), v.end(), greater<int>())
#define pb push_back
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define ld long double
#define ll long long
#define ull unsigned long long
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;

int a;
ll b;

void solve() {
    int d, h, difmax = -1, dmax = -1;
    for (int i = 0; i < a; ++i) {
        cin >> d >> h;
        if (d - h > difmax) difmax = d - h;
        if (d > dmax) dmax = d;
    }
    if (dmax >= b) { cout << 1 << endl; return; }
    if (difmax <= 0) { cout << "MISSION FAILED!" << endl; return; }
    d = 1;
    while (b - difmax > dmax) {
        b -= difmax;
        ++d;
    }
    cout << d + 1 << endl;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    cin >> t;
    while (t--) {
        cin >> a >> b;
        solve();
    }
    return 0;
}