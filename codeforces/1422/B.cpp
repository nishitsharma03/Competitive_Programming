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
		int n,m;
		cin>>n>>m;
		ll a[n][m];
		fab(0,n,i)
		{
			fab(0,m,j)
			cin>>a[i][j];

		}
		bool done[n][m];
		fab(0,n,i)
		fab(0,m,j)
		done[i][j]=false;
		ll req=0;

		fab(0,n,i)
		{
			fab(0,m,j)
			{
				if(done[i][j])
					continue;
				vector<ll> v;
				v.pb(a[i][j]);
				if(n-i-1!=i)
				v.pb(a[n-i-1][j]);
			if(m-1-j!=j)
				v.pb(a[i][m-1-j]);
				if(m-1-j!=j and n-i-1!=i)
				v.pb(a[n-i-1][m-j-1]);
				// fab(0,v.size(),kk)
				// cout<<v[kk]<<" ";
				// cout<<endl;
				 ll ans=1e12+2;

				fab(0,v.size(),k)
				{
					ll tot=0;
					fab(0,v.size(),p)
					{
						
							tot+=abs(v[k]-v[p]);
						

					}
				//	cout<<"i:"<<i<<" "<<j<<" "<<tot<<endl;
					ans=min(tot,ans);
				}
				//cout<<"ans:"<<ans<<endl;;

				req+=ans;
				done[i][j]=1;
				done[n-i-1][j]=1;
				done[i][m-1-j]=1;
				done[n-i-1][m-j-1]=1;

			}

		}
		cout<<req<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}