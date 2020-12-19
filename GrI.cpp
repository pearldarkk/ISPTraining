#include <algorithm>
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

#define For(i, a, b) for (i64 i = a; i < b; ++i)
#define FOR(i, a, b) for (i64 i = a; i <= b; ++i)
#define iFor(i, a, b) for (i64 i = a; i >= b; --i)
#define pb push_back
#define mt make_tuple
#define fi first
#define se second
#define MOD 1000000007LL
#define INF 1e9
#define LINF 1e18
#define ld long double
#define i64 long long
#define i64_t unsigned long long
typedef pair<i64, i64> ii;
typedef vector<i64> vi;
typedef vector<vector<i64>> vvi;
typedef vector<ii> vii;
typedef vector<string> vs;
typedef tuple<i64, i64> tii;
typedef tuple<i64, i64, i64> tiii;

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    int t;
    int n;
    vi v;
    cin >> t;
    while (t--) {
        cin >> n;
        v.resize(n);
        For(i, 0, n)
            cin >> v[i];
        
        bool check = 0; 
        sort(v.begin(), v.end());
        iFor(i, n - 1, 2)
            if (v[i] < v[i - 1] + v[i - 2]) {
                check = 1;
                cout << "YES" << endl;
                break;
            }
        if (!check) 
            cout << "NO" << endl;
    }
    
    return 0;
}