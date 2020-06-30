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
vector<int> v[N];
pair<int,int> edges[N];

bool oddcycleexist()
{
	int col[N];
	memset(col,-1,sizeof(col));
	queue<int> q;
	q.push(1);
	col[1]=0;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto i:v[top])
		{
			if(col[i]==-1)
			{
				col[i]=1-col[top];
				q.push(i);
			}
			else if(col[i]==col[top])
				return true;
		}
	}
	return false;

}
map<pii,int> m;
void dfs(int src,bool vis[],bool incoming)
{
	vis[src]=true;
	for(auto i:v[src])
	{
		if(incoming)
			{
				m[{src,i}]=1;	
				m[{i,src}]=2;
			}
			else
				{m[{src,i}]=2;
				m[{i,src}]=1;}

		if(!vis[i])
		{
			
			dfs(i,vis,1-incoming);


		}
	}


}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n,k;
	cin>>n>>k;
	fab(0,k,i)
	{
		cin>>edges[i].f>>edges[i].se;
		v[edges[i].f].pb(edges[i].se);
		v[edges[i].se].pb(edges[i].f);
	}
	if(oddcycleexist())
	{
		cout<<"NO\n";
		return 0;
	}
	else
	{
		bool vis[n+1]={0};
		dfs(1,vis,1);
		cout<<"YES\n";
		string ans="";
		fab(0,k,i)
		{
			cout<<m[edges[i]]-1;
		}

	}



 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}