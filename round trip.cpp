#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int col[100001],par[100001],Start,End;
vector<int> ar[100001];
bool cycle;

bool DFS(int src)
{
	col[src]=1;
	for(auto child : ar[src])
	{
		if(col[child]==0)
		{
			par[child]=src;
			if(DFS(child))
				return true;
		}
		else if(col[child]==2)
		{
			cycle=true;
			Start=src;
			End=child;
			return true;
		}
	}
	col[src]=2;
	return false;
}

int main()
{
	fastio;
	int n,m,a,b,i;
	cin>>n>>m;
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
	}
	
	for(i=1;i<=n;i++)
		if(col[i]==0)		// means not visited
		{
			if(DFS(i))
				break;
		}
	if(cycle)
	{
		vector<int> round_trip;
		i=End;
		while(i!=Start)
		{
			round_trip.pb(i);
			i=par[i];
		}
		round_trip.pb(Start);
		round_trip.pb(End);
		cout<<round_trip.size()<<"\n";
		for(auto el : round_trip)
			cout<<el<<" ";
	}
	else
		cout<<"IMPOSSIBLE";
	return 0;
}

