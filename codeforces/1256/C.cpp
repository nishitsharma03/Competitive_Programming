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
	
	{
		int n,m,d;
		cin>>n>>m>>d;
		ll c[m];
		int sum=0;
		fab(0,m,i)
		{cin>>c[i];
		sum+=c[i];}
		int a[n+1]={0};
		int i=0,j=0;
		while(i<n+1 and j<m)
		{

			ll moveto=min(n+1-sum,i+d);
		//	cout<<"I:"<<i<<" "<<moveto<<endl;
			fab(moveto,moveto+c[j],pp)
			a[pp]=j+1;
			i=moveto+c[j]-1;
			sum-=c[j];
			j++;
		}
		if(i+d<=n)
			cout<<"NO\n";
		else
		{
			cout<<"YES\n";
			fab(1,n+1,l)
			cout<<a[l]<<" ";
		}

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}