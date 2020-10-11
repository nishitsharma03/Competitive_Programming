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
#define int ll
const int N=2e5+5;
int seg[2*N];
int n;
vector<int> a;

void update( int ind, int val)
{
	ind =ind+n;
	seg[ind]+=val;
	for( int i=ind;i>1;i/=2)
		seg[i/2]=seg[i]+seg[i^1];

}

int query( int l, int r)
{
	l+=n;r+=n;
	int ans=0;
	while(l<r)
	{
		if(l%2)
		{
			ans+=seg[l++];
			
		}
		if(r%2)
		{
			ans+=seg[--r];
			
		}
		l/=2;
		r/=2;
	}
	return ans;
}

int32_t main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	string s;
	
	cin>>n;
	cin>>s;
	map<char, vector<int> > m;
	fab(0,n,i)
	{
		m[s[i]].pb(i);
	}
	string s1=s;
	a= vector<int> (n);
	reverse(all(s1));
	for( int i=n-1;i>=0;i--){
		a[i]=m[s1[i]].back();
		m[s1[i]].pop_back();
	}
	int ans=0;
	for( int i=n-1;i>=0;i--)
	{
		ans+=query(0,a[i]);
		//cout<<"qq:"<<(query(0,a[i]))<<endl;
		update(a[i],1);

	}
	cout<<ans<<endl;

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}