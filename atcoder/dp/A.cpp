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

int main()
{ quick;

	int n;
	cin>>n;
	int h[n];
	fab(0,n,i)
	cin>>h[i];
	vector<int> dp(n);
	dp[n-1]=0;
	dp[n-2]=abs(h[n-1]-h[n-2]);

	for(int i=n-3;i>=0;i--)
	{
		dp[i]=min(dp[i+1]+abs(h[i+1]-h[i]),dp[i+2]+ abs(h[i+2]-h[i]));
	}
	cout<<dp[0]<<endl;

	return 0;
}