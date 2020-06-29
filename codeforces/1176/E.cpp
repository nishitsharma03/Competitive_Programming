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
vector<int> ans;

int dist[N];
void bfs(int src,bool vis[],bool ch)
{
	queue<int> q;
	q.push(src);
	vis[src]=1;
	dist[src]=0;
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		for(auto i: v[top])
		{
			if(!vis[i])
			{
				q.push(i);
				vis[i]=1;
				dist[i]=dist[top]+1;
			}
		}
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
	{int n,m;
	cin>>n>>m;
	fab(0,n+1,i)
	v[i].clear();
	ans.clear();

	fab(0,m,i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	bool vis[n+1]={0};
	bfs(1,vis,1);
	vector<int> o,e;
	fab(1,n+1,i)
	{
		if(dist[i]%2)
			o.pb(i);
		else
			e.pb(i);
	}
	if(o.size()<=n/2)
		ans=o;
	else
		ans=e;
	
	cout<<ans.size()<<endl;
	for(auto i:ans)
		cout<<i<<" ";
	cout<<endl;
	}


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}