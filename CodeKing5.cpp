#include <bits/stdc++.h>
#define faster() ios::sync_with_stdio(0); cin.tie(0); cout.tie(0);
#define base 1000000007
using namespace std;
typedef long long ll;
typedef unsigned long long ull;
typedef unsigned int uint;
typedef vector <int> vi;
typedef vector <string> vs;

int main()
{
	faster();
	ull n, s2=3, s1=6, ans;
	cin >> n;
	if (n==1) ans=0;
	else if (n==2) ans=3;
	else if (n==3) ans=6;
	else{
		for (int i=4; i<=n; i++){
			ans=(3*s2 + 2*s1)%base;
			s2=s1;
			s1=ans;
		}
	}
	cout << ans;
	return 0;
}


