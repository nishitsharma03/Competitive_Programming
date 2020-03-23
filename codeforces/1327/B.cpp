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
		vector<int> v[n+1];
		bool married[n+1],mar[n+1];
		fab(1,n+1,i)
		{married[i]=false;
			mar[i]=false;

		}
		

		ll int k;
		fab(1,n+1,i)
		{
			cin>>k;
			fab(0,k,l)
			{
				ll int p;
				cin>>p;
				if(!married[p]&&!mar[i])
				{	married[p]=true;
					mar[i]=true;
				}
				//v[i].pb(p);
			}
		}
		//fab(1,n+1,i)
		//cout<<married[i]<<" ";
		ll int ind=-1,ind2=-1;
		fab(1,n+1,i)
		{
			if(mar[i]==false)
				{ind=i;
					break;}
		}
		fab(1,n+1,i)
		{
			if(married[i]==false)
			{
				ind2=i;
				break;
			}
		}

		if(ind!=-1&&ind2!=-1)
			{cout<<"IMPROVE\n";
			cout<<ind<<" "<<ind2<<endl;}
			else
				cout<<"OPTIMAL\n";
	}
	

	return 0;
}