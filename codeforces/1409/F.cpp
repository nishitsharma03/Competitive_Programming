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
const int N=205;

ll dp[N][N][N];
string s,t;
int n,k;

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
   
    cin>>n>>k;
    cin>>s>>t;
	
    memset(dp,-1,sizeof(dp));	
    dp[0][0][0]=0;
	for( int i=0;i<n;i++)
	{
		for( int j=0;j<=k;j++)
		{
			for( int p=0;p<=i+1;p++)
			{
				if(dp[i][j][p]==-1)
					continue;
				
				if(s[i]==t[0])
					dp[i+1][j][p+1]=max(dp[i+1][j][p+1],dp[i][j][p]+(s[i]==t[1]?p:0));
				else
					dp[i+1][j][p]=max(dp[i+1][j][p],dp[i][j][p]+(s[i]==t[1]?p:0));
				

				if(j<k)
				{
					dp[i+1][j+1][p+1]=max(dp[i+1][j+1][p+1],dp[i][j][p]+((t[0]==t[1])?p:0));
					dp[i+1][j+1][p+(t[0]==t[1])]=max(dp[i+1][j+1][p+(t[0]==t[1])],dp[i][j][p]+p);
				}

				
			}

		}
	}
		ll ans=0;
		fab(0,k+1,j)
		{
			fab(0,n+1,p)
			ans=max(ans,dp[n][j][p]);
		}
		cout<<ans;
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}