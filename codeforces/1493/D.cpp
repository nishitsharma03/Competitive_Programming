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
const int N = 2e5 + 5;
multiset<int> v[N];
map<int, int> m[N];
int primefac[N];
void getsmallestprimefactors()
{
	primefac[1] = 1;
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

map<int, int> temp;

void getprimefactors(int n, int i)
{
	//	Use this to get the result in a map.
	// map<int,int> fac;


	while (n > 1)
	{
		//	Use this when using a map
		//fac[primefac[n]]++;

		m[i][primefac[n]]++;
		n /= primefac[n];

	}

}

void fun(int n)
{
	while (n > 1)
	{
		//	Use this when using a map
		//fac[primefac[n]]++;

		temp[primefac[n]]++;
		n /= primefac[n];

	}

}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t = 1;
	//cin >> t;
	getsmallestprimefactors();
	while (t--)
	{
		int n, q;
		cin >> n >> q;

		vector<ll> a(n);
		ll gc = 0;
		fab(0, n, i)
		{
			cin >> a[i];
			gc = __gcd(a[i], gc);
			getprimefactors(a[i], i);
		}

		fab(0, n, i)
		{
			for (auto j : m[i])
			{
				//cout << ":SDA" << j.f << " " << j.se << endl;
				v[j.f].insert(j.se);

			}
		}

		// fab(2, 13, i)
		// {
		// 	for ( auto l : v[i])
		// 	{
		// 		cout << l << " ";
		// 	}
		// 	cout << endl;

		// }

		while (q--)
		{
			ll x;
			int ind;
			cin >> ind >> x;
			ind--;
			temp.clear();
			fun(x);

			for (auto j : temp)
			{
				//cout << "j.f<" << j.f << " " << j.se << endl;
				if (m[ind].find(j.f) != m[ind].end())
				{
					if (v[j.f].size() == n)
					{
						gc = mul(gc, mod_inv(power(j.f, *v[j.f].begin())));
					}
					v[j.f].erase(v[j.f].find(m[ind][j.f]));
					m[ind][j.f] += j.se;
					v[j.f].insert(m[ind][j.f]);
					if (v[j.f].size() == n)
					{
						gc = mul(gc, power(j.f, *v[j.f].begin()));
					}

				}
				else
				{
					// cout << "set:" << j.f << endl;
					// for (auto i : v[j.f])
					// {
					// 	cout << i << " ";

					// }
					// cout << endl;
					m[ind][j.f] = j.se;
					v[j.f].insert(j.se);
					// cout << "set2:" << j.f << endl;
					// for (auto i : v[j.f])
					// {
					// 	cout << i << " ";

					// }
					// cout << endl;


					if (v[j.f].size() == n)
					{
						gc = mul(gc, power(j.f, *v[j.f].begin()));
					}

				}
			}

			cout << gc << endl;




		}


	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}