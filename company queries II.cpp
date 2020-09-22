#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;
 
vector<int> ar[200001];
int level[200001],lca[200001][20],maxN;
 
void DFS(int src,int par,int d)
{
	lca[src][0]=par;
	level[src]=d;
	for(auto child : ar[src])
		if(child!=par)
			DFS(child,src,d+1);	
}
 
int findLCA(int a,int b)
{
	int i,d;
	if(level[a]>level[b])
		swap(a,b);
	d=level[b]-level[a];
	while(d>0)
	{
		i=log2(d);
		b=lca[b][i];
		d-=(1<<i);
	}
	if(a==b)
		return b;
	for(i=maxN;i>=0;i--)
	{
		if(lca[a][i]!=-1 && (lca[a][i]!=lca[b][i]))
		{
			a=lca[a][i];
			b=lca[b][i];
		}
	}
	return lca[a][0];
}
 
int main()
{
	fastio;
	
	int n,q,a,b,i,j;
	
	cin>>n>>q;
	
	for(i=2;i<=n;i++)
	{
		cin>>a;
		ar[i].pb(a);
		ar[a].pb(i);
	}
	
	DFS(1,-1,0);
	
	maxN=log2(n)+1;
	
	for(j=1;j<=maxN;j++)
	{
		for(i=1;i<=n;i++)
		{
			if(lca[i][j-1]!=-1)
			{
				int LCA=lca[i][j-1];
				lca[i][j]=lca[LCA][j-1];
			}
		}
	}
	
	while(q--)
	{
		cin>>a>>b;
		cout<<findLCA(a,b)<<"\n";
	}
	return 0;
}
