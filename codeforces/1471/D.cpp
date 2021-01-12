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
const int N = 1e6 + 5;

int primefac[N];
void getsmallestprimefactors()
{
	for ( ll i = 2; i < N; i++)
	{
		if (!primefac[i])
		{
			primefac[i] = i;
			for ( ll j = i * i; j < N; j += i)
			{
				if (!primefac[j])
					primefac[j] = i;
			}
		}
	}

}


ll getfactors(ll n)
{
	unordered_map<ll, ll> m;

	while (n > 1)
	{
		m[primefac[n]]++;
		n /= primefac[n];
	}

	ll val = 1;
	for (auto i : m)
	{
		if (i.se % 2)
		{
			val *= i.f;
		}
	}

	return val;
}



int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	getsmallestprimefactors();
	int pp = 0;
	while (t--)
	{
		ll n;
		cin >> n;
		ll a[n];
		fab(0, n, i)
		{
			cin >> a[i];
		}

		ll k[n];
		map<ll, ll> m;
		fab(0, n, i)
		{
			ll x = getfactors(a[i]);
			m[x]++;


		}
		ll bg = 0;
		ll val = 0;
		for (auto i : m)
		{


			bg = max(bg, i.se);
			val += (i.se % 2 ? 0LL : i.se);
			val += (i.f == 1 and i.se % 2 == 1 ? i.se : 0LL);
		}
		ll q;
		cin >> q;
		while (q--)
		{
			ll x;
			cin >> x;

			if (x == 0LL)
				cout << bg << endl;
			else
				cout << max(val, bg) << endl;
			pp++;

		}

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}