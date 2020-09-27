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
		map<int , vector<int> > m;
		int n;
		cin>>n;
		int a[n];
		fab(0,n,i)
		{
			cin>>a[i];
			if(m[a[i]].size()==0)
				m[a[i]].pb(-1);
		m[a[i]].pb(i);
		}
		vector<int>  ans(n,-1);
			
			for( auto &i: m)
			{
				i.se.pb(n);
				 vector<int> v=i.se;
				 int tot=0;
				 for( int j=0;j<v.size()-1;j++)
				 	tot=max(v[j+1]-v[j]-1, tot);
				 //cout<<tot<<endl;
				for( int j=tot;j<n;j++)
				{
					if(ans[j]!=-1)
						break;
					else ans[j]=i.f;
				}

			}
			for( auto i: ans)
				cout<<i<<" ";
			cout<<endl;

		}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}