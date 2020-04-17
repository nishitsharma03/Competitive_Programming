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
vector<ll int> v[200005];
ll int dep[200005],subsiz[200005];
ll int  dfs(int src,int par,int depe)
{
	dep[src]=depe;
	subsiz[src]=1;
	for(auto i:v[src])
	{
		if(i==par)
			continue;
		subsiz[src]+=dfs(i,src,depe+1);
	}
	return subsiz[src];

}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll int n,k;
	cin>>n>>k;
	fab(1,n,i)
	{
		ll int x,y;
		cin>>x>>y;
		x--;
		y--;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(0,-1,0);
	vector<ll int> opti(n);
	fab(0,n,i)
	{//cout<<dep[i]<<" ";
	
		opti[i]=subsiz[i]-1-(dep[i]);


	}
	sort(all(opti),greater<ll int>());
	ll int tot=0;
	int i=0;
	fab(0,n-k,i)
	tot+=opti[i];
	cout<<tot<<endl;
		

	return 0;
}