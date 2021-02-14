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

const int N = 5e6 + 5;
vector<int> prime(N);
vector<int> countPrime(N);
void precomp()
{

	prime[0] = prime[1] = 1;

	for (ll i = 2; i < N; i++)
	{
		if (!prime[i])
		{
			prime[i] = i;
			for (ll j = i * i; j < N; j += i)
			{
				if (!prime[j])
					prime[j] = i;

			}
		}
	}

}

int primefact( ll n)
{
	int cnt = 0;
	while (n > 1)
	{
		cnt++;
		n /= prime[n];

	}
	return cnt;
}


int main()
{	quick;
#ifndef ONLINE_JUDGE
	freopen("D:/sublime/input.txt", "r", stdin);
	freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t = 1;
	cin >> t;
	precomp();
	// fab(0, 25, i)
	// cout << prime[i] << " ";
	countPrime[1] = 1;
	fab(2, N, i)
	{
		countPrime[i] = primefact(i) + countPrime[i - 1];



	}

	while (t--)
	{
		ll a, b;
		cin >> a >> b;


		cout << countPrime[a] - countPrime[b] << endl;

	}


	cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}