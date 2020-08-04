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
const int N=3e5+5;
vector<pair<ll,ll> > v[N];
ll dp[N],w[N];
ll ans;
void dfs( int src, int par)
{
	dp[src]=w[src];
	ans=max(ans,dp[src]);
	for(auto i: v[src])
	{
		if(i.f^par)
		dfs(i.f,src);
	}
	for(auto i: v[src])
	{
		if(i.f^par)
		{
			ans=max(ans,dp[src]+dp[i.f]-i.se);
			dp[src]=max(dp[src],w[src]-i.se+dp[i.f]);

		}

	}
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	fab(1,n+1,i)
	cin>>w[i];
	fab(0,n-1,i)
	{
		int u,x,c;
		cin>>u>>x>>c;
		v[u].pb({x,c});
		v[x].pb({u,c});
	}
	dfs(1,-1);
	
	cout<<ans<<endl;




 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}