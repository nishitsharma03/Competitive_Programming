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

using namespace std;

ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}

vector<int> dig = {0, 1, 5, -1, -1, 2, -1, -1, 8, -1};

int h, m;
bool isValid(int a, int b)
{
	return (a < h and b < m);
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
		cin >> h >> m;
		string s;
		cin >> s;
		//cout << "s:" << s << endl;
		string hr = "" , mn = "" ;
		hr += s[0];
		mn += s[3];
		hr += s[1];
		mn += s[4];
		//cout << "SSS" << hr << " " << mn << endl;
		int a = stoi(hr), b = stoi(mn);
		while (1)
		{
			//cout << "A" << a << " " << b << endl;
			int p = a;
			bool ok = 1;
			while (p)
			{
				int rem = p % 10;
				if (dig[rem] == -1)
				{
					ok = 0;
					break;
				}
				p /= 10;
			}

			p = b;
			while (p )
			{
				int rem = p % 10;
				if (dig[rem] == -1)
				{
					ok = 0;
					break;
				}
				p /= 10;

			}

			if (!ok)
			{
				if (b == m - 1)
				{
					b = 0;
					a++;
					a %= h;
				}

				else
					b++;
				continue;
			}

			int val = 0;
			p = b;
			int tr = 2;
			while (tr--)
			{
				int rem = p % 10;
				int pp = dig[rem];
				val *= 10;
				val += pp;
				p /= 10;

			}

			p = a;
			int get = 0;
			tr = 2;
			while (tr--)
			{
				int rem = p % 10;
				//cout << "rr" << rem << endl;
				int pp = dig[rem];
				get *= 10;
				get += pp;
				p /= 10;
			}
			//cout << "Va:" << val << " " << get << endl;

			ok &= (isValid(val, get));
			if (ok)
			{
				break;
			}

			if (b == m - 1)
			{
				b = 0;
				a++;
				a %= h;
			}

			else
				b++;





		}
		string hh = to_string(a), mm = to_string(b);
		if (hh.size() == 1)
			hh = '0' + hh;
		if (mm.size() == 1)
			mm = '0' + mm;

		cout << hh << ":" << mm << endl;

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}