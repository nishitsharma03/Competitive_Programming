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
		db tot;
		cin>>n>>tot;
		db a[n];
		fab(0,n,i)
		cin>>a[i];
		db l=0.0 ,h=1e9+0.1;
		db ans;
		while(h-l>1e-6)
		{
			db mid=(l+h)/2;
			db curr=0,speed=1.0;
			db tim=0.0;
			fab(0,n,i)
			{
				db dist=(a[i]-curr);
				db req=dist/speed;
				if(tim+req<=mid)
				{
					tim+=req;
					speed++;
					curr=a[i];
				}
				else 
				{
					db left= mid-tim;
					curr+=(speed)*left;
					tim=mid;
					break;
				}

			}
			if(mid>tim)
			{
				db left= mid-tim;
				curr+=(speed)*left;
			}
			db d1=curr;
			curr=tot;
			speed=1.0;
			tim=0.0;

			for( int i=n-1;i>=0;i--)
			{
				db dist=(curr-a[i]);
				db req=dist/speed;
				
				if(tim+req<=mid)
				{
					tim+=req;
					speed++;
					curr=a[i];
				}
				else 
				{
					db left= mid-tim;
					curr-=(speed)*left;
					tim=mid;
					
					break;
				}

			}
			if(mid>tim)
			{
				db left= mid-tim;
					curr-=(speed)*left;
			}
			//cout<<"curr:"<<curr<<" "<<d1<<" "<<mid<<endl;
			if(curr<=d1)
			{
				h=mid;
				ans=mid;
			}
			else
				l=mid;

		}
		cout<<fixed<<setprecision(10)<<ans<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}	