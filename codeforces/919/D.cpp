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
int maxPathValue(int n, int m, vector<vector<int>> &edges, string &values)
{

    vector<int> adj[n + 1];
    vector<int> inDegree(n + 1, 0);
    for (vector<int> i : edges)
    {
        adj[i[0]].push_back(i[1]);
        inDegree[i[1]]++;
    }

    queue<int> q;

    vector<vector<int>> dp(n + 1, vector<int>(26, 0));

    for (int i = 1; i <= n; i++)
    {
        if (inDegree[i] == 0)
        {
            q.push(i);
        }
    }

    int popCounts = 0;
    int ans = 0;

    while (q.empty() == false)
    {
        int curr = q.front();
        q.pop();
        popCounts++;

        dp[curr][values[curr - 1] - 'a']++;
        ans = max(ans, dp[curr][values[curr - 1] - 'a']);

        for (int i : adj[curr])
        {
            for (int j = 0; j < 26; j++)
            {
                dp[i][j] = max(dp[i][j], dp[curr][j]);
                ans = max(ans, dp[i][j]);
            }

            inDegree[i]--;

            if (inDegree[i] == 0)
            {
                q.push(i);
            }
        }

        if (popCounts == n)
        {
            break;
        }
    }

    if (q.empty() == false or popCounts < n)
    {
        return -1;
    }

    return ans;
}

int main()
{   quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int n, m;
    cin >> n >> m;
    vector<vector<int> >  v(m, vector<int> (2));
    string s;
    cin >> s;
    fab(0, m, i)
    {
        cin >> v[i][0] >> v[i][1];
    }
    cout << maxPathValue(n, m, v, s);







    cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
    return 0;
}