//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define endl "\n"
#define f first
#define se second
#define all(x) x.begin(),x.end()
#define MOD 1000000007
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
bool ran(int x,int l,int r)
{return (x>=l and x<=r);}
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	
		ll int n,h,l,r;
		cin>>n>>h>>l>>r;
		vector<ll int> a(n);
		for(auto &i:a)
			cin>>i;
		ll int dp[n+1][h];
		fab(0,n+1,i)
		fab(0,h,j)
		dp[i][j]=0;
		//dp[0][0]=0;
		for(int i=n-1;i>=0;i--)
		{
			fab(0,h,j)
			{
				int t1=(j+a[i])%h;
				int t2=(j+a[i]-1)%h;
				dp[i][j]=max(dp[i+1][t1]+ran(t1,l,r),dp[i+1][t2]+ran(t2,l,r));
				
				//cout<<dp[i][j]<<" ";

			}
//			cout<<endl;

		}
		cout<<dp[0][0]<<endl;
	
	

	return 0;
}