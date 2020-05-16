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
vector< vector<ll int> > dp;
ll int a[105],b[105];
ll int n,w;
ll int knapsack(int pos,ll int w)
{
	if(w<=0)
		return 0;
	if(pos>=n)
		return 0;


	if(dp[pos][w]!=-1)
		return dp[pos][w];
	if(w<a[pos])
		return dp[pos][w]=knapsack(pos+1,w);	
	if(pos==n-1)
		return dp[pos][w]=b[pos]; 
	return dp[pos][w]=max(knapsack(pos+1,w),knapsack(pos+1,w-a[pos])+b[pos]);



}

int main()
{ quick;

	
	cin>>n>>w;
	
	fab(0,n,i)
	cin>>a[i]>>b[i];
	dp=vector< vector<ll int> > (n,vector<ll int>(w+1,-1));
	knapsack(0,w);
	cout<<dp[0][w]<<endl;


	return 0;
}