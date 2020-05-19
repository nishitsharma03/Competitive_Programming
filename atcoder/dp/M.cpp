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
ll dp[105][100005],n,k,a[105];

int main()
{ quick;

	cin>>n>>k;
	fab(0,n,i)
	cin>>a[i];
	ll pref[k+1]={0};
	dp[0][0]=1;
	pref[0]=1;
	fab(1,a[0]+1,i)
	{
		dp[0][i]=1;
		//pref[i]=pref[i-1]+dp[0][i];

	}
	fab(1,k+1,i)
	pref[i]=(pref[i-1]+dp[0][i])%MOD;
	fab(0,n,i)
	dp[i][0]=1;

	fab(1,n,i)
	
	{
		fab(1,k+1,j)
		{
			ll tot=max((ll)(0),j-a[i]),op;
			if(tot==0)
				op=(pref[j])%MOD;
			else
				op=(pref[j]-pref[tot-1])%MOD;
			//assert(op>=0);
			op=op+MOD;

			dp[i][j]=(op)%MOD;//+(tot==0?j:a[i]);


			

		}
		//cout<<pref[0]<<" ";
		fab(1,k+1,j)
		{
			//cout<<pref[j]<<" ";
			pref[j]=(pref[j-1]%MOD+dp[i][j])%MOD;
		}
		//cout<<endl;

	}
	//cout<<"\n\n";
	/*fab(0,n,i)
	{fab(0,k+1,j)
	cout<<dp[i][j]<<" ";
	cout<<endl;}*/
	cout<<dp[n-1][k]%MOD;


	return 0;
}
