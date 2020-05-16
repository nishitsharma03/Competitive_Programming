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
vector< vector<int> > dp;
int n;
int cnt;
/*int recurse(int pos,int last,vector< vector<int> > v)
{
	//cnt++;
	//	cout<<cnt<<endl;
	if(dp[pos][last]!=-1)
		return dp[pos][last];
	//v[pos][last]=-1;
	if(pos==n-1)
	{
		v[pos][last]=-1;
		return dp[pos][last]=*max_element(all(v[pos]));
	}
	if(last==0)
	return dp[pos][last]=max({recurse(pos+1,1,v)+v[pos][1],recurse(pos+1,2,v)+v[pos][2]});
	else if(last==1)
		return dp[pos][last]=max({recurse(pos+1,0,v)+v[pos][0],recurse(pos+1,2,v)+v[pos][2]});
	else
		return dp[pos][last]=max(recurse(pos+1,1,v)+v[pos][1],recurse(pos+1,0,v)+v[pos][0]);
}*/
int main()
{ quick;


	cin>>n;
	vector< vector<int> > a(n, vector<int>(3));
	fab(0,n,i)
	{
		cin>>a[i][0]>>a[i][1]>>a[i][2];

	}
	dp= vector< vector<int> > (n,vector<int>(3,0));
	int ans=-1;
	fab(0,3,i)
	dp[0][i]=a[0][i];
	fab(1,n,i)
	{
		fab(0,3,j)
		{
			fab(0,3,k)
			if(j!=k)
			{
				dp[i][j]=max(dp[i][j],dp[i-1][k]+a[i][j]);
			}
		}
	}
	cout<<*max_element(all(dp[n-1]))<<endl;
	//for(auto p:dp[n-1])
	//	cout<<p<< " ";

	return 0;
}