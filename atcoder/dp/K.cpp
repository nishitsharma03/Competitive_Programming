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
ll n,k,a[105];
int dp[100005];



int main()
{ quick;

	cin>>n>>k;
	fab(0,n,i)
	cin>>a[i];
	memset(dp,-1,sizeof(dp));
	sort(a,a+n);
	ll sm=a[0];
	fab(0,sm+1,i)
	dp[i]=1;
	
		fab(0,n,i)
		{
			
			dp[a[i]]=1;
			fab(0,sm and a[i]+j<=k,j)
			{
				dp[a[i]+j]=1;
			}
		}
			/*	fab(0,k+1,i)
		cout<<dp[i]<<" ";
		cout<<endl;*/

		fab(0,k+1,i)
		{
			if(dp[i]!=-1)
				continue;
			bool flag=false;
			fab(0,n and a[j]<=i,j)
			{
				if(dp[i-a[j]]==0)
				{
					dp[i]=1;
					flag=true;
				}
			}
			if(dp[i]==-1 and !flag)
				dp[i]=0;
		}
		/*fab(0,k+1,i)
		cout<<dp[i]<<" ";
		cout<<endl;*/
		if(dp[k]==1)
		{
			cout<<"First";
		}
		else
			cout<<"Second";

	


	return 0;
}