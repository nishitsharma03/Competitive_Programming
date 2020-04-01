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
	cin>>t;
	while(t--)
	{
		ll int n,x;
		cin>>n>>x;
		string s;
		cin>>s;
		ll int cnt[2]={0};
		ll int maxdif=0;
		fab(0,n,i)
		{
			cnt[s[i]-'0']++;
			if(cnt[0]-cnt[1]>maxdif)
				maxdif=cnt[0]-cnt[1];

		}
		ll int diff=cnt[0]-cnt[1];
		ll int c=0;
		if(diff==0)
		{
			ll int ans=0;
			fab(0,n,i)
			{
				if(s[i]=='1')
					c--;
				else
					c++;
				if(c==x)
				{
					ans=-1;
					break;
				}
			}

				{cout<<ans<<endl;
					continue;}
		}
		
	
			
			ll int ans=0;
			
			fab(0,n,i)
			{
				if((abs(x-c)%abs(diff))==0)
					if((x-c)/diff>=0)
						ans++;



				if(s[i]=='1')
					c--;
				else
					c++;
				
			}
			cout<<ans<<endl;

		
	}
	

	return 0;
}