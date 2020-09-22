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
	int t;
	cin>>t;
	while(t--)
	{
		int n,x,b,i,k;
		cin>>n;
		int fre[100001]={0};
		for(i=0;i<n;i++)
		{
			cin>>x;
			fre[x]++;
		}
		cin>>k;
		for(i=1;i<=100001;i++)
		{
			if(fre[i]>0)
				k-=fre[i];
			if(k<=0)
				break;
		}
		cout<<i<<"\n";
	}
	return 0;
}

