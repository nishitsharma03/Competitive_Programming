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
	int t;
	cin>>t;
	string va="";
	char lo='a';
	fab(0,26,i)
	{va+=lo;
	lo++;}
	lo='A';
	fab(0,26,i)
	{va+=lo;
	lo++;}
	lo='0';
	fab(0,10,i)
	{va+=lo;
	lo++;}
	while(t--)
	{

		int r,c,k;
		cin>>r>>c>>k;
		vector<string> a(r);
		char ans[r][c];

		fab(0,r,i)
		cin>>a[i];
		int cnt=0;
		fab(0,r,i)
		{
			fab(0,c,j)
			cnt+=(a[i][j]=='R');
		}

		int perchk=(cnt)/k;
		int modi=cnt%k;
		int chk=0,req=perchk;
		int tot=0;
		if(chk<modi)
			req++;

		fab(0,r,i)
		{
			if(i%2)
			fab(0,c,j)
			{
				tot+=((a[i][j]=='R'));
				ans[i][j]=va[chk];
				if(tot==req)
				{
					if(chk<k-1)
					chk++;
					tot=0;
					req=perchk;
					if(chk<modi)
						req++;
				}

			}
			else
				for(int j=c-1;j>=0;j--)
			{
				tot+=((a[i][j]=='R'));
				ans[i][j]=va[chk];
				if(tot==req)
				{	
					if(chk<k-1)
					chk++;
					tot=0;
					req=perchk;
					if(chk<modi)
						req++;
				}

			}
		}
		fab(0,r,i)
		{
			fab(0,c,j)
			cout<<ans[i][j];
			cout<<endl;
		}

	}
	
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}