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
typedef vector<ll> vll;

ull gcd(ull a, ull b) { return b == 0 ? a : gcd(b, a % b); }

int div() {
    int n;
    ull r, x;
    cin >> n;
    r = 0;
    for (int i = 0; i < n; ++i) {
        cin >> x;
        r = gcd(r, x);
    }
    if (r < 2) return 1;
    ull cnt = 0;
    int y = sqrt(r);
    for (int i = 2; i <= y; ++i)
        if (r % i == 0)
            ++cnt;
    if (y * y == r)
        return 2 * cnt + 1;
    else
        return 2 * cnt + 2;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cout << div() << endl;

    return 0;
}