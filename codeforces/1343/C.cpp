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
		ll int n;
		cin>>n;
		ll int a[n];
		bool pres=false;
		fab(0,n,i)
		{cin>>a[i];
			if(a[i]>0)
				pres=true;
		}
		if(pres==false)
			{cout<<*max_element(a,a+n)<<endl;
		continue;}
		bool neg=true;
		if(a[0]>0)
		 neg=false;
		ll int sum=0;
		//cout<<"neg:"<<neg<<endl;

		fab(0,n,i)
		{
			if(neg==false)
			{
				//cout<<"i:"<<i<<endl;
				while(i<n and a[i]<0)
					i++;
				if(i<n)
				{
					ll int max=0;
					while(i<n and a[i]>0)
					{
						if(a[i]>max)
							max=a[i];
						i++;
					}
					i--;
					//cout<<"max:"<<max<<endl;
					sum+=max;
				}
				neg=true;
			}
			else
			{
				//cout<<"i:"<<i<<endl;
				while(i<n and a[i]>0)
					i++;
				if(i<n)
				{
					ll int min=-1e9-10;
					while(i<n and a[i]<0)
					{
						if(a[i]>min)
							min=a[i];
					i++;
					}
					//cout<<"min:"<<min<<endl;
					sum+=min;
					i--;
				}
				neg=false;
			}

		}
		cout<<sum<<endl;
	}
	

	return 0;
}