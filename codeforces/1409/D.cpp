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
ll digsum(string s)
{
	int sum=0;
	int n=s.length();
	fab(0,n,i)
	sum+=(s[i]-'0');
	return sum;
}
ll getpow[19];
void precomp()
{
	getpow[0]=1;
	fab(1,19,i)
	getpow[i]=10*getpow[i-1];
}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	precomp();
	while(t--)
	{
		ll n;
		cin>>n;
		ll s;
		cin>>s;
		ll temp=n;
		string num="";
		while(temp>0)
		{
			num+=char('0'+temp%10);
			temp/=10;
		}
		
		int sum=digsum(num);
		if(sum<=s)
		{
			cout<<0<<endl;
			continue;
		}

		int i=0;
		ll ans=0;
		while(sum>s and i<num.length())
		{
			
				 int dig=num[i]-'0';
				 dig=10-dig;
				// cout<<"check:"<<" "<<i<<" "<<power(10,i)*dig<<endl;
				ans+=(getpow[i]*dig);
				num[i]='0';
				int j=i+1;
				while(j<num.length() and num[j]=='9')
					{num[j]='0';
					j++;}
					if(j<num.length())
					{
						num[j]++;
					}
					else num+='1';
					sum=digsum(num);
				i++;
			
		}
		
		//int ans=0;
		cout<<ans<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}