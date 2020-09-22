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
int timer=1,lca[200001][19],level[200001],maxN;

struct query
{
	int l,r,i,type;
}Q[200001];

void DFS(int src,int par,int d)
{
	level[src]=d;
	lca[src][0]=par;
	for(auto child : ar[src])
		if(child!=par)
			DFS(child,src,d+1);
}

int findLCA(int a,int b)
{
	if(level[a]>level[b])
		swap(a,b);
	int i,d=level[b]-level[a];
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
	
	maxN=log2(n)+1;
	
	for(i=0;i<n-1;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	
	DFS(1,-1,0);
	
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
	
	for(i=0;i<q;i++)
	{
		cin>>a>>b;
		cout<<level[a]+level[b]-2*level[findLCA(a,b)]<<"\n";
	}
	return 0;
}

