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
int n;
ll a[10][10];
ll ans;
ll op;
void recurse(ll val, ll tim, ll last, ll cnt)
{
    if(cnt==n)
    {
        tim+=a[last][0];
        if(tim==op)
            ans++;
        return;
    }


    fab(0,n,i)
    {
        if(i!=last and (val&(1<<i))==0)
            recurse(val|(1<<i),tim+a[last][i],i,cnt+1);
    }
}

int main()
{ quick;

    cin>>n>>op;
    fab(0,n,i)
    {
        fab(0,n,j)
        {
            cin>>a[i][j];
        }
    }
    recurse(1,0,0,1);
    cout<<ans<<endl;
    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}