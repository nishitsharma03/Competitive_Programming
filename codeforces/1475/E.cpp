//#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(ll i=a;i<b;i++)
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

const int N = 1e4;
ll fac[N];
ll ncr(ll n, ll r)
{
    assert(r >= 1 and r <= n);
    ll ans = mul(fac[n] , mod_inv(fac[r])); ans = mul(ans, mod_inv(fac[n - r]));
    return ans;
}

void precomp()
{
    fac[0] = 1;
    fab(1, N, i)
    {
        fac[i] = mul(fac[i - 1], i);
    }
}

int main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int t = 1;
    cin >> t;
    precomp();
    while (t--)
    {
        ll n, k;
        cin >> n >> k;
        vector<ll> a(n);
        map<ll, int> m;

        fab(0, n, i)
        {
            cin >> a[i];
            m[a[i]]++;

        }
        sort(all(a));
        reverse(all(a));
        int cnt = 0;
        for ( int i = k - 1; i >= 0; i--)
        {
            cnt += (a[i] == a[k - 1]);
        }

        ll ans = ncr(m[a[k - 1]], cnt);
        cout << ans << endl;



    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}