#define M 1000000007
#define Pn printf("\n")
#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <unsigned long long> vull;
typedef vector <pii> vpii;

vull fb(int n)
{
    vull f;
    f.push_back(0);
    f.push_back(1);

    for (int i = 2; i <= n; ++i)
        f.push_back(f[i-1] + f[i - 2]);

    return f;
}

int main()
{
    int t;
    cin >>> t;

    vull f = fb(81);
    int n;
    ull a[10][10];
    for (int id = 1; id <= t; ++id)
    {
        printf("Test %d:\n", id);
        S(n);

        //Draw :)
        int idx = 0;
        int begin = 1,end = n;
        while (idx < n * n)
        {
            for (int i = begin; i <= end; ++i)
            a[begin][i] = f[++idx];
            for (int i = begin + 1; i < end; ++i)
            a[i][end] = f[++idx];
            for (int i = end; i > begin; --i)
            a[end][i] = f[++idx];
            for (int i = end; i > begin; --i)
            a[i][begin] = f[++idx];
            ++begin;
            --end;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            printf("%lld ", a[i][j]);
            printf("\n");
        }
    }

    return 0;
}
