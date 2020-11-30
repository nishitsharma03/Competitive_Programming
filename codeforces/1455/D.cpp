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
bool issorted(vector<int> &a)

{
	int n=a.size();
	bool ok=1;
	fab(0,n-1,i)
	{
		ok&=(a[i+1]>=a[i]);
	}
	return ok;
}

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
		int n,x;
		cin>>n>>x;
		vector<int> a(n);
		fab(0,n,i)
		cin>>a[i];
		vector<int> b=a;
		sort(all(b));
		if(b==a)
		{
			cout<<0<<endl;
			continue;
		}

		int x1=x;
		int ans=-1;
		int cnt=0;
		fab(0,n,i)
		{
			

			if(a[i+1]>=x1 and a[i]>x1 and (i==0 or a[i-1]<=x1))
			{
				swap(a[i],x1);
				cnt++;
			}
			// fab(0,n,i)
			// cout<<a[i]<<" ";
			// cout<<endl;

			if(issorted(a))
			{
				ans=cnt;
				break;
			}

		}
		cout<<ans<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}