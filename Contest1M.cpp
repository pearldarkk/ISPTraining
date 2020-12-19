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

void check(const string &s)
{
    int r = 1;

    int dif = 0;
    size_t idx = 1;
    
    while (dif == 0)
    {
        dif = s[idx] - s[idx - 1];
        ++idx;
    }

    for (size_t i = idx; i < s.size(); ++i)
    if ((s[i] - s[i - 1]) * dif < 0) 
    {
        r = 0;
        break;
    }

    if (r) Pr("YES");
        else Pr("NO");
}
int main()
{
    int t;
    S(t);

    while (t--)
    {
        string s;
        cin >> s;
        check(s);
        Pn;
    }
    
    return 0;
}
