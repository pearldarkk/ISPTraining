#include <bits/stdc++.h>
using namespace std;

#define M 1000000007
typedef long long ll;
typedef unsigned long long ull;
typedef pair <int, int> pii;
typedef vector <int> vi;
typedef vector <pii> vpii;

//a > b ?
bool big(string& a, string& b)
{
    int x = a.size(), y = b.size();
    if (x > y) return true;
    if (x < y) return false;

    for (int i = 0; i != x; ++i)
    if (a[i] > b[i])
        return true;
    else 
        if (a[i] < b[i])
            return false;
    
    return true;
}

vi dif(string& a, string& b)
{
    if (!big(a, b)) 
        swap(a, b);

    vi r;

    int x = a.size();
    int y = x - b.size();
    while (y--)
    {
        b = '0' + b;
    }

    int c = 0;

    for (int i = x - 1; i >= 0; --i)
    {
        int sub = a[i] - b[i] - c;
        c = 0;
        if (sub < 0)
        {
            sub += 10;
            c = 1;
        }
        r.push_back(sub);
    }
    if (*(r.end() - 1) == 0) r.pop_back();
    
    return r;
}

int main()
{
    int t;
    cin >> t;
    
    while (t--)
    {
        string s1, s2;
        cin >> s1 >> s2;
        vi diff = dif(s1, s2);
        for (auto i = diff.rbegin(); i != diff.rend(); ++i)
            cout << *i;
        cout << "\n";
    }

    return 0;
}
