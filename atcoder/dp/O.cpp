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
const int N=21;
ll dp[1LL<<N+5];
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    bool match[n][n];
    fab(0,n,i)
    fab(0,n,j)
    cin>>match[i][j];
    dp[0]=1;
    fab(0,1<<n,i)
    {
        int setbits=__builtin_popcount(i);
        fab(0,n,j)
        {
            if(((1<<j)&i)==0 and match[setbits][j])
            {
                dp[i|(1<<j)]+=dp[i];
                dp[i|(1<<j)]%=MOD;
            }
        }
    }
    cout<<dp[(1<<n)-1]<<endl;
    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}