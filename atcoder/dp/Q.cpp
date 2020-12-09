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
const int N = 2e5 + 4;
ll seg[2 * N];
int n;
void update( int i, ll val)
{
    i += n;
    seg[i] = val;
    for ( ; i > 1; i /= 2)
    {
        seg[i / 2] = max(seg[i] , seg[i ^ 1]);
        //  cout << "seg:" << i / 2 << " " << seg[i / 2] << endl;
    }
}

ll query( int l, int r)
{
    //cout << "l:" << l << " " << r << endl;
    l += n;
    r += n;
    ll ans = 0;
    while (r > l)
    {
        if (l % 2) {

            //cout << "l " << l << " " << seg[l] << endl;
            ans = max(ans, seg[l]);
            l++;
        }
        if (r % 2)
        {


            r--;
            //cout << "r " << r << " " << seg[r] << endl;
            ans = max(ans, seg[r]);
        }

        l /= 2;
        r /= 2;
    }
    return ans;
}

int main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    // int t;
    // cin >> t;
    // while (t--)
    {

        cin >> n;
        vector<ll> h(n), b(n);
        fab(0, n, i)
        {
            cin >> h[i];
        }
        fab(0, n, i)
        {
            cin >> b[i];
        }
        fab(0, 2 * n + 2, i)
        {
            seg[i] = 0;
        }
        ll ans = 0;
        for ( int i = 0; i < n; i++)
        {
            ll prev = query(1, h[i]);
           // cout << "i:" << i << " " << prev << " " << h[i] << " " << b[i] << endl;
            ans = max(ans, (prev + b[i]));
            update(h[i], (prev + b[i]));
        }
        cout << ans << endl;

    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}