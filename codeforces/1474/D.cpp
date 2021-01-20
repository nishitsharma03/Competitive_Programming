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

bool fun(vector<ll> a)
{
	bool ok = 1;
	int n = a.size();

	fab(0, n - 1, j)
	{
		if (a[j + 1] < a[j] or a[j] == -1)
			return false;
		a[j + 1] -= a[j];
		a[j] = 0;
	}
	fab(0, n, j)
	{
		ok &= (a[j] == 0);

	}

	return ok;
}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vll a(n) ;
		fab(0, n, i)
		{
			cin >> a[i];
		}
		if (fun(a))
		{
			cout << "YES" << endl;
			continue;

		}

		vector<ll> pref(n), suff(n);
		pref[0] = a[0];
		ll curr = a[0];
		for ( int i = 1; i < n; i++)
		{
			ll rem = a[i] - curr;
			if (pref[i - 1] == -1 or curr > a[i])
				pref[i] = -1;
			else
				pref[i] = rem;
			curr = rem;

		}

		suff[n - 1] = a[n - 1];
		curr = a[n - 1];
		for ( int i = n - 2; i >= 0; i--)
		{
			ll rem = a[i] - curr;
			if (suff[i + 1] == -1 or curr > a[i])
				suff[i] = -1;
			else
				suff[i] = rem;
			curr = rem;


		}

		bool ok = 0;

		for ( int i = 0; i < n - 1; i++)
		{
			vector<ll> temp;
			if (i > 0)
				temp.pb(pref[i - 1]);
			temp.pb(a[i + 1]);
			temp.pb(a[i]);
			if (i + 2 < n)
				temp.pb(suff[i + 2]);
			if (fun(temp))
			{	ok = 1;
				break;
			}

		}
		cout << (ok ? "YES" : "NO") << endl;
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}