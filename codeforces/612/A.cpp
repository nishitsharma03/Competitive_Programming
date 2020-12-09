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
    string s;

    int n, p, q;
    cin >> n >> p >> q;
    cin >> s;
    int a1 = -1;
    int a2 = -1;
    fab(0, 100, i)
    {
        fab(0, 100, j)
        {
            if (i * p + q * j == n)
            {
                a1 = i;
                a2 = j;
                break;
            }
        }
    }
    if (a1 == -1)
    {
        cout << -1 << endl;
    }
    else
    {
        cout << a1 + a2 << endl;
        int i = 0;
        fab(0, a1, j)
        {
            string tem = "";
            fab(0, p, k)
            {
                tem += s[i];
                i++;

            }
            cout << tem << endl;
        }
        fab(0, a2, j)
        {
            string tem = "";
            fab(0, q, k)
            {
                tem += s[i];
                i++;

            }
            cout << tem << endl;
        }

    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}