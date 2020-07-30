#pragma GCC optimize "trapv"
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
const int N=2e5+5;
vector<ll> v[N];
vector<ll> topo;
ll a[N+1],b[N+1];
void dfs( int src,bool vis[])
{
	vis[src]=1;
	for( auto i: v[src])
	{
		if(!vis[i])
			dfs(i,vis);
	}
	topo.pb(src);
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	ll n;
	cin>>n;
	
	fab(1,n+1,i)
	cin>>a[i];
	fab(1,n+1,i)
	cin>>b[i];
	fab(1,n+1,i)
	{
		if(b[i]!=-1)
		{
			
				v[i].pb(b[i]);
			
			
		}

	}
	bool vis[n+1];
	fab(0,n+1,i)
	vis[i]=0;
	fab(1,n+1,i)
	{
		if(!vis[i])
			dfs(i,vis);
	}
	reverse( all(topo));
	ll ans=0;
	vector<int> later,now;
	fab(0,topo.size(),i)
	{
		
		ans+=a[topo[i]];
		if(a[topo[i]]>=0 and b[topo[i]]!=-1)
		{
			
				
				a[b[topo[i]]]+=a[topo[i]];	
				now.pb(topo[i]);
			
		}
		else
			later.pb(topo[i]);
	}
	reverse(all(later));
	cout<<ans<<endl;
	for(auto i: now)
		cout<<i<<" ";
	for(auto i: later)
		cout<<i<<" ";


	




 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}