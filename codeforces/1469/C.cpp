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
		ll n, k;
		cin >> n >> k;
		ll a[n];
		fab(0, n, i)
		{
			cin >> a[i];

		}
		ll prev = a[0] + k;
		vector<ll > pos(n);
		pos[0] = prev;
		bool ok = 1;
		fab(1, n - 1, i)
		{

			if (a[i + 1] > a[i])
			{
				pos[i] = (prev + k - 1 );
				if (pos[i] > a[i] + k - 1 + k)
				{
					pos[i] = a[i] + k - 1 + k;
				}
				if (pos[i] - k < a[i])
				{
					pos[i] = a[i] + k;
				}


			}
			else
			{
				pos[i] = (prev - k + 1 );
				if (pos[i] > a[i] + k - 1 + k)
				{
					pos[i] = a[i] + k - 1 + k;
				}
				if (pos[i] - k < a[i])
				{
					pos[i] = a[i] + k;
				}
			}
			prev = pos[i];

		}

		pos[n - 1] = a[n - 1] + k;

		fab(0, n - 1, i)
		{
			if (abs(pos[i] - pos[i + 1]) >= k or pos[i] - k < a[i] or pos[i] - k > a[i] + k - 1)
			{

				ok = 0;
			}
		}
		cout << (ok ? "Yes" : "No") << endl;
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}