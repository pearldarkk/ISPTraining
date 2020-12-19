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
    int t;
    cin >> t;
    for (int k = 1; k <= t; ++k)
    {
        int n;
        scanf("%d", &n);
        printf("Test %d:\n", k);
        ll a[25][25];

        ll num = n * n;
        int begin = 1,end = n;
        while (num)
        {
            for (int i = begin; i <= end; ++i)
            a[begin][i] = num--;
            for (int i = begin + 1; i < end; ++i)
            a[i][end] = num--;
            for (int i = end; i > begin; --i)
            a[end][i] = num--;
            for (int i = end; i > begin; --i)
            a[i][begin] = num--;
            ++begin;
            --end;
        }

        for (int i = 1; i <= n; ++i)
        {
            for (int j = 1; j <= n; ++j)
            cout << a[i][j] << ' ';
            cout << endl;
        }
    }
    return 0;
}
