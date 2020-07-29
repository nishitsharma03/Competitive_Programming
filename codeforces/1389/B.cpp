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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n,k,z;
		cin>>n>>k>>z;
		int a[n];
		fab(0,n,i)
		cin>>a[i];
		ll pref[n];
		pref[0]=a[0];
		fab(1,n,i)
		pref[i]=a[i]+pref[i-1];

		int moves=0;
		ll ans=0;
		fab(1,k+1,i)
		{
			moves++;
			ll tm=pref[i];
			//cout<<"tm:"<<moves<<" "<<tm<<endl;
			int currmoves=moves;
			int left=min((k-moves+1)/2,z);
			//cout<<"left:"<<left<<endl;
			tm+=a[i-1]*(left);
			tm+=a[i]*(left-1);
			int bachehue=k-(currmoves+left+left-1);
			tm+=pref[i+bachehue-1]-pref[i-1];
		//	cout<<"tmmmm:"<<tm<<endl;
			ans=max(ans,tm);


		}
		cout<<ans<<endl;





	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}