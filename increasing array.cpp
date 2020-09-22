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
	lli n,i,ans=0;
	cin>>n;
	lli a[n];
	cin>>a[0];
	for(i=1;i<n;i++)
	{
		cin>>a[i];
		if(a[i]<a[i-1])
		{
			ans+=a[i-1]-a[i];
			a[i]+=a[i-1]-a[i];
		}
	}
	cout<<ans;
	return 0;
}

