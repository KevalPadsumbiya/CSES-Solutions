#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
using namespace std;

struct edge
{
	lli a,b,w;
};

edge ar[200001];
lli par[100001];

bool comp(edge a,edge b)
{
	if(a.w<b.w)
		return true;
	return false;
}

lli find(lli a)
{
	if(par[a]<0)
		return a;
	return par[a]=find(par[a]); // path compression
}

void Union(lli a,lli b)
{
	par[b]=a;
}

int main()
{
	ios_base::sync_with_stdio(false); 
    cout.tie(NULL);
	
	lli i,n,m,ans=0,nodes=1;
	
	cin>>n>>m;
	
	for(i=1;i<=n;i++)
		par[i]=-1;
		
	for(i=0;i<m;i++)
		cin>>ar[i].a>>ar[i].b>>ar[i].w;
	
	sort(ar,ar+m,comp);
	
	for(i=0;i<m;i++)
	{
		lli a,b;
		a=find(ar[i].a);
		b=find(ar[i].b);
		
		if(a!=b)
		{
			ans+=ar[i].w;
			nodes++;
			Union(a,b);
		}
	}
	if(nodes==n)
		cout<<ans;
	else
		cout<<"IMPOSSIBLE";
	return 0;
}

