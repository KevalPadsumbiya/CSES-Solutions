#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;
 
lli a[200001];
int vis[200001],segtree[800001];
 
void makesegTree(int index,int start,int end)
{
	if(start==end)
	{
		segtree[index]=vis[start];	
		return;	
	}
	int mid=(start+end)>>1;
	makesegTree(index<<1,start,mid);
	makesegTree(index<<1|1,mid+1,end);
	
	segtree[index]=segtree[index<<1]+segtree[index<<1|1];		
}	
 
int findSum(int index,int start,int end,int l,int r)
{
	if(l==start && r==end)
		return segtree[index];
	int mid=(start+end)>>1;
	if(r<=mid)
		return findSum(index<<1,start,mid,l,r);
	else if(l>=mid+1)
		return findSum(index<<1|1,mid+1,end,l,r);
	else
		return findSum(index<<1,start,mid,l,mid) + findSum(index<<1|1,mid+1,end,mid+1,r);	
}
 
void pointUpdate(int index,int start,int end,int i)
{
	if(start==end)
	{
		segtree[index]=0;
		return;	
	}	
	int mid=(start+end)>>1;
	if(i<=mid)
		pointUpdate(index<<1,start,mid,i);
	else
		pointUpdate(index<<1|1,mid+1,end,i);
	segtree[index]=segtree[index<<1]+segtree[index<<1|1];
}
 
lli query(int i,int start,int end,int l,int r)
{
	if(l==r)
	{
		vis[l]=0;
		pointUpdate(1,start,end,l);
		return a[l];
	}
	
	int mid=(l+r)>>1;
	int sum=findSum(1,start,end,0,mid);
	
	if(sum==i && vis[mid]==1)
	{
		vis[mid]=0;
		pointUpdate(1,start,end,mid);
		return a[mid];
	}
	else if((sum==i && vis[mid]==0) || sum>i)
		query(i,start,end,l,mid-1);
	else if(sum<i)
		query(i,start,end,mid+1,r);
}
 
int main()
{
	fastio;
	int n,i,l;
	cin>>n;
		
	for(i=0;i<n;i++)
		vis[i]=1;
		
	for(i=0;i<n;i++)
		cin>>a[i];	
	
	makesegTree(1,0,n-1);
	
	for(i=0;i<n;i++)
	{
		cin>>l;
		cout<<query(l,0,n-1,0,n-1)<<" ";
	}
	return 0;
}
