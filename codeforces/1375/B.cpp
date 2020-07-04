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
int n,m;
int valid(int i,int j)
{
	int cnt=0;
	if(i-1>=0)
		cnt++;
	if(j-1>=0)
		cnt++;
	if(i+1<n)
		cnt++;
	if(j+1<m)
		cnt++;
	return cnt;
}

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
		
		cin>>n>>m;
		ll a[n][m];
		fab(0,n,i)
		{
			fab(0,m,j)
			{
				cin>>a[i][j];
			}
		}
		string ans="YES";
		fab(0,n,i)
		{
			fab(0,m,j)
			{
				if(a[i][j]>valid(i,j))
				{
					ans="NO";
					break;
				}
				a[i][j]=valid(i,j);
			}
		}
		cout<<ans<<endl;
		if(ans=="YES")
		{
			fab(0,n,i)
			{
				fab(0,m,j)
				{
					cout<<a[i][j]<<" ";

				}
				cout<<endl;

			}
		}
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}