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
void get( int n, vector<int> &a)
{
    fab(1, sqrt(n) + 1, i)
    {
        if (n % i == 0)
        {
            a.pb(i);
            a.pb(n / i);
        }
    }
}

int main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    // int t;
    // cin>>t;
    // while(t--)
    {
        int n;
        cin >> n;
        int a[n];
        fab(0, n, i)
        cin >> a[i];
        sort(a, a + n);
        ll sum = 0;
        fab(0, n, i)
        sum += a[i];

        ll ans = 1e9;
        fab(0, n, i)
        {
            vector<int> f;
            get(a[i], f);
            //cout << "aa" << a[i] << endl;
            for (auto j : f)
            {
                //cout << "I:" << a[i] << " " << j << " " << sum - a[i] - a[0] + a[i] / j + (a[0] * j) << endl;
                ans = min(ans, sum - a[i] - a[0] + a[i] / j + (a[0] * j));
            }

        }
        cout << ans << endl;



    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}