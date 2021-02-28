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
//#define endl "\n"
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
        cin >> n;
        vector<ll> a(n + 1);
        fab(1, n + 1, i)
        {
            cin >> a[i];
        }

        ll ans = 0;
        // fab(1, n + 1, i)
        // {
        //     if (i + a[i] > n )
        //     {
        //         ans += (i + a[i]) - n;
        //         a[i] -= (i + a[i]) - n;

        //     }
        // }

        set<ll> s;
        fab(1, n + 1, i)
        {
            if (a[i] != 1)
            {
                s.insert(i);
                //cout << "Sd" << i << endl;
            }
        }
        s.insert(n + 1);


        fab(1, n + 1, i)
        {
            bool done = 1;
            ll j = i;
            if (a[i] == 1)
                continue;

            //cout << "a[i]" << a[i] << endl;
            if (a[i] + i > n)
            {
                //cout << "ads" << (i + a[i]) - n << " ";
                ans += (i + a[i]) - n;
                a[i] -= (i + a[i]) - n;
                if (a[i] == 0)
                {
                    ans--;
                    a[i]++;
                }
                //cout << a[i] << endl;

            }

            while (a[i] > 1)
            {
                ll j = i;
                while (j <= n)
                {
                    //cout << "j:" << j << " " << a[j] << endl;
                    ll next = j + a[j];
                    if (a[j] == 1)
                    {
                        // for (auto k : s)

                        // {
                        //     cout << k << " ";
                        // }
                        // cout << endl;
                        auto p = *s.lower_bound(j + 1);
                        j = p;
                        continue;

                    }
                    a[j]--;
                    if (a[j] == 1)
                    {
                        if (s.find(j) != s.end())
                        {
                            s.erase(j);
                        }

                    }
                    a[j] = max(1LL, a[j]);
                    j = next;

                }
                ans++;
            }
        }

        cout << ans << endl;


    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}