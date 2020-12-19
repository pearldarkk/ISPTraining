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
#define fill(a, x) fill(a.begin(), a.end(), 0)
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

int n, k, r, N;
vi p, f;

int pwr(int base, int exp, int m)
{
    int r = 1;
    base = base % m;

    while (exp)
    {
        if (exp & 1)
            r = (r * base) % m;
        exp = exp >> 1;
        base = (base * base) % m;
    }

    return r;
}

void sieve() {
    int n = 1000;
    bitset<1000> m;
    p.pb(2);
    for (int i = 3; i * i <= n; i += 2)
        if (!m[i])
            if (i * 1ll * i <= n)
                for (int j = i * i; j <= n; j += i)
                    m[j] = 1;
    for (int i = 3; i <= n; i += 2)
        if (!m[i])
            p.pb(i);
    N = p.size();
    f.resize(N);
}

void cal() {
    fill(f, 0);
    int x;
    for (int i = n - k + 1; i <= n; ++i) {
        x = i;
        for (int j = 0; x!= 1; ++j)
            while (x % p[j] == 0) {
                ++f[j];
                x /= p[j];
            }
    }
    //divide
    for (int i = 2; i <= k; ++i) {
        x = i;
        for (int j = 0; x != 1; ++j)
            while (x % p[j] == 0) {
                --f[j];
                x /= p[j];
            }
    }

    r = 1;
    for (int i = 0; i < N; ++i)
        if (f[i])
            r *= pwr(p[i], f[i], MOD) % MOD;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    sieve();
    int t;
    cin >> t;
    while (t--) {
        cin >> n >> k;
        cal();
        cout << r << endl;
    }
    return 0;
}