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
//#define endl "\n"
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
const int N=2e5+5;

int seg[4*N];
vector<int> v;
 void build( int node, int l, int r)
 {
 	if(l==r)
 	{
 		seg[node]=v[l];
 	}
 	else
 	{
 		int mid=(l+r)/2;
 		build(2*node,l,mid);

 		build(2*node+1,mid+1,r);
 		seg[node]=max(seg[2*node], seg[2*node+1]);	
 	}
 }

 int query( int node,int l, int r, int s, int e)
 {
 	if(l>e or r<s)
 		return 0;
 	if(s<=l and r<=e)
 		return seg[node];
 	int mid=(l+r)/2;
 	return max( query(2*node,l,mid,s,e), query(2*node+1,mid+1,r,s,e));
 }

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
		v.clear();
		int n,k;
		cin>>n>>k;
		fab(0,4*n+1,i)
		seg[i]=0;
		int  a[n];
		fab(0,n,i)
		{
			cin>>a[i];

		}

		fab(0,n,i)
		{ int kkk;
			cin>>kkk;
		}
		sort(a,a+n);
	
		int i=0;
		int j=0;
		int left,right;
		int ans1=0,ans=0;
		
		while(i<n)
		{
			while(j<n and a[j]-a[i]<=k)
			{
				j++;
			}
			v.pb(j-i);
			i++;
			

		}
		build(1,0,v.size()-1);
		//cout<<"first"<<ans<< " "<<left<<" "<<right<<endl;
		int cnt=0;
		i=0,j=0;
		
		//cout<<"qqqL"<<query(1,0,v.size()-1,5,v.size()-1)<<endl;
		while(i<n)
		{
			while(j<n and a[j]-a[i]<=k)
			{
				
				j++;
			}

			auto kk= lower_bound(a,a+n,a[j-1]+1)-a;
			auto jj= lower_bound(a,a+n,a[i]-k)-a;
			//cout<<"i:"<<i<<" "<<j<<" "<<jj<<" "<<kk<<endl;
			int op=query(1,0,v.size()-1,0,jj-1);
			if(jj==0)
				op=i;
			int kp=query(1,0,v.size()-1,kk,v.size()-1);
			//cout<<"op:"<<op<<" "<<kp<<endl;

			ans1=max(ans1,j-i+max(op,kp));
			
			i++;
		}
		//cout<<"dec:"<<ans1<<endl;
		cout<<ans1<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}