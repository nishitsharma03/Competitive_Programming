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
//#define endl "\n"
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
		int a[n];
		int cnt=0;
		fab(0,n,i)
		{cin>>a[i];
		if(a[i]==1)
			cnt++;
		}
		int cnt1=cnt;
		if(n==2)
		{
			if(a[0]==a[1])
			{
				cout<<2<<endl<<a[0]<<" "<<a[1]<<endl;
			}
			else
			{
				cout<<1<<endl<<0<<endl;
			}
			continue;
		}
		int req=n/2;
		int an=1;
		vector<int> v;
		if(cnt<req )
			{	
				an=0;
				cnt=(n-cnt);
			}
			int ok=cnt%2;
			if(cnt>req or req%2==0)
			{
				fab(0,cnt-ok,i)
				{
					v.pb(an);

				}

			}
			else if (cnt==req)
			{
			fab(0,req,i)
			v.pb(0);


			}

	
		
		
		cout<<v.size()<<endl;
		int sum=0;
		int tot=0;
		fab(0,v.size(),i)
		{
			if(i%2==0)
			sum+=v[i];
			else
				sum-=v[i];
			if(v[i]==1)
				tot++;
		}
		
		for(auto i: v)
			cout<<i<<" ";
		cout<<endl;
	
		
		
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}