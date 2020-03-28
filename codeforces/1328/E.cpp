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
vector<int> v[200005];
ll int d[200005];
ll int p[200005],tin[200005],tout[200005];
ll int t;
void dfs(ll int src,int par,int lev)
{
	 tin[src]=t++;
	 p[src]=par;
	 d[src]=lev;
	 for(auto i:v[src])
	 {
	 	if(i==par)
	 		continue;
	 	dfs(i,src,lev+1);
	 }
	 tout[src]=t++;
}


int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll int n,m;
	cin>>n>>m;
	fab(1,n,i)
	{
		ll int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
	}
	dfs(1,-1,0);
	while(m--)
	{
		ll int k;
		cin>>k;
		vector<ll int> vi(k);
		for(auto &i:vi)
			cin>>i;
		ll int des=vi[0];
		for(auto i:vi)
		{
			if(d[i]>d[des])
				des=i;
		}
		fab(0,k,i)
		{
			if(vi[i]==des)
				continue;
			if(p[vi[i]]!=-1)
				vi[i]=p[vi[i]];
		}
		bool chk=true;
		fab(0,k,i)
		{
			if(tin[vi[i]]>tin[des]||tout[vi[i]]<tout[des])
			{
				chk=false;
				break;
			}
		}
		if(chk)
			cout<<"YES\n";
		else
			cout<<"NO\n";


	}


	return 0;
}