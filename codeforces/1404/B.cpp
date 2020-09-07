//#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
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
const int N=1e5;
vector<int> v[N];
void dfs( int src, int par,int dist, int dis[])
{
	dis[src]=dist;
	for( auto i: v[src])
	{
		if(i^par)
		{
			dfs(i,src,dist+1,dis);
		}
	}
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
		ll n,a,b,da,db;
		cin>>n>>a>>b>>da>>db;
		
		fab(0,n+1,i)
		{
			v[i].clear();
		}
		fab(0,n-1,i)
		{
			int x,y;
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}

		int ad[n+1],bd[n+1];
		dfs(a,-1,0,ad);
		int atob=ad[b];
		int dis=0;
		int node=0;
		fab(1,n+1,i)
		{
			if(ad[i]>dis)
			{
				dis=ad[i];
				node=i;
			}
		}
		dfs(node,-1,0,bd);
		ll dia=*max_element(bd+1,bd+n+1);
		bool ans=0;
		if(atob<=da or dia<=2*da or db<=2*da)
		{

		}
		else if(db>2*da)
		{
			ans=1;

		}
		cout<<(ans?"Bob":"Alice")<<endl;


	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}