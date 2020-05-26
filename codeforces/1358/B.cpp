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
		int a[n];
		fab(0,n,i)
		cin>>a[i];
		sort(a,a+n);
		int ans=1;
		bool flag=0;
		for(int i=n-1;i>=0;i--)
			//fab(0,n,i)
		{
			//cout<<a[i]<<" ";
			if(a[i]-(i+1)<=0)
			{
				ans+=(i+1);
				flag=1;
				break;
			}
		}
		
		cout<<ans<<endl;
	}
	

	return 0;
}