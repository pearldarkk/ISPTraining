#include <bits/stdc++.h>
using namespace std;

void ers(string& s, string& ss)
{
    s += ' ';
    string stemp;
    stemp.resize(s.size());
    transform(s.begin(), s.end(), stemp.begin(), :: tolower);
    transform(ss.begin(), ss.end(), ss.begin(), :: tolower);

    size_t p = stemp.find(ss);
    int cnt = 0, len = ss.length() + 1;
    while (p != string::npos)
    {
        s.erase(s.begin() + p - cnt*len, s.begin() + p + len - cnt*len);
        ++cnt;
        p = stemp.find(ss, p + 1);
    }
}

int main()
{
    int n;
    scanf("%d\n", &n);

    string s, ss;
    for (int k = 0; k < n; ++k)
    {
        getline(cin, s);
        getline(cin, ss);
        ers(s, ss);
        cout << s << "\n";
    }

    return 0;
}
