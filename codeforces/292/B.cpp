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
const int N=1e5+5;
vector<int> v[N];

void dfs( int src, bool vis[])
{
    vis[src]=1;
    for(auto i: v[src])
    {
        if(!vis[i])
            dfs(i,vis);
    }
}



int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int n,m;
    cin>>n>>m;
    fab(0,m,i)
    {
        int x,y;
        cin>>x>>y;
        v[x].pb(y);
        v[y].pb(x);
    }
    bool vis[n+1];
    fab(1,n+1,i)
    vis[i]=0;
    dfs(1,vis);
    bool ok=1;
    fab(1,n+1,i)
    {
        ok&=(vis[i]);

    }
    int two=0,one=0;
    int n1=0;
    fab(1,n+1,i)
    {
        two+=((v[i].size()==2));
        one+=((v[i].size()==1));
        n1+=((v[i].size()==n-1));
    }
    //cout<<one<<" "<<two<<" "<<n1<<endl;
    if(two==n-2 and one==2)
    {
        cout<<"bus topology"<<endl;
        return 0;
    }
    if(n1==1 and one==n-1)
    {
        cout<<"star topology"<<endl;
        return 0;
    }
    if(ok and two==n)
    {
        cout<<"ring topology"<<endl;
        return 0;
    }

    cout<<"unknown topology"<<endl;


    

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}