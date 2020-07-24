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
vector< int> v[25];

void dfs( int src, bool vis[])
{
	vis[src]=1;
	for(auto i: v[src])

	{
		if (!vis[i])
			dfs(i,vis);
	}
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
		string a,b;
		int n;
		cin>>n;
		cin>>a>>b;
		fab(0,25,i)
		v[i].clear();
		bool ok=1;
		fab(0,n,i)
		{
			if(a[i]>b[i])
				ok=0;
			v[a[i]-'a'].pb(b[i]-'a');
			v[b[i]-'a'].pb(a[i]-'a');
		}
		if(!ok)
		{
			cout<<-1<<endl;
			continue;
		}
		bool vis[21]={};
		int components=0;
		fab(0,20,i)
		{
			if(!vis[i])
				{dfs(i,vis);
					components++;
				}
		}
		cout<<20-components<<endl;



	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}