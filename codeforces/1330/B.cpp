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
		//cout<<"n="<<n<<" ";
		ll int a[n];
		fab(0,n,i)
		cin>>a[i];
		int freq[200005]={0},freq2[200005]={0};//freq3[200005]={0};

		//fab(0,n,i)
		//cout<<a[i]<<" ";
		ll int su=0,ans=-1;
		fab(0,n,i)
		{
			freq2[a[i]]++;
		if(freq2[a[i]]>2)
			{ans=0;
		break;}
	}

	fab(0,200005,i)
	freq2[i]=0;
		ll int sum=0,pmax[n]={0};

		ll int max=0;
		for(int i=n-1;i>=0;i--)
		{
			if(a[i]>max)
				max=a[i];
			pmax[i]=max;
		}
		vector<int> l1;
		fab(0,n,i)
		sum+=a[i];
		

		 max=0;
		 ll int las=0;
		 for(int i=n-1;i>=0;i--)
		 {
		 	freq2[a[i]]++;
		 	if(freq2[a[i]]>1)
		 	{
		 		las=i;
		 		break;
		 	}
		 }
		//// cout<<"las=ii"<<las<<" ";
		 max=0;
		 fab(0,las,i)
		 {
		 	if(a[i]>max)
				max=a[i];
			su+=a[i];
			freq[a[i]]++;
			if(freq[a[i]]>1)
				{	ans=0;
					break;
				}
		 }
		 //cout<<"su="<<su<<" "<<ans<<" ";
		 if(ans==0)
		 {
		 	cout<<0<<endl;
		 	continue;
		 }
		 ans=0;
		fab(las,n-1,i)
		{
			if(a[i]>max)
				max=a[i];
			su+=a[i];
			freq[a[i]]++;
			//cout<<"fre"<<freq[a[i]]<<" ";
			if(freq[a[i]]>1)
				break;

			if(su==(max*(max+1)/2))
			{	
				//cout<<"i="<<max<<endl;
				if(sum-su==(pmax[i+1]*(pmax[i+1]+1)/2))
					{ans++;
						l1.pb(i+1);
						}
			}
		}
		cout<<ans<<endl;
		fab(0,l1.size(),i)
		cout<<l1[i]<<" "<<n-l1[i]<<endl;
	}
	

	return 0;
}