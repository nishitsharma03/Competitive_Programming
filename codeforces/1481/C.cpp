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
const int N = 1e5 + 5;
vector<int> v[N], alt[N];

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
		fab(0, n + 1, i)
		{
			v[i].clear();
			alt[i].clear();

		}

		ll a[n], b[n], c[m];
		fab(0, n, i)
		{
			cin >> a[i];

		}

		unordered_map<int, int> mo, pp;
		set<int> av;
		fab(0, n, i)
		{
			cin >> b[i];
			if (a[i] != b[i])
			{
				v[b[i]].pb(i + 1);
				mo[i + 1] = 1;
				//av.insert(i + 1);

			}
			else
				alt[b[i]].pb(i + 1);

		}
		bool ok = 1;
		vector<int> ans;
		vector<int> cnt(n + 2);
		fab(0, m, i)
		{
			cin >> c[i];
			cnt[c[i]]++;
			pp[c[i]] = i ;


		}
		vector<int> le(n + 2);
		set < pll> s;
		int avai = -1;
		fab(1, n + 1, i)
		{
			ok &= (cnt[i] >= v[i].size());

		}
		//fab(0, m, i)
		for ( int i = m - 1; i >= 0; i--)
		{
			if (v[c[i]].empty())
			{
				if (alt[c[i]].empty())
				{

					if (av.size())
					{
						ans.pb(*av.begin());

					}
					else
					{
						ok = 0;
						break;
					}

				}
				else
				{
					ans.pb(alt[c[i]].back());
					av.insert(alt[c[i]].back());
				}
			}
			else
			{
				int x = v[c[i]].back();
				av.insert(x);
				a[x - 1] = c[i];
				v[c[i]].pop_back();
				ans.pb(x);
				alt[c[i]].pb(x);


			}
		}
		reverse(all(ans));
		fab(0, n, i)
		ok &= (a[i] == b[i]);

		cout << (ans.size() == m and ok ? "YES" : "NO") << endl;
		if (ans.size() == m and ok)
		{
			fab(0, m, i)
			cout << ans[i] << " ";

			cout << endl;
		}


	}



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}