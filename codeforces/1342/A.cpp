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
		ll int x,y;
		cin>>x>>y;
		ll int a,b;
		cin>>a>>b;
		
		
		ll int diff=abs(x-y);
		//cout<<"gg"<<diff<<endl;
		ll int sm=min(x,y);
		if (2*a < b) cout << (x+y)*a << endl;
		else
		
		cout<<diff*a+sm*b<<endl;
	

	}
	

	return 0;
}