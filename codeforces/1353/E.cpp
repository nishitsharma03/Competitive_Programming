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
int dp[2*1000005];
int suff[2*1000005];
int cnt[2*1000005]={0},cnt1[2*1000005];
int n,k;
string s;
int recurse(int pos)
{
	if(pos>=n)
		return 0;
	if(dp[pos]!=-1)
		return dp[pos];
	if(pos+k>=n)
	{
		return dp[pos]=min(suff[pos],cnt[pos]+s[pos]-'0');
	}

	else
	{
		return dp[pos]=min(suff[pos]+recurse(pos+k),cnt[pos]+s[pos]-'0');
	}
}
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
		//ll int n,k;
		cin>>n>>k;
		//string s;
		cin>>s;
		while(n>0 and s[n-1]=='0')
			n--;
		if(n<2)
		{
			cout<<0<<endl;
			continue;
		}
		int st=0;
		fab(0,n,i)
		{
			if(s[i]=='1')
			{
				st=i;
				break;
			}
		}

		fab(0,n+k+1,i)
		{dp[i]=-1;
		suff[i]=0;
		cnt[i]=0;
		cnt1[i]=0;
		}
		
		int tot=0;
		for(int i=n-1;i>=0;i--)
		{
			if(s[i]=='0')
			{
				//suff[i]=1+(cnt);
				cnt[i]=tot;
				suff[i]=1+(cnt[i]-cnt[i+k-1]);

			}
			else if(s[i]=='1')
			{
				//cout<<"SGFD"<<i<<endl;
				//suff[i]=(cnt-suff[i+k]);
				cnt[i]=tot;
				suff[i]=(cnt[i]-cnt[i+k-1]);
				tot++;

			}
			//	cout<<cnt[i]<<" "<<i<<" "<<tot<<endl;
		}
		//fab(0,n,i)
		//cout<<suff[i]<<" ";
		//cout<<endl;
		int pp=0;
		fab(0,n,i)
		{
			recurse(i);
			
			cnt1[i]=pp;
			if(s[i]=='1')
				pp++;
		}
		int mn=count(all(s),'1')-1;
		fab(0,n,i)
		{

			/*int ut=0,tt=0;
			int j=i-k;
			while(j>=st)
			{
				
				if(s[j]=='1')
					ut++;
				else
					tt++;
				j-=k;
			}*/

			//cout<<dp[i]<<" "<<cnt1[i]<<" "<<ut<<" "<<tt<<" "<<cnt[i]<<endl;
			mn=min(mn,(dp[i]+cnt1[i]));
		}
		cout<<mn<<endl;


	}
	
	

	return 0;
}