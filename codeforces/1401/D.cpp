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
const ll N=1e5+5;
vector<ll> v[N];
ll subtree[N];
ll n;
vector<ll> edge;
void dfs( ll src, ll par)
{
	subtree[src]=1;
	for( int i: v[src])
	{
		if(i^par)
		{
			dfs(i,src);
			subtree[src]+=subtree[i];
		}
	}
	if(par!=-1)
	{
		edge.pb((n-subtree[src])*subtree[src]);
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
		
		cin>>n;
		fab(1,n+1,i)
		v[i].clear();
		fab(1,n,i)
		{
			ll x,y;
			cin>>x>>y;
			v[x].pb(y);v[y].pb(x);

		}

		ll m;
		cin>>m;
		vector<ll> a;

		fab(0,m,i)
		{ll x;
			cin>>x;
		a.pb(x);}
		
		edge.clear();

		dfs(1,-1);
		sort(all(edge));
		reverse(all(edge));
		ll ans=0;
		if(m>=n)
		{
			ll prod=1;
			sort(all(a));
			reverse(all(a));
			
			fab(0,m-n+2,i)
			{
				prod=mul(prod,a[i]);
				//cout<<a[i]<<" ";


			}
			

			ans=mul(prod,edge[0]);
			int cnt=1;
			fab(m-n+2,m,i)
			{
				//cout<<a[i]<<" ";
				ans=add(mul(edge[cnt],a[i]),ans);
				cnt++;

			}
			//cout<<cnt<<endl;

		}
		else
		{
			while(a.size()<n-1)
				a.pb(1);
			sort(all(a));
			reverse(all(a));
		/*	for( auto i: edge)
				cout<<i<<" ";
			cout<<endl;
			for( auto i: a)
				cout<<i<<" ";
			cout<<endl;*/
			fab(0,n-1,i)
			{
				ans=add(ans,mul(edge[i],a[i]));
			}
		}
		cout<<ans<<endl;


	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}