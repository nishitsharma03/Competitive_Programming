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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	string s;
	cin>>s;
	int n=s.length();
	int br=-1;
	fab(0,n,i)
	{
		if(s[i]=='|')
		{
			br=i;
			break;
		}
	}
	string t;
	cin>>t;
	string a1=s.substr(0,br),a2=s.substr(br+1,n-1-br);
	//cout<<"a!:"<<a1<<" "<<a2<<endl;

	int k=a1.size()-a2.size();
	k=abs(k);
	if((t.length()+s.length()-1)%2 or k>t.length())
	{
		cout<<"Impossible\n";
	}
	else
	{
		int i=0;
		while(a1.length()<a2.length())
	{		a1+=t[i];
		i++;
	}
	while(a1.length()>a2.length())
	{		a2+=t[i];
		i++;
	}
	while(i<t.length())
	{
		a1+=t[i];
		i++;
		a2+=t[i];
		i++;
	}

	
	cout<<a1<<"|"<<a2<<endl;
}

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}