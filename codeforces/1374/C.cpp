//#pragma GCC optimize "trapv"
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
//ll lcm(ll x, ll y) {ll res = (x * y) / __gcd(x, y); return res;}
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
		ll n;
		cin>>n;
		string s;
		cin>>s;
		int op=0,cl=0;
		ll ans=0;
		bool flag=0;
		vector<int> rem;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='(')
			op++;
		else
			cl++;
		if(op>cl)
			{rem.pb(i);
				op--;
			}


		}


		for(auto i: rem)
			{//cout<<i<<" ";
				s.erase(i);
			}
		op=0;
		cl=0;
		fab(0,s.size(),i)
		{
			if(s[i]=='(')
				{	
					op++;
					

				}
			else
				cl++;
			if(cl>op)
				{ans++;
			flag=1;
			op++;
			}
		}
		cout<<ans<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}