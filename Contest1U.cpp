#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

void bubble(vi& v)
{
    bool swp = true;
    int cnt = 0;
    while (swp)
    {
        swp = false;
        for (auto i = v.begin(); i != v.end() - 1; ++i)
            if (*i > *(i + 1))
            {
                swp = true;
                swap(*i, *(i + 1));
            }

        if (swp)
        {
            cout << "Buoc " << ++cnt << ":";
            for (auto i = v.begin(); i != v.end(); ++i)
                cout << " " << *i;
            cout << "\n";
        }
    }
}
int main()
{
    int n;
    cin >> n;

    vi v;
    int j;
    for (int i = 0; i != n; ++i)
    {
        cin >> j;
        v.push_back(j);
    }
    bubble(v);

    return 0;
}