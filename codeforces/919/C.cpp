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

int arrangeinrow(vector<string> &v, int n, int m, int k)
{
	int ans=0;
	fab(0,n,i)
	{
		int cnt=0;
		fab(0,m,j)
		{
			if(v[i][j]=='*')
				cnt=0;
			else
				cnt++;
			if(cnt>=k)
				ans++;

		}
	}
	return ans;
}
int arrangeincol(vector<string> &v, int n, int m, int k)
{
	int ans=0;
	fab(0,m,i)
	{
		int cnt=0;
		fab(0,n,j)
		{
			if(v[j][i]=='*')
				cnt=0;
			else
				cnt++;
			if(cnt>=k)
				ans++;

		}
	}
	return ans;
}

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	 int n,m,k;
	 cin>>n>>m>>k;
	vector<string> v(n);
	fab(0,n,i)
	cin>>v[i];
	if(k==1)
	{
		int cnt=0;
		fab(0,n,i)
		fab(0,m,j)
		cnt+=v[i][j]=='.';
		cout<<cnt<<endl;
		return 0;
	}
	cout<<arrangeincol(v,n,m,k)+arrangeinrow(v,n,m,k)<<endl;


 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}