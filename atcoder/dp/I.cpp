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
db n,a[3005];
db dp[3005][3005];
void builddp()
{
	cout<<setprecision(12);
	dp[0][0]=1-a[0];
	dp[0][1]=a[0];
	for(int i=1;i<n;i++)
	{
		dp[i][0]=dp[i-1][0]*(1-a[i]);
		fab(1,i+2,j)
		{
			dp[i][j]=dp[i-1][j]*(1-a[i])+dp[i-1][j-1]*a[i];
		
		//cout<<dp[i][j]<<" ";
		}
		//cout<<endl;
	}

	db ans=0;

	fab(n/2+1,n+1,i)
	ans+=(dp[int(n-1)][i]);
	cout<<setprecision(12)<<ans<<endl;
}


int main()
{ quick;

	cin>>n;
	fab(0,n,i)
	cin>>a[i];
	//memset(dp,-1,sizeof(dp));
	builddp();
	return 0;
}