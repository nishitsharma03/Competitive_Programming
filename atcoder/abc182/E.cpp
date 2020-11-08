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
map<int,int> m;
void fac(int n)
{
    fab(1,sqrt(n)+1,i)
    {
        if(n%i==0)
        {
            m[i]++;
            if(n/i!=i)

            {
                m[n/i]++;
            }
        }
    }
}
int main()
{ quick;

    ll h,w,n,m;
    cin>>h>>w>>n>>m;
    vector< vector<int> > a(h,vector<int> (w,0));
    vector< vector<int> > ans=a;
    fab(0,n,i)
    {
        int v,b;
        cin>>v>>b;
        a[v-1][b-1]=1;
    }
    fab(0,m,i)
    {
        int v,b;
        cin>>v>>b;
        a[v-1][b-1]=-1;
    }
    // fab(0,h,i)
    // {
    //     fab(0,w,j)
    //     cout<<a[i][j]<<" ";
    //     cout<<endl;
    // }
    fab(0,h,i)
    {
        int ok=0;
        fab(0,w,j)
        {
            ok|=(a[i][j]==1);
            if(a[i][j]==-1)
                ok=0;
            ans[i][j]|=ok;



        }
        ok=0;
        for( int j=w-1;j>=0;j--)
        {
            ok|=(a[i][j]==1);
            if(a[i][j]==-1)
                ok=0;
            ans[i][j]|=ok;

        }



    }
    // fab(0,h,i)
    // {
    //     fab(0,w,j)
    //     //sum+=ans[i][j];
    //     cout<<ans[i][j]<<" ";
    //     cout<<endl;
    // }
    fab(0,w,i)
    {
        bool ok=0;
        fab(0,h,j)
        {
            ok|=(a[j][i]==1);
            if(a[j][i]==-1)
                ok=0;
            ans[j][i]|=ok;

        }
        ok=0;
        for( int j=h-1;j>=0;j--)
        {
            ok|=(a[j][i]==1);
            if(a[j][i]==-1)
                ok=0;
            ans[j][i]|=ok;

        }
    }
    ll sum=0;
    fab(0,h,i)
    {
        fab(0,w,j)
        {sum+=ans[i][j];
        //cout<<ans[i][j]<<" ";
    }

        //cout<<endl;
    }
    cout<<sum<<endl;

 //cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}