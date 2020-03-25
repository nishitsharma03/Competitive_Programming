#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;

ll int fun(int b[],ll int dp[],int i,int n)
{
	
		ll int j=i+1;
		//int k=j;
		while(j<n)
		{
			if(b[j]-b[i]==j-i)
			{
				if(dp[j]!=-1)
				{
					dp[i]=dp[j]+b[i];
					return dp[i];
				}
				else
				{
					 return fun(b,dp,j,n);
				}
				
			}
			else
			{
				
			}
			j++;

		}
		return b[i];
}


int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	ll int a[n];
	ll int dp[n];
	//int dp1[400005]={0};
	map<ll int,ll int> m;
	fab(0,n,i)
	{
		cin>>a[i];
		//i-a[i];
		m[i-a[i]]=0;
		//dp[i]=-1;
	}
	fab(0,n,i)
	{
		m[i-a[i]]+=a[i];
	}
	
	/*for(int i=0;i<n;i++)
	{
		dp[i]=a[i];
		fab(0,i,j)
		{
			if(a[j]-a[i]==j-i&&a[i]+dp[j]>dp[i])
			{
				dp[i]=a[i]+dp[j];
			}
		}

	}*/
	ll int max=0;
	for(auto i:m)
	{
		//cout<<i.first<<" "<<i.second<<endl;
		if(i.second>max)
			max=i.second;
	}
	//fab(0,n,i)
	//cout<<dp[i]<<" ";
	cout<<max<<endl;

	return 0;
}