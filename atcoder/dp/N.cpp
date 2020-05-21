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
const ll INF=1e18+7;
ll dp[405][405];
//dp[i][j] denotes the minimum sum to combine interval i...j
// final answer will be dp[0][n-1]
ll rangesum(vector<ll> a,int l,int r)
{
	ll sum=0;
	fab(l,r+1,i)
	sum+=a[i];
	return sum;
}

int main()
{ quick;

	int n;
	cin>>n;
	vector<ll> a(n);
	//memset(dp,(ll)INF,sizeof(dp));
	fab(0,n,i)
	cin>>a[i];
	for(int i=n-1;i>=0;i--)
	{
		fab(i,n,j)
		{
			if(i==j)
			{
				dp[i][j]=0;
			}
			else
			

			{
				dp[i][j]=INF;
				fab(i,j,k)
				dp[i][j]=min(dp[i][k]+dp[k+1][j],dp[i][j]);
				dp[i][j]+=rangesum(a,i,j);
			}


		}
		
	}
	cout<<dp[0][n-1]<<endl;

	return 0;
}