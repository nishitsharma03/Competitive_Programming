//#pragma GCC optimize "trapv"
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
	{
		int n;
		cin>>n;
		vi a(n);
		set<int> st;
		map<int,int> posi;
		fab(0,n,i)
		{cin>>a[i];
			//st.insert(a[i]);
		posi[a[i]]=i+1;}
		sort(all(a));
		
		fab(1,n-1,i)
		st.insert(a[i+1]-a[i]);
		if(st.size()==1)
		{
			cout<<posi[a[0]];
			return 0;
		}
		st.clear();
		st.insert(a[2]-a[0]);
		fab(2,n-1,i)
		st.insert(a[i+1]-a[i]);
		if(st.size()==1)
		{
			cout<<posi[a[1]];
			return 0;
		}
		st.clear();
		int ans=-1;
		int mx=(a[1]-a[0]),cnt=0;
		fab(0,n-1,i)
		{
			
			if(a[i+1]-a[i]==mx)
			{
				cnt++;

			}
			else if(i<n-2 and a[i+2]-a[i]==mx)
			{
				ans=posi[a[i+1]];
				cnt++;
			}
			else if(i==n-2 and a[i+1]-a[i]!=mx and ans==-1 )
			{
				ans=posi[a[n-1]];
			}
			}
			if(cnt==n-2)
				ans=ans;
			else
				ans=-1;
		
		cout<<ans<<endl;


	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}