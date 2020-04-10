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
		ll int a[n],b[n];
		pair<ll int,ll int> p[n];
		fab(0,n,i)
		cin>>a[i]>>b[i];
		//p[i]=mp(a[i],i);}
		//multimap<ll int ,pair<ll int, ll int>] m;
		//sort(p,p+n);
		bool kill[n];
		//fab(0,n,i)
		//kill[i]=false;
		ll int min=a[0],ind=0,sum=0,ans=342355676356477555,diff[n];
		fab(0,n,i)
		{
			if(a[i]<min)
			{
				min=a[i];
				ind=i;
			}
			if(a[i]==min)
			{
				if(b[i]>b[ind])
					ind=i;
			}
		}
		fab(0,n,i)
		{	
			if(a[(i+1)%n]-b[i]>0)
			diff[i]=a[(i+1)%n]-b[i];
		else
			diff[i]=0;
			sum+=diff[i];
		}
		//cout<<sum<<endl;
		//fab(0,n,i)
		//cout<<diff[i]<<" ";
		fab(0,n,i)
		{	
			ll int k;
			if(i==0)
			 k=sum-diff[n-1];
			else
				k=sum-diff[i-1];
			ll int temp=a[i]+k;
			//cout<<"temp"<<k<<" "<<a[i]<<" \n";
			if(temp<ans)
				{ans=temp;
					ind=i;}
		}
		/*ans+=a[ind];
		cout<<ind<<endl;
		ll int dam=b[ind];
		ll int i=ind+1;
		while(i%n!=ind)
		{
			if(a[i%n]-dam>0)
			{
				
				ans+=a[i%n]-dam;
				
			}
			dam=b[i%n];
			i++;

		}*/
		//cout<<"ind="<<ind<<endl;
		cout<<ans<<endl;
		
	}
	

	return 0;
}