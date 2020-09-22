#include<iostream>
#include<vector>
#include<math.h>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define fastio ios_base::sync_with_stdio(false); cin.tie(NULL); 
using namespace std;
 
lli a=0,b=1,tr[2][2],id[2][2];
 
void mul(lli a[2][2],lli b[2][2],lli dim)
{
	lli res[2][2];
	int i,j,k;
	for(i=0;i<2;i++)
	{
		for(j=0;j<2;j++)
		{
			res[i][j]=0;
			for(k=0;k<2;k++)
			{
				lli x=(a[i][k]*b[k][j])%mod;
				res[i][j]=(res[i][j]+x)%mod;
			}
		}
	}
	for(i=0;i<2;i++)
		for(j=0;j<2;j++)
			a[i][j]=res[i][j];
}
 
lli nth(lli n)
{
	id[0][0]=id[1][1]=1;
	id[0][1]=id[1][0]=0;
	tr[0][0]=0;
	tr[0][1]=tr[1][0]=tr[1][1]=1;

	if(n==1)
		return b;
	while(n)
	{
		if(n%2)
			mul(id,tr,2);
		mul(tr,tr,2);
		n>>=1;	// n/=2;
	}
	return (a*id[0][0]+b*id[1][0])%mod;
}
 
int main()
{
	fastio;
	lli n;
	cin>>n;
	cout<<nth(n)<<endl;
	return 0;
}
 
