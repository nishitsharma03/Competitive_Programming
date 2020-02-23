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
		int a[3];
		cin>>a[0]>>a[1]>>a[2];
		if(a[0]>3&&a[1]>3&&a[2]>3)
		{	cout<<7<<endl;
			continue;}

			int ans=0;
			if(a[0]>0)
			{
				a[0]--;
				ans++;
			}
			if(a[1]>0)
			{
				a[1]--;
				ans++;
			}
			if(a[2]>0)
			{
				a[2]--;
				ans++;
			}

			
				int flag=0;
				int bg=0;
				fab(0,3,i)
				{
					if(a[i]==0)
						flag++;
					if(a[i]>1)
						bg++;
				}
				int gr=*max_element(a,a+3);
				if(bg==3)
					ans+=3;
				else if(flag==0&&gr>1)
					{ans+=2;

				}
				else if(flag==0)
					ans+=1;
				if(flag==1)
					{ans+=1;
				}
				

			
			cout<<ans<<endl;

		


	}

	return 0;
}