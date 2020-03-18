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
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int cnt;
ll int ans;
void dfs(vector<int> v[],bool vis[],int src)
{	
		cnt++;
	vis[src]=true;
	fab(0,v[src].size(),i)
	{
		if(!vis[v[src][i]])
			dfs(v,vis,v[src][i]);
	}
}

ll conneccomp(vector<int> v[],int n,int k)
{
	bool vis[n+1];
	fab(0,n+1,i)
	vis[i]=false;

	fab(1,n+1,i)
	{	cnt=0;
		if(!vis[i])
			dfs(v,vis,i);

	//	cout<<"cnt:"<<cnt<<endl;
		ll int cnt1=cnt;
		fab(1,k,i)
		{
			cnt1=(cnt1*cnt)%MOD;
		}
		ans=(ans+cnt1)%MOD;
	}

return ans;
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
		int n,k;
		cin>>n>>k;
		vector<int> v[n+1];
		fab(0,n-1,i)
		{
			int x,y,p;
			cin>>x>>y>>p;
			if(!p)
			{
				v[x].pb(y);
				v[y].pb(x);
			}

		}
		ll final=conneccomp(v,n,k);
		//cout<<"final:"<<final<<endl;
//		cout<<"nn="<<n<<endl;
		ll int nn=n;
	fab(1,k,i)
	{
		nn=(nn*n)%MOD;
	}
	//cout<<"n="<<nn<<endl;
	cout<<(nn-final+MOD)%MOD<<endl;
	

	return 0;
}