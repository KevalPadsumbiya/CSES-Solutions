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

int findLCA(int a,int d)
{
	if(d>level[a])
		return -1;
	int i;
	while(d>0)
	{
		i=log2(d);
		a=lca[a][i];
		d-=(1<<i);
	}
	return a;
}

int main()
{
	fastio;
	int n,q,a,d,i,j;
	cin>>n>>q;
	for(i=2;i<=n;i++)
	{
		cin>>a;
		ar[i].pb(a);
		ar[a].pb(i);
	}
	DFS(1,-1,0);
//	for(i=1;i<=n;i++)
//		cout<<lca[i][0]<<" ";
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
		cin>>a>>d;
		cout<<findLCA(a,d)<<"\n";
	}
	return 0;
}

