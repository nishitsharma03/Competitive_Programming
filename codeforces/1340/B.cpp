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
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	//cin>>t;
	vector<string> dig={"1110111", "0010010", "1011101", "1011011", "0111010", "1101011", "1101111", "1010010", "1111111", "1111011"};
	t=1;
	while(t--)
	{
		ll int n,k;
		cin>>n>>k;
		ll int req[n][10]={0};

		string s[n];
		fab(0,n,i)
		{
			
			cin>>s[i];
			fab(0,10,j)
			fab(0,7,ki)
			{
				if(s[i][ki]=='0' and dig[j][ki]=='1')
					++req[i][j];
				else if(s[i][ki]=='1' and dig[j][ki]=='0')
					{req[i][j]=-1;
						break;}

			}
		}
		/*fab(0,n,i)
		{fab(0,10,j)
		cout<<req[i][j]<<" ";
		cout<<endl;}*/
		ll int dp[n+1][k+1]={0};
		fab(0,n+1,i)
		fab(0,k+1,j)
		dp[i][j]=0;
		dp[n][0]=1;
		for(int i=n;i>0;i--)
		{
			for(int j=0;j<=k;j++)
			{
				if(dp[i][j])
				{fab(0,10,p)
				{
					if(req[i-1][p]!=-1 and j+req[i-1][p]<=k )
						dp[i-1][j+req[i-1][p]]=1;
				}

				}
			}
		}
		/*fab(0,n+1,i)
		{
			fab(0,k+1,j)
			cout<<dp[i][j]<<" ";
			cout<<endl;
		}*/
		
		if(!dp[0][k])
		{
			cout<<-1<<endl;
			return 0;
		}
		fab(0,n,i)
		{
			ll int curr=-1;
			for(int j=9;j>=0;j--)
			{
				if(req[i][j]!=-1 and req[i][j]<=k and dp[i+1][k-req[i][j]]==1  )
				{
					curr=j;
					k-=req[i][j];
					break;
				}
			}
			//assert(curr!=-1);
			cout<<curr;
		}

	}
	

	return 0;
}