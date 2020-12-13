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
const int N = 3e5 + 5;
int seg[2 * N];
int a[N];
int n;
//!-------- CAUTION this Tree works for [l,r) .... mind the open interval on r -------!
void build( )
{
	fab(0, n, i)
	{
		seg[i + n] = a[i];
	}
	for ( int i = n - 1; i > 0; i--)
	{
		seg[i] = (seg[2 * i] ^ seg[2 * i + 1]);
	}

}

void update( int ind , int val)
{
	ind += n;
	seg[ind] ^= val;

	for ( ; ind > 1; ind >>= 1)
	{
		seg[ind >> 1] = (seg[ind] ^ seg[ind ^ 1]);
	}
}
//!-------- CAUTION this function works for [l,r) .... mind the open interval on r -------!
int query(int l, int r)
{
	l += n;
	r += n;
	int ans = 0;
	while (l < r)
	{
		if (l % 2)
		{
			ans = (ans ^ seg[l]);
			l++;
		}
		if (r % 2)
		{
			--r;
			ans = (ans ^ seg[r]);
		}
		l >>= 1;
		r >>= 1;
	}

	return ans;

}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif

	int q;
	cin >> n >> q;
	fab(0, n, i)
	cin >> a[i];
	build();
	while (q--)
	{
		int l, r;
		int type;
		cin >> type;

		cin >> l >> r;
		if (type == 1)
		{
			update(l - 1, r);
		}
		else
		{
			cout << query(l - 1, r) << endl;
		}

	}



	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}