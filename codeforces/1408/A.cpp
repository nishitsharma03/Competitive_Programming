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
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		int a[n],b[n],c[n];
		fab(0,n,i)
		cin>>a[i];
		fab(0,n,i)
		cin>>b[i];
		fab(0,n,i)
		cin>>c[i];
		vector<int> ans;
		ans.pb(a[0]);
		fab(1,n-1,i)
		{
			if(a[i]!=ans.back() )
				ans.pb(a[i]);
			else if(b[i]!=ans.back() )
				ans.pb(b[i]);
		}
		
		{
			if(a[n-1]!=ans.back() and a[n-1]!=ans[0])
				ans.pb(a[n-1]);
			else if(b[n-1]!=ans.back() and b[n-1]!=ans[0])
				ans.pb(b[n-1]);
			else
				ans.pb(c[n-1]);
		}
		for( auto i: ans)
			cout<<i<<" ";
		cout<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}