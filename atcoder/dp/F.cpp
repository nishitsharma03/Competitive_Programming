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
string s,t;
ll dp[3005][3005];
ll recurse(int i,int j)
{
    if(i<=0 or j<=0)
        return 0;
    if(dp[i][j]!=-1)
        return dp[i][j];
    if(s[i-1]==t[j-1])
    {
        dp[i][j]=recurse(i-1,j-1)+1;
    }
    else
    {
        dp[i][j]=max(recurse(i-1,j),recurse(i,j-1));
    }
    return dp[i][j];
}
int main()
{ quick;

    cin>>s>>t;
   
    memset(dp,-1,sizeof(dp));
    int i=s.size();
    int j=t.size();
   recurse(i,j);
   
    string ans="";
   while(i>0 and j>0)
    {
        
        if(s[i-1]==t[j-1])
        {
            ans=ans+s[i-1];
            i--;
            j--;

        }
        else
        { if(dp[i-1][j]>=dp[i][j-1])
            {
                i--;
            }
            else
                j--;

        }
    }
    reverse(all(ans));
    cout<<ans<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}