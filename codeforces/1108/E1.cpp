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
	int n,m;
	cin>>n>>m;
	int a[n];
	fab(0,n,i)
	cin>>a[i];

	pair<int,int> p[m];
	fab(0,m,i)
	{
		cin>>p[i].f>>p[i].se;
		p[i].f--;
		p[i].se--;
	}

	ll ans=*max_element(a,a+n)-*min_element(a,a+n);
	int ind=-1;
	fab(0,n,i)
	{
		int tm[n];
		fab(0,n,i)
		tm[i]=a[i];


		fab(0,m,j)
		{
			if(p[j].f<=i and p[j].se>=i)
				continue;
			fab(p[j].f,p[j].se+1,k)
			tm[k]--;
			ll op=(*max_element(tm,tm+n)-*min_element(tm,tm+n));
			if(op>ans)
			{ans=op;
			ind=i;}

		}		
	}
	cout<<ans<<endl;
	
		
		if(ind+1==0)
			{cout<<0<<endl;
			return 0;}
			vector<int> v;
		fab(0,m,i)
		{
			if(p[i].f<=ind and p[i].se>=ind)
				continue ;
			else
				v.pb(i+1);
		}
		cout<<v.size()<<endl;
		for(auto i:v )
			cout<<i<<" ";

	
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}