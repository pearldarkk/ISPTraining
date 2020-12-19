#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;

bitset <10> p;

void primedig()
{
    p.set();
    p[0] = p[1] = false;
    for (int i = 4; i < 10; ++i)
        for (int j = 2; j * j <= i; ++j)
            if (i % j == 0)
            {
                p[i] = false;
                break;
            }
}

bool pdig(int n)
{
    while (n)
        if (p[n % 10] == false)  
            return 0;
        else 
            n /= 10;
    return 1;
}

void out(vi &v)
{
    unordered_map <int, int> m;
    unordered_map <int, int> :: iterator it;

    for (auto i = v.begin(); i != v.end(); ++i)
        if (pdig(*i))
        {
            it = m.find(*i);
            if (it == m.end())
                m.insert({*i, 1});
            else 
                ++(it -> second);
        }
    
    for (auto i = m.begin(); i != m.end(); ++i)
        cout << i -> first << " " << i -> second << "\n";
}

int main()
{
    int n;
    vi v;
    while (scanf("%d", &n) != EOF)
        v.push_back(n);

    primedig();
    out(v);

    return 0;
}
