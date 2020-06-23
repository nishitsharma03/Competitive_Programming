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
vector<int> v[30];
string ans="";
void dfs(int src,bool vis[])
{
	vis[src]=1;
	ans+=char('a'+src);
	for(auto i:v[src])
	{
		if(!vis[i])
			dfs(i,vis);
	}
}
bool cycleexist(int src,bool vis[],int par)
{
	vis[src]=1;
	bool ok=0;
	for(auto i: v[src])

	{
		if(i==par)
			 continue;
			if(vis[i])
				return true;
			else
				ok|=cycleexist(i,vis,src);
	}
	return ok;
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
		ans.clear();
		ans="";
		fab(0,26,i)
		v[i].clear();
		string s;
		cin>>s;
		int n=s.size();
		fab(0,n-1,i)
		{
			if(find(all(v[s[i]-'a']),s[i+1]-'a')==v[s[i]-'a'].end())
			{
				// cout<<"ins:"<<i<<endl;
				v[s[i]-'a'].pb(s[i+1]-'a');
				v[s[i+1]-'a'].pb(s[i]-'a');
			}

		}
		bool ok=1;int all2=2;
		fab(0,26,i)
		{
			
			
			if(v[i].size()>2)
			{
				//cout<<"i:"<<i<<endl;
				ok=0;
				break;
			}
			
		}
		if(!ok )
		{
			cout<<"NO"<<endl;
			continue;
		}
		bool vis[26]={0};
		ok=0;
		fab(0,26,i)
		{
			if(!vis[i])
				ok|=cycleexist(i,vis,-1);
		}
		if(ok)
		{
			cout<<"NO\n";
			continue;
		}
		memset(vis,0,sizeof(vis));
		fab(0,26,i)
		{
			if(!vis[i] and v[i].size()<2)
				dfs(i,vis);

		}
		cout<<"YES\n";
		cout<<ans<<endl;
		

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}