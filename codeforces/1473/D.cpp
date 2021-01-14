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
		string s;
		cin >> s;
		pair<int, int> pref[n];

		vector<int> plus, minus;
		int val[n];
		int cnt = 0;
		int sm = 0, bg = 0;
		fab(0, n, i)
		{
			if (s[i] == '+')
			{
				plus.pb(i);
			}
			else
				minus.pb(i);
			cnt += (s[i] == '+' ? 1 : -1);
			//cout << cnt << " ";
			val[i] = cnt;
			sm = min(sm, cnt);
			bg = max(bg, cnt);
			pref[i] = {sm, bg};

			if (i > 0)
			{
				pref[i].f = min(pref[i - 1].f, pref[i].f);
				pref[i].se = max(pref[i - 1].se, pref[i].se);
			}

		}

		pair<int, int> aux[n];
		aux[n - 1] = {0, 0};
		(s[n - 1] == '+' ? aux[n - 1].se++ : aux[n - 1].f--);
		for ( int i = n - 2; i >= 0; i--)
		{

			if (s[i] == '+')
			{
				aux[i] = aux[i + 1];
				aux[i].se = max(1, aux[i + 1].se + 1);
				if (aux[i].f < 0)
					aux[i].f++;

			}
			else
			{
				aux[i] = aux[i + 1];
				aux[i].f = min(-1, aux[i + 1].f - 1);
				if (aux[i].se > 0)
					aux[i].se--;
			}

			// aux[i] = aux[i - 1];


			// if (s[i - 1] == '-')
			// {
			// 	aux[i].f++;
			// 	if (aux[i].se > 0)
			// 		aux[i].se++;

			// }
			// else
			// {
			// 	aux[i].se--;
			// 	if (aux[i].f < 0)
			// 		aux[i].f--;
			// }



		}
		// fab(0, n, i)
		// {
		// 	cout << "aux:" << aux[i].f << " " << aux[i].se << endl;
		// }


		while (q--)
		{
			int l, r;
			cin >> l >> r;
			l -= 2;
			if (l < 0 and r == n)
			{
				cout << 1 << endl;
				continue;
			}

			if (l < 0)
			{
				cout << aux[r].se - aux[r].f + 1 << endl;
				continue;

			}
			auto k = pref[l];
			if (r < n)
			{
				k.se = max(k.se, val[l] + aux[r].se);

				k.f = min(k.f, val[l] + aux[r].f);
			}
			cout << k.se - k.f + 1 << endl;
		}

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}