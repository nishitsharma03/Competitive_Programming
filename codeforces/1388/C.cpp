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
const int N=1e5+5;
vector<int> v[N];
ll subtree[N];
ll p[N],h[N];
ll dfs( int src, int par)
{
	subtree[src]=p[src];
	for( auto i: v[src])
	{
		if(i^par)
		{
			subtree[src]+=dfs(i,src);
		}
	}
	return subtree[src];

}

bool dfs2( int src, int par)
{
	int good=(subtree[src]+h[src])/2;
	if((subtree[src]+h[src])%2 or abs(h[src])>subtree[src])
		return 0;
	int bad=(subtree[src]-good);
	//cout<<"SrC:"<<src<<" "<<good<< " "<<bad<<endl;
	bool ok=1;
	ll sum=0,sum1=0;
	for( auto i : v[src])
	{
		if(i^par)
		{
			int goodi=(subtree[i]+h[i])/2;
			int badi=(subtree[i]-goodi);

			sum+=goodi;
			sum1+=badi;

			if(sum>good)
				return 0;
			ok&=dfs2(i,src);
		}
	}
	if(sum+sum1!=subtree[src]-p[src])
		return 0;
	return ok;
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
		int n,m;
		cin>>n>>m;
		fab(1,n+1,i)
		v[i].clear();
		fab(1,n+1,i)
		cin>>p[i];
		fab(1,n+1,i)
		cin>>h[i];
		fab(0,n-1,i)
		{
			int x,y;
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		dfs(1,-1);
		bool ok=dfs2(1,-1);
		cout<<(ok?"YES\n":"NO\n");
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}