#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

lli count(int n)
{
	lli res=1,a=2;
	while(n)
	{
		if(n%2)
			res=(res*a)%mod;
		a=(a*a)%mod;
		n>>=1;
	}
	return res;
}

int main()
{
	fastio;
	int n;
	cin>>n;
	cout<<count(n);
	return 0;
}

