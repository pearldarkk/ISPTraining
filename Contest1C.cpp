#include <bits/stdc++.h>
using namespace std;

#define MAX 32000

vector<int> prime;
bitset<MAX> m;

void sieve()
{
    m.set();
    m[0] = 0;
    m[1] = 0;

    for (int i = 2; i <= MAX; ++i)
        if (m[i])
        {
            prime.push_back(i);
            for (int j = i * i; j <= MAX; j += i)
            {
                m[j] = 0;
            }
        }
}

bool dig(int x)
{
    while (m[x % 10])
        x /= 10;

    if (x == 0)
        return 1;
    return 0;
}

bool digS(int x)
{
    int s = 0;
    while (x)
    {
        s += x % 10;
        x /= 10;
    }

    return (m[s]);
}

int cnt(int l, int r)
{
    int res = 0;

    bool mark[r - l + 1];
    for (int i = 0; i < r - l + 1; ++i)
        mark[i] = true;

    for (int i = 0; prime[i] * prime[i] <= r; ++i)
    {
        int cp = prime[i];
        int base = (l / cp) * cp;
        if (base < l)
            base += cp;

        for (int j = base; j <= r; j += cp)
            mark[j - l] = false;

        if (base == cp)
            mark[base - l] = true;
    }

    for (int i = 0; i < r - l + 1; ++i)
        if (mark[i]) //i + l is prime
            if (digS(i + l) && dig(i + l))
                ++res;
    return res;
}

int main()
{
    int t;
    scanf("%d", &t);
    sieve();
    int l, r;
    while (t--)
    {
        scanf("%d%d", &l, &r);
        if (r > l)
            swap(r, l);
        printf("%d\n", cnt(l, r));
    }

    return 0;
}