//#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(ll i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
//#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
const int N=2e5+2;

ll a[N];
ll seg[N*4];
void build(int node,int l, int r)
{
	if(l==r)
	{
		seg[node]=a[l];
	}
	else
	{
		int mid=(l+r)/2;
		build(2*node,l,mid);
		build(2*node+1,mid+1,r);
		seg[node]=min(seg[2*node],seg[2*node+1]);
	}
}
ll query(int node, int l, int r, int s, int e)
{
	//cout<<"s:"<<s<<" "<<e<<endl;
	if(l>e or r<s)
	{
		return 1e9+124;
	}
	if(s<=l and r<=e)
		return seg[node];
	int mid=(l+r)/2;
	ll ans=min(query(2*node,l,mid,s,e),query(2*node+1,mid+1,r,s,e));
	return ans;

}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		ll n;
		cin>>n;
		fab(0,n,i)
		{
			cin>>a[i];

		}
		fab(0,4*n+5,i)
		{
			seg[i]=INT_MAX;

		}
		build(1,0,n-1);

		ll pref[n],suff[n];
		pref[0]=a[0];

		map<int,int > m1,m2;

		fab(1,n,i)
		{
			pref[i]=max(pref[i-1],a[i]);
			
		}
		suff[n-1]=a[n-1];
		vector<ll> op={a[n-1]};
		for( int i=n-2;i>=0;i--)
		{
			suff[i]=max(suff[i+1],a[i]);
			
		
		}
		fab(0,n,i)
		{
			m1[suff[i]]=i;

		}
		for( int i=n-1;i>=0;i--)
		{
			m2[suff[i]]=i;
		}
		//reverse(all(op));
		
		 
		vector<int> v;
		fab(0,n-2,i)
		{
		
			if(m1.find(pref[i])==m1.end())
				continue;
			ll get=m2[pref[i]]-1;
			ll ind=m1[pref[i]]-1;
			//cout<<get<<endl;
			

			get=max(i+1,get);

			//cout<<"gg:"<<pref[i]<<" "<<get<<" "<<ind<<" "<<i<<endl;
			while(get<=ind )
			{
				int mid=(get+ind)/2;

				//cout<<"mid:"<<mid<<" "<<10<<endl;
				ll q=query(1,0,n-1,i+1,mid);
				//cout<<"mid:"<<mid<<" "<<q<<endl;
				if(q==pref[i])
				{
					v.pb(i+1);
					v.pb(mid-i);
					v.pb(n-mid-1);
					break;
				}
				else if(q<pref[i])
						ind=mid-1;
				else
					get=mid+1;

			}
			if(v.size())
				break;

		}
		if(v.size()==0)
		{
			cout<<"NO"<<endl;

		}
		else
		{
			cout<<"YES"<<endl;
			for(auto i: v)
				cout<<i<<" ";
			cout<<endl;

		}





	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}