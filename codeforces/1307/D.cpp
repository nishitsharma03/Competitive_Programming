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
void bfs(int n,ll int d[],int src)
{
	bool vis[n+1];
	fab(0,n+1,i)
	vis[i]=false;
	vis[src]=true;
	queue<int> q;
	q.push(src);
	d[src]=0;
	while(!q.empty())
	{
		auto top=q.front();
		q.pop();
		fab(0,v[top].size(),i)
		{
			if(!vis[v[top][i]])
			{
				vis[v[top][i]]=true;
				q.push(v[top][i]);
				d[v[top][i]]=d[top]+1;
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
	ll int n,m,k;
	cin>>n>>m>>k;
	int sp[k];
	
	int p,q;
	fab(0,k,i)
	{
		cin>>sp[i];
		
	}
	fab(0,m,i)
	{
		cin>>p>>q;
		v[p].pb(q);
		v[q].pb(p);
	}
	ll int d[n+1],d2[n+1];
	fab(0,n+1,i)
	{d[i]=-1;
		d2[i]=-1;}
bfs(n,d,1);
bfs(n,d2,n);
vector< pair<ll int,ll int> > v;
fab(0,k,i)
{
	v.pb(mp(d[sp[i]],d2[sp[i]]));



}
sort(all(v));
reverse(all(v));
ll int m2=v[0].f;
ll int m1=v[0].se;
ll int ans=0,ind=0;

fab(1,k,i)
{
	ans=max(ans,v[i].f+m1+1);
	m1=max(m1,v[i].se);
}
cout<<min(ans,d[n])<<endl;

return 0;
}