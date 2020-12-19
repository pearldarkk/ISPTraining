#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define Pn printf("\n")
#define S(x) scanf("%d",&x)
#define P(x) printf("%d", x)
#define P2(x, y) printf("%d %d", x, y)
#define SS(x) scanf("%s", x)
#define e1 first
#define e2 second
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

int cnt(int m[], int n)
{
    int r = 0;
    for (int i = 0; i < 10; ++i)
    {
        if (n < m[i]) continue;

        r += n / m[i];
        n %= m[i];
    }

    return r;
}

int main()
{
    int m[10] = {1000, 500, 200, 100, 50, 20, 10, 5, 2, 1};

    int t;
    S(t);

    int n;
    while (t--)
    {
        S(n);
        P(cnt(m, n));
        Pn;
    }
    return 0;
}
