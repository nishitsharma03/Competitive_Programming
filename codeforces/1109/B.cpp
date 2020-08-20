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
bool ispalindrome(string s)
{
	int n=s.length();
	bool ok=1;
	fab(0,n,i)
	ok&=(s[i]==s[n-1-i]);
	return ok;
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	string s;
	cin>>s;
	
	int n=s.length();
	int freq[26]={0};
	fab(0,n,i)
	{
		freq[s[i]-'a']++;
	}
	fab(0,26,i)
	{
		if(freq[i]>=n-1)
		{
			cout<<"Impossible"<<endl;
			return 0;
		}
	}


	string tm="";
	fab(0,n,i)
	{
		tm+=s[i];
		string k=s.substr(i+1,n-i)+tm;
		
		if(k!=s and ispalindrome(k))

		{
			cout<<1<<endl;
			return 0;
		}


	}
	cout<<2<<endl;

	return 0;



	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}