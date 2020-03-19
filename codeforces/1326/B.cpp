#pragma GCC optimize "trapv"
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
	ll int n;
	cin>>n;
	ll int b[n];
	fab(0,n,i)
	cin>>b[i];
	ll int a[n];
	a[0]=b[0];
	ll int max=a[0];
	fab(1,n,i)
	{
		a[i]=b[i]+max;
		if(a[i]>max)
			max=a[i];

	}
	fab(0,n,i)
	cout<<a[i]<<" ";
	cout<<endl;

	return 0;
}