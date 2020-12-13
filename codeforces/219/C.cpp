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
	int n, k;
	cin >> n >> k;
	string s;
	cin >> s;

	ll dp[n][k];
	for ( int i = 0; i < k; i++)
	{
		dp[0][i] = (('A' + i) != s[0]);
		//cout << "i:" << i << " " << dp[0][i] << endl;
	}

	for ( int i = 1; i < n; i++)
	{
		int sm = 1e9 + 2;
		int cnt = 0;
		vector<pair<int, int> > v(k);
		fab(0, k, j)
		{
			v[j] = {(dp[i - 1][j]), j};
		}

		sort(all(v));
		fab(0, k, j)
		{

			int val = ((j == v[0].se) ? v[1].f : v[0].f);

			dp[i][j] = val + (s[i] != ('A' + j));
			//cout << dp[i][j] << " (" << *st.begin() << ") ";

			//cout << dp[i][j] << " ";


		}
		//cout << endl;
	}

	ll ans = INT_MAX;
	fab(0, k, i)
	ans = min(ans, dp[n - 1][i]);
	cout << ans << endl;


	string op = "";
	for ( int i = n - 1; i >= 0; i--)
	{
		for ( int j = 0; j < k; j++)
		{
			if (dp[i][j] == ans and (op.size() == 0 or op.back() != ('A' + j)))
			{
				op += ('A' + j);
				ans -= (s[i] != ('A' + j));
				break;
			}
		}
	}
	reverse(all(op));
	cout << op << endl;

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}