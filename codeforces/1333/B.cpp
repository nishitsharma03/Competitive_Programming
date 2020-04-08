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
		ll int n;
		cin>>n;
		ll int  a[n],b[n];
		fab(0,n,i)
		{
			cin>>a[i];

		}
		fab(0,n,i)
		cin>>b[i];
		string ans="YES";
		if(a[0]!=b[0])
			ans="NO";
		ll int min=a[0],max=a[0];
		fab(1,n,i)
		{
			if(b[i]<a[i]&&min>=0)
				ans="NO";
			if(b[i]>a[i]&&max<=0)
				ans="NO";
			if(a[i]<min)
				min=a[i];
			if(a[i]>max)
				max=a[i];
		}
		cout<<ans<<endl;
	}
	

	return 0;
}