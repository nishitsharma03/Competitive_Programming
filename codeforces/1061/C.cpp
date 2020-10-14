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
const int N=1e6+3;
vector<int> v[N];
bool prim[N];
void findfac(int n)
{
	vector<int> cur;
	for(int j=1;j*j<=n;j++)
		{		
			if(n%j==0)
			{
				cur.push_back(j);
				if(j != n/j)
					cur.push_back(n/j);
			}
		}
		sort(cur.begin(), cur.end());
		reverse(cur.begin(), cur.end());
		v[n]=cur;

}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	vector<int> a(n);
	fab(0,n,i)
	cin>>a[i];

	fab(0,n,i)
	{
		if(v[a[i]].size()==0){
			findfac(a[i]);
			}
	}
	vector<ll> dp(N+1,0);
	dp[0]=1;
	fab(0,n,i)
	{
		//cout<<a[i]<<" "<<endl;
		for( auto j: v[a[i]])
		{
			
			//cout<<"a[i]:"<< a[i]<<" "<<j<<endl;
			
			dp[j]=add(dp[j],dp[j-1]);
		}
	}
	ll sum=0;
	// fab(1,n+1,i)
	// cout<<dp[i]<<" ";
	// cout<<endl;
	fab(1,n+1,i)
	sum=add(sum,dp[i]);
	cout<<sum<<endl;

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}