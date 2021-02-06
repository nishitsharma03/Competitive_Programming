//#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(ll i=a;i<b;i++)
#define pb push_back
#define db long double
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

db x, y, r;

bool dist(db a, db b)
{
	db dis = (x - a) * (x - a) + (b - y) * (b - y);

	return (dis <= (r * r));
}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	// int T = 1;
	// cin >> T;
	// while (T--)
	{
		cin >> x >> y >> r;

		r += 1e-14;

		ll val = x - r - 400;
		ll op = x + r + 400;
		ll ans = 0;
		fab(val, op + 1, i)
		{
			//cout << "i:" << i << endl;
			ll l = 0, h = 1e10;
			ll op = 0;

			while (l <= h)
			{
				ll mid = (l + h) / 2;
				//cout << "mid:" << mid << endl;

				db coord = floor(y + mid);
				//cout << "coord:" << i << " " << coord << endl;
				if (dist(i, coord))
				{
					//cout << "have:" << i << " " << coord << endl;
					//cout << "mid:" << mid << endl;
					l = mid + 1;
					op = coord - ceil(y) + 1;


				}
				else
					h = mid - 1;
			}
			//cout << "jL" << l << endl;

			ans += op;

			l = (y == int(y) ? 1 : 0), h = 1e10;
			op = 0;
			while (l <= h)
			{
				ll mid = (l + h) / 2;
				//cout << "mid:" << mid << endl;

				db coord = floor(y - mid * 1.0);
				//cout << "coord:" << i << " " << coord << endl;
				if (dist(i, coord))
				{
					//cout << "have1:" << i << " " << coord << endl;
					//cout << "mid1:" << floor(y) - coord + 1 << endl;
					l = mid + 1;
					op = floor(y) - coord + (y == int(y) ? 0 : 1);


				}
				else
					h = mid - 1;
			}
			//cout << "jL2" << l << endl;

			ans += op  ;


		}
		cout << ans << endl;

	}

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}