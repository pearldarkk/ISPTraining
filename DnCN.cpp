#define M 1000000007

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;

int cnt, n;

void out(string s) {
    for (int i = 0; i < n - 1; ++i)
        if (s[i] == '1')
            if (s[i] == s[i + 1]) {
                cout << s << endl;
                ++cnt;
                return;
            }
    for (int i = 1; i <= n / 3; ++i)
        for (int j = 0; j <= n - 3 * i; ++j) {
            string s1 = s.substr(j, i);
            string s2 = s.substr(j + i, i);
            string s3 = s.substr(j + 2 * i, i);
            if (s1 == s2 && s2 == s3) {
                cout << s << endl;
                ++cnt;
                return;
            }
        }
}

void bt(string s) {
    if (s.size() == n)
        out(s);
    else {
        bt(s + '0');
        bt(s + '1');
    }
}

int main() {
    ios_base::sync_with_stdio(0);
    cin.tie(0);
    cout.tie(0);

    cin >> n;
    bt("");
    cout << cnt << endl;

    return 0;
}
