#define M 1000000007
#define Pn printf("\n")

#include <bits/stdc++.h>
using namespace std;

typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

unordered_map <int, int> m;

bool vals(pii& a, pii& b)
{
    if (a.second == b.second)
        return m[a.first] < m[b.first];
    return a.second > b.second;
}

void freqs(int *a, int n)
{
    unordered_map <int, int> track;
    vpii v;

    for (int i = 0; i != n; ++i)
    {
        ++track[a[i]];
        if (m[a[i]] == 0)
            m[a[i]] = i + 1;
    }

    copy(track.begin(), track.end(), back_inserter(v));
    sort(v.begin(), v.end(), vals);

    for (size_t i = 0; i != v.size(); ++i)
        for (int j = 0; j < v[i].second; ++j)
            cout << v[i].first << " ";
}

int main()
{
    int t;
    cin >> t;

    while (t--)
    {
        int n;
        cin >> n;
        int a[100005];
        for (int i = 0; i != n; ++i)
            cin >> a[i];
        freqs(a, n);
        Pn;
    }

    return 0;
}
