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
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    // int t;
    // cin >> t;
    // while (t--)
    {
        int v;
        cin >> v;
        int a[9];
        int sm = 1e9;
        int ind = -1;
        fab(0, 9, i)
        {
            cin >> a[i];
            if (sm >= a[i])
            {
                sm = a[i];
                ind = i;
            }

        }
        string s(v / sm, char('1' + ind));
        //cout << s << endl;
        ll cost = (v / sm) * sm;
        //cout << cost << endl;
        for ( int i = 0; i < s.length(); i++)
        {
            for ( int j = 8; j > ind; j--)
            {
                if (cost + a[j] - sm <= v)
                {

                    cost += a[j];
                    cost -= sm;
                    s[i] = ('1' + j);
                    break;
                }
            }
        }
        if (s.length())
            cout << s << endl;
        else
            cout << -1 << endl;
    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}