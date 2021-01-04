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
//#define endl "\n"
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
	int t;
	cin >> t;
	while (t--)
	{
		int n;
		cin >> n;
		vector <  pair<int, int > > v(n), b(n);
		int h[n], w[n];
		// height
		vector<pair<int, int> >  a(n);
		//weight
		vector<pair<int, int> > k(n);
		fab(0, n, i)
		{
			cin >> v[i].f >> v[i].se;
			h[i] = v[i].f;
			w[i] = v[i].se;
			v[i].se = i;
			b[i] = v[i];
			b[i].f = w[i];
		}
		sort(all(b));
		sort(all(v));

		vector < pair<int, int> > minh(n, mp(1e9 + 2, 1e9 + 2)), minw(n, mp(1e9 + 2, 1e9 + 2));
		// cout << "sorted by height" << endl;
		// fab(0, n, i)
		// {
		// 	cout << v[i].f.f << " " << v[i].se << endl;
		// }
		// cout << "sorted by weight" << endl;
		// fab(0, n, i)
		// {
		// 	cout << b[i].f.f << " " << b[i].se << endl;
		// }
		fab(0, n, i)
		{
			int ind = v[i].se;
			a[i].f = w[ind] ;
			a[i].se = ind;
			minh[i] = a[i];
			if (i > 0)
			{
				minh[i] = min(minh[i - 1], minh[i]);
			}
			ind = b[i].se;
			k[i].f = h[ind];
			k[i].se = ind;
			minw[i] = k[i];
			if (i > 0)
			{
				minw[i] = min(minw[i - 1], minw[i]);
			}
		}
		// fab(0, n, i)
		// {
		// 	cout << k[i].f << " " << k[i].se << endl;
		// }

		for ( int i = 0; i < n; i++)
		{
			int hh = h[i];
			//cout << "i:" << i << endl;
			//cout << "hh:" << hh << " " << w[i] << endl;
			int ind = lower_bound(all(v), mp(h[i], -1)) - v.begin() - 1;
			if (ind >= 0)
			{	auto val = minh[ind];
				//cout << "ind:" << ind << " " << val.f << " " << val.se << endl;
				if (val.f < w[i])
				{
					cout << val.se + 1 << " ";
					continue;
				}
			}
			int ww = w[i];
			ind = lower_bound(all(v), mp(w[i], -1)) - v.begin() - 1;
			if (ind >= 0)

			{
				auto val = minh[ind];
				//cout << "ind2:" << ind << " " << val.f << endl;
				if (val.f < h[i])
				{
					cout << val.se + 1 << " ";
					continue;
				}
			}
			cout << -1 << " ";
			//cout << endl;


		}
		cout << endl;




	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}