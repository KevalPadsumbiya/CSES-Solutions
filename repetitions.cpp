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
	int ans=1,i=0,cnt;
	string s;
	cin>>s;
	while(i<s.length()-1)
	{
		cnt=1;
		while(s[i]==s[i+1])
		{
			cnt++;
			i++;
		}
		i++;
		ans=max(ans,cnt);
	}
	cout<<ans;
	return 0;
}

