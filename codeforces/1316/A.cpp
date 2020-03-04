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
		cin>>n>>m;
		int a[n];
		ll int sum=0;
		fab(0,n,i)
		{
			cin>>a[i];
			if(i!=0)
				sum+=a[i];
		}
		if(sum>=(m-a[0]))
			cout<<m<<endl;
		else
			cout<<a[0]+sum<<endl;
	}
	

	return 0;
}