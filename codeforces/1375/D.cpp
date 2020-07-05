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
int getmex(int n, int a[])
{
	bool marked[1002];
	memset(marked,0,sizeof(marked));
	fab(0,n,i)
	marked[a[i]]=1;
	fab(0,1002,i)
	if(!marked[i])
		return i;
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
		int n;
		cin>>n;
		int a[n];
		fab(0,n,i)
		cin>>a[i];
		bool ok=1;
		vector<int> ans;
		while(ok)
			{
				int k=getmex(n,a);
				if(k==n)
			{
				fab(0,n,i)
				{
					if(a[i]!=i)
					{
						a[i]=n;
						ans.pb(i);
						break;
					}
				}
			}
			else
			{
				a[k]=k;
				ans.pb(k);
			}
			ok=0;
			fab(0,n,i)
			{
				if(a[i]!=i)

				{
					ok=1;
					break;
				}
			}

		}
		cout<<ans.size()<<endl;
		for(auto i:ans)
			cout<<i+1<<" ";
		cout<<endl;

	

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}