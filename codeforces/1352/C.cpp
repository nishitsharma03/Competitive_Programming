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
		ll int n,k;
		cin>>n>>k;
		if(k%(n-1)!=0)
		{ll int bas=k/(n-1);
		cout<<n*bas+k%(n-1)<<endl;}
		else
		{
			ll int bas=k/(n-1);
			cout<<n*bas-1<<endl;

		}
	}
	

	return 0;
}