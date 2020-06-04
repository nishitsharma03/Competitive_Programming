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
int n,m;
vector<int> a(500005),ans,lowest(500005);
vector<int> v[500005];
int vis[500005];

ll dfs(int src,int num,bool mark[])
{
	vis[src]=num;
	mark[num]=1;
	ans.pb(src);
	if(mark[num-1]==0)
		return 0;
	for(auto i:v[src])
	{
		//cout<<"ss:"<<src<<" "<<i<<endl;
		if(vis[i]>0)
			continue;
		if(a[i]<=num)
		{
			//cout<<"checkp:"<<src<<" "<<i<<" "<<num<<" "<<a[3]<<endl;
			//cout<<-1<<endl;
			return 0;
		}
		if(a[i]==num+1 and num==1)
		{
			//cout<<"i:"<<num<<" "<<i<<endl;
			dfs(i,num+1,mark);
		}


	}
	return 1;

}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
	cin>>n>>m;
	
	
	fab(0,m,i)
	{
		int x,y;
		cin>>x>>y;
		v[x].pb(y);
		v[y].pb(x);
		
	}
	
	fab(1,n+1,i)
	cin>>a[i];
	vector< pair<int,int> > req;
	fab(1,n+1,i)
	{
		req.pb(mp(a[i],i));
	}
	sort(all(req));
	int cnt=1;
	
	bool mark[n+1]={0};
	mark[0]=true;
	for(auto i:req)
	{
		
	//cout<<"inc:"<<i.f<< " "<<i.se<<endl;
		
	/*	
		
		if(!vis[i.se])
		{bool mark[n+1]={0};
	mark[0]=true;
	for(auto j:v[i.se])
	{
		if
	}


			if(!dfs(i.se,i.f,mark))
		{
			//cout<<"i.se:"<<i.se<<" "<<i.f<<endl;
			cout<<-1;
			return 0;
		}

	}*/
		//cout<<"i:"<<i.se<<" "<<i.f<<endl;
	int cnt=0;
	
		set<int> s;
		for(auto j:v[i.se])
		{
			if(a[j]==i.f)
			{
				cout<<-1;
				return 0;
			}
			if(a[j]<i.f)
			s.insert(a[j]);
		}
		//cout<<"cnt:"<<cnt<<endl;
		if(s.size()>=i.f-1)
		{	
			ans.pb(i.se);
			vis[i.se]=1;
		}
		
		else
		{
			cout<<-1<<endl;
			return 0;
		}
		
	
		

	}
	for(auto i: ans)
		cout<<i<<" ";


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}