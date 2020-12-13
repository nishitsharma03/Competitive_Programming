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
	int n, m;
	cin >> n >> m;
	vector<int> v;

	fab(0, m, i)

	{
		int x;
		cin >> x;

		v.pb(x);
	}
	if (m == 0)
	{
		cout << 1 << endl;
		return 0;
	}
	int gg = *min_element(all(v));
	int og = *max_element(all(v));
	if (og != n)
		v.pb(n + 1);
	if (gg != 1)
		v.pb(0);
	sort(all(v));

	int sm = 1e9 + 2;
	fab(1, v.size(), i)
	{
		if (v[i] - v[i - 1] - 1 > 0)
			sm = min(sm, v[i] - v[i - 1] - 1);
	}

	//cout << "Sm:" << sm << endl;
	ll ans = 0;
	if (sm == 0)
	{
		cout << 0 << endl;
		return 0;
	}
	fab(1, v.size(), i)
	{
		ans += (v[i] - v[i - 1] - 1 + sm - 1) / sm;
	}
	cout << ans << endl;


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}