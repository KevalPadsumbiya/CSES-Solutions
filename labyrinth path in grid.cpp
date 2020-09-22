#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int main()
{
	fastio;
	bool reachable=false;
	int n,m,i,j;
	pair<int,int> start,dest;
	
	cin>>n>>m;
	
	char a[n][m];
	
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
		{
			cin>>a[i][j];
			if(a[i][j]=='A')
				start={i,j};
			if(a[i][j]=='B')
				dest={i,j};
		}
		
	vector<vector<pair<int,int>>> v(n,vector<pair<int,int>> (m,{0,0}));
	queue<pair<int,int>> q;
	q.push(start);
	v[start.first][start.second]={-1,-1};
	
	int vis[n][m];
	for(i=0;i<n;i++)
		for(j=0;j<m;j++)
			vis[i][j]=0;
			
	vis[start.first][start.second]=1;
	while(!q.empty())
	{
		pair<int,int> cur=q.front();
		q.pop();
		if(cur.first==dest.first && cur.second==dest.second)
		{
			reachable=true;
			break;
		}
		if(cur.first-1>=0 && (a[cur.first-1][cur.second]=='.'  || a[cur.first-1][cur.second]=='B') && vis[cur.first-1][cur.second]==0 )
		{
			vis[cur.first-1][cur.second]=1;
			q.push({cur.first-1,cur.second});
			v[cur.first-1][cur.second]=cur;
		}
		if(cur.first+1<n && (a[cur.first+1][cur.second]=='.' || a[cur.first+1][cur.second]=='B') && vis[cur.first+1][cur.second]==0)
		{
			vis[cur.first+1][cur.second]=1;
			q.push({cur.first+1,cur.second});
			v[cur.first+1][cur.second]=cur;
		}
		if(cur.second+1<m && (a[cur.first][cur.second+1]=='.' || a[cur.first][cur.second+1]=='B') && vis[cur.first][cur.second+1]==0)
		{
			vis[cur.first][cur.second+1]=1;
			q.push({cur.first,cur.second+1});
			v[cur.first][cur.second+1]=cur;
		}
		if(cur.second-1>=0 && (a[cur.first][cur.second-1]=='.' || a[cur.first][cur.second-1]=='B') && vis[cur.first][cur.second-1]==0)
		{
			vis[cur.first][cur.second-1]=1;
			q.push({cur.first,cur.second-1});
			v[cur.first][cur.second-1]=cur;
		}
	}
	if(reachable)
	{
		vector<pair<int,int>> path;
		string ans="";
		i=dest.first,j=dest.second;
		while(v[i][j].first!=-1 && v[i][j].second!=-1)
		{
			path.pb({i,j});
			int temp=i;
			i=v[i][j].first;
			j=v[temp][j].second;
		}
		path.pb(start);
		reverse(path.begin(),path.end());
		for(i=1;i<path.size();i++)
		{
			if(path[i].first==path[i-1].first && path[i].second==path[i-1].second-1)
				ans+='L';
			else if(path[i].first==path[i-1].first && path[i].second==path[i-1].second+1)
				ans+='R';
			else if(path[i].first==path[i-1].first-1 && path[i].second==path[i-1].second)
				ans+='U';
			else 
				ans+='D';
		}
		cout<<"YES\n"<<ans.length()<<"\n"<<ans;
	}
	else
		cout<<"NO";
	return 0;
}

