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


int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n;
	cin >> n;
	vector<int> v(n);
	fab(0, n, i)
	{
		string s;

		cin >> s;
		if (s == "AND")
			v[i] = 1;
		else
			v[i] = 0;
	}


	vector<vector<ll> > dp(n + 3, vector<ll> (5, 0));
	dp[0][0] = dp[0][1] = 1;

	for ( int i = 0; i < n; i++)
	{
		if (v[i] == 0)
		{
			dp[i + 1][0] = dp[i][0] * 2 + dp[i][1] ;
			dp[i + 1][1] = dp[i][1];

		}
		else
		{
			dp[i + 1][0] = dp[i][0];
			dp[i + 1][1] = dp[i][1] * 2 + dp[i][0];

		}

	}


	cout << dp[n][0] << endl;


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}