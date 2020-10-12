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
int n,k,m;
int best[505][505];
ll dp[505][505];
vector<string> v;
vector<int> tot;

 ll recurse(int pos,int left)
 {
 	if(pos>=n)
 		return 0;
 	
 	if(dp[pos][left]!=-1)
 		return dp[pos][left];
 	dp[pos][left]=INT_MAX;
 	
 	fab(0,tot[pos]+1,i)
 	{
 		if(left>=i)
 		dp[pos][left]=min(dp[pos][left],recurse(pos+1,left-i)+best[pos][i]);
 	}
 	return dp[pos][left];


 }

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    cin>>n>>m>>k;
    v= vector<string > (n);
    tot= vector<int> (n,0);
    fab(0,505,i)
    {
    	fab(0,505,j)
    	dp[i][j]=-1;
    }

    fab(0,n,i)
    {
    	cin>>v[i];
    for(auto j: v[i])
    	tot[i]+=(j-'0');

	}
	//fab(0,n,i)
	//cout<<tot[i]<<" ";
	fab(0,n,pp)
	{
		int pos=pp;
		vector<int> a(tot[pos]+1,INT_MIN);
 	vector<int> b(tot[pos]+1,INT_MAX);
 	
 	int cnt=0;
 	int last=-1;
 	fab(0,m,i)
 	{
 		if(v[pos][i]=='1')
 			last=i;
 	}
 	int first=-1;
 	fab(0,m,i)
 	{	if(v[pos][i]=='1')
 		{first=i;
 		break;}

 	}
 	
 	fab(0,last+1,i)
 	{
 		
 		
 		a[cnt]=max(a[cnt],i);
 		cnt+=(v[pos][i]-'0');




 	}
 	if(first==-1)
 		{best[pp][0]=0;
 		continue;}
 	cnt=0;
 	for( int i=m-1;i>=first;i--)
 	{
 		b[cnt]=min(b[cnt],i);
 		cnt+=(v[pos][i]-'0');

 	}
 	a[tot[pos]]=last;
 	b[tot[pos]]=first;
 	//cout<<"ff:"<<first<<" "<<last<<endl;
 	
 	// cout<<pos<<" "<<left<<endl;
 	//  fab(0,tot[pos]+1,i)
 	//  cout<<a[i]<<" "<<b[i]<< " ";
 	//  cout<<endl;
 	vector<int> happy(tot[pos]+1,INT_MAX);
 	for( int i=0;i<=tot[pos];i++)
 	{
 		happy[i]=min(last-a[i]+1,b[i]-first+1);
 	//	cout<<"hh:"<<happy[i]<<" ";
 		for( int j=0;j<=i;j++)
 		{
 			//cout<<"j:"<<j<<" "<<i<<endl;
 			if(b[j]>=a[i-j])
 			happy[i]=min(happy[i],(b[j]-a[i-j]+1));
 			
 		}
 		// cout<<happy[i]<<" ";
 	}
 	happy[tot[pos]]=0;
 	fab(0,tot[pos]+1,i)
 	best[pp][i]=happy[i];
	}

	ll val=recurse(0,k);
	cout<<val<<endl;
	
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}