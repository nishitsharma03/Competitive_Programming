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
	int t;
	cin >> t;
	while (t--)
	{
		int n, q;
		cin >> n >> q;
		vector<int> a(n);
		fab(0, n, i)
		cin >> a[i];
		map<ll, ll> m;

		ll sum = 0;
		sort(all(a));
		vector<ll> pref(n);
		pref[0] = a[0];
		fab(1, n, i)
		{
			pref[i] += pref[i - 1] + a[i];
		}

		m[pref[n - 1]]++;
		for (auto i : m)
		{
			sum += (i.f * i.se);
		}

		queue<pair<int, int> > p;
		p.push({0, n - 1});

		while (!p.empty())
		{
			auto k = p.front();
			p.pop();
			if ( k.f > k.se)
				continue;
			if (k.f == k.se)
			{
				m[a[k.f]]++;
			}

			int l = k.f, r = k.se;
			int mid = (a[l] + a[r]) / 2;
			//cout << "l:" << l << " " << r << " " << mid << endl;
			int ind = lower_bound(all(a), mid + 1) - a.begin();
			//cout << "ind:" << ind << endl;
			if (ind > r )
			{
				//cout << "aaa" << pref[r] - (l > 0 ? pref[l - 1] : 0) << endl;
				m[pref[r] - (l > 0 ? pref[l - 1] : 0)]++;
				continue;
			}
			ll left = (ind > 0 ? pref[ind - 1] : 0) - (l > 0 ? pref[l - 1] : 0);
			ll right = pref[r] - (ind > 0 ? pref[ind - 1] : 0);
			if (left > 0)
			{
				m[left]++;
				p.push({l, ind - 1});
			}
			if (right > 0)
			{
				m[right]++;
				p.push({ind, r});
			}
		}




		while (q--)
		{
			ll req;
			cin >> req;
			if (m.find(req) != m.end())
			{
				cout << "Yes" << endl;
			}
			else
				cout << "No" << endl;

		}



	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}