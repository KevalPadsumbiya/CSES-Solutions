#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;
 
vector<int> ar[100001];
 
int main()
{
	fastio;
	int n,m,a,b,i;
	cin>>n>>m;
	int path[n+1]={0};
	
	for(i=0;i<m;i++)
	{
		cin>>a>>b;
		ar[a].pb(b);
		ar[b].pb(a);
 	}
	
	queue<int> q;
	q.push(1);
	path[1]=-1;
	
	while(!q.empty())
	{
		int cur=q.front();
		q.pop();
		if(cur==n)
			break;
		for(auto child : ar[cur])
		{
			if(path[child]==0)
			{
				path[child]=cur;
				q.push(child);
			}
		}
	}
	
	if(path[n]==0)
		cout<<"IMPOSSIBLE";
	else
	{
		i=n;
		vector<int> ans;
		while(path[i]!=-1)
		{
			ans.pb(i);
			i=path[i];
		}
		ans.pb(1);
		
		reverse(ans.begin(),ans.end());
		
		cout<<ans.size()<<"\n";
		for(auto el : ans)
			cout<<el<<" ";
	}
	return 0;
}
