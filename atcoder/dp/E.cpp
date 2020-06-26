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
const int inf=1e9+5;
int n,w;
ll a[105],b[105];
ll dp[105][100005];

ll recurse(int ind,int val)
{
    if(val<=0)
        return 0;
    if(ind>=n)
        return inf;
    if(dp[ind][val]!=-1)
        return dp[ind][val];
    dp[ind][val]=min(recurse(ind+1,val),recurse(ind+1,val-b[ind])+a[ind]);
    return dp[ind][val];
}

int main()
{ quick;

    memset(dp,-1,sizeof(dp));
    cin>>n>>w;
   // cout<<"w:"<<w<<endl;
    fab(0,n,i)
    cin>>a[i]>>b[i];
   

    for(int i=1e5+2;i>=0;i--)
    {
        if(recurse(0,i)<=w)
        {
            cout<<i<<endl;
            return 0;
        }
    } 
    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}