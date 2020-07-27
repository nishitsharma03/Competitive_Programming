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
const int N=105;
vector<int> v[N];
vector<char> ans;
bool dfs( int src, bool vis[], bool recstack[])
{
	vis[src]=1;
	recstack[src]=1;
	
	bool ok=0;
	for (auto i : v[src])
	{
		if(recstack[i])
			return 1;
		if(!vis[i])
			ok|=dfs(i,vis,recstack);

	}
	recstack[src]=0;
	ans.pb(char('a'+src));

	return ok;
}


int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int  n;
	
	cin >> n;

	vector<string> a(n);

	for( int i = 0; i < n ; i++)

		cin >> a[i];
	bool ok=0;

	for( int i = 1; i < n ; i++)
	
	{
		 bool done=0;
		for ( int j = 0; j < min(a[i-1].size(),a[i].size()) ; j++ )

		{
			if(a[i-1][j]!=a[i][j])
			{
				int smaller=a[i-1][j]-'a';
				int bigger = a[i][j]-'a';
				done=1;

				//cout<<a[i-1][j]<<" "<<a[i][j]<<endl;
				if(find(all(v[smaller]),bigger)==v[smaller].end())
				v[smaller].pb(bigger);
				break;
			}
		}
		if(done == 0 and a[i-1].length()>a[i].length())
		{
			ok=1;
			break;
		}





	}
	//cout << "oko:"<<ok<<endl;

	bool vis[26]={0},recstack[26]={0};
	
	

	for( int i = 0; i < 26 ; i++)
	{
		if(!vis[i])
			ok|=dfs(i,vis,recstack);

	}

	if ( ok )

		cout << "Impossible\n";
	else
	{
		reverse(all(ans));
		for(auto i: ans)
			cout<<i;
	}





 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}