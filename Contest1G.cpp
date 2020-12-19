#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
#define Pn printf("\n")
#define S(x) scanf("%d",&x)
#define P(x) printf("%d", x)
#define P2(x, y) printf("%d %d", x, y)
#define SS(x) scanf("%s", x)
#define Pr(sth) printf(sth)
#define e1 first
#define e2 second
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

int main()
{
    string s;
    getline(cin, s);
    int a, b, c;
    a = s[0] - 48;
    b = s[4] - 48;
    c = s[8] - 48;

    if (c == a + b) Pr("YES");
        else Pr("NO");

    return 0;
}
