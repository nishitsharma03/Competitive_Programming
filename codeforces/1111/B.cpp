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
	db n,k,m;
	cin>>n>>k>>m;
	vector<db> a(n);
	fab(0,n,i)
	cin>>a[i];
	sort(all(a));
	db pref[(int)n];
	pref[0]=a[0];
	fab(1,n,i)
	{
		pref[i]=pref[i-1]+a[i];

	}
	db ans=(pref[(int)n-1]+min(m,n*k))/n;

	fab(0,n-1 and i<m,i)
	{
		db removed=db(i+1);
		db avg=(pref[(int)n-1]-pref[i]+min(m-removed,k*(n-removed)))/(n-removed);
		//cout<<"abg:"<<avg<<endl;
		
		ans=max(ans,avg);


	}
	if(n==1)
	{
		cout<<fixed<<setprecision(10)<<a[0]+min(k,m)<<endl;
		return 0;
	}
	cout<<fixed<<setprecision(10)<<ans<<endl;



	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}