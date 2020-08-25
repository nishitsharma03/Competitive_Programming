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
		string s;
		cin>>s;
		int x;
		cin>>x;
		int n=s.length();
		string ans="";
		fab(0,n,i)
		ans+='1';
		bool ok=1;
		int mark[n];
		fab(0,n,i)
		mark[i]=-1;
		fab(0,n,i)
		{
			if(s[i]=='0')
			{
				if(i-x>=0 )
					if(mark[i-x]!=1)
					{ans[i-x]='0';
					mark[i-x]=0;}
					else
						ok=0;
				if(i+x<n)
					if(mark[i+x]!=1)
					{ans[i+x]='0';
				mark[i+x]=0;}
				else
					ok=0;
			}
			else if(s[i]=='1')

			{
				if(i-x<0 and i+x>=n)
				ok=0; 
			if(i-x>=0 and i+x<n)
			{
				if( mark[i-x]==0 and mark[i+x]==0)
				ok=0;
			else if (mark[i-x]==0)
				mark[i+x]=1;
			else if (mark[i+x]==0)
				mark[i-x]=1;
			}

			else if(i-x>=0)
			{
				if( mark[i-x]==0)
				ok=0;
					else
				mark[i-x]=1;
			}
			else if(i+x<n)
			{if( mark[i+x]==0)
				ok=0;
					else
				mark[i+x]=1;
		}


				if(ok==0)
					break;
				





			}
			


		}
		/*fab(0,n,i)
		cout<<mark[i]<<" ";
		cout<<endl;
		*/

		
		cout<<(ok?ans:"-1")<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}