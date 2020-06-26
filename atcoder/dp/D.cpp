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
int n,w;
ll a[105],b[105];
ll dp[105][100005];

ll recurse(int weight,int ind)
{
    if(ind>=n)
        return 0;
    if(dp[ind][weight]!=-1)
        return dp[ind][weight];
    dp[ind][weight]=max(dp[ind][weight],recurse(weight,ind+1));
    if(weight+a[ind]<=w)
        dp[ind][weight]=max(dp[ind][weight],recurse(weight+a[ind],ind+1)+b[ind]);
    return dp[ind][weight];

}

int main()
{ quick;

    memset(dp,-1,sizeof(dp));
    cin>>n>>w;
    fab(0,n,i)
    cin>>a[i]>>b[i];
    
    cout<<recurse(0,0)<<endl; 
    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}