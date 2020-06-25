//#pragma GCC optimize "trapv"
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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n,c;
	cin>>n>>c;
	ll a[n],b[n];
	fab(1,n,i)
	cin>>a[i];
	fab(1,n,i)
	cin>>b[i];
	ll dp[n+1][2];
	memset(dp,0,sizeof(dp));
	dp[1][0]=0;dp[1][1]=c;
	fab(2,n+1,i)
	{
		dp[i][0]=min(dp[i-1][0]+a[i-1],dp[i-1][1]+a[i-1]);
		dp[i][1]=min(dp[i-1][0]+b[i-1]+c,dp[i-1][1]+b[i-1]);
	}
	fab(1,n+1,i)
	{
		cout<<min(dp[i][0],dp[i][1])<<" ";
	}

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}