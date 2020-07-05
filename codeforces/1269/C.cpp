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
ll power(ll x, ll y) {ll res = 1; x %= MOD; while (y) {if (y & 1)res = mul(res, x); y >>= 1; x = mul(x, x);} return res;}
ll mod_inv(ll x) {return power(x, MOD - 2);}

using namespace std;
bool isgood(string s,int n,int k)
{
	fab(0,k,i)
	{
		int j=i;
		set<int> p;
		while(j<n)
		{
			p.insert(s[j]-'0');
			j+=k;
		}
		if(p.size()>1)
			return false;
		

	}
	return true;
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int n,k;
	cin>>n>>k;
	string s;
	cin>>s;
	string tt=s;
	if(isgood(s,n,k))
	{
		cout<<s.size()<<endl;
		cout<<s<<endl;
		return 0;
	}
	 bool isbig=0;
		for(int i=k-1;i>=0 ;i--)
		{
			int j=i;
		
		

		
		
		j=i;
		while(j<n)
		{
			s[j]=s[i];
			j+=k;
		}

	
	

	}
	//cout<<s<<endl;
	if(s>tt)
	{
		cout<<s.length()<<endl;
		cout<<s<<endl;
		return 0;
	}
	for(int i=k-1;i>=0;i--)
	{
		if(s[i]!='9')
			{s[i]++;
		int j=i;
		while(j<n)
		{
			s[j]=s[i];
			j+=k;
		}
		fab(i+1,k,l)
		{
			s[l]='0';
			int j=l;
		while(j<n)
		{
			s[j]=s[l];
			j+=k;
		}
		}
		break;}
	}
	
	cout<<s.size()<<endl;
	cout<<s<<endl;




 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}