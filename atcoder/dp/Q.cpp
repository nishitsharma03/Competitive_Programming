//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
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
int n;
ll h[200005],a[200005],seg[4*200005];
vector<ll > dp(400005);
void update(ll node,ll s,ll e,ll ind ,ll val)
{
	if(s==e)
	{
		seg[node]=val;
		//dp[ind]=val;
	}
	else
	{
		ll mid=s+(e-s)/2;
		if(ind<=mid)
			update(2*node,s,mid,ind,val);
		else
			update(2*node+1,mid+1,e,ind,val);

	
	seg[node]=max(seg[2*node],seg[2*node+1]);
	}
}
ll query(ll node,ll s,ll e,ll l, ll r)
{
	if(s>r or e<l)
		return 0;
	if(l<=s and e<=r)
		return seg[node];

	ll mid=s+(e-s)/2;
	return max(query(2*node,s,mid,l,r),query(2*node+1,mid+1,e,l,r));

}
int main()
{ quick;

	cin>>n;
	fab(0,n,i)
	cin>>h[i];
	fab(0,n,i)
	cin>>a[i];
	vector<ll> v(n+1,0),sum(n+1,0);
	v[1]=h[0];
	sum[1]=a[0];
	int lisptr=2;
	int i=1;
	
	fab(0,n,i)
	{
		ll res=query(1,0,n+1,0,h[i]-1);
		//cout<<"res:"<<res<<" "<<i<<endl;
		dp[h[i]]=max(dp[h[i]],res+a[i]);
		update(1,0,n+1,h[i],dp[h[i]]);
	}
	/*fab(0,4*n,i)
	{
		cout<<dp[i]<<endl;
	}*/
	cout<<query(1,0,n+1,0,n+1)<<endl;

	//cout<<query(1,0,n+1,n+1,n+1)<<endl;

	return 0;
}