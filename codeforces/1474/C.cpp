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
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector<ll> a(2 * n);
		fab(0, 2 * n, i)
		{
			cin >> a[i];

		}
		sort(all(a));
		vector<ll> v;
		fab(0, 2 * n - 1, i)
		{
			v.pb(a[2 * n - 1] + a[i]);

		}

		multiset<ll> s;
		ll ans = -1;
		for (auto j : v)
		{
			s.clear();
			//cout << "j:" << j << endl;
			bool ok = 1;
			fab(0, 2 * n, i)
			{
				s.insert(a[i]);
			}
			ll val = j;

			for ( int i = 2 * n - 1; i >= 0; i--)
			{
				auto k = s.find(a[i]);
				if (k == s.end())
					continue;
				//cout << "getL:" << a[i] << " " << val << endl;
				ll op = *k;
				ll req = val - *k;
				s.erase(k);
				auto p = s.find(req);
				if (p == s.end())
				{
					ok = 0;
					break;
				}
				else {
					op = max(op, *p);

					s.erase(p);
				}
				val = op;
			}

			if (ok)
			{
				ans = j;
				break;
			}

		}
		if (ans == -1)
		{
			cout << "NO" << endl;
			continue;
		}
		else
		{
			cout << "YES" << endl;
			cout << ans << endl;
			s.clear();
			bool ok = 1;
			fab(0, 2 * n, i)
			{
				s.insert(a[i]);
			}
			ll val = ans;

			for ( int i = 2 * n - 1; i >= 0; i--)
			{
				auto k = s.find(a[i]);
				if (k == s.end())
					continue;
				ll op = *k;
				ll req = val - *k;

				s.erase(k);
				auto p = s.find(req);
				assert(p != s.end());
				{

					cout << op << " " << *p << endl;
					op = max(op, *p);

					s.erase(p);
				}
				val = op;
			}



		}
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}