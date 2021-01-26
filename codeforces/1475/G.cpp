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

const int N = 2e5 + 4;
vector<int> fact[N];

void factors( ll n)
{
	vector<int> v ;


	for ( int i = 1; i <= sqrt(n); i++)
	{
		if (n % i == 0)
		{
			v.pb(i);
			if (n / i != i and i > 1)
				v.pb(n / i);

		}

	}

	fact[n] = v;

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
		int n;
		cin >> n;
		vector<ll> a(n);


		vector<int> dp(N, 0), freq(N, 0);

		int val = 0;
		fab(0, n, i)
		{
			cin >> a[i];
			freq[a[i]]++;
			val = max(val, freq[a[i]]);

		}

		sort(all(a));
		int ans = 0;
		fab(0, n, i)
		{
			if (fact[a[i]].size() == 0 and a[i] != 1)
				factors(a[i]);
			vector<int> v = fact[a[i]];
			sort(all(v));
			dp[a[i]] = freq[a[i]];
			for ( auto j : v)
				dp[a[i]] = max(dp[a[i]], dp[j] + freq[a[i]]);
		}
		fab(0, N, i)
		{
			val = max(val, dp[i]);
		}
		cout << n - val << endl;



	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}