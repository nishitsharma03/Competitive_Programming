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

#define vll vector<ll>
#define vi vector<int>
#define pii pair<int,int>
#define pll pair<ll,ll>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
const int MOD=998244353;
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;

int main()
{ quick;

    int n,k;
    cin>>n>>k;
    vector<ll> dp(n,0LL), pref(n,0LL);
    dp[0]=1;
    //pref[0]=1;
    vector<pair<ll,ll>  > seg(k);
    fab(0,k,i)
    cin>>seg[i].f>>seg[i].se;
    fab(0,n,i)
    {
        if(i>0)
        pref[i]=add(pref[i],pref[i-1]);
        dp[i]=add(dp[i],pref[i]);
        fab(0,k,j)
        {
            ll l=seg[j].f,r=seg[j].se;
           // cout<<"i:"<<i+l<<" "<<i+r+1<<endl;
            if(i+l<n)
                pref[i+l]=add(pref[i+l],dp[i]);
            if(r+i+1<n)
                pref[i+r+1]=sub(pref[i+r+1],dp[i]);
           
        }
    }
  
    cout<<dp[n-1]<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}