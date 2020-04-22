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
void bfs(int src,ll int a[])
{
	a[src]=0;
	queue<ll int> q;
	q.push(src);
	while(!q.empty())
	{
		ll int top=q.front();
		q.pop();
		for(auto i:v[top])
		{
			if(a[i]==-1)
			{
				a[i]=a[top]+1;
				q.push(i);
			}
		}
	}

}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		ll int n,m,a,b,c;
		cin>>n>>m>>a>>b>>c;
		ll int p[m];
		a--;b--;c--;
		fab(0,m,i)
		cin>>p[i];
	
		fab(0,m,i)
		{
			ll int u,vi;
			cin>>u>>vi;
			u--;
			vi--;
			v[u].pb(vi);
			v[vi].pb(u);

		}
		ll int ai[n],bi[n],ci[n];
		fab(0,n,i)
		{
			ai[i]=-1;bi[i]=-1;ci[i]=-1;
		}
		//fab(0,n,i)
		//cout<<"a[i]:"<<ai[i]<<" "<<bi[i]<<" "<<ci[i]<<" ";
		bfs(a,ai);
		bfs(b,bi);
		bfs(c,ci);
		//fab(0,n,i)
	//	cout<<"a[i]:"<<ai[i]<<" "<<bi[i]<<" "<<ci[i]<<" ";
	//	cout<<endl;
		sort(p,p+m);
		ll int ans=1e18;
		ll int bef[m+1];
		bef[0]=0;
		fab(0,m,i)
		{
			bef[i+1]=bef[i]+p[i];
		}
		//fab(0,m,i)
		//cout<<bef[i]<<" ";
		//for(auto i :si)
		//	cout<<"si:"<<i.f<<" "<<i.se;
		//cout<<endl;
		fab(0,n,i)
		{
			//considering each node to be the intersection point
			//only one intersection is possible
			if(ai[i]+bi[i]+ci[i]>m)
				continue;
			ans=min(ans,(bef[bi[i]]+bef[ai[i]+bi[i]+ci[i]]));

		}
	
		
		cout<<ans<<endl;
		fab(0,n,i)
		v[i].clear();


	}
	

	return 0;
}