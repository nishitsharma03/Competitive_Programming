//#pragma GCC optimize "trapv"
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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
const int N=1e5+5;
vector<int> v[N];
vector<int> ans;
void dfs(int src, bool vis[])
{
	vis[src]=1;
	ans.pb(src);

	for(auto i: v[src])
	{
		if(!vis[i])
			dfs(i,vis);

	}
}


int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	map<ll,ll> m,op;
	ll ind=1;
	fab(0,n,i)
	{
		ll x,y;
		cin>>x>>y;
		if(!m[x])
			{
				m[x]=ind;
				op[ind]=x;
				ind++;
			}
			if(!m[y])
			{
				m[y]=ind;
				op[ind]=y;
				ind++;
			}
			v[m[x]].pb(m[y]);
			v[m[y]].pb(m[x]);

		}
			fab(1,m.size(),j)
			{
				if(v[j].size()==1)
				{
					bool vis[N]={0};
					dfs(j,vis);
					break;
				}
			}
			for(auto i:ans)
				cout<<op[i]<<" ";

	


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}