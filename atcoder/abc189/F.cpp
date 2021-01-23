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
	long double m, k;
	cin >> n >> m >> k;
	vector<bool> block(n + 1, 0);
	fab(0, k, i)
	{
		int x;
		cin >> x;
		block[x] = 1;

	}
	bool poss = 0;



	vector<vector<long db> > dp(n + m + 3, vector<long db> (2, 0));
	long db cnt = 0;
	long db sum = 0;

	for ( int i = n - 1; i >= 0; i--)
	{
		if (block[i])
		{
			dp[i][0] = 0;
			dp[i][1] = 1;
		}
		else
		{
			dp[i][0] = 1.0 + (sum) / m;
			dp[i][1] = cnt / (m * 1.0);

		}

		sum += dp[i][0];
		sum -= dp[i + m][0];
		cnt += dp[i][1];
		cnt -= dp[i + m][1];

		if (cnt >= m)
		{
			cout << -1 << endl;
			return 0;
		}
	}

	if (1 - dp[0][1] < 1e-8)
	{
		cout << -1 << endl;
		return 0;
	}

	cout << fixed << setprecision(12) << dp[0][0] / (1 - dp[0][1]) << endl;




	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}