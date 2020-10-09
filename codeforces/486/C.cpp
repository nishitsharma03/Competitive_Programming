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
		int n,p;
		cin>>n>>p;
		string s;
		cin>>s;
		int ans=0;
		fab(0,n,i)
		{
			int j=n-i-1;
			if(j<=i)
				break;
			if(s[i]>s[j])
				swap(s[i],s[j]);
			int a=s[j]-s[i];
			int b=('z'-s[j])+(s[i]-'a')+1;
			ans+=min(a,b);

		}
		//cout<<ans<<endl;
		if(p<=n/2)
		{
			int go=p;
			int go2=p;
			
			fab(p,n/2,i)
			{
				int j=n-i-1;
				if(s[i]!=s[j])
					go=i+1;
			}
			for( int i=p-2;i>=0;i--)
			{
				if(s[i]!=s[n-i-1])
					go2=i+1;
			}
			int a=(go-p)*2+ (p-go2);
			int b= (go-p)+(p-go2)*2;
			go=p;
			fab(p,n,i)
			{
				if(s[i]!=s[n-i-1])
					go=i+1;
			}
			//cout<<"a:"<<a<<" "<<b<<" "<<go<<endl;
			ans+=min({a,b,go-p});

		}
		else
		{
			int go=p,go2=p;
			fab(p,n,i)
			{
				if(s[i]!=s[n-i-1])
					go=i+1;
			}
			for( int i=p-2;i>=n/2;i--)
			{
				if(s[i]!=s[n-i-1])
					go2=i+1;
			}
			int a=(go-p)*2+(p-go2);
			int b=(go-p)+ (p-go2)*2;
			go=p;
			for( int i=p-2;i>=0;i--)
				{
					if(s[i]!=s[n-i-1])
						go=i+1;
				}
				ans+=min({a,b,p-go});
		}
		cout<<ans<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}