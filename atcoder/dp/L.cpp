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
int n;
ll a[3005];
ll dp[3005][3005][2];
int turn;
ll recurse(int i,int j, int k)
{
    if(i>j)
        return 0;
    if(dp[i][j][k]!=-1)
        return dp[i][j][k];
    if(k==0) 
        dp[i][j][k]=max(recurse(i+1,j,1-k)+a[i],recurse(i,j-1,1-k)+a[j]);
        
    
    else
        dp[i][j][k]=min(recurse(i+1,j,1-k)-a[i],recurse(i,j-1,1-k)-a[j]);
    return dp[i][j][k];


}
int main()
{ quick;

    cin>>n;
    fab(0,n,i)
    cin>>a[i];
    memset(dp,-1,sizeof(dp));
    cout<<recurse(0,n-1,0);

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}