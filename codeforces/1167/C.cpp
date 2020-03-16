#pragma GCC optimize "trapv"
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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
void dfs(vector<int> v[],int n,int src,bool vis[],vector<int> &ans,int cnt)
{
	//static int xnt=0
	vis[src]=true;
	
	
		ans[src]=cnt;
		fab(0,v[src].size(),i)
		{
			if(!vis[v[src][i]])
			{
				ans[v[src][i]]=cnt;

				dfs(v,n,v[src][i],vis,ans,cnt);
			}
		}

}
vector<int> connectedcomp(vector<int> v[],int n)
{
	bool vis[n+1];
	vector<int> ans(n+1);
	fab(1,n+1,i)
	vis[i]=false;
	ll int cnt=0;
	fab(1,n+1,i)
	{
		if(!vis[i])
	{		cnt++;
		dfs(v,n,i,vis,ans,cnt);
		
	}

	}
	ans[0]=cnt;
	return ans;
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	ll int n,m;
	cin>>n>>m;
	vector<int> v[n+1];
	fab(0,m,i)
	{
		int k;
		cin>>k;
		vector<int> p(k);
		fab(0,k,l)
		{
			ll int o;
			cin>>o;
			p[l]=o;
		}
		fab(0,k-1,t)
		{
			v[p[t]].pb(p[t+1]);
			v[p[t+1]].pb(p[t]);

		}
		

	}
	vector<int> ans=connectedcomp(v,n);
	vector<int> pp[ans[0]+1];
	//fab(1,n+1,i)
	//cout<<ans[i]<<" ";
	//cout<<"\nhh\n";
	fab(1,n+1,i)
	{	

		pp[ans[i]].pb(i);

		

	}
	int fin[n+1];
	fab(1,ans[0]+1,i)
	{
		int siz=pp[i].size();
		fab(0,siz,j)
		{
			fin[pp[i][j]]=siz;
		}
	}

fab(1,n+1,i)
cout<<fin[i]<<" ";


	return 0;
}