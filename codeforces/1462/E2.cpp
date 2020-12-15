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
const int N = 2e5 + 5;
ll fac[N], inv[N];
void precomp()
{
	fac[0] = 1;
	inv[0] = 1;
	fab(1, N, i)
	{
		fac[i] = mul(fac[i - 1], i);
		inv[i] = mod_inv(fac[i]);
	}
}

ll ncr(ll n, ll r)
{
	if (r > n)
	{
		return 0;
	}

	ll num = mul(fac[n], inv[r]);
	num = mul(num, inv[n - r]);
	return num;

}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	precomp();
	while (t--)
	{
		int n, m, k;
		cin >> n >> m >> k;
		vector<int> a(n);
		fab(0, n, i)
		cin >> a[i];
		sort(all(a));
		ll ans = 0;
		fab(0, n, i)
		{
			ll big = a[i] + k;
			ll ind = lower_bound(all(a), big + 1) - (a.begin() + i) ;
			//	cout << "i:" << i << " " << ind << endl;
			ans = add(ans, ncr(ind - 1, m - 1));


		}
		cout << ans << endl;

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}