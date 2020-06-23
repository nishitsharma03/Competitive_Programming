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
const int N=2e5+5;
int n,q;
vector<int> v[N];
ll subtree[N];
vector<int> order;
int dfs(int src,int par)
{
	subtree[src]=1;
	order.pb(src);
	for(auto i: v[src])
	{
		//cout<<"src:"<<src<<" "<<i<<endl; 
		if(i==par)
			continue;
		subtree[src]+=dfs(i,src);
	}
	return subtree[src];
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    cin>>n>>q;
    ll baap[n];
    baap[0]=-1;
    fab(1,n,i)
    {
    	int x;
    	cin>>x;
    	
    	x--;
   baap[i]=x;
    	v[i].pb(x);
    	v[x].pb(i);
    }
    fab(0,n,i)
    {
    	
    	sort(all(v[i]));
    }
    dfs(0,-1);
    map<int,int> m;
   // cout<<"order:"<<endl;
    fab(0,n,i)
    {
    	//cout<<order[i]<<" ";
    	m[order[i]]=i;
    }

    while(q--)
    {
    	int a,b;
    	cin>>a>>b;
    	a--;
    	if(subtree[a]<b)
    	{
    		cout<<-1<<endl;
    		continue;
    	}
    	int start=m[a];
    	cout<<order[start+b-1]+1<<endl;
    	
    	//cout<<"check:"<<b<<endl;
    	

    }
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}