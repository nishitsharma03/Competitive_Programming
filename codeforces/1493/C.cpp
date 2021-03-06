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
		int n, k;
		cin >> n >> k;
		string s;
		cin >> s;
		string ans ;

		if (n % k)
		{
			cout << -1 << endl;
			continue;
		}

		string a = s;
		vector<int> p(26);
		fab(0, n, i)
		{
			p[s[i] - 'a']++;

		}
		bool kk = 1;
		fab(0, 26, i)
		{
			kk &= (p[i] % k == 0);

		}
		if (kk)
		{
			cout << s << endl;
			continue;
		}
		vector<int> get(26);
		for ( int i = n - 1; i >= 0; i--)
		{
			int pos = s[i] - 'a';
			p[pos]--;

			int can = n  - i;
			bool ok = 0;
			for ( int j = pos; j < 26; j++)
			{
				ok |= (get[j]);


			}

			int need = 0;
			int newpos = -1;
			for ( int j = 0; j < 26; j++)
			{
				if (p[j] % k)
				{
					need += (k - p[j] % k);
					if (j > pos and newpos == -1 )
					{
						newpos = j;
					}
				}

			}

			if (need > can)
			{
				continue;
			}
			if (pos == 25)
			{
				continue;
			}

			//cout << "can:" << i << " " << can << " " << need << endl;

			ans = s.substr(0, i );
			//cout << "ans:" << ans << endl;
			bool done = 0;
			for ( int j = pos + 1; j < 26; j++)
			{
				int val = need;
				if (p[j] % k)
				{
					val -= (k - p[j] % k);


				}
				p[j]++;
				if (p[j] % k)
					val += (k - p[j] % k);

				//cout << "ppppp:" << val << " " << can << endl;

				if (val <= can)
				{
					//assert((val - can) % k == 0);

					ans += char('a' + j);

					//cout << "anS:" << ans << endl;
					//cout << "van" << can << " " << val << endl;
					int div = (can - val - 1) / k;
					//cout << "dic:" << div << endl;
					fab(0, div, pp)
					ans += string(k, 'a');

					for ( int j = 0; j < 26; j++)
					{
						//cout << "p[j]:" << j << " " << p[j] << endl;
						if (p[j] % k == 0)
						{
							continue;
						}

						int req = (k - p[j] % k);
						ans += string(req, char('a' + j));
					}
					done = 1;
					break;


				}


				p[j]--;

			}
			if (done)
				break;


		}
		cout << ans << endl;

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}