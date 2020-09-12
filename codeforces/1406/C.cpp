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
const int N=1e5+5;
int n;
vector<int> v[N];
map<int,int> m;
int subs[N],par[N];
int maxcomp=0;
void init()
{
	fab(1,n+1,i)
	{v[i].clear();
	subs[i]=0;
	par[i]=0;
	}
	maxcomp=1e8;
	m.clear();
}
int dfs(int src,int parent)
{
	int subtree=1;
	int ans=0;

	par[src]=parent;
	for( auto i: v[src])
	{
		if(i!=parent)
		{int k=dfs(i,src);
		ans=max(ans,k);
		subtree+=k;}
	}
	ans=max(ans,n-subtree);
	subs[src]=ans;
	maxcomp=min(maxcomp,ans);
	m[ans]++;
	return subtree;
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
		init();
		fab(1,n,i)
		{
			int x,y;
			cin>>x>>y;
			v[x].pb(y);
			v[y].pb(x);
		}
		dfs(1,-1);
		//cout<<"mx:"<<maxcomp<<endl;
		if(m[maxcomp]==1)
		{
			cout<<v[1][0]<<" "<<1<<endl;
			cout<<v[1][0]<<" "<<1<<endl;
		}
		else
		{
			int ind=0;
			fab(1,n+1,i)
			{
				if(subs[i]==maxcomp)
				{
					ind=i;
					break;
				}
			}

			for( auto i: v[ind])
			{
				if(i^par[ind])
				{
					if(subs[i]==maxcomp)
					{
						for( auto j: v[i])
						{
							if(j!=ind)
							{
								cout<<j<<" "<<i<<endl;
								cout<<j<<" " <<ind<<endl;
								break;
							}
						}
						break;
					}
				}

			}

			if(subs[par[ind]]==maxcomp)
			{

				for( auto j: v[ind])
						{
							if(j!=par[ind])
							{
								cout<<j<<" "<<ind<<endl;
								cout<<par[ind]<<" " <<j<<endl;
								break;
							}
						}
			}


		}




	}

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}