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
	
	{
		int n;
		cin>>n;
		ll a[n];
		ll sum=0;
		ll sm=1e7,big=-1e7;
		map<ll,ll> m;
		fab(0,n,i)
		{
			cin>>a[i];
			big=max(big,a[i]);
			sm=min(a[i],sm);
			sum+=a[i];
			m[a[i]]++;


		}
		ll ans=1e9+9;
		int freq[3]={0};
		ll beg=sm;
		
		
		
			fab(0,n+1,i)
			{
				ll tot=sm*i;
				
				ll rem=sum-tot;

				// solve linear eqns
				// a+b=n-i
				// a*(sm+1)+ b*(sm+2)=rem
				// (n-i-b)*sm + (n-i-b) + b*sm + 2*b=rem
				// (n-i)*(sm+1)+b=rem;
				

				ll b=rem-(ll)(n-(ll)i)*(sm+1);
				if(sm+2>big)
					b=0;
				ll a=n-i-b;
				if(sm+1>big)
					a=0;
				
				ll req=1e12;
				
				if(a>=0 and b>=0 and i*sm+a*(sm+1)+b*(sm+2)==sum and a+b+i==n)
					req=min(req,min((ll)i,m[sm])+min(b,m[sm+2])+min(a,m[sm+1]));
				
				
				if(req<ans)
				{
					ans=req;
					freq[0]=i;
					freq[1]=a;
					freq[2]=b;
					beg=sm;


				}

			}

			
		cout<<ans<<endl;
		fab(0,3,i)
		{
			fab(0,freq[i],j)
			cout<<beg+i<<" ";
		}

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}