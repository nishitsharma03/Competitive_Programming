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
#define BIG 1e10
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
ll dp[100005][105];
ll a[105],b[105],n,w;
ll recurse(ll val,int i)
{
	if(val<=0)
		return 0;

	if(i==n)
		return BIG;
	if(dp[val][i]!=-1)
		return dp[val][i];
	dp[val][i]=min(recurse(val,i+1),a[i]+recurse(val-b[i],i+1));

	return dp[val][i];
		


}
int main()
{ quick;

	//ll n,w;
	cin>>n>>w;
	
	fab(0,n,i)
	cin>>a[i]>>b[i];
	memset(dp,-1,sizeof(dp));
	for(int i=100002;i>=0;i--)
	{
			//cout<<recurse(i,0)<<endl;
			if(recurse(i,0)<=w)
				{cout<<i;
			return 0;}
		
	}

	return 0;
}