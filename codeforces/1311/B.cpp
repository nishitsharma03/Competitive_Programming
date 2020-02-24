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
int n,m;
		cin>>n>>m;
		int a[n+1];
		bool s[n];
		fab(0,n,i)
		s[i]=false;
		fab(1,n+1,i)
		cin>>a[i];
		int k;

		fab(0,m,i)
		{
			cin>>k;
			s[k]=true;
		}
		bool flag=true;
		fab(0,n,j)
		{	
			fab(1,n,i)
			{
			if(a[i+1]<a[i])
			{ 
				if(s[i]==false)
				{
					flag=false;
					break;
				}
				else
				{
					int temp=a[i+1];
					a[i+1]=a[i];
					a[i]=temp;
				}
			}
		}

		}
		if(flag)
			cout<<"YES\n";
		else
			cout<<"NO\n";

	}

	return 0;
}