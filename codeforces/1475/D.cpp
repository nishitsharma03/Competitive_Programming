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
		ll n, m;
		cin >> n >> m;
		vector<ll> a(n), b(n);
		fab(0, n, i)
		{
			cin >> a[i];
		}
		vector<ll> op, pp;
		fab(0, n, i)
		{
			cin >> b[i];
			if (b[i] == 1)
			{
				op.pb(a[i]);
			}
			else
				pp.pb(a[i]);
		}
		sort(all(op), greater<ll>());
		sort(all(pp), greater<ll>());
		vector<ll> pref;

		fab(0, pp.size(), i)
		{
			ll val = pp[i];
			if (i > 0)
				val += pref[i - 1];
			pref.pb(val);
		}
		ll ans = 1e18;
		ll tot = 0;
		ll val = 0;
		fab(0,  op.size() + 1, i)
		{
			if (i > 0)
				tot += op[i - 1];

			ll rem = m - tot;
			val = -1;
			if (rem > 0)
			{
				val = lower_bound(all(pref), rem) - pref.begin();
				if (val == pref.size())
					val = 1e18;


			}
			ans = min(ans, i + (val + 1) * 2);

		}
		cout << (ans == 1e18 ? -1 : ans) << endl;

	}



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}