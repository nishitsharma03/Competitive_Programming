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
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		vector<int > a(n),b(n);
		map<int , int > m;
		fab(0,n,i)
		{
			cin>>a[i];
			//m[a[i]].pb(i);
			b[i]=a[i];
		}
		sort(all(b));
	int i=0,j=n-1;
	int k=0;
	int cntf=0,cntb=0;
	while(i<=j and k<n)
	{
		if(a[i]==b[k])
		{
			cntf++;
			i++;
			k++;
		}
		else if(a[j]==b[k])
		{
			cntb++;
			j--;
			k++;
		}
		else
		{
			while(i<=j and a[i]!=b[k])

			{
				m[a[i]]++;
				i++;

			}
			cntf=0;
		}
		while(k<n and m[b[k]])
		{
			m[b[k]]--;
			k++;

		}
	}
	//cout<<"cntf:"<<cntf<<" "<<cntb<<endl;
	cout<<n-(cntf+cntb)<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}