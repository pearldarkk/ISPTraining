#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

ull n, x;
string s;

void init() {
    cin >> s >> n;
    --n;
    x = s.size();
    while (n >= x) x <<= 1;
}

int search(ull k) {
    x >>= 1;
    if (k < s.size()) return k;
    if (k > x) return search(k - x - 1);
    if (k == x) return search(k - 1);
    return search(k);
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    init();
    int k = search(n);
    cout << s[k] << endl;
    return 0;
}
