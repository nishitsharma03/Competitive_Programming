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
const int N=2e5+5;
vector<int> v[N],dir[N];
vector<int> topo;
void dfs1(int src, bool vis[])
{
	vis[src]=1;
	for(auto i: dir[src])
	{	if(!vis[i])
			dfs1(i,vis);
	}
	topo.pb(src);

}

bool checkcycle(int src,bool vis[], bool recstack[])
{
	bool ok=0;
	vis[src]=1;
	recstack[src]=1;
	for(auto i:dir[src])
	{
		if(recstack[i])
			return 1;
		if (!vis[i])
		ok|=checkcycle(i,vis,recstack);
		
	}
	recstack[src]=0;

	return ok;

}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n,m;
		cin>>n>>m;
		//cout<<n<<" "<<m<<endl;
		fab(1,n+1,i)
		dir[i].clear();
		topo.clear();
		vector< pair<int,int> > undir;
		fab(0,m,i)
		{
			int ty,a,b;
			cin>>ty>>a>>b;

			if(ty==1)
				{dir[a].pb(b);
			//dir[b].pb(a);}
		}
		else
		{
			undir.pb({a,b});
		}

		}
		bool vis[n+1],recstack[n+1];
		memset(vis,0,sizeof(vis));
		memset(recstack,0,sizeof(recstack));
		bool ok=0;
		fab(1,n+1,i)
		{	
			if(!vis[i])
			ok|=(checkcycle(i,vis,recstack));

		}
		if(ok)
		{
			cout<<"NO\n";
			continue;
		}

		memset(vis,0,sizeof(vis));
		fab(1,n+1,i)
		{	
			if(!vis[i])
			dfs1(i,vis);

		}
		reverse(all(topo));
		map<int,int> pos;
		fab(0,topo.size(),i)
		{
			pos[topo[i]]=i+1;

		}
		for(auto i: undir)
		{
			if(pos[i.f]<pos[i.se])
			{
				dir[i.f].pb(i.se);
			}
			else
				{
					
					dir[i.se].pb(i.f);


				}
		}
		cout<<"YES\n";
		fab(1,n+1,i)
		{
			for(auto j: dir[i])
				cout<<i<<" "<<j<<endl;
		}
			fab(1,n+1,i)
		dir[i].clear();
		topo.clear();
		



	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}