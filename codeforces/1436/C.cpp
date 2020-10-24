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
void bin(int n,int x, int pos)
{
	int l=0,r=n;
	ll ans=1;
	vector<int> pref(n+2,0);
	while(l<r)
	{
		int mid=(l+r)/2;
		// if(a[mid]<=x)
		// 	l=mid+1;
		// else
		// 	r=mid;
		//cout<<"mid:"<<mid<<" "<<ans<<endl;
		if(mid>pos)
		{
			int cnt=n-x;
			fab(x+1,n+1,i)
			{
				cnt-=(pref[i]);
			}
			pref[x+1]++;
		//	cout<<"nt:"<<cnt<<endl;
			ans=mul(ans,cnt);
			r=mid;

		}
		else
		{
			if(pos==mid)
				{l=mid+1;
					pref[x]=1;
				continue;
				}
			else
				{
					int cnt=x-1;
					fab(1,x,i)
					{
						cnt-=pref[i];
				
					}
					ans=mul(ans,cnt);
					pref[1]++;
					l=mid+1;
				}

		}

	}
	ll cnt=n;
	fab(1,n+1,i)
	{
		cnt-=pref[i];

	}
	fab(1,cnt+1,i)
	ans=mul(ans,i);
	cout<<ans<<endl;
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int x,n,pos;
	cin>>n>>x>>pos;
	bin(n,x,pos);

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}