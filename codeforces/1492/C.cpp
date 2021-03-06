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
	int tt = 1;
	//cin >> tt;
	while (tt--)
	{
		int n, m;
		cin >> n >> m;
		string s, t;
		cin >> s >> t;

		vector<int> suff(m + 1);
		int j = m - 1;
		for ( int i = n - 1; i >= 0 and j >= 0; i--)
		{
			if (s[i] == t[j])
			{
				suff[j] = i;
				j--;
			}

		}

		// vector<vector<int> > a(26);

		// fab(0, n, i)
		// {
		// 	a[s[i] - 'a'].pb(i);
		// }

		j = 0;
		int ans = 0;
		fab(0, n, i)
		{
			if (j == m)
			{
				break;
			}
			if (s[i] == t[j])
			{
				if (j + 1 < m)
				{
					//cout << "i:" << i << " " << suff[j + 1] << endl;
					ans = max(ans, suff[j + 1] - i);
				}
				j++;

			}

		}
		cout << ans << endl;




	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}