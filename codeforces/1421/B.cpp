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
		cin>>n;
		int a[n][n];
		vector<string > pp(n);
		fab(0,n,i)
		{
			cin>>pp[i];
			fab(0,n,j)
			{
				a[i][j]=pp[i][j]-'0';
			}
		}
		vector< pair<int,int> > v;
		int cnt=0;
		cnt+=a[n-2][n-2];
		cnt+=a[n-3][n-1];
		cnt+=a[n-1][n-3];
		//cout<<"cnt:"<<cnt<<endl;
		if(cnt==0 or cnt==1)
		{
			 if(cnt==0)
			{
				if(a[n-2][n-1]==a[n-2][n-2])
				v.pb({n-2,n-1});
				if(a[n-1][n-2]==a[n-2][n-2])
			 
				v.pb({n-1,n-2});
			}
			else if(a[n-2][n-1]!=a[n-1][n-2])
			{
				if(a[n-2][n-2])
				v.pb({n-2,n-2});
			else if(a[n-1][n-3])
				v.pb({n-1,n-3});
			else if(a[n-3][n-1])
				v.pb({n-3,n-1});

			if(!a[n-2][n-1])
				v.pb({n-2,n-1});
			else if(!a[n-1][n-2])
				v.pb({n-1,n-2});


			}
			
			else
			{
				if(a[n-2][n-2]==a[n-1][n-2])
				v.pb({n-2,n-2});
				if(a[n-1][n-3]==a[n-1][n-2])
				v.pb({n-1,n-3});
				 if(a[n-3][n-1]==a[n-1][n-2])
				v.pb({n-3,n-1});

			}
		}
		else
		{
			if(cnt==3)
				{
					if(a[n-2][n-1]==a[n-2][n-2])
				v.pb({n-2,n-1});
				if(a[n-1][n-2]==a[n-2][n-2])
					v.pb({n-1,n-2});


				}
			else if(a[n-2][n-1]!=a[n-1][n-2])
			{
				if(!a[n-2][n-2])
				v.pb({n-2,n-2});
			else if(!a[n-1][n-3])
				v.pb({n-1,n-3});
			else if(!a[n-3][n-1])
				v.pb({n-3,n-1});

			if(a[n-2][n-1])
				v.pb({n-2,n-1});
			else if(a[n-1][n-2])
				v.pb({n-1,n-2});


			}
			else
			{
				if(a[n-2][n-2]==a[n-1][n-2])
				v.pb({n-2,n-2});
				if(a[n-1][n-3]==a[n-1][n-2])
				v.pb({n-1,n-3});
				 if(a[n-3][n-1]==a[n-1][n-2])
				v.pb({n-3,n-1});

			}
			
		}
		cout<<v.size()<<endl;
			for(auto i: v)
				cout<<i.f+1<<" "<<i.se+1<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}