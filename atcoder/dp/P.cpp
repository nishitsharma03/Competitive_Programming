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
vector<int> v[100005];
ll dp[100005][2];
void dfs(int src,int par )

{
	//cout<<"src:"<<src<<" "<<pr<<endl;
	\
	dp[src][0]=dp[src][1]=1;

	for(auto i: v[src])
	{
		if(i==par)
			continue;
			dfs(i,src);
		
			dp[src][0]=((dp[i][1]+dp[i][0])*dp[src][0])%MOD;
	
		
			dp[src][1]=(dp[src][1]*dp[i][0])%MOD;

	}
	//cout<<"dp:"<<dp[src][pr]<<endl;
}

int main()
{ quick;

	int n;
	cin>>n;
	fab(0,n+1,i)
	dp[i][0]=dp[i][1]=-1;
	fab(1,n,i)
	{
		int x,y;
		cin>>x>>y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);

	}
	dfs(0,-1);
	cout<<(dp[0][1]+dp[0][0])%MOD<<endl;

	return 0;
}