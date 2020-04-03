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
		ll int a[n];
		fab(0,n,i)
		cin>>a[i];
		int ch[500]={0};
		fab(0,n,i)
		{
			ch[a[i]]=1;
		}
		int i=1;
		ll int cnt=0;
		while(cnt!=x)
		{
			if(ch[i]==0)
				{cnt++;
					ch[i]=1;
					//cout<<ch[i]<<" g";
				}
			
			i++;
		}
		int ans=0;
		fab(1,500,i)
		{

			if(ch[i]==1)
				{	
					ans=i;
				}
				else
					break;
		
		}
		cout<<ans<<endl;
	}
	

	return 0;
}