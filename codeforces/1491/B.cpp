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

using namespace std;

ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}
ll lcm(ll x, ll y) { ll res = x / __gcd(x, y); return (res * y);}


int main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    while (t--)

    {
        int n;
        ll u, v;
        cin >> n;
        cin >> u >> v;
        vector<int> a(n);
        fab(0, n, i)
        {
            cin >> a[i];
        }

        ll ans = min(u + v, 2 * v);

        fab(0, n - 1, i)
        {
            if (abs(a[i + 1] - a[i]) > 1)
            {
                ans = 0;
                break;
            }

        }

        fab(0, n, i)
        {
            if (i + 1 < n and a[i + 1] != a[i])
            {
                ans = min(ans, v);

            }
            if (i - 1 > 0 and a[i - 1] != a[i])
            {
                ans = min(ans, v);
            }
        }

        fab(0, n - 1, i)
        {
            if (a[i] != a[i + 1])
            {
                ans = min(ans,  u);
            }

        }
        cout << ans << endl;
    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}