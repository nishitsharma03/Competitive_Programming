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
//#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 10000000000000007
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
vector<ll> v;
ll getmepowerof10[20];
void recurse( int rem,ll val, int cnt,int last)
{
    if(rem==0){
       // cout<<"vvv:"<<val<<" "<<log10(val)<<endl;
        if(val!=0 and (int)log10(val)==cnt-1)
        v.pb(val);
        return;}
         recurse(rem-1,val+getmepowerof10[cnt]*(last),cnt+1,last);
    if(last>=1)
{
    recurse(rem-1,val+getmepowerof10[cnt]*(last-1),cnt+1,last-1);
}
    if(last+1<=9)
    recurse(rem-1,val+getmepowerof10[cnt]*(last+1),cnt+1,last+1);


}
void pre()
{
    getmepowerof10[0]=1;
    fab(1,19,i)
    getmepowerof10[i]=getmepowerof10[i-1]*10;
}
int main()
{ quick;

    int  k;
    cin>>k;
    int dig=1;
    pre();
   while(v.size()<k)
    {
        fab(0,10,i)
        {
            recurse(dig-1,i,1,i);

        }
        dig++;
    }
    sort(all(v));
    // for(auto i: v)
    //     cout<<i<<" ";
    // cout<<endl;
    cout<<v[k-1]<<endl;
 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}