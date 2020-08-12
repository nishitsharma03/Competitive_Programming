//#pragma GCC optimize "trapv"
#pragma GCC optimize("O3", "unroll-loops")
#pragma GCC target("avx2")
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

int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int t=1;
	//cin>>t;
	while(t--)
	{
		int n,m,x,y;
		cin>>n>>m>>x>>y;
		int mat[n+1][m+1];
		fab(0,n+1,i)
		fab(0,m+1,j)
		mat[i][j]=0;
		mat[x][y]=1;
		cout<<x<<" "<<y<<endl;
		int curr=0,row=x;
		while(row>0)
		{
			if(curr==0)
			{
				curr=1;
				while(curr<m+1)
			{
				if(mat[row][curr]==0)
				{	cout<<row<<" "<<curr<<endl;
				mat[row][curr]=1;}
				curr++;
			
				}	
			
			}
			

			else
			{
				curr=m;
				while(curr>0)
				{
					if(mat[row][curr]==0)
			{		cout<<row<<" "<<curr<<endl;
					mat[row][curr]=1;		
			}
			curr--;

				}
			}
			row--;




		}
		row=x+1;
		while(row<n+1)
		{
			//cout<<"AD"<<endl;
			if(curr==0)
			{
				curr=1;
				while(curr<m+1)
			{
					if(mat[row][curr]==0)
				{	cout<<row<<" "<<curr<<endl;
					mat[row][curr]=1;}
					curr++;
			}
			}
			else
			{
				curr=m;
				while(curr>0)
				{
					if(mat[row][curr]==0)
			{		cout<<row<<" "<<curr<<endl;
					mat[row][curr]=1;		
			}
			curr--;

				}
			}
			row++;




		}

	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}