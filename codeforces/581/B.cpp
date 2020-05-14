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
	ll int n;
	cin>>n;
	ll int a[n+1];
	fab(0,n,i)
	cin>>a[i];
	a[n]=0;
	ll int suff[n];
	ll int mx=a[n];
	for(int i=n-1;i>=0;i--)
	{

		mx=max(mx,a[i+1]);
		suff[i]=mx;

	}
	//fab(0,n,i)
	//cout<<suff[i]<<" ";
	//cout<<endl;
	fab(0,n,i)
	{
		cout<<(suff[i]>=a[i]?suff[i]-a[i]+1:0)<<" ";
	}

	return 0;
}