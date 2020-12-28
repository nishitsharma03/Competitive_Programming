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

		if (n <= 50)
		{	vector<pii> v;
			fab(1, n, i)
			{
				if (i == (n + 1) / 2)
					continue;
				v.pb({i, n});

			}
			v.pb({n, (n + 1) / 2});


			int x = (n + 1) / 2;
			int y = x;
			while (x > 1)
			{
				v.pb({(n + 1) / 2, n});
				x = (x + 1) / 2;
			}

			cout << v.size() << endl;

			for (auto i : v)
				cout << i.f << " " << i.se << endl;

		}
		else
		{
			vector<pii> v;
			fab(1, n, i)
			{
				if (i == 8 or i == 2 or i == 1)
					continue;

				v.pb({i, n});

			}
			int x = n;
			while (x > 1)
			{
				v.pb({n, 8});
				x = (x + 7) / 8;
			}
			x = 8;
			while (x > 1)
			{
				v.pb({8, 2});

				x = (x + 1) / 2;
			}
			assert(v.size() <= n + 5);
			cout << v.size() << endl;

			for (auto i : v)
				cout << i.f << " " << i.se << endl;

		}


	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}