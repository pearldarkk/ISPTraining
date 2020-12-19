#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int pwr(int base, int exp) {
    int r = 1;
    while (exp) {
        if (exp & 1)
            r = r * base % M;
        base = base * base % M;
        exp >>= 1;
    }
    return r;
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    ll n;
    cin >> n;
    cout << pwr(3, n - 1) << endl;

    return 0;
}
