#include <bits/stdc++.h>
using namespace std;

typedef vector <int> vi;

void ins(vi &v) 
{ 
    for (auto i = v.begin(); i != v.end(); ++i) 
    {         
        auto const insp =  upper_bound(v.begin(), i, *i); 
        rotate(insp, i, i+1);        

        cout << "Buoc " << i - v.begin() << ":";
        for (auto j = v.begin(); j <= i; ++j)
            cout << " " << *j;

        cout << "\n";
    } 
} 

int main()
{
    int n;
    cin >> n;

    int j;
    vi v;
    for (int i = 0; i != n; ++i)
    {
        cin >> j;
        v.push_back(j);
    }
    ins(v);

    return 0;
}