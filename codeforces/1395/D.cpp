//#pragma GCC optimize "trapv"
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
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
	int t=1;
	//cin>>t;
	while(t--)
	{
		int n,d,m;
		cin>>n>>d>>m;
		ll a[n];
		vector<ll> x,y;
		fab(0,n,i)
		{
		cin>>a[i];
		if(a[i]>m)
			x.pb(a[i]);
		else
			y.pb(a[i]);
		}
		
		sort(all(x),greater<ll>());
		sort(all(y),greater<ll>());
		ll ans=0;
		ll pref[n];
		fab(0,y.size(),i)
		{
			pref[i]=y[i];
			//cout<<y[i]<<" ";
			if(i>0)
				pref[i]+=pref[i-1];
		}
		/*cout<<endl;
		 fab(0,y.size(),i)
		 cout<<pref[i]<<" ";
		 cout<<endl;
		 */
		fab(y.size(),n,i)
		pref[i]=pref[i-1];
		if(x.size()==0)
		{
			cout<<pref[n-1]<<endl;
			return 0;
		}
		if(y.size()==0)
		{
			ll div=(n+d)/(d+1);
			ll s=0;
			fab(0,div,i)
			s+=x[i];
			cout<<s<<endl;
			return 0;
		}
		ll sum=0;
		fab(0,x.size(),i)
		{
			sum+=x[i];
			ll bigg=(ll)(i)*(d+1)+1;
			ll rem=n-bigg;
			if(bigg==n)
				ans=max(ans,sum);
			if(rem>0)
			{
				ans=max(ans,sum+pref[rem-1]);
			}

		}
		cout<<ans<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}