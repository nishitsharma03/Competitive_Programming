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
		ll n;
		ll s;
		cin>>n>>s;
		pair<ll,ll>  a[n];
		fab(0,n,i)
		cin>>a[i].f>>a[i].se;
		//sort(a,a+n);
		ll h=1e14+4;
		
		ll l=0;
		ll ans=0;
		while(l<=h)
		{
			ll mid=(l+h)/2;
			ll cnt=0;
			ll toto=0;
			vector< pair<ll,ll> > v;
			fab(0,n,i)
			{
				if(a[i].f<mid and mid<=a[i].se)
					{v.pb(a[i]);
			//			cout<<"chceke:"<<mid<<" "<<a[i].f<<" "<<a[i].se<<endl;
					}
				else if(a[i].f<mid)
					cnt+=a[i].f;
				else if(a[i].f>=mid )
					{cnt+=a[i].f;
				toto++;}

			}
			//cout<<"mid:"<<mid<<" "<<v.size()-(n-n/2-toto)<<" "<<toto<<endl;
			ll req=max(0ll,(n-n/2-toto));
			if(v.size()<req  )
				{h=mid-1;
				continue;
			}
			

		//	cout<<"mid:"<<mid<<" "<<cnt<<endl;
			sort(all(v));
			
			fab(0,v.size()-req,i)
			{
				cnt+=v[i].f;
				
			}
			cnt+=req*mid;
			if(cnt<=s)
			{
				ans=mid;
				l=mid+1;
			}
			else
				h=mid-1;




		}
		cout<<ans<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}