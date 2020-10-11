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
		string s;
		cin>>s;	
		vector<int> v;
		
		fab(0,n,i)
		{
			int j=i;
			while(j<n and s[j]==s[i])
				j++;
			v.pb(j-i);
			i=j-1;
		}
		int cnt=0,ans=0;
		for(auto &i: v)
		{
			
			if(i!=1)
				{
					//cout<<"cnt:"<<cnt<<" "<<ans<<endl;
					if(i>cnt)
						{	ans+=cnt;
							i-=cnt;
							if(i>1)
								ans++;
							cnt=0;
						}
						else
						{
							ans+=(i-1);
							cnt-=(i-1);
							
							i=1;

						}
				}
				cnt+=(i==1);
		}
		ans+=(cnt+1)/2;
		cout<<ans<<endl;
		// fab(0,v.size(),i)
		// {
		// 	if(v[i]!=1)
		// 	{
		// 		ans++;
		// 		val.erase(val.find(v[i]));
		// 	}
		// 	else
		// 	{
		// 		ans++;
		// 		if(val.size()==1)
		// 			{v.clear();
		// 		continue;}
		// 		int big=val.begin();
		// 		if(big-1>0)
		// 			val.insert(big-1);
		// 		val.erase(val.find(big));
		// 	}

		// }

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}