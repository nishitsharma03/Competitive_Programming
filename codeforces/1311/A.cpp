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
		ll int a,b;
		cin>>a>>b;
		if(a==b)
			cout<<0<<endl;

		if(b>a)
		{
			if((a%2==1&&b%2==0)||((a%2==0)&&b%2==1))
				cout<<1<<endl;
			else
				cout<<2<<endl;
	
		}
		if(a>b)
			{
				if((a%2==0&&b%2==0)||(a%2==1&&b%2==1))
				cout<<1<<endl;
			else
				cout<<2<<endl;

			}
	}

	return 0;
}