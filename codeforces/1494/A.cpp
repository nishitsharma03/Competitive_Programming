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
		string s;
		cin >> s;
		int n = s.length();
		int cnt[3] = {0};
		fab(0, n, i)
		{
			cnt[s[i] - 'A']++;

		}
		bool done = 0;
		if (cnt[0] + cnt[1] == cnt[2])
		{
			int val = 0;
			bool ok = 1;
			fab(0, n, i)
			{
				val += (s[i] == 'A' or s[i] == 'B');
				val -= (s[i] == 'C');
				if (val < 0)
				{
					ok = 0;
				}


			}
			done |= (ok and val == 0);
			ok = 1;
			val = 0;
			fab(0, n, i)
			{
				val -= (s[i] == 'A' or s[i] == 'B');
				val += (s[i] == 'C');
				if (val < 0)
				{
					ok = 0;
				}


			}
			done |= (ok and val == 0);
		}
		if (cnt[1] + cnt[2] == cnt[0])
		{
			int val = 0;
			bool ok = 1;
			fab(0, n, i)
			{
				val += (s[i] == 'C' or s[i] == 'B');
				val -= (s[i] == 'A');
				if (val < 0)
				{
					ok = 0;
				}


			}
			done |= (ok and val == 0);
			ok = 1;
			val = 0;
			fab(0, n, i)
			{
				val -= (s[i] == 'C' or s[i] == 'B');
				val += (s[i] == 'A');
				if (val < 0)
				{
					ok = 0;
				}


			}
			done |= (ok and val == 0);
		}
		if (cnt[0] + cnt[2] == cnt[1])
		{
			int val = 0;
			bool ok = 1;
			fab(0, n, i)
			{
				val += (s[i] == 'A' or s[i] == 'C');
				val -= (s[i] == 'B');
				if (val < 0)
				{
					ok = 0;
				}


			}
			done |= (ok and val == 0);
			ok = 1;
			val = 0;
			fab(0, n, i)
			{
				val -= (s[i] == 'A' or s[i] == 'C');
				val += (s[i] == 'B');
				if (val < 0)
				{
					ok = 0;
				}


			}
			done |= (ok and val == 0);
		}
		cout << (done ? "YES" : "NO") << endl;

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}