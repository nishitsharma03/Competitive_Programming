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
		int x;
		cin>>x;
		ll ans=0;
		int cnt=1;
		while(ans+cnt<=x)
		{
			ans+=cnt;
			cnt++;
		}
		//cout<<"cnt:"<<cnt<<" "<<ans<<endl;
		if(ans==x)
		{
			cout<<cnt-1<<endl;
		}
		else
		{
			ll move=ans+cnt - x;
			if(move==1)
			cout<<cnt+1<<endl;
			else
				cout<<cnt<<endl;

		}
		// if(ans<x)
		// {
		// 	ll req=(cnt-(x-ans));
		// 	ll move=ans+cnt - x;
		// 	//cout<<"req:"<<req<<" "<<move<<endl;
		// 		ll mo=1e9+1;
		// 		if( move>1)
		// 		{
		// 			mo=1;
		// 		}
		// 		else

		// 	tot+=min(, mo);
		// }
		//cout<<tot<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}