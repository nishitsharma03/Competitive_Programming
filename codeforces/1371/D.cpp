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
		int n,k;
		cin>>n>>k;
		 int mat[n][n];
		 memset(mat,0,sizeof(mat));
		 int cnt=0;
		 int j=0;
		 while(cnt<k)
		 {
		 	fab(0,n,i)
		 	{
		 		mat[(i+j)%n][i]=1;
		 		cnt++;
		 		if(cnt>=k)
		 			break;

		 	}
		 	j++;
		 }
		 int row[n]={0},col[n]={0};
		 fab(0,n,i)
		 {
		 	fab(0,n,j)
		 	{
		 		row[i]+=mat[i][j];
		 		col[j]+=mat[i][j];
		 	}
		 }
		 ll kp=*max_element(row,row+n)-*min_element(row,row+n);
		 ll p=*max_element(col,col+n)-*min_element(col,col+n);
		 ll ans=kp*kp+p*p;
		 cout<<ans<<endl;
		
		 fab(0,n,i)
		 {
		 	fab(0,n,j)
		 	cout<<mat[i][j];
		 	cout<<endl;
		 }

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}