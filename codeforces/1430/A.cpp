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
	int ans=0;
	while(t--)
	{
		 int n;
		 cin>>n;
		 bool ok=0;
	
		 fab(0,n+1,i)
		 {
		 	int rem=n-7*i;
		 	//a+b=n-i
		 	// 5*a + 7*b=rem
		 	if(rem<0)
		 		break;
		 	fab(0,rem+1,j)
		 	{
		 		int rem2=rem-5*j;
		 		if(rem2<0)
		 			break;
		 		if(rem2%3==0)
		 		{
		 			ok=1;
		 			cout<<rem2/3<<" "<<j<<" "<<i<<endl;
		 			break;
		 		}

		 	}
		 	if(ok)
		 		break;
		 	
		 }
		 if(!ok)
		 	cout<<-1<<endl;

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}