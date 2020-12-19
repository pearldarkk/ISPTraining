#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;

void mul(int n)
{
    int a[25][25];
    int s = 0;

    for (int i = 1; i <= n; ++i)
    {
        s += i*i;
        for (int j = i; j <= n; ++j)
            a[i][j] = s;
    }

    for (int i = 1; i <= n; ++i)
    {
        for (int j = 1; j < i; ++j)
            cout << a[j][i] << " ";
        for (int j = i; j <= n; ++j)
            cout << a[i][j] << " ";
        cout << "\n";
    }

}

void out(int t)
{
    int n;
    for (int i = 1; i <= t; ++i)
    {
        cin >> n;
        cout << "Test " << i << ":\n";
        mul(n);
    }
}

int main()
{
    int t;
    cin >> t;
    out(t);

    return 0;
}
