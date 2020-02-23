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
		ll int n,x,y;
		cin>>n>>x>>y;
		
		 ll int max=n,min=1;
			


		 ll int sum=x+y;
		ll int cnt=1;
		ll int xx=sum+1-max;
		//cout<<"xx="<<xx<<"  ";

		if(xx>1)
			{	cnt+=xx-1;

		}

		if(min==2&&xx==1)
			cnt+=1;	
		if(cnt>n)
			cnt=n;	

		
		
		
		ll int  cnt1=n;
		ll int yy=sum-max;
		if(yy<=0)
			cnt1+=(yy-1);

		


		cout<<cnt<<" "<<cnt1<<endl;



	}

	return 0;
}