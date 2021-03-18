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
		ll n;
		cin >> n;
		vector<ll> a(n);
		fab(0, n, i)
		{
			cin >> a[i];
		}

		ll ans = 1e18;
		ll o = 0, e = 0;
		ll op = 1, ep = 1;
		ll esum = a[0], osum = a[1];
		ll emin = a[0], omin = a[1];

		vector<ll> ev, ov;
		ev.pb(a[0]*n);
		ov.pb(a[1]*n);
		ans = ev[0] + ov[0];
		fab(2, n, i)
		{

			//cout << "I:" << i << endl;

			if (i % 2 == 0)
			{
				ll rem = n - ep;

				//cout << "rem:" << rem << endl;
				emin = min(emin, a[i]);

				ll cost = emin * rem;
				esum += a[i];
				//cout << "emin:" << emin << " " << esum << endl;

				cost += (esum - emin);
				ep++;

				ll val = ov.back();

				//cout << "val:" << val + cost << endl;

				ans = min(ans, val + cost);
				ev.pb(cost);




			}
			else
			{
				ll rem = n - op;

				omin = min(omin, a[i]);

				ll cost = omin * rem;
				osum += a[i];
				cost += (osum - omin);
				op++;

				ll val = ev.back();
				//cout << "val:" << val + cost << endl;
				ans = min(ans, val + cost);
				ov.pb(cost);
			}


		}
		cout << ans << endl;


	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}