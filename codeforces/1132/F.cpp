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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	
	{
		int n;
		cin>>n;
		string s;
		cin>>s;
		const int N=505;
		int dp[N][N];
		fab(0,n,i)
		{
			fab(0,n,j)
			dp[i][j]=1000;
		}
		fab(0,n,i)
		{
			dp[i][i]=1;
		}
		fab(0,n-1,i)
		{
			if(s[i]==s[i+1])
				dp[i][i+1]=1;
			else
				dp[i][i+1]=2;
		}
		for( int len=3;len<=n;len++)
		{
			for( int i=0;i<n-len+1;i++)
			{
				int j=i+len-1;
				//cout<<"i:"<<i<<" "<<j<<endl;
				dp[i][j]=min(dp[i+1][j]+(s[i]!=s[i+1]),dp[i][j-1]+(s[j]!=s[j-1]));
				
				//if(s[i]==s[j])
				{for( int k=i;k<j;k++)
				{
					if(s[j]==s[k])
					dp[i][j]=min(dp[i][j],dp[i][k]+dp[k+1][j-1]);
				}
				}
			}
		}
		// fab(0,n,i)
		// {
		// 	fab(0,n,j)
		// 	{
		// 		cout<<dp[i][j]<<" ";
		// 	}
		// 	cout<<endl;
		// }

		cout<<dp[0][n-1]<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}