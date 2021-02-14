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

using namespace std;

ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}
const int N = 1e5 + 5;
vector<vector<ll>> dp(N, vector<ll> (2));
vector<int> v[N];
vector<int> a(N);

void dfs(int src, int par)
{
	if (src != 0 and v[src].size() == 1)
	{	dp[src][a[src]] = 1;
		return;
	}
	if (a[src] == 1)
		dp[src][1] = 1;
	else
		dp[src][0] = 1;
	ll p = dp[src][0], u = dp[src][1];
	for (auto i : v[src])
	{
		if (i ^ par)
		{

			dfs(i, src);
			ll p1 = p, u1 = u;
			p = 0, u = 0;

			if (a[src] == 1)
			{
				u = add(u, mul(u1, dp[i][1]));
				u = add(u, mul(u1, dp[i][0]));
				dp[src][0] = 0;
			}
			else
			{

				p = add(p, mul(p1, dp[i][0]));
				p = add(p, mul(p1, dp[i][1]));
				u = add(u, mul(u1, dp[i][1]));
				u = add(u, mul(p1, dp[i][1]));
				u = add(u, mul(u1, dp[i][0]));
			}
		}


	}

	dp[src][1] = u;
	dp[src][0] = p;
}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	fab(0, n - 1, i)
	{
		int x;
		cin >> x;
		v[i + 1].pb(x);
		v[x].pb(i + 1);
	}
	fab(0, n, i)
	{
		cin >> a[i];
	}


	dfs(0, -1);


	cout << add( 0ll, dp[0][1]) << endl;


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}