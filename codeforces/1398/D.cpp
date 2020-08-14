//#pragma GCC optimize "trapv"
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
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
const int N=205;

ll dp[N][N][N];
int r,g,b;
vector<ll> x(N),y(N),z(N);
ll recurse(int i, int j, int k)
{
	int cnt=0;
	if(i>=r)
		cnt++;
	if(j>=g)
		cnt++;
	if(k>=b)
		cnt++;
	if(cnt>=2)
		return 0;
	else if(dp[i][j][k]!=-1)
		return dp[i][j][k];
	if(i<r and j<g)
		dp[i][j][k]=max(dp[i][j][k],x[i]*y[j]+recurse(i+1,j+1,k));
	if(i<r and k<b)
	{
		dp[i][j][k]=max(dp[i][j][k],x[i]*z[k]+recurse(i+1,j,k+1));

	}
	if(j<g and k<b)
	{
		dp[i][j][k]=max(dp[i][j][k],y[j]*z[k]+recurse(i,j+1,k+1));
	}
	return dp[i][j][k];

}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t=1;
	//cin>>t;
	while(t--)
	{
		memset(dp,-1,sizeof(dp));
		cin>>r>>g>>b;
		
		fab(0,r,i)
		cin>>x[i];
		fab(0,g,i)
		cin>>y[i];
		fab(0,b,i)
		cin>>z[i];
		sort(all(x),greater<int>());
		sort(all(z),greater<int>());
		sort(all(y),greater<int>());
		cout<<recurse(0,0,0)<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}