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
vector<int> v[1005];
bool roadconst[1005][1005];
void bfs(int src,int level[],int n)
{
	bool vis[n]={0};
	queue< pair<int,int> > q;
	q.push({src,0});
	vis[src]=1;

	while(!q.empty())
	{
		pair<int,int> aage=q.front();
		int node=aage.f;
		q.pop();
		
		level[node]=aage.se;
		for(auto i:v[node])
		{
			if(!vis[i])
			{
				q.push({i,aage.se+1});
				vis[i]=true;
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
	int n;
	int m,s,t;
	cin>>n>>m>>s>>t;
	s--;
	t--;
	fab(0,m,i)
	{
		int x,y;
		cin>>x>>y;
		x--;y--;
		roadconst[x][y]=1;
		roadconst[y][x]=1;
		v[x].pb(y);
		v[y].pb(x);
	}
	int dists[n],distt[n];
	
	bfs(s,dists,n);
	//memset(vis,0,sizeof(vis));
	bfs(t,distt,n);

	ll ans=0;
	fab(0,n,i)
	{
		fab(0,n,j)
		{
			if(i!=j and roadconst[i][j]==0)
			{
				ll sm=min(distt[i]+1+dists[j],distt[j]+1+dists[i]);
				if(sm>=distt[s])
					{ans++;
					//	cout<<"i:"<<i<<" "<<j<<" "<<distt[s]<<endl;
						roadconst[i][j]=1;
						roadconst[j][i]=1;
					}
			}
		}
	}
	cout<<ans<<endl;


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}