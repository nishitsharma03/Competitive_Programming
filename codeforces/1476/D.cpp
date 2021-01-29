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
const int N = 3e5 + 50;
ll dp[N][2], dp2[N][2];
int n;
string s;
char toggle(char a)
{
	if (a == 'L')
		return 'R';
	return 'L';
}

ll rec(int ind, int par)
{
	if (ind == n)
		return dp[ind][par] = 1;

	if (dp[ind][par] != -1)
		return dp[ind][par];
	char p = s[ind];
	if (par == 1)
	{
		p = toggle(p);

	}
	// if (ind > 0)
	// {
	// 	char op = s[ind - 1];
	// 	if (par == 1)
	// 	{
	// 		op = toggle(op);

	// 	}
	// 	if (op == 'L')
	// 	{
	// 		dp[ind][par] = 0;

	// 	}

	// }

	if (p == 'L')
	{
		dp[ind][par] = 1;
	}
	else
	{
		dp[ind][par] = 1 + rec(ind + 1, 1 ^ par);
	}
	return dp[ind][par];

}


ll go( int ind, int par)
{
	if (ind < 0)
		return 0;
	if (dp2[ind][par] != -1)
		return dp2[ind][par];
	if (ind == 0)
	{
		return dp2[ind][par] = 1;
	}

	char p = s[ind - 1];
	char c = s[ind];
	if (par == 1)
	{
		p = toggle(p);
		c = toggle(c);

	}
	if (p == 'L')
	{
		ll val = 1 + go(ind - 1, 1 ^ par);
		//cout << "ind:" << ind << " " << par << " " << val << endl;
		dp2[ind][par] = val;
		// if (c == 'R')
		// 	dp2[ind][par] = val;
		// else
		// 	dp2[ind][par] = val;

	}
	else
	{
		dp2[ind][par] = 1;
	}

	return dp2[ind][par];


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
		cin >> s;
		fab(0, n + 4, i)
		{
			dp[i][0] = -1;
			dp[i][1] = -1;
			dp2[i][0] = -1;
			dp2[i][1] = -1;
		}

		fab(0, n + 1, i)
		{
			rec(i, 0);
			go(i, 0);
		}

		// fab(0, n + 1, i)
		// {
		// 	cout << dp[i][0] << " " << dp2[i][0] << endl;
		// }

		fab(0, n + 1, i)
		{
			cout << dp2[i][0] + dp[i][0] - 1 << " ";
		}
		cout << endl;

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}