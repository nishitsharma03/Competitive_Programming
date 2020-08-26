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

const int N=2e5+5;
int maxutil=0;
vector<int> v[N];
void dfs( int src, bool vis[])
{
	vis[src]=1;
	maxutil=max(maxutil,src);
	for(auto i: v[src])
	{
		if(!vis[i])
			dfs(i,vis);
		
	}
	
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n,m;
	cin>>n>>m;
	fab(0,m,i)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	bool vis[n]={0};
	ll ans=0;
	fab(0,n,i)

	{
		if(!vis[i])
			dfs(i,vis);
		fab(i,maxutil,j)
		{
			if(!vis[j])
			{
				ans++;
				v[i].pb(j);
				v[j].pb(i);
				dfs(j,vis);
			}
		}
		i=maxutil;


	}
	cout<<ans<<endl;



 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}