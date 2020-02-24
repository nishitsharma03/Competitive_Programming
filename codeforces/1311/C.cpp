#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
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

		int n,m;
		string s;
		cin>>n>>m;
		cin>>s;
		int a[m];
		fab(0,m,i)
		cin>>a[i];
		int dp[n+1][26]={0};

		fab(1,n,i)
		{
			dp[i][s[i-1]-'a']++;
			fab(0,26,j)
			dp[i+1][j]=dp[i][j];

		}
		
		dp[n][s[n-1]-'a']++;
		int total[26]={0};
		fab(0,m,i)
		{
			fab(0,26,j)
			total[j]+=dp[a[i]][j];
		}
		fab(0,26,j)
		total[j]+=dp[n][j];
		fab(0,26,i)
		cout<<total[i]<<" ";
		cout<<endl;

	}

	return 0;
}