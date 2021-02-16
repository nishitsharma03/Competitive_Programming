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
		vector<int> a(n);
		fab(0, n, i)
		{
			cin >> a[i];
		}
		vector<int> b(3);
		fab(0, n, i)
		{
			b[a[i] % 3]++;
		}
		int re = n / 3;

		int x = re - b[0];
		int y = re - b[1], z = re - b[2];
		int ans = 0;
		while (x < 0)
		{
			if (y > 0)
			{
				int mn = min(-x, y);
				ans += mn;
				y -= mn;
				x += mn;
			}

			if (z > 0)
			{
				int mn = min(-x, z);
				ans += 2 * mn;
				z -= mn;
				x += mn;

			}


		}
		while (y < 0)
		{
			if (x > 0)
			{
				int mn = min(-y, x);
				ans += mn * 2;
				y += mn;
				x -= mn;
			}

			if (z > 0)
			{
				int mn = min(-y, z);
				ans += mn;
				z -= mn;
				y += mn;

			}


		}
		while (z < 0)
		{

			if (x > 0)
			{
				int mn = min(-z, x);
				ans += mn;
				x -= mn;
				z += mn;
			}

			if (y > 0)
			{
				int mn = min(-z, y);
				ans += mn * 2;
				z += mn;
				y -= mn;

			}


		}
		cout << ans << endl;

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}