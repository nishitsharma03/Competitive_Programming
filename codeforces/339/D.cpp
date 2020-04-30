//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
ll int seg[1000000];
ll int a[1000000];
int build(ll int node,ll int beg,ll int end)
{
	if(beg==end)
	{
		seg[node]=a[beg];
		return 1;

	}
	else
	{
		ll int mid=(beg+end)/2;
		int p=build(2*node,beg,mid);
		int q=build(2*node+1,mid+1,end);
		assert(p==q);
		if(p%2)
		seg[node]=seg[2*node]|seg[2*node+1];
		else
			seg[node]=seg[2*node]^seg[2*node+1];
		return 1-p;
	}
}
int update(ll int node,ll int beg,ll int end,ll int ind,ll int val)
{
	if(beg==end)
	{
		a[beg]=val;
		seg[node]=val;
		return 1;
	}
	else
	{
		ll int mid=(beg+end)/2;
		int p;
		if(ind<=mid)
			p=update(2*node,beg,mid,ind,val);
		else
			p=update(2*node+1,mid+1,end,ind,val);
		if(p%2)
		seg[node]=seg[2*node]|seg[2*node+1];
		else
			seg[node]=seg[2*node]^seg[2*node+1];
		return 1-p;
		//seg[node]=seg[2*node]^seg[2*node+1];
	}
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll int n,m;
	cin>>n>>m;
	fab(0,pow(2,n),i)
	{
		cin>>a[i];
	}
	n=pow(2,n);
	build(1,0,n-1);
	while(m--)
	{
		ll int p,b;
		cin>>p>>b;
		update(1,0,n-1,p-1,b);
		//fab(1,2*n,i)
		//cout<<seg[i]<<" ";
		cout<<seg[1]<<endl;
	}


	return 0;
}