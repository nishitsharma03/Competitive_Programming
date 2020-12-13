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
int n, m;
const int N = 1e3 + 3;
ll dp[N][N];
int a[N], b[N];

ll  lcs( int i, int j)
{
	if (i < 0 or j < 0)
	{

		return i + j + 2;
	}
	if (dp[i][j] != -1)
		return dp[i][j];
	dp[i][j] = 1e9 + 2;



	dp[i][j] = min({lcs(i - 1, j - 1) + (a[i] != b[j]), lcs(i - 1, j) + 1, lcs(i, j - 1) + 1});

	return dp[i][j];
}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	cin >> n >> m;

	fab(0, n, i)
	cin >> a[i];
	fab(0, m, i)
	cin >> b[i];
	memset(dp, -1, sizeof(dp));
	cout << lcs(n - 1, m - 1) ;



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}