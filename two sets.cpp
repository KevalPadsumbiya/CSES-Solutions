#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int vis[1000001];
int main()
{
	fastio;
	lli n,i;
	cin>>n;
	if(((n*(n+1))/2)%2)
		cout<<"NO";
	else
	{
		vector<int> v1,v2;
		
		lli sum=(n*(n+1))/4;
		
		i=n;
		
		while(sum>=i)
		{
			v1.pb(i);
			sum-=i;
			vis[i]=1;
			i--;
		}
		
		if(sum>0)
		{
			vis[sum]=1;
			v1.pb(sum);
		}
		
		for(i=1;i<=n;i++)
			if(vis[i]==0)
				v2.pb(i);
		
		cout<<"YES\n"<<v1.size()<<"\n";
		for(auto el : v1)
			cout<<el<<" ";
		
		cout<<"\n"<<v2.size()<<"\n";
		for(auto el : v2)
			cout<<el<<" ";
	}
	return 0;
}

