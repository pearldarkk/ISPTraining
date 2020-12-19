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

const int N = 100001;
vi p, v, cnt;
int n;

void sieve() {
    p.resize(N);
    for (int i = 2; i * i < N; ++i)
        if (!p[i])
            if (i * 1ll * i < N)
                for (int j = i; j < N; j += i)
                    p[j] = i;

    for (int i = 1; i < N; ++i)
        if (!p[i])
            p[i] = i;
}

int solve() {
    cnt.resize(N);
    int r = 1, x;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        while (x > 1) {
            int div = p[x];
            while (x % div == 0)
                x /= div;
            r = max(r, ++cnt[div]);
        }
    }
    return r;
}

int main() {
    //freopen("text.inp", "r", stdin);
    //freopen("text.out", "w", stdout);
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    cin >> n;
    cout << solve() << endl;

    return 0;
}