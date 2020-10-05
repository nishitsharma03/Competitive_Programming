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
 vector< vector< pair<int,int> > > v;
 map<int, vector<int> > m;

vector<int> subreversal, lev;
 int dfs( int src, int par, int req)
 {
 	int needtoreverse=0;
 	
 	subreversal[src]=req;
 	if(par!=-1)
 		lev[src]=lev[par]+1;
 	else
 		lev[par]=0;
 	// cout<<"src:"<<src<<" "<<req<<endl;
 	for(auto i: v[src])
 	{
 		if(i.f^par)
 		{
 			needtoreverse+=i.se;
 			needtoreverse+=dfs(i.f,src,req+i.se);
 			

 		}
 	}
 	//cout<<"needtoreverse:"<<needtoreverse<<" "<<src<<endl;
 	return needtoreverse;

 }

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
    int n;
    cin>>n;
     v= vector< vector< pair<int,int> > > (n);
     subreversal= vector<int> (n);
     
     lev= vector<int> (n);
     fab(1,n,i)
     {
     	int a,b;
     	cin>>a>>b;
     	a--;
     	b--;
     	v[a].pb({b,0});
     	v[b].pb({a,1});
     }
    int tot= dfs(0,-1,0);
   // cout<<"tot:"<<tot<<endl;
     
     fab(0,n,i)
     {
     	int req=tot- subreversal[i]+lev[i]-subreversal[i];
     	m[req].pb(i+1);
     }
     for( auto i: m)
     {
     	cout<<i.f<<endl;
     	for( auto j: i.se)
     		cout<<j<<" ";
     	break;
     }

	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}