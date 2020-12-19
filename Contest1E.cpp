#include <bits/stdc++.h>
using namespace std;


int main()
{
    int n;
    cin >> n;
    
    int u, d;
    int mU = INT_MAX, mD = INT_MAX;
    int sU = 0, sD = 0;
    for (int i = 0; i != n; ++i)
    {
        cin >> u >> d;
        mU = mU < u ? mU : u;
        mD = mD < d ? mD : d;
        sU += u;
        sD += d;
    }

    sU += mD;
    sD += mU;

    cout << (sU > sD ? sU : sD) << endl;

    return 0;
}