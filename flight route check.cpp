#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int vis[100001],call=0,node1,node2;
vector<int> ar[100001];

void DFS(int src)
{
	vis[src]=1;
	for(auto child : ar[src])
		if(vis[child]==0)
			DFS(child);
}

int main()
{
	fastio;
	int n,m,a,b,i,j;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
//		ar[b].pb(a);
	}
	for(i=1;i<=n;i++)
	{
//		if(ar[i].size()==0)
//			cout<<i<<"\n";
		cout<<i<<" : ";
		for(auto el : ar[i])
			cout<<el<<" ";
		cout<<endl;
	}
//	for(i=1;i<=n;i++)
//	{
//		if(ar[i].size()<n-1)
//		{
//			for(auto el : ar[i])
//				vis[el]=1;
//			vis[i]=1;
//			for(j=1;j<=n;j++)
//				if(vis[j]==0)
//				{
//					cout<<"NO\n"<<i<<" "<<j;
//					return 0;
//				}
//		}
//	}
//	cout<<"YES";
	return 0;
}

