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

    
  ll n,x,m;
  cin>>n>>x>>m;
  ll ans=x;
  map<ll,ll> mi;
  mi[x]=0;
  vector<ll> v={x};
  fab(1,n,i)
  {
    x=(x*x)%m;
   // cout<<x<<" "<<endl;
    
    if(mi.find(x)!=mi.end())
    {
        int st=mi[x];
        ll sum=0;
        fab(st,v.size(),j)
        sum+=v[j];
        ll rem=n-v.size();
        ll len=v.size()-st;
        ans+=(rem/len)*sum;
        fab(st,rem%len+st,j)
        ans+=v[j];
        break;

    }
    ans+=x;
    mi[x]=i;
    v.pb(x);



  }
  cout<<ans<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}