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
vector<int> v[100005];
ll dp[100005];
ll dfs(int src, bool vis[])
{
    vis[src]=1;
    for(auto i:v[src])
    {
        if(!vis[i])
            dfs(i,vis);
        dp[src]=max(dp[src],dp[i]+1);
    }
    return dp[src];
}
int main()
{ quick;

    int n,m;
    cin>>n>>m;
    fab(0,m,i)
    {
        int a,b;
        cin>>a>>b;
        a--;b--;
        v[a].pb(b);
       
    }
    ll ans=0;
    bool vis[n];
    memset(vis,0,sizeof(vis));
    fab(0,n,i)
    {
        if(!vis[i])
            dfs(i,vis);
        ans=max(ans,dp[i]);
    }
   
    cout<<ans<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}