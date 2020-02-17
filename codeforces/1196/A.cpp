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
		ll int a[3];
		fab(0,3,i)
		cin>>a[i];
		//int m=*max_element(a,a+3);
		ll int sum=a[0]+a[1]+a[2];
		cout<<sum/2<<endl;

	}

	return 0;
}