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
vector< vector<int> > v(100005);
vector< int> ans(100005);
void dfs(int src,bool vis[], int col)
{
	vis[src]=true;
	ans[src]=col;
	fab(0,v[src].size(),i)
	{
		if(!vis[v[src][i]])
			dfs(v[src][i],vis,1-ans[src]);
	}


}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	fab(0,n-1,i)
	{
		ll int u,p;
		cin>>u>>p;
		v[u].pb(p);
		v[p].pb(u);


	}
	bool vis[n+1];
	fab(0,n+1,i)
	vis[i]=false;
	dfs(1,vis,1);
	int cnt=0;
	fab(1,n+1,i)
	if(ans[i]==1)
		cnt++;
	
	cout<<(ll)(cnt)*(ll)(n-cnt)-n+1<<endl;


	return 0;
}