#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define Pn printf("\n")

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <vector <int>> vvi;
typedef vector <pii> vpii;

void inp(vvi& vv, int n)
{
    string s;
    for (int i = 0; i < n; ++i)
    {
        getline(cin, s);
        istringstream ss(s);
        vi v;
        int j;

        while (ss >> j)
            v.push_back(j - 1);
        vv.push_back(v);   
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);

    short a[n][n];
    memset(a, 0, sizeof(a));
    vvi vv;
    inp(vv, n);

    for (size_t i = 0; i != vv.size(); ++i)
        for (size_t j = 0; j != vv[i].size(); ++j)
        {
            a[i][vv[i][j]] = 1;
            a[vv[i][j]][i] = 1;
        }

    for (int i = 0; i != n; ++i)
    {
        for (int j = 0; j != n; ++j)
            cout << a[i][j] << " ";
        Pn;
    }

    return 0;
}
