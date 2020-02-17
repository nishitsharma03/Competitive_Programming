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
		int n,d;
		cin>>n>>d;
		int a[n];
		fab(0,n,i)
		{
			cin>>a[i];
		}
		int i=1,days=d;
		int sum=0;
	while(i<n&&days>=i)
	{				if(a[i]>=(days/i))
					{sum+=days/i;

						days=days%i;}
						else
					{		sum+=a[i];
					
							days-=a[i]*i;
					}
				
			
			i++;
		


	}
	cout<<sum+a[0]<<endl;
	}

	return 0;
}