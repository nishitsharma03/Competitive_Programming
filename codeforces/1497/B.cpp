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

		vector<int> b(m);
		vector<int> a(n);


		fab(0, n, i)
		{
			cin >> a[i];
			b[a[i] % m]++;
		}

		ll ans = 0;
		if (b[0])
			ans++;
		fab(1, (m + 1) / 2 , i)
		{
			int req = m - i;

			int vl = min(b[i], b[req]);
			//cout << "i:" << i << " " << vl << endl;

			//cout << "re:" << req << " " << b[i] << " " << b[req] << endl;
			b[i] -= vl;
			b[req] -= vl;


			if (vl)
				ans++;
			//cout << "bb:" << b[i] << " " << b[req] << endl;
			ans += b[i];
			ans += b[req];
			if ((b[i] or b[req]) and vl > 0)
				ans--;


//			cout << "ans:" << ans << endl;

		}
		if (m % 2 == 0 and b[m / 2])
			ans++;
		cout << ans << endl;
	}



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}