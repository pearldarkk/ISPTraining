#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

inline int min(int a, int b)
{
    return a < b ? a : b;
}

int sqr(int n)
{
    int a, b;
    int ma = M, mb = M;
    while (n--)
    {
        cin >> a >> b;\
        ma = min(ma, a);
        mb = min(mb, b);
    }

    return ma * mb;
}

int main()
{
    int n;
    cin >> n;
    cout << sqr(n) << '\n';

    return 0;
}
