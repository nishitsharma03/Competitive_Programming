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
const int N=2e5+5;
vi v[N];
void dfs(int src,int par,int dist[])
{
	dist[src]=dist[par]+1;
	for(auto i:v[src])
	{
		if(i==par)
			continue;
		dfs(i,src,dist);
	}

}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,x;
    cin>>n>>x;
    fab(1,n,i)
    {
    	int a,b;
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
    }
    int  dist1[n+1],distx[n+1];
    dist1[0]=-1;
    distx[0]=-1;
    dfs(1,0,dist1);
    dfs(x,0,distx);
    int ans=0;
    fab(1,n+1,i)
    {
    	if(distx[i]<dist1[i])
    	{
    		ans=max(ans,2*dist1[i]);
    	}
    }
    cout<<ans<<endl;

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}