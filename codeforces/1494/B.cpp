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

int a[4];
int n;
// bool go(int i, vector<int>&v )
// {
// 	if (i >= 4)
// 	{
// 		return true;
// 	}
// 	if (a[v[i]] < 0)
// 	{
// 		return 0;
// 	}
// 	bool ok = 0;
// 	if (a[i] == n - 1)
// 	{
// 		a[(i + 1) % 4]--;
// 		ok |= (go(i + 1, v));
// 		a[(i + 1) % 4]++;
// 	}

// }

// bool fun(int i)
// {
// 	if (i >= 4)
// 		return true;
// 	if (a[i] == n - 1)
// 	{

// 	}
// }

bool go( int ind, vector<vector<int>> &v)

{
	if (ind >= 4)
	{

		fab(0, n, i)
		{
			fab(0, n, j)
			{
				cout << v[i][j] << " ";
			}
			cout << endl;
		}
		int cnt = 0;
		fab(0, n, i)
		{
			cnt += (v[0][i] == 1);
		}
		if (cnt != a[0])
			return false;
		cnt = 0;
		fab(0, n, i)
		{
			cnt += (v[i][n - 1] == 1);
		}
		if (cnt != a[1])
			return false;
		cnt = 0;
		fab(0, n, i)
		{
			cnt += (v[n - 1][i] == 1);

		}
		if (cnt != a[2])
			return false;
		cnt = 0;
		fab(0, n, i)
		{
			cnt += (v[i][0] == 1);
		}
		if (cnt != a[3])
			return false;
		return true;

	}

	bool ok = 0;
	if (ind == 0)
	{
		fab(0, a[ind], i)
		{
			v[0][i] = 1;

		}
		int j = a[ind];
		ok |= go(ind + 1, v);
		while (j < n)
		{
			v[0][j - a[ind]] = 0;
			v[0][j] = 1;
			ok |= go(ind + 1, v);
			j++;
		}
	}
	else if (ind == 1)
	{
		fab(0, a[ind], i)
		{
			v[i][n - 1] = 1;

		}
		int j = a[ind];
		ok |= go(ind + 1, v);
		while (j < n)
		{
			v[j - a[ind]][n - 1] = 0;
			v[j][n - 1] = 1;
			ok |= go(ind + 1, v);
			j++;
		}

	}
	else if (ind == 2)
	{
		fab(0, a[ind], i)
		{
			v[n - 1][i] = 1;

		}
		int j = a[ind];
		ok |= go(ind + 1, v);
		while (j < n)
		{
			v[n - 1][j - a[ind]] = 0;
			v[n - 1][j] = 1;
			ok |= go(ind + 1, v);
			j++;
		}
	}
	else if (ind == 3)
	{
		fab(0, a[ind], i)
		{
			v[i][0] = 1;

		}
		int j = a[ind];
		ok |= go(ind + 1, v);
		while (j < n)
		{
			v[j - a[ind]][0] = 0;
			v[j][0] = 1;
			ok |= go(ind + 1, v);
			j++;
		}


	}

	return ok;



}

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
		cin >> n;
		int u, r, d, l;
		fab(0, 4, i)
		{
			cin >> a[i];
		}
		// vector<int> v = {0, 1, 2, 3};
		bool ok = 0;
		// if (a[0] < 2 and a[1] == n and a[3] == n )
		// {
		// 	ok = 0;


		// }
		// if (a[1] < 2 and a[0] == n and a[2] == n)
		// {
		// 	ok = 0;
		// }
		// if (a[2] < 2 and a[1] == n and a[3] == n)
		// {
		// 	ok = 0;
		// }
		// if (a[3] < 2 and a[0] == n and a[3] == n)
		// {
		// 	ok = 0;

		// }

		// /////
		// if (a[0] < 2 and (a[1] == n or a[3] == n) )
		// {
		// 	ok = 0;


		// }
		// if (a[1] < 1 and (a[0] == n or a[2] == n))
		// {
		// 	ok = 0;
		// }
		// if (a[2] < 1 and (a[1] == n or a[3] == n))
		// {
		// 	ok = 0;
		// }
		// if (a[3] < 1 and (a[0] == n or a[3] == n))
		// {
		// 	ok = 0;

		// }

		// if (a[0] == n - 1 and a[1] == 0 and a[3] == 0)
		// {
		// 	ok = 0;
		// }
		// if (a[1] == n - 1 and a[0] == 0 and a[2] == 0)
		// {
		// 	ok = 0;
		// }
		// if (a[2] == n - 1 and a[1] == 0 and a[3] == 0)
		// {
		// 	ok = 0;
		// }
		// if (a[3] == n - 1 and a[0] == 0 and a[2] == 0)
		// {
		// 	ok = 0;
		// }
		// if (a[0] <= 1 and a[2] == 0 and a[1] == n - 1 and a[3] == n - 1)
		// {
		// 	ok = 0;
		// }
		// if (a[1] <= 1 and a[0] == n - 1 and a[2] == n - 1 and a[3] == 0)
		// {
		// 	ok = 0;
		// }
		// if (a[2] <= 1 and a[1] == n - 1 and a[3] == n - 1 and a[0] == 0)
		// {
		// 	ok = 0;
		// }
		// if (a[3] <= 1 and a[0] == n - 1 and a[2] == n - 1 and a[1] == 0)
		// 	ok = 0;

		vector<vector<int>> v(n, vector<int> (n));

		// ok = go(0, v);
		// do
		// {
		// 	bool done = 1;

		// 	fab(0, 4, i)
		vector<pair<int, int> > pp = {{0, 0}, {0, n - 1}, {n - 1, n - 1}, {n - 1, 0}};

		fab(0, (1 << 4), i)
		{
			fab(0, 4, j)
			{
				v[pp[j].f][pp[j].se] = 0;

			}
			fab(0, 4, j)
			{
				if (i & (1 << j))
				{
					v[pp[j].f][pp[j].se] = 1;


				}
			}
			// cout << "i:" << i << endl;
			// fab(0, n, i)
			// {
			// 	fab(0, n, j)
			// 	{
			// 		cout << v[i][j] << " ";

			// 	}
			// 	cout << endl;
			// }
			// cout << endl;

			int cnt = v[0][0] + v[0][n - 1];
			int rem = a[0] - cnt;
			if (rem > n - 2 or cnt > a[0])
			{
				continue;
			}
			cnt = v[0][n - 1] + v[n - 1][n - 1];
			rem = a[1] - cnt;
			if (rem > n - 2 or cnt > a[1])
			{
				continue;
			}
			cnt = v[n - 1][n - 1] + v[n - 1][0];
			rem = a[2] - cnt;
			if (rem > n - 2 or cnt > a[2])
			{
				continue;
			}
			cnt = v[n - 1][0] + v[0][0];
			rem = a[3] - cnt;
			if (rem > n - 2 or cnt > a[3])
			{
				continue;
			}
			ok = 1;
		}



		// } while (next_permutation(all(v)));
		cout << (ok ? "YES" : "NO") << endl;
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}