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
	string a, b;
	cin >> a >> b;
	int k;
	cin >> k;
	int cnt = 0, op = 0;
	int n = a.length();
	for ( int i = 0; i < n; i++)
	{
		string temp = a.substr(i, n - i);
		temp += a.substr(0, i);
		if (temp == b)
		{
			cnt++;
		}
		else
			op++;
	}

	//cout << "cnt:" << cnt << " " << op << endl;
	ll dp[k + 1][2];
	memset(dp, 0, sizeof(dp));
	dp[0][(a == b)] = 1;

	fab(1, k + 1, i)
	{
		dp[i][1] = add(mul(dp[i - 1][0], cnt), mul(dp[i - 1][1], cnt - 1));

		dp[i][0] = add(mul(dp[i - 1][1], op), mul(dp[i - 1][0], op - 1));
	}
	cout << dp[k][1] << endl;



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}