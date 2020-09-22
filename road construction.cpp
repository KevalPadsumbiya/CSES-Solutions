#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int par[100001],components,mx=mod;

int find(int a)
{
	if(par[a]<0)
		return a;
	return par[a]=find(par[a]);
}

void Union(int a,int b)
{
	components--;	
	par[a]+=par[b];
	mx=min(mx,par[a]);
	par[b]=a;
}

int main()
{
	fastio;
	int a,b,n,m;
	cin>>n>>m;
	components=n;
	memset(par,-1,sizeof(par));
	while(m--)
	{
		cin>>a>>b;	
		a=find(a);
		b=find(b);
		if(a!=b)
			Union(a,b);
		cout<<components<<" "<<abs(mx)<<"\n";
	}	
	return 0;
}
