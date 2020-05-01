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
		ll int n,k;
		cin>>n>>k;
		ll int a[n],mx=0,mn=1e12;
		set<ll int,greater<ll int> > s;
		fab(0,n,i)
		{
			cin>>a[i];
			if(a[i]>mx)
				mx=a[i];
			if(a[i]<mn)
				mn=a[i];
			s.insert(a[i]);
		}
	/*	if(k==1)
		{
			int fl=500;
			fab(0,n,i)
			{
				if(a[i]!=a[0])
				{
					fl=-1;
					break;
				}
			}
			if(fl==-1)
				cout<<-1<<endl;
			else
			{
				cout<<n<<endl;
				fab(0,n,i)
				cout<<a[i]<<" ";
				cout<<endl;

			}
			continue;
		}*/
		if(s.size()>k)
		{
			cout<<-1<<endl;
			continue;

		}
		else
		{
			if(mx<=k)
				{mx=k;
					mn=1;
				}
				ll int ii=1;
			while(s.size()<k)
			{
				s.insert(ii);
				ii++;
			}	
			cout<<n*(k)<<endl;

			fab(0,n,i)
			{
				for(auto i:s)
					cout<<i<<" ";


			}
			cout<<endl;
		}
	}
	

	return 0;
}