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
	lli i,n,sum=0,x;
	cin>>n;
	for(i=0;i<n-1;i++)
		cin>>x , sum+=x;
	cout<<(n*(n+1))/2-sum;
	return 0;
}

