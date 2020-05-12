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
		ll int a[n];
		bool fl=false;
		fab(0,n,i)
		{
			cin>>a[i];
			if(a[i]==k)
				{a[i]=1;
					fl=true;
				}
			else if(a[i]>k)
				a[i]=2;
			else
				a[i]=0;
		}
		if(!fl)
			{cout<<"no\n";
		continue;}
		if(n==1 and fl)
		{
			cout<<"yes\n";
			continue;
		}
		string ans="no";
		fab(0,n,i)
		{
			fab(i+1,n && j-i<=2,j)
			{
				if(a[i]>0 and a[j]>0)
					{ans="yes";
						break;
					}
			}
		}
		cout<<ans<<endl;	
	}
	

	return 0;
}