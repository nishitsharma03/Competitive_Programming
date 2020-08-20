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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	int a[n];
	map<int,int> m,freq;
	fab(0,n,i)
	{
		cin>>a[i];
		m[a[i]]=i;
		freq[a[i]]++;

	}
	ll ans=1;
	fab(0,n,i)
	{
		//cout<<"i:"<<i<<endl;
		if(freq[a[i]]>1 and m[a[i]]!=i)
		{
			int mx=m[a[i]];
			if(i!=0)
				ans=mul(ans,2ll);
			while(i<n and i<mx)
			{
				mx=max(m[a[i]],mx);
				i++;

			}
			//i--;

		}
		else
		{
			if(i!=0)
			ans=mul(ans,2ll);
		}

	}
	cout<<ans<<endl;


	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}