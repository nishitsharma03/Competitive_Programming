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
    int t;cin>>t;
    while(t--)
	{int n;
	cin>>n;
	ll a[n];
	vector<pair<int,int> > pos,neg;

	fab(0,n,i)
	{cin>>a[i];
	if(a[i]>0)
		pos.pb({a[i],i});
	else
		neg.pb({a[i],i});}
	int i=0,j=0;
	ll ans=0;
	while(i<pos.size())
	{
		while(j<neg.size() and neg[j].se<pos[i].se)
		{
			j++;
		}
			//cout<<"ch:"<<i<<" "<<j<<endl;
			while(j<neg.size() and pos[i].f+neg[j].f>0)
			{
				pos[i].f+=neg[j].f;
				j++;
			}
			//cout<<"hh:"<<pos[i].f<<endl;
			if(pos[i].f>0 and j<neg.size())
			{
				neg[j].f+=pos[i].f;;
			}
			else
			{
				while(i<pos.size())
				{ans+=pos[i].f;
			i++;}
			break;
			}
			i++;
		
	}
	cout<<ans<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}