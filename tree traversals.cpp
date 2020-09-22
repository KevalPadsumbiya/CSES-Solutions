#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

int in_order[100001],pre_order[100001];

void postOrder(int in,int pre,int n)
{
	int root=in_order[pre_order[pre]];
	if(root!=mod)
		postOrder(in,pre+1,root);
	if(root!=mod)
		postOrder(in+root+1,pre+root+1,n-root-1);
	cout<<pre_order[pre]<<" ";
}

int main()
{
	fastio;
	int n,x,i;
	cin>>n;
	memset(in_order,mod,sizeof(in_order));
	for(i=0;i<n;i++)
		cin>>pre_order[i];
	for(i=0;i<n;i++)
	{
		cin>>x;
		in_order[x]=i;
	}
	postOrder(0,0,n);
	return 0;
}

