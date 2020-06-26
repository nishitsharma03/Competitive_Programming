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
int h,w;
ll dp[1005][1005];
int main()
{ quick;

    cin>>h>>w;
    vector<string> v(h);
    fab(0,h,i)
    cin>>v[i];
    fab(0,w,i)
    {
        if(v[0][i]=='#')
            break;
        dp[0][i]=1;
    }
    fab(0,h,i)
    {
        if(v[i][0]=='#')
            break;
        dp[i][0]=1;
    }
    fab(1,h,i)
    {
        fab(1,w,j)
        {
            if(v[i][j]=='#')
                continue;
            dp[i][j]=dp[i-1][j]+dp[i][j-1];
            dp[i][j]%=MOD;

        }
    }
    cout<<dp[h-1][w-1]<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}