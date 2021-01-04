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
		int n;
		cin >> n;
		int a[n];
		multiset<ll, greater<ll> > o, e;
		fab(0, n, i)
		{
			cin >> a[i];
			if (a[i] % 2)
			{
				o.insert(a[i]);
			}
			else
				e.insert(a[i]);
		}

		ll s1 = 0, s2 = 0;
		int turn = 1;
		while (o.size() or e.size())
		{
			if (o.empty() )
			{
				if (turn)
					s1 += *e.begin();
				e.erase(e.begin());

			}
			else if (e.empty())
			{
				if (!turn)
					s2 += *o.begin();
				o.erase(o.begin());
			}
			else
			{

				if (*o.begin() > *e.begin())
				{
					if (!turn)
						s2 += *o.begin();
					o.erase(o.begin());

				}
				else
				{
					if (turn)
						s1 += *e.begin();
					e.erase(e.begin());

				}
			}

			turn = 1 - turn;


		}

		//cout << "sss:" << s1 << " " << s2 << endl;
		if (s1 == s2)
		{
			cout << "Tie" << endl;
		}
		else if (s1 > s2)

		{
			cout << "Alice" << endl;
		}
		else
		{
			cout << "Bob" << endl;
		}

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}