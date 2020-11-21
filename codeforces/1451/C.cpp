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
	while(t--)
	{
		int n,k;
		cin>>n>>k;
		string a,b;
		cin>>a>>b;
		vector<int> x(27),y(27);
		fab(0,n,i)
		{
			x[a[i]-'a']++;
			y[b[i]-'a']++;

		}
		bool ok=1;
		fab(0,26,i)
		{
			//cout<<"x:"<<x[i]<<" "<<y[i]<<endl;
			if(y[i]>x[i])
			{
				ok=0;
				break;
			}
			ll rem=x[i]-y[i];
			
			//cout<<"rem?"<<rem<<" ";
				x[i+1]+=(rem - rem%k);
				x[i]=y[i]+(rem%k);
				
			
			
//			cout<<"x:"<<x[i]<<" "<<y[i]<<endl;

		}
		fab(0,27,i)
		{
			//cout<<"x:"<<x[i]<<" "<<y[i]<<endl;
			ok&=(x[i]==y[i]);
		}
		cout<<(ok?"YES":"NO")<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}