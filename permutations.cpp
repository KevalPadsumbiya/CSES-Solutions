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
	int n,i;
	cin>>n;
	if(n>=2 && n<=3)
		cout<<"NO SOLUTION";
	else if(n==4)
		cout<<"2 4 1 3";
	else
	{
		if(n%2==0)
		{
			int i=1,j=n/2+1;
			while(j<=n)
				cout<<i++<<" "<<j++<<" ";
		}
		else
		{
			int i=1,j=n/2+2;
			while(j<=n)
				cout<<i++<<" "<<j++<<" ";
			cout<<n/2+1;
		}
	}
	return 0;
}

