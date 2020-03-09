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
		int n,k;
		cin>>n>>k;
		ll int a[n];
		fab(0,n,i)
		cin>>a[i];
		bool fl=true;
		int arr[1000]={0};
		fab(0,n,i)
		{
				ll int temp=a[i],te=a[i];
			//	int mo=a[i]%k;
			
			
				int cnt=0;
			while(temp>0)
			{
				if(temp%k==0)
				{cnt++;
				temp/=k;}
				else
				{
					//cout<<"cnt="<<cnt<<" i="<<i<<"temp="<<temp<<endl;
					if(arr[cnt]==0)
						{arr[cnt]+=1;

							}
					else
					{
						arr[cnt]+=1;
						fl=false;
						break;
					}
					te-=(pow(k,cnt));
					temp=te;
					//cout<<"temo"<<temp;
					cnt=0;

				}

			}
		}
		//fab(0,20,i)
		//cout<<arr[i]<<" ";

			if(!fl)
				cout<<"NO\n";
			else
				cout<<"YES\n";

			
		
		
	}
	//cout<<fixed<<pow(2,60);

	return 0;
}
