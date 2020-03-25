#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define quick ios_base::sync_with_stdio(false);cin.tie(NULL)
using namespace std;
bool triangleform(int a,int b,int c)
{
	if (a+b > c && a+c > b && b+c > a)
		return true;
	return false;
}
 
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
		ll int n,x;
		cin>>n>>x;
		ll int a[n];
		bool flag=false;
		fab(0,n,i)
		{
			cin>>a[i];
			if(a[i]==x)
				flag=true;
		}
		if(flag)
			cout<<"1"<<endl;
 
		//sort(a,a+n);
		else
			cout<<max((ll int )2,(ll int)ceil((db)x/(*max_element(a,a+n))))<<endl;

		
//cout<<min<<endl;
 
	}
 
	return 0;
}