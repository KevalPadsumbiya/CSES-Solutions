#include<iostream>
#include<vector>
#include<bits/stdc++.h>
#define lli long long int
#define mod 1000000007
#define pb push_back
#define mk make_pair
#define fastio ios_base::sync_with_stdio(false); cout.tie(NULL);
using namespace std;

vector<lli> segtree[2000001];
lli val[500001],b[500001];
map<lli,lli> m;

void make_segTree(lli index,lli start,lli end)
{
	if(start==end)
	{
		segtree[index].pb(b[start]);
		return;
	}
	lli mid=(start+end)>>1;
	make_segTree(index<<1,start,mid);
	make_segTree(index<<1|1,mid+1,end);
	
	merge(segtree[index<<1].begin(),segtree[index<<1].end(),segtree[index<<1|1].begin(),segtree[index<<1|1].end(),back_inserter(segtree[index]));
}

lli query(lli index,lli start,lli end,lli l,lli r,lli x)
{
	if(l==start && r==end)
	{
		lli last_index=upper_bound(segtree[index].begin(),segtree[index].end(),x)-segtree[index].begin();
		return segtree[index].size()-last_index;	
	}	
	lli mid=(start+end)>>1;
	if(r<=mid)
		return query(index<<1,start,mid,l,r,x);
	else if(l>=mid+1)
		return query(index<<1|1,mid+1,end,l,r,x);
	else
		return query(index<<1,start,mid,l,mid,x) + query(index<<1|1,mid+1,end,mid+1,r,x);
}

int main()
{
	lli n,q,l,r,i;

	scanf("%lld %lld",&n,&q);

	for(i=0;i<n;i++)
		scanf("%lld",&val[i]);

	for(i=n-1;i>=0;i--)
	{
		if(m.find(val[i])==m.end())
			b[i]=mod;
		else
			b[i]=m[val[i]];
		m[val[i]]=i;
	}

	make_segTree(1,0,n-1);

	while(q--)
	{
		scanf("%lld %lld",&l,&r);
		printf("%lld\n",query(1,0,n-1,l-1,r-1,r-1));
	}
	return 0;
}

