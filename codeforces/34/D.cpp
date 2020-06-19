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
vector<int> ans(100005);

void dfs(int src,int par)
{
	ans[src]=par;
	for(auto i: v[src])
	{
		if(i==par)
			continue;
		dfs(i,src);
	}

}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll n,r1,r2;
	cin>>n>>r1>>r2;
	
	fab(1,n+1,i)
	{
		if(i==r1)
			continue;
		ll k;
		cin>>k;
		v[k].pb(i);
		v[i].pb(k);

	}
	dfs(r2,-1);
	fab(1,n+1,i)
	{
		if(i==r2)
			continue;
		cout<<ans[i]<<" ";
	}


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}