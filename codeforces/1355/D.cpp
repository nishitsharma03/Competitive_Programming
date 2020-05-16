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
	int t=1;
	//cin>>t;
	while(t--)
	{
		ll int n,s;
		cin>>n>>s;
		if(n==1)
		{
			if(s!=1)
			{cout<<"YES\n";
			cout<<s<<endl;
			cout<<s-1<<endl;
			}
			else if(s==1)
			{
				cout<<"NO\n";
			}
			continue;
		}
		if(s<2*n)
		{
			cout<<"NO\n";
		}
		else
		{
			cout<<"YES\n";
			fab(0,n-1,i)
			cout<<2<<" ";
			cout<<s-2*(n-1)<<endl;
			cout<<1<<endl;
		}
	}
	

	return 0;
}