#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int n, s, cnt, currS, m = 30,
    t[35];

void Try(int x) {
    if (x == n) return;

    for (int i = 0; i <= 1; ++i) {
        currS += t[x] * i;
        cnt += i;
        if (s == currS) {
            if (m > cnt)
                m = cnt;
        }
        Try(x + 1);
        currS -= t[x] * i;
        cnt -= i;
    }
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    cin >> n >> s;
    for (int i = 0; i < n; ++i)
        cin >> t[i];

    Try(0);
    cout << m << endl;

    return 0;
}
