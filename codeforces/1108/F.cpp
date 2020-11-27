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
vector< pair<int,int> >  v[N];
int par[N],sz[N];
bool comp(const vector<int> &a, const vector<int> &b)
{
	return a[2]<b[2];
}

int find_set(int a)
{
	if(par[a]==a)
		return a;
	return par[a]=find_set(par[a]);
}

void union_sets(int a, int b)
{
	a=find_set(a);
	b=find_set(b);
	if(a!=b)
	{
		if(sz[a]>sz[b])
			swap(a,b);
		par[a]=b;
		sz[b]+=sz[a];
	}
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n,m;
	cin>>n>>m;
	vector< vector<int> > edges;
	fab(0,m,i)
	{
		int x,y,w;
		cin>>x>>y>>w;
		x--;
		y--;
		v[x].pb({y,w});
		v[y].pb({x,w});
		edges.pb({x,y,w});
	}
	fab(0,n,i)
	{
		par[i]=i;
		sz[i]=1;
	}
	sort(all(edges),comp);
	// for(auto i: edges)
	// {
	// 	cout<<i[0]<<" "<<i[1]<<" "<<i[2]<<endl;
	// }
	int ans=0;
	fab(0,m,i)
	{
		int j=i;
		
		vector<pair<int,int> > canbeused;
		while(j<m and edges[j][2]==edges[i][2])
		{
			//cout<<find_set(edges[j][0])<<" "<<find_set(edges[j][1])<<endl;

			if(find_set(edges[j][0]) == find_set(edges[j][1]));
			else
			{

				canbeused.pb({edges[j][0],edges[j][1]});
			}
			
			j++;


		}
		
		i=j-1;
		int cnt=0;
		for(auto op: canbeused )
		{
			if(find_set(op.f)!=find_set(op.se))
			{
				union_sets(op.f,op.se);
				
			}
			else
				cnt++;
		}
		ans+=cnt;
	}
	cout<<ans<<endl;

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}