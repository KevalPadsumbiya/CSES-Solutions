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
	lli n;
	cin>>n;
	lli c=6;
	while(n>=1)
	{
		cout<<n<<" ";
		if(n%2 && n>1)
			n=n*3+1;
		else
			n/=2;
	}
	return 0;
}

