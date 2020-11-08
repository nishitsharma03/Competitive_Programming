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

    ll n;
    cin>>n;
    string s=to_string(n);
    //cout<<s.length()<<endl;
    int a[3]={0};
    int sum=0;
    for(auto i:s)
    {
        a[(i-'0')%3]++;
        sum+=(i-'0');
    }
    if(sum%3==0)
    {
        cout<<0<<endl;
        return 0;
    }
    if(sum%3==1)
    {
        if(a[1] and s.length()>1)
        {
            cout<<1<<endl;
        }
        else if(a[2]>=2 and s.length()>2)
        {
            cout<<2<<endl;
        }
        else
            cout<<-1<<endl;
    }
    else
    {

        if(a[2] and s.length()>1)
        {
            cout<<1<<endl;
        }
        else if (a[1]>=2 and s.length()>2)
        {

                cout<<2<<endl;
        }
        else
            cout<<-1<<endl;
    }

// cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}