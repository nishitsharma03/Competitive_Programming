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

int main()
{ quick;


    {
        int n;
        cin>>n;
        ll mat[n][3];
        fab(0,n,i)
        {
            fab(0,3,j)
            cin>>mat[i][j];
        }
        ll dp[n][3];
        memset(dp,0,sizeof(dp));
        fab(0,3,i)
        dp[0][i]=mat[0][i];
        fab(1,n,i)
        {
            fab(0,3,j)
            {
                fab(0,3,k)
                {
                    if(k!=j)
                    dp[i][j]=max(dp[i][j],dp[i-1][k]+mat[i][j]);
                }
                
            }
            

        }
        cout<<max({dp[n-1][0],dp[n-1][1],dp[n-1][2]})<<endl;
    }
    
    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}