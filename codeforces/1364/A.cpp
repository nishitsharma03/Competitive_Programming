//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
//#define endl "\n"
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
		int n;
		cin>>n;
		int x;
		cin>>x;
		int a[n],sum=0;
		fab(0,n,i)
		{cin>>a[i];
		sum+=a[i];}
		int l=0, r=n-1,ans=0;
		if(sum%x!=0)
	{		cout<<n<<endl;
		continue;
	}
		//cout<<"sum:"<<sum<<endl;
		int tot;
		int pp=0,st=n-1;
		sum=0;
		fab(0,n,i)
		{
			sum+=a[i];
			if(sum%x!=0)
			{
				st=i;
				break;
			}
		}
		int yy=0,et=n-1;
		sum=0;
		fab(0,n,i)
		{
			sum+=a[n-i-1];
			if(sum%x!=0)
			{
				et=i;
				break;

			}
		}

		if(min(et,st)!=n-1)
		cout<<n-min(et,st)-1<<endl;
		
			
	else
		cout<<-1<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}