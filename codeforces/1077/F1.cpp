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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
ll n,k,x;
ll a[205];
ll dp[205][205];
void build()
{

	dp[0][x]=0;
	fab(1,n+1,i)
	{
//	dp[i][1]=a[i];

	fab(0,x,ind)
	{
		
	//int cnt=0;
	for( int j=i-1;j>=i-k and j>=0	;j--)
	{
		if(dp[j][ind+1]!=-1)
		dp[i][ind]=max((dp[j][ind+1]+a[i-1]),dp[i][ind]);
		//cnt++;
	}
	//cout<<cnt<<endl;

	}
	
	}

	ll ans=-21;
	

	fab(n-k+1,n+1,i)
	{
		fab(0,x,j)
		{
			ans=max(ans,dp[i][j]);
		}
	}


	cout<<ans<<endl;
}


int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    
    cin>>n>>k>>x;
   
    memset(dp,-1,sizeof(dp));
    
    fab(0,n,i)
    cin>>a[i];
   
    build();

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}