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
		ll int n,m;
		cin>>n>>m;
		if(n==2 and m==2 )
		{
			cout<<"YES\n";
			//continue;
		}
		else if(n==1 or m==1)
		{
			cout<<"YES\n";
		}
		else
		{
			
				cout<<"NO\n";
			
		}
		//cout<<(n%5+5)%5<<endl<<(m%5+5)%5<<endl<<(-100%5+5)%5<<endl<<2<<endl<<4;
	}
	

	return 0;
}