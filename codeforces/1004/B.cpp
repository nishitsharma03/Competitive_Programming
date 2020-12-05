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
    int n,m;
    cin>>n;
    pii a[n];
    fab(0,n,i)
    {
        cin>>a[i].f>>a[i].se;
    }
    string s="";
    fab(0,n,i)
    {
        if(i%2)
        s+='1';
    else
        s+='0';
    }
    string t="";
    fab(0,n,i)
    {
        if(i%2)
            t+='0';
        else 
            t+='1';
    }
    ll val=0,val1=0;;
    fab(0,m,i)
    {
        int l=a[i].f-1,r=a[i].se;
        int len=r-l;
        int cnt=0,cnt1=0;
        fab(l,r,j)
        {
            cnt+=(s[i]=='1');
            cnt1+=(t[i]=='1');
        }

        val+=(cnt*(len-cnt));
        val1+=(cnt1*(len-cnt1));


    }
    if(val>val1)
        cout<<s<<endl;
    else
        cout<<t<<endl;
    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}