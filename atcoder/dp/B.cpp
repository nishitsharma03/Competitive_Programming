//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
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

	int n,k;
	cin>>n>>k;
	int h[n];
	fab(0,n,i)
	cin>>h[i];
	vector<int> dp(n);
	dp[n-1]=0;
	dp[n-2]=abs(h[n-1]-h[n-2]);

	for(int i=n-2;i>=0;i--)
	{
		int r=1e9;
		fab(i+1,i+k+1 and j<n,j)
		{
			r=min(r,dp[j]+abs(h[i]-h[j]));


		}
		dp[i]=r;
		//cout<<dp[i]<<" ";
	}
	//fab(0,n,i)
	//cout<<dp[i]<<" ";
	cout<<dp[0]<<endl;

	return 0;

	return 0;
}