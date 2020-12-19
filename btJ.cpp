#define M 1000000007
 
#include <bits/stdc++.h>
using namespace std;
 
typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
 
int n, m, cnt, x, y, mpath;
bool path[25][25];
 
void setup() {
    cnt = 0;
    mpath = 0;
    cin >> n >> m;
    for (int i = 0; i < n; ++i)
        for (int j = 0; j < n; ++j)
            path[i][j] = 0;
 
    while (m--) {
        cin >> x >> y;
        path[x][y] = 1;
        path[y][x] = 1;
    }
}
 
void travel(int x) {
    for (int i = 0; i < n; ++i)
        if (path[x][i]) {
            path[x][i] = 0;
            path[i][x] = 0;
            ++cnt;
 
            travel(i);
            if (cnt > mpath)
                mpath = cnt;
 
            path[x][i] = 1;
            path[i][x] = 1;
            --cnt;
        }
}
 
int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    int t;
    cin >> t;
 
    while (t--) {
        setup();
        travel(0);
        cout << mpath << endl;
    }
 
    return 0;
}