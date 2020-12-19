#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

bool check(int *a, int *b, int n)
{
    for (int i = 0; i != n; ++i)
        if (a[i] > b[i])
            return 0;
    return 1;
}

int main()
{
    int n;
    cin >> n;
    int a[105], b[105];
    for (int i = 0; i != n; ++i)
        cin >> a[i];
    for (int i = 0; i != n; ++i)
        cin >> b[i];
    
    sort(a, a + n);
    sort(b, b + n);

    if (check(a, b, n))
        cout << "YES";
    else    
        cout << "NO";
    Pn;

    return 0;
}
