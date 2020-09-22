#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int main()
{
	fastio;
	lli n,sum,i;
	cin>>n>>sum;
	lli a[n];
	unordered_map<lli,lli> m;
	for(i=0;i<n;i++)
		cin>>a[i];
	for(i=0;i<n;i++)
	{
		if(m.find(sum-a[i])!=m.end())
		{
			cout<<m[sum-a[i]]+1<<" "<<i+1;
			return 0;
		}
		m[a[i]]=i;
	}
	cout<<"IMPOSSIBLE";
	return 0;
}

