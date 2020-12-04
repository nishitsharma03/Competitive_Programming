//#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
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
		int n;
		cin>>n;
		ll a[n];
		vector<ll> v;
		fab(0,n,i)
		{
			cin>>a[i];

		}
		ll tot=0;
		for( int i=n-1;i>0;i--)
		{
			ll val=abs(a[i-1]-a[i]);
			tot+=val;

		}
		// vector<ll> pref;
		// pref.pb(0);
		// fab(1,n,i)
		// {
		// 	pref[i]+=pref[i-1]+abs(a[i]-a[i-1]);

		// }
		//cout<<"tot:"<<tot<<endl;
		ll ans=1e18;
		fab(0,n,i)
		{
			if(i>0)
			{
				//cout<<"i prev:"<<i<<" "<<abs(a[i]-a[i-1])<<" "<<(i-2>=0?abs(a[i]-a[i-2]):0)<<endl;
				ll req=tot-abs(a[i]-a[i-1]) -(i-2>=0?abs(a[i-1]-a[i-2]):0) + (i-2>=0?abs(a[i]-a[i-2]):0) ;
				ans=min(ans,req);

			}
			if(i+1<n)
			{
				ll req=tot- abs(a[i]-a[i+1])- (i+2<n?abs(a[i+1]-a[i+2]):0) + (i+2<n?abs(a[i]-a[i+2]):0);
				ans=min(ans,req);
			}
			//cout<<i<<endl;

		}
		cout<<ans<<endl;
	}

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}