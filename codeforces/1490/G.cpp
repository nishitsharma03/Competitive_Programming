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
		int n, m;
		cin >> n >> m;
		vector<ll> a(n);
		fab(0, n, i)
		cin >> a[i];

		set<pll> s;
		ll sum = 0;
		fab(0, n, i)
		{
			sum += a[i];
			s.insert({sum, i * 1LL});
		}
		map<ll, ll> qq;
		ll cnt = n;
		for (set<pll>::reverse_iterator i = s.rbegin(); i != s.rend(); i++)
		{
			cnt = min(cnt, i->se);
			qq[i->se] = cnt;


		}

		vector<ll> x(m);
		fab(0, m, i)
		{
			cin >> x[i];


			auto k = *s.rbegin();
			if (x[i] > k.f)
			{
				if (sum <= 0 )
				{
					cout << -1 << " ";
				}
				else
				{
					ll req = (x[i] - k.f + sum - 1) / sum;
					ll rem = ((x[i] - sum * req) ) ;
					// << "rem:" << rem << endl;

					auto p = s.lower_bound({rem, -1});

					p = s.lower_bound({rem, -1});

					//cout << "p::" << p->f << " " << p->se << endl;

					assert(p != s.end());

					ll ans = req * n + qq[p->se] ;
					cout << ans << " ";

				}

			}
			else
			{
				ll rem = x[i];
				auto p = s.lower_bound({rem, -1});
				assert(p != s.end());
				ll ans = qq[p->se] ;
				cout << ans << " ";


			}
		}
		cout << endl;


	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}