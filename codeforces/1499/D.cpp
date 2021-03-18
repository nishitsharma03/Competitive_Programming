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
const int N = 2e7 + 5;
int prime[N], val[N];


void go()
{
    prime[1] = 1;


    for (int i = 2; i < N; i++)
    {
        if (prime[i])
            continue;
        for (ll j = i ; j < N; j += i)
        {
            if (prime[j] == 0)
                prime[j] = i;
        }
    }


    for ( int i = 2; i < N; i++)
    {
        int j = i / prime[i];

        val[i] = val[j] + (prime[i] != prime[j]);

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
    go();
    while (t--)
    {
        int c, d, x;
        cin >> c >> d >> x;
        ll ans = 0;

        for ( int i = 1; i <= sqrt(x); i++)
        {
            if (x % i == 0)
            {
                int val1 = x / i + d;

                if (val1 % c == 0)
                {
                    int pp = val1 / c;
                    //cout << "pp:" << pp << " " << (i + d) / c << " " << val[pp] << " " << val[(i + d) / c] << endl;
                    // cout << "val:" << val << " " << endl;

                    ans += (1LL << val[pp]);


                }
                if (x / i != i and (i + d) % c == 0)
                {
                    ans += (1LL << val[(i + d) / c]);
                }

            }

        }

        cout << ans << endl;



    }


    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}