#define M 1000000007
#define sqr(x) ((x) * (x))
#define x first
#define y second
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair<int, int> ii;
typedef vector<int> vi;
typedef vector<vector<int>> vvi;
typedef vector<ii> vii;
typedef pair<double, double> point;
typedef pair<double, int> rec;

set<rec> S;
point p[100000];
int n;

double dist(const point &a, const point &b) {
    return sqrt(sqr(a.x - b.x) + sqr(a.y - b.y));
}

int main() {
    ios_base::sync_with_stdio(false);
    cin.tie(NULL);
    cout.tie(NULL);

    int t;
    cin >> t;
    while (t--) {
        cin >> n;
        for (int i = 0; i < n; ++i)
            cin >> p[i].x >> p[i].y;

        sort(p, p + n);

        int j = 0;
        double ans = 1e9;

        for (int i = 0; i < n; ++i) {
            while (p[i].x - p[j].x > ans) {
                S.erase(S.find({p[j].y, j}));
                ++j;
            }
            set<rec>::iterator it = S.lower_bound({p[i].y - ans, 0});
            set<rec>::iterator ed = S.upper_bound({p[i].y + ans, 0});

            while (it != ed) {
                ans = min(ans, dist(p[i], p[it->y]));
                ++it;
            }
            S.insert({p[i].y, i});
        }

        cout << setprecision(6) << fixed << ans << endl;
    }

    return 0;
}
