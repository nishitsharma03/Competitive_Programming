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
		vector<pll> a(n);
		map<ll, ll> m;
		fab(0, n, i)
		{
			cin >> a[i].f;
			a[i].se = i;
		}
		sort(all(a));
		vector<ll> pref(n);
		pref[0] = a[0].f;
		fab(1, n, i)
		{
			pref[i] += pref[i - 1] + a[i].f;
		}

		m[a[n - 1].f] = 1;

		for ( int i = n - 2; i >= 0; i--)
		{
			if (m.find(a[i].f) != m.end())
				continue;
			if (pref[i] < a[i + 1].f)
			{
				m[a[i].f] = 0;
			}
			else
				m[a[i].f] = m[a[i + 1].f];


		}
		vector<int> ans(n);
		fab(0, n, i)
		{
			ans[a[i].se] = m[a[i].f];
		}
		int cnt = 0;
		fab(0, n, i)
		cnt += ans[i];
		cout << cnt << endl;

		fab(0, n, i)
		{
			if (ans[i])
			{
				cout << i + 1 << " ";
			}
		}
		cout << endl;
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}