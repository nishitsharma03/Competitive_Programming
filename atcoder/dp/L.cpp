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
ll dp[3005][3005][2],n,a[3005];
ll recurse(int l,int r,int i)
{
	if(l>r)
		return 0;
	if(dp[l][r][i]!=-1)
		return dp[l][r][i];
	if(l==r )
		if(i==0)
		return dp[l][r][i]=a[l]+recurse(l+1,r,1);

		else
			return dp[l][r][i]=recurse(l+1,r,0)-a[l];
	if(i==0)
	dp[l][r][i]=max(recurse(l+1,r,1)+a[l],recurse(l,r-1,1)+a[r]);
	else
		dp[l][r][i]=(min(recurse(l+1,r,0)-a[l],recurse(l,r-1,0)-a[r]));
	return dp[l][r][i];


}

int main()
{ quick;

	cin>>n;
	memset(dp,-1,sizeof(dp));
	fab(0,n,i)
	cin>>a[i];
	cout<<recurse(0,n-1,0)<<endl;
	/*fab(0,n,i)
	{
		fab(0,n,j)
		{
			fab(0,2,k)
			cout<<dp[i][j][k]<<" ";
			cout<<endl;
		}
		cout<<endl;
	}*/

	return 0;
}