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
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
int h,w;
ll dp[1005][1005];
void builddp(string s[])
{
	for(int i=0;i<h;i++)
	{
		if(s[i][0]=='.')
			dp[i][0]=1;
		else
			break;
	}
	for(int i=0;i<w;i++)
	{
		if(s[0][i]=='.')
			dp[0][i]=1;
		else
			break;
	}
	for(int i=1;i<h;i++)
	{
		fab(1,w,j)
		{
			if(s[i][j]=='#')
				continue;
			dp[i][j]=(dp[i-1][j]+dp[i][j-1])%MOD;
		}
	}
	cout<<dp[h-1][w-1]<<endl;
}
int main()
{ quick;

    cin>>h>>w;
    string s[h];
    fab(0,h,i)
    cin>>s[i];
    builddp(s);
	

	return 0;
}