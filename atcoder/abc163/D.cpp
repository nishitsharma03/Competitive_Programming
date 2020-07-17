//#pragma GCC optimize "trapv"
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
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
const int N=2e5+5;

ll getmax(ll n,ll k)
{
    ll ans= n*(n+1)/2;
    ans-=(n-k)*(n-k+1)/2;
    return ans;
}
ll getmin(ll n,ll k )
{
    return k*(k+1)/2;
}

int main()
{ quick;


    int n,k;
    cin>>n>>k;
    //n++;
    //ll sm=1e15+3,mx=0;
    ll ans=0;
    fab(k,n+2,i)
    {ll sm=(getmin(n,(ll)(i-1)));
    ll mx=(getmax(n,i));
    //cout<<sm<<" "<<mx<<endl;
    ans+=((mx-sm+1))%MOD;
    }
cout<<ans%MOD<<endl;

    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}