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
//dp with bitmasking
ll dp[1<<21+1];
int main()
{ quick;

	int n;
	cin>>n;
	bool allowed[n][n];
	fab(0,n,i)
	fab(0,n,j)
	cin>>allowed[i][j];
	
	dp[0]=1;
	for(int mask=0;mask<(1<<n);mask++)
	{
		int x=__builtin_popcount(mask);
		for(int i=0;i<n;i++)
		{
			if(allowed[x][i] and (mask&(1LL<<i))==0)
			{
				dp[mask|(1LL<<i)]=(dp[mask|(1LL<<i)]+dp[mask])%MOD;
			}
		}
	}

	cout<<dp[(1<<n)-1]<<endl;


	return 0;
}