#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define Pn printf("\n")

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

int main()
{
    int n;
    cin >> n;

    int a[n][n];

    for (int i = 0; i != n; ++i)
        for (int j = 0; j != n; ++j)
            cin >> a[i][j];

    for (int i = 0; i != n; ++i)
        {
            for (int j = 0; j != n; ++j)
                if (a[i][j])
                    cout << j + 1 << " ";
            Pn;
        }

    return 0;
}
