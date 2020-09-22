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
		lli row,col;
		cin>>row>>col;
		if(col<=row)
		{
			if(row%2)
				cout<<(row-1)*(row-1)+col<<"\n";
			else
				cout<<(row-1)*(row-1)+(row*2-1-(col-1))<<"\n";
		}
		else
		{
			if(col%2==0)
				cout<<(col-1)*(col-1)+row<<"\n";
			else
				cout<<(col-1)*(col-1)+(2*col-1-(row-1))<<"\n";
		}
	}
	return 0;
}

