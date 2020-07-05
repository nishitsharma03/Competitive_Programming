//#pragma GCC optimize "trapv"
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
	int t;
	cin>>t;
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string s;
		cin>>s;
		int cnt=0;
		vector<pii > v;
		int i=0;
		
		while(cnt<k-1)
		{
			if(i&1)
			{
				
					int j=i;
					while(j<n and s[j]!=')')
					{
						j++;
					}
					reverse(s.begin()+i,s.begin()+j+1);
					v.pb({i,j});
					cnt++;

			}
			else
			{
				int j=i;
				while(j<n and s[j]!='(')
					{
						j++;
					}
					reverse(s.begin()+i,s.begin()+j+1);
					v.pb({i,j});
			}
			
			i++;

		}
		
		while(i<n)
		{
			int j=i;
			//cout<<"J:"<<j<<endl;
			while(j<n and s[j]!='(')
			{
				j++;

			}
			if(j==n)
				break;
			reverse(s.begin()+i,s.begin()+j+1);
					v.pb({i,j});
					i++;
		}
		
		while(i<n)
		{
			int j=i;
			while(j<n and s[j]!=')')
			{
				j++;

			}
			if(j==n)
				break;
			reverse(s.begin()+i,s.begin()+j+1);
					v.pb({i,j});
					i++;

		}
		//cout<<"S:"<<s<<endl;
		cout<<v.size()<<endl;
		for(auto j: v)
			cout<<j.f+1<<" "<<j.se+1<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}