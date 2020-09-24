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
#define MOD 998244353
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
const int N=3e5+5;
ll fac[N],inv[N];

void precomp()
{
	fac[0]=1;
	fac[1]=1;
	inv[0]=1;
	inv[1]=1;
	fab(2,N,i)
	{
		fac[i]=mul(i,fac[i-1]);
		inv[i]=mod_inv(fac[i]);
	}

}
ll ncr(ll n, ll r)
{
	ll tm=mul(fac[n],inv[r]);
	return mul(tm,inv[n-r]);
}




int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    precomp();
	int n,k;
	cin>>n>>k;

	pair<ll,ll>  a[n];
	vector<pll> v;
	ll ans=0;

	fab(0,n,i)
	{
		cin>>a[i].f>>a[i].se;
		
		v.pb({a[i].f,1});
		v.pb({a[i].se,2});

	}
	sort(all(v));
	int cnt=0;
	fab(0,v.size(),i)
	{
		//cout<<"v:"<<v[i].f<<" "<<v[i].se<<endl;
		if(v[i].se==1)
			{
				cnt++;
			}
		else
			{ 
				//cout<<"cnt:"<<cnt<<endl;
				if(cnt==k)
				ans=add(ncr(cnt,k),ans);
				else if(cnt>k)
				ans=add(ncr(cnt-1,k-1),ans);
			
				cnt--;
				
			}

			// if(cnt>k)
			// 	ans=add(ncr(cnt-1,k-1),ans);
			// else if (cnt==k) ans=add(ans,1);

		
	}
	cout<<ans<<endl;

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}