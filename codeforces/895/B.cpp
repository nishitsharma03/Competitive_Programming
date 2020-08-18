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
	ll n,x,k;
	cin>>n>>x>>k;
 
	ll a[n];
	fab(0,n,i)
	cin>>a[i];
	sort(a,a+n);
	ll ans=0;
	fab(0,n,i)
	{
		ll div=(a[i]-1)/x;
		div+=k;
		auto lb=lower_bound(a,a+n,div*x);
		auto kk=lower_bound(a,a+n,a[i]);
		if(lb<kk)
			lb=kk;
		auto up=upper_bound(a,a+n,div*x+x-1);
		//cout<<"lb:"<<lb-a<<" "<<up-a<<endl;
		ans+=(up-lb);
 
	}
	cout<<ans<<endl;
	
 
 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
/*
2 5 0
3 4
*/