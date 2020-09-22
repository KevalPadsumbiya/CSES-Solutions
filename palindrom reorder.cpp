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
	string s;
	
	cin>>s;
	
	int i,j,odd=0,fre[26]={0};
	
	for(auto ch : s)
		fre[ch-'A']++;
	
	for(i=0;i<26;i++)
		if(fre[i]%2)
			odd++;
			
	string pal="";
	
	if(s.length()%2==0 && odd==0)
	{
		for(i=0;i<26;i++)
		{
			for(j=0;j<fre[i]/2;j++)
				pal+=char(i+'A');
		}
	
		for(i=pal.length()-1;i>=0;i--)
			pal+=pal[i];
	
		cout<<pal;
	}
	else if(s.length()%2==1 && odd==1)
	{
		int index;
		for(i=0;i<26;i++)
		{
			if(fre[i]%2)
				index=i;
			for(j=0;j<fre[i]/2;j++)
				pal+=char(i+'A');
		}
	
		pal+=char(index+'A');
	
		for(i=pal.length()-2;i>=0;i--)
			pal+=pal[i];
		cout<<pal;
	}
	else
		cout<<"NO SOLUTION";
	return 0;
}

