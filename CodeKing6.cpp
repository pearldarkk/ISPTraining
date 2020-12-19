#include<bits/stdc++.h>
 
using namespace std;
 
int main()
{
	int n;
	cin >> n;
	vector<long long> a, b;
 
	for(int i = 0; i < n; ++i)
	{
		long long x;
	 	cin >> x;
		a.push_back(x);
	}
	for(int i = 0; i < n; ++i)
	{
		long long x; 
		cin >> x;
		b.push_back(x);
	}
 
	vector<unsigned long long> sum(n, 0);
	vector< int > mark_right(n, n-1);
	int left = n - 1;
	long long max_val = a[n - 1];
	unsigned long long max_sum = b[n - 1];
	sum[n - 1] = b[n - 1];
 
	for(int i = n-2; i >= 0; --i)
	{
		if(max_val >= a[i])	
		{
			sum[i] = sum[i + 1] + b[i];
			mark_right[i] = mark_right[i + 1];
		}
 		else
 		{
 			sum[i] = b[i];
 			max_val = a[i];
 			mark_right[i] = i;
		}
		if(sum[i] > max_sum)
		{
			max_sum = sum[i];
			left = i;
		}
	}
	cout << left << " " << mark_right[left];
	return 0;
}