#pragma GCC optimize "trapv"
#pragma GCC optimize("Ofast")
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx,avx2,fma")
#include<bits/stdc++.h>
#define int long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define vint vector<int>
#define vi vector<int>
#define pii pair<int,int>
#define pint pair<int,int>
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
int add(int x, int y) {int res = x + y; return (res >= MOD ? res - MOD : res);}
int mul(int x, int y) {int res = x * y; return (res >= MOD ? res % MOD : res);}
int sub(int x, int y) {int res = x - y; return (res < 0 ? res + MOD : res);}
int power(int x, int y) {int res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
int mod_inv(int x) {return power(x, MOD - 2);}


using namespace std;
const int N = 2e5 + 5;
vector<pair<int, int> > v;
int suff[N + 2];

bool comp(pair<int, int>  a, pair<int, int> b)
{
    int prof1 = a.f + a.se - b.f;
    int prof2 = b.f + b.se - a.f;

    return (prof1 > prof2);

}

int32_t main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int n;
    cin >> n;
    v.resize(n);
    fab(0, n, i)
    {

        cin >> v[i].f >> v[i].se;

    }
    sort(all(v), comp);

    suff[n - 1] = v[n - 1].f;
    for ( int i = n - 2; i > 0; i--)
    {
        suff[i] = suff[i + 1] + v[i].f;


    }
    int sum = 0;
    fab(0, n, i)
    {
        if (sum > suff[i])
        {
            cout << i ;
            return 0;
        }
        sum += (v[i].f + v[i].se);

    }
    cout << n;
    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}