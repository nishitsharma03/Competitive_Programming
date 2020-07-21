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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL);cout.tie(NULL)
ll add(ll x, ll y) {ll res = x + y; return (res >= MOD ? res - MOD : res);}
ll mul(ll x, ll y) {ll res = x * y; return (res >= MOD ? res % MOD : res);}
ll sub(ll x, ll y) {ll res = x - y; return (res < 0 ? res + MOD : res);}
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
char toggle(char a)
{
	if(a=='1')
		return '0';
	else
		return '1';
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		string a,b;
		int n;
		cin >> n;

		cin>>a>>b;
		vector<int> ans;
		//cout<<"a::"<<a<<" " <<b<<endl;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]==b[i])
				continue;
			else 
			{
				if(a[0]==b[i])
				{
					
					ans.pb(1);
					a[0]=toggle(a[0]);
					ans.pb(i+1);
				}
				else
				{
					ans.pb(i+1);
				}
				fab(0,i+1,j)
				a[j]=toggle(a[j]);
				reverse(a.begin(),a.begin()+i+1);
				
				


			}

		}
		//cout<<"a:"<<a<<endl<<"b:"<<b<<endl;
		cout<<ans.size()<<" ";
		for(auto i: ans)
			cout<<i<<" ";
		cout<<endl;


	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}