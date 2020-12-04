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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int n,k;
    cin>>n>>k;
    int a[n];
    int c[k+1]={0};
    fab(0,n,i)
    {
        cin>>a[i];
        c[a[i]]++;

    }
    sort(c,c+k+1);
    reverse(c,c+k+1);
    int cnt=(n+1)/2;
    int od=0;
    ll ans=0;
    int i=0;
    while(cnt>0 and c[i]!=0)
    {
        int get=c[i]/2;
        od+=c[i]%2;
       // cout<<"gg:"<<get<<" "<<c[i]<<endl;
        if(cnt-get>=0)
        {
            ans+=get*2;
            cnt-=get;

        }
        else
        {
            ans+=cnt*2;
            cnt=0;
        }
        i++;

    }
    ans+=min(cnt,od);
    cout<<ans<<endl;


    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}