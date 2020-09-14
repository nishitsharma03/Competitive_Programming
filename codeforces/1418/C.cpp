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
const int N=2e5+5,INF=1e9+5;
int a[N];
int dp[N][2];
int n;
int  recurse( int pos,int turn)
{

	if(pos>=n)
		return 0;
	if(dp[pos][turn]!=INF)
		return dp[pos][turn];


	dp[pos][turn]=recurse(pos+1,1-turn)+(turn==1?a[pos]:0);
	if(pos+1<n)
		dp[pos][turn]=min(recurse(pos+2,1-turn)+(turn==1?a[pos]+a[pos+1]:0),dp[pos][turn]);

	return dp[pos][turn];
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		
		cin>>n;
		fab(0,n,i)
		cin>>a[i];
		fab(0,n,i)
		{
			dp[i][0]=INF;
			dp[i][1]=INF;
		}
		cout<<recurse(0,1)<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}