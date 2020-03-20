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
vector< vector<int> > v(200003);
vector<int> ans;
void bfs(int src,int n)
{
	bool vis[n+1];
	fab(0,n+1,i)
	vis[i]=false;
	
	queue<int> q;
	q.push(src);
	
	while(!q.empty())
	{
		int top=q.front();
		q.pop();
		vis[top]=true;
		ans.pb(top);

		fab(0,v[top].size(),i)
		{
			if(!vis[v[top][i]])
			{
				q.push(v[top][i]);
				vis[v[top][i]]=true;
				cout<<top<<" "<<v[top][i]<<endl;
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
	ll int n,m;
	cin>>n>>m;
	fab(0,m,i)
	{
		ll int l,k;
		cin>>l>>k;
		v[k].pb(l);
		v[l].pb(k);
	}
	int maxdeg=v[1].size();
	int vert=1;
	fab(1,n+1,i)
	{
		if(v[i].size()>maxdeg)
		{
			maxdeg=v[i].size();
			vert=i;
		}
	}

	bfs(vert,n);
//	fab(0,n-1,i)
//	cout<<ans[i]<<" "<<ans[i+1]<<endl;
	

	return 0;
}