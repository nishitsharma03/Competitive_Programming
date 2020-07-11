//#pragma GCC optimize "trapv"
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
const int N=1e5+5;
ll dp[N];

void precomp(int k)
{
	dp[0]=1;
	fab(1,N,i)
	{
		dp[i]=dp[i-1];
		if(i>=k)
			dp[i]=add(dp[i],dp[i-k]);
	}

fab(1,N,i)
{
	dp[i]=add(dp[i],dp[i-1]);
}


}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll t,k;
	cin>>t>>k;
	precomp(k);

	while(t--)
	{

		ll a,b;
		cin>>a>>b;
		cout<<sub(dp[b],dp[a-1])<<endl;


	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}