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
int st[200001],et[200001],fl[400001],timer=1;

void DFS(int src,int par)
{
	st[src]=timer;
	fl[timer++]=src;
	for(auto child : ar[src])
		if(child!=par)
			DFS(child,src);
	et[src]=timer;
	fl[timer++]=src;
}

int main()
{
	fastio;
	int n,a,i;
	cin>>n;
	for(i=2;i<=n;i++)
	{
		cin>>a;
		ar[i].pb(a);
		ar[a].pb(i);
	}
	DFS(1,-1);
	for(i=1;i<=n;i++)
		cout<<(et[i]-st[i]+1)/2-1<<" ";
	return 0;
}

