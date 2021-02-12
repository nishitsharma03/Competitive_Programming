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
vector<int> fac(ll n)
{
	vector<int> v;
	fab(2, sqrt(n) + 1, i)
	{
		if (n % i == 0)
		{
			v.pb(i);
			if (n / i != i)
			{
				v.pb(n / i);
			}
		}
	}
	return v;
}

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
		ll a, b;
		cin >> a >> b;
		//vector<int> f = fac(b);
		//for (auto i : f)
		//	cout << i << " ";
		//cout << endl;
		// if (b <= 10000)
		// {	ll ans = 0;
		// 	fab(2, b + 1, i)
		// 	{
		// 		ll den = a / i;
		// 		//cout << "i:" << i << " " << min(i - 1LL, (a / i) - (den * i + den > a)) << endl;
		// 		ans += min(i - 1LL, (a / i) - (den * i + den > a));
		// 	}
		// 	cout << ans << endl;
		// }
		// else
		{
			ll ans = 0;
			ll pt = -1;
			fab(2, b + 1, i)
			{
				ll den = a / i;
				ll val = min(i - 1LL, (a / i) - (den * i + den > a)) ;
				if (val != i - 1)
				{
					pt = i - 1;
					break;
				}
				ans += min(i - 1LL, (a / i) - (den * i + den > a));
			}
			//cout << "pt:" << pt << endl;

			for ( ll i = 1; i <= pt; i++)
			{
				ll h = b, l = pt + 1;
				ll val = pt;

				while (l <= h)
				{
					ll mid = (l + h) / 2;
					ll den = mid / i ;
					ll pp = (mid * i + i);

					//cout << "mid:" << mid << " " << den << endl;
					if (pp <= a)
					{
						l = mid + 1;
						val = mid;
					}
					else
						h = mid - 1;
				}
				//cout << "i:" << i << " " << val << endl;
				ans += (val - pt);


			}
			cout << ans << endl;

		}
	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}
/*i:2 1
i:3 2
i:4 3
i:5 4
i:6 5
i:7 6
i:8 7
i:9 6
i:10 6
i:11 5
i:12 5
i:13 4
i:14 4
i:15 4
i:16 4
i:17 3
i:18 3
i:19 3
i:20 3
i:21 3
i:22 3
i:23 2
i:24 2
i:25 2
i:26 2
i:27 2
i:28 2
i:29 2
i:30 2
i:31 2
i:32 2
i:33 2
i:34 1
i:35 1
i:36 1
i:37 1
i:38 1
i:39 1
i:40 1
i:41 1
i:42 1
i:43 1
i:44 1
i:45 1
i:46 1
i:47 1
i:48 1
i:49 1
i:50 1
i:51 1
i:52 1
i:53 1
i:54 1
i:55 1
i:56 1
i:57 1
i:58 1
i:59 1
i:60 1
i:61 1
i:62 1
i:63 1
i:64 1
i:65 1
i:66 1
i:67 1
i:68 1
i:69 0*/