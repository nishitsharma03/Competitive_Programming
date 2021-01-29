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
	int t = 1;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll> c(n);
		fab(0, n, i)
		{
			cin >> c[i];

		}
		vector<ll> dp(n);
		vector<ll> a(n), b(n);
		fab(0, n, i)
		{
			cin >> a[i];

		}
		fab(0, n, i)
		{
			cin >> b[i];
			ll sm = min(a[i], b[i]);
			ll bg = max(a[i], b[i]);
			a[i] = sm;
			b[i] = bg;

		}

		fab(1, n, i)
		{
			if (a[i] == b[i])
			{
				dp[i] = c[i] + 1;
			}
			else
			{
				if (i == 1)
				{
					dp[i] = (c[i] + 1 + b[i] - a[i]);
					continue;

				}
				dp[i] = max(c[i] + 1 + b[i] - a[i], c[i] + 1 + a[i] - 1 + (c[i - 1] - b[i]) + dp[i - 1] - c[i - 1] + 1);
			}

		}
		// cout << "dp:" << endl;

		// fab(0, n, i)
		// {
		// 	cout << dp[i] << " ";
		// }
		//cout << endl;
		cout << *max_element(all(dp)) << endl;
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}