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
    //cin >> t;
    while (t--)

    {
        int n;
        cin >> n;
        vector<pair<int, int> > a(n);
        map<int, vector<int>> pp;
        fab(0, n, i)
        {
            cin >> a[i].f;
            a[i].se = i;
            pp[a[i].f].pb(i);
        }
        sort(all(a));
        int m = min(n, 5000);
        map<int, pair<int, int> > hash;
        vector<int> ans;
        for (auto i : pp)
        {
            if (i.se.size() > 1)
            {
                ans.pb(i.se[0]);
                ans.pb(i.se[1]);

            }
        }
        if (ans.size() >= 4)
        {
            cout << "YES" << endl;
            cout << ans[0] + 1 << " " << ans[2] + 1 << " " << ans[1] + 1 << " " << ans[3] + 1 << endl;
            return 0;

        }


        ans.clear();
        fab(0, m, i)
        {
            if (ans.size())
                break;
            fab(i + 1, m, j)
            {
                if (hash.find(a[i].f + a[j].f) != hash.end() and hash[a[i].f + a[j].f].se != a[j].se and hash[a[i].f + a[j].f].f != a[i].se and hash[a[i].f + a[j].f].se != a[i].se and hash[a[i].f + a[j].f].f != a[j].se)
                {
                    //cout << "As:" << i << " " << j << endl;
                    auto p = hash[a[i].f + a[j].f];
                    //cout << p.f << " " << p.se << endl;
                    ans.pb(p.f);
                    ans.pb(p.se);
                    ans.pb(a[i].se);
                    ans.pb(a[j].se);
                    break;
                }
                else
                {
                    hash[a[i].f + a[j].f] = {a[i].se, a[j].se};
                }

            }

            if (ans.size())
                break;

        }



        if (ans.size())
        {
            set<int> s;
            fab(0, 4, i)
            {
                s.insert(ans[i]);
            }
            assert(s.size() == 4);
            cout << "YES" << endl;
            fab(0, 4, i)
            {
                cout << ans[i] + 1 << " ";
            }
            cout << endl;
        }
        else
            cout << "NO" << endl;

    }

    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}