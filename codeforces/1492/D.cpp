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

void go(int a, int b, int k)
{
	string s = "", t = "";
	int rem = a - k ;
	fab(0, rem, i)
	{
		s += '0';
		t += '0';
	}
	t += '1';
	fab(0, k, i)
	{	s += '0';
		t += '0';
	}
	s += '1';
	b--;
	fab(0, b, i)
	{
		s += '1';
		t += '1';
	}
	reverse(all(s));
	reverse(all(t));
	cout << "Yes" << endl;
	cout << s << endl << t << endl;
}

int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int a, b, k;
	cin >> a >> b >> k;
	int qq = a + b;
	if (k == 0)
	{
		string s = "";
		fab(0, b, i)
		s += '1';
		fab(0, a, i)
		s += '0';
		cout << "Yes" << endl;
		cout << s << endl << s << endl;
		return 0;

	}
	if (a == 0)
	{
		cout << "No" << endl;
		return 0;
	}

	if ((a + b - 2) < k or (b == 1))
	{
		cout << "No";
		return 0;
	}
	if (a >= k)
	{
		go(a, b, k);
		return 0;
	}
	string s = "", t = "";
	int rem = k - a ;
	s += '0';
	t += '1';
	fab(0, rem, i)
	{
		s += '1';
		t += '1';
	}
	fab(0, a - 1, i)
	{
		s += '0';
		t += '0';

	}
	b -= rem;

	t += "0";
	s += "1";
	b--;
	fab(0, b, i)
	{
		s += '1';
		t += '1';
	}

	reverse(all(s));
	reverse(all(t));
	assert(s.length() == t.length() and s.length() == qq );
	cout << "Yes" << endl;
	cout << s << endl << t << endl;

	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}