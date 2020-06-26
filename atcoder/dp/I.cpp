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
db dp[3005][3005];
int main()
{ quick;

    int n;
    cin>>n;
    db a[n];
    fab(0,n,i)
    cin>>a[i];
    dp[0][0]=1-a[0];
    fab(1,n,i)
    {
        dp[i][0]=dp[i-1][0]*(1-a[i]);
    }
    dp[0][1]=a[0];
    fab(1,n,i)
    {
        fab(1,n+1,j)
        {
        dp[i][j]=dp[i-1][j]*(db(1)-a[i])+dp[i-1][j-1]*(a[i]);
        }
    }
    
    db ans=0;
    fab((n+1)/2,n+1,i)
    ans+=dp[n-1][i];

    cout<<setprecision(10)<<ans<<endl;



 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}