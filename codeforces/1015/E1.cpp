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
	//cin >> t;
	while (t--)
	{
		int n, m;
		cin >> n >> m;
		vector<vector<char> > a(n, vector<char> (m));
		fab(0, n, i)
		{
			fab(0, m, j)
			{
				cin >> a[i][j];
			}
		}

		vector<vector<char> > ans(n, vector<char> (m, '.'));
		vector<array<int, 3>> val;
		fab(0, n, i)
		{
			fab(0, m, j)
			{
				if (a[i][j] != '*')
				{
					continue;
				}

				int cnt = 1;

				while (i + cnt < n and i - cnt >= 0 and j + cnt < m and j - cnt >= 0 )
				{
					if (i + cnt < n and a[i + cnt][j] != '*')
						break;

					if (i - cnt >= 0 and a[i - cnt][j] != '*')
						break;
					if (j + cnt < m and a[i][j + cnt] != '*')
						break;

					if (j - cnt >= 0 and a[i][j - cnt] != '*')
						break;
					if (j - cnt >= 0)
						ans[i][j - cnt] = '*';
					if (i + cnt < n)
						ans[i + cnt][j] = '*';
					if (i - cnt >= 0)
						ans[i - cnt][j] = '*';
					if (j + cnt < m)
						ans[i][j + cnt] = '*';
					cnt++;

				}
				cnt--;

				if (cnt > 0)
				{
					ans[i][j] = '*';
					array<int, 3> op = { i + 1, j + 1, cnt};
					val.pb(op);
				}



			}
		}


		if (ans != a)
		{
			cout << -1 << endl;
			return 0;
		}
		else
		{
			cout << val.size() << endl;
			fab(0, val.size(), i)
			{
				fab(0, 3, j)
				{
					cout << val[i][j] << " ";
				}
				cout << endl;
			}
		}

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}