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
vi v[105];

// checking for odd length cycles and then drop one vertex from each cycle
int ans=0;
void dfs(int src, int col[],int color)
{
	col[src]=color;
	for(auto i: v[src])
	{
		if(col[i]!=-1  and col[i]==col[src])
		{
			ans++;
			col[i]=2;
			
		}
		else if(col[i]==-1)
			dfs(i,col,1-color);
	}

}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n,m;;
    cin>>n>>m;
    fab(0,m,i)
    {
    	int a,b;
    	cin>>a>>b;
    	v[a].pb(b);
    	v[b].pb(a);
    }
	int col[n+1];
	memset(col,-1,sizeof(col));
	fab(1,n+1,i)
	{
		if(col[i]==-1)
			dfs(i,col,1);
	}
	if((n-ans)%2)
		ans++;
	cout<<ans<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}