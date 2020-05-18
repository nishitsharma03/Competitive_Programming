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
int n,m,dp[100005],vis[100005];
vector<int> v[100005];
int dfs(int src)
{
	vis[src]=true;
	for(auto i:v[src])
	{
		if(!vis[i])
			dfs(i);
		dp[src]=max(dp[src],dp[i]+1);
	}
	return dp[src];
}
void longpath()
{
	int ans=0;
	fab(1,n+1,i)
	{
		if(!vis[i])
			dfs(i);
		ans=max(ans,dp[i]);
	}
	cout<<ans<<endl;
}



int main()
{ quick;

    cin>>n>>m;
    fab(0,m,i)
    {
    	int a,b;

    	cin>>a>>b;
    	//cout<<a<<" "<<b<<endl;
    	v[a].pb(b);}
	longpath();

	return 0;
}