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
	ll int a[32];
		ll int k=2;
		a[1]=k;
		fab(2,32,i)
		a[i]=a[i-1]*2;
	while(t--)
	{
		ll int n;
		cin>>n;
		
		cout<<a[n/2+1]-2<<endl;
	}
	

	return 0;
}