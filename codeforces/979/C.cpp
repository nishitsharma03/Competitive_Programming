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
vector<ll> v[300005];
ll cnt=0;
ll ftob;
ll subtree[300005];
bool checkx[300005];
int x,y;
ll dfs(int src,int par)
{
	subtree[src]=1LL;
	if(src==x)
		checkx[src]=true;
	else
		checkx[src]=false;
	for(auto i : v[src])
	{
		if(i==par)
			continue;
		subtree[src]+=dfs(i,src);
		checkx[src]|=checkx[i];
	}
	return subtree[src];

	
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n;
	cin>>n>>x>>y;
	x--;y--;
	fab(1,n,i)
	{
		ll a,b;
		cin>>a>>b;
		a--;b--;
		v[a].pb(b);
		v[b].pb(a);

	}
	ll ans=(n*(n-1));
	dfs(y,-1);
	for(auto i:v[y])
	{
		if(checkx[i])
		{
			ans-=(subtree[y]-subtree[i])*subtree[x];
		}
	}
	cout<<ans<<endl;


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}