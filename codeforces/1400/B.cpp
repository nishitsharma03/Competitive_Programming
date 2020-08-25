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
	int t;
	cin>>t;
	while(t--)
	{
		ll a,b;
		cin>>a>>b;
		ll sw,ax;
		cin>>sw>>ax;
		ll x,y;
		cin>>x>>y;
		ll ans=0;
		if(x>y)
		{
			swap(x,y);
			swap(sw,ax);
		}
		fab(0,sw+1,i)
		{
			if(a<i*x)
				break;
			ll cnt=a-(i*x);
			ll tm=i;
			ll cnt2=cnt/y;
			tm+=cnt2;
			ll rem1=sw-i,rem2=ax-cnt2;
			cnt=min(b/x,rem1);
			cnt2=min(rem2,(b- cnt*x)/y);
			tm+=cnt+cnt2;
			ans=max(ans,tm);


		}
		cout<<ans<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}