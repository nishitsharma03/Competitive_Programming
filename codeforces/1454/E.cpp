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
const int N=2e5+5;
vector<int> v[N];
int par[N];
bool iscycle[N];
vector<int> cycle;
void init(ll n)
{
	fab(0,n+2,i)
	{
		v[i].clear();
		par[i]=0;
		iscycle[i]=0;
	}
	cycle.clear();

}
bool dfs( int src, int parent, bool vis[])
{
	vis[src]=1;
	par[src]=parent;
	//cout<<"src:"<<src<<" "<<parent<<endl;
	for(auto i: v[src])
	{
		if(i^parent)
		{
			if(vis[i])
			{
				//cout<<"cc:"<<i<<endl;

				int x=src;
				while(x!=i)
				{
					//cout<<"x:"<<x<<endl;
					cycle.pb(x);
					x=par[x];
				}
				cycle.pb(i);
				return 1;
			}
			else
			{
				if(dfs(i,src,vis))
					return 1;
			}
		}

	}
	return 0;
}
ll dfs2(int src, int par)
{
	ll sz=1;
	for(auto i: v[src])
	{
		if(i^par and iscycle[i]==false)
		{
			sz+=dfs2(i,src);
			
		}
	}
	return sz;
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
		init(n);
		fab(0,n,i)
		{
			int x,y;
			cin>>x>>y;
			x--;y--;
			v[x].pb(y);
			v[y].pb(x);
		}
		bool vis[n]={0};
		dfs(0,-1,vis);
		for(auto i: cycle)
		{
			iscycle[i]=1;
		}
		ll ans=n*(n-1);
		for(auto i: cycle)
		{
			ll tr=dfs2(i,-1);
			ll rem=(n-tr)*tr;
			ans+=rem;

		}
		cout<<ans/2<<endl;





	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}