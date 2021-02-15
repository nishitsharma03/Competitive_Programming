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
	// const ll N = 1e9 + 10000;
	// ll ans = 0;
	// int p = 1e5 + 5;
	// vector<int> dp (p);

	// for (ll i = 3; i * i <= 2 * N; i++)
	// {

	// 	ll val = i * i;
	// 	ll x = val / 2, y = val / 2 + 1;
	// 	if (i % 2 == 0)
	// 	{
	// 		x = val / 4 - 1;
	// 		y = val / 4 + 1;

	// 	}
	// 	if (i * i == x + y)
	// 	{
	// 		dp[max(x, y)]++;

//ll l = i, h = n;
// ll mx = i;
// while (l <= h)
// {
// 	ll mid = (l + h) / 2;

// 	if (val - mid >= mid)
// 	{
// 		mx = mid;
// 		l = mid + 1;
// 	}
// 	else
// 		h = mid - 1;

// }
// cout << "i:" << i << " " << mx << endl;
// ans += mx - i;


	while (t--)
	{
		ll n;
		cin >> n;
		ll ans = 0;
		for (ll i = 3; i * i <= 2 * n; i++)
		{

			ll val = i * i;
			ll x = val / 2, y = val / 2 + 1;
			if (i % 2 == 0)
			{
				x = val / 4 - 1;
				y = val / 4 + 1;

			}
			if (i * i == x + y)
			{
				ans++;
			}
			//ll l = i, h = n;
			// ll mx = i;
			// while (l <= h)
			// {
			// 	ll mid = (l + h) / 2;

			// 	if (val - mid >= mid)
			// 	{
			// 		mx = mid;
			// 		l = mid + 1;
			// 	}
			// 	else
			// 		h = mid - 1;

			// }
			// cout << "i:" << i << " " << mx << endl;
			// ans += mx - i;

		}


		cout << ans << endl;
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}