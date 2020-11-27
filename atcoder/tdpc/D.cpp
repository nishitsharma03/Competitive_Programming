//#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
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
#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;

db dp[205][101][101];





int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
    ll d;
    cin>>d;    
    int cnt2=0,cnt3=0,cnt5=0;
    ll temp=d;
    while(temp%2==0)
    {
        cnt2++;
        temp/=2;
    }
    while(temp%3==0)
    {
        cnt3++;
        temp/=3;
    }
    while(temp%5==0)
    {
        cnt5++;
        temp/=5;

    }
    if(temp>2 or cnt2>n or cnt3>n or cnt5>n or max(cnt2,cnt3)+cnt5>n)
    {
        cout<<0<<endl;
        return 0;
    }
    //cout<<"op:"<<cnt2<<" "<<cnt3<<" "<<cnt5<<endl;

    memset(dp,0.0,sizeof(dp));

    dp[0][0][0]=1.0;

    for( int i=1;i<=n;i++)
    {
        db new_dp[205][101][101];
        for( int j=0;j<=2*n;j++)
        {
            for( int k=0;k<=n;k++)
            {
                for( int p=0;p<=n;p++)
                {   //

                    //dp[i][j][k][p]+=((dp[i-1][j][k][p])/6.0);
                    //cout<<"check:"<<i<<" "<<j<<" "<<k<<" "<<p<<" "<<dp[i][j][k][p]<<endl;
                    //                  get 2                       get 6                                               get 3                                 get 5                get 4               
                    db val=0.0;
                    // get 1
                    val+=(dp[j][k][p]);
                    // get 2
                    
                    if(j>0)
                    {
                        val+=dp[j-1][k][p];

                    }
                    // get 6
                    if(k>0 and j>0)
                    {
                        val+=dp[j-1][k-1][p];
                    }
                    // get 3
                    if(k>0)
                    {
                        val+=dp[j][k-1][p];
                    }
                    // get 5
                    if(p>0)
                    {
                        val+=dp[j][k][p-1];
                    }
                    // get 4
                    if(j>1)
                    {
                        val+=dp[j-2][k][p];

                    }
                    new_dp[j][k][p]=(val/6.0);
                    //dp[i][j][k][p]+=(((j==0)?0:dp[i-1][j-1][k][p]) + ((j==0 or k==0 )?0:dp[i-1][j-1][k-1][p]) + ((k==0)?0:dp[i-1][j][k-1][p]) + ((p==0)?0:dp[i-1][j][k][p-1])+((j<=1)?0:dp[i-1][j-2][k][p]))/6.0;
                   // cout<<"get2"<<(j==0?0:dp[i-1][j-1][k][p])<<endl;
                    //cout<<"i:"<<i<<" "<<j<<" "<<k<<" "<<p<<" "<<dp[i][j][k][p]<<endl;
                }  
            }


        }
        swap(dp,new_dp);
    }
    db val=0.0;
    
        fab(0,2*n+1,j)
        {
            fab(0,n+1,k)
            {
                fab(0,n+1,p)
                {
                    if(j>=cnt2 and k>=cnt3 and p>=cnt5)
                    {
                        val+=dp[j][k][p];
                    }
                }
            }
        }
    
    cout<<fixed<<setprecision(12)<<val<<endl;
    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}