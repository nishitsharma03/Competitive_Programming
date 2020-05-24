//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
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
		int n;
		cin>>n;
		int a[n];
		int req[2]={0};
		fab(0,n,i)
		{
			cin>>a[i];
			req[a[i]%2]++;

		}
		sort(a,a+n);
		if(req[0]%2==0 and req[1]%2==0)
			cout<<"YES\n";
		else
			{
				string ans="NO";
				fab(0,n,i)
				{
					if(a[i+1]-a[i]==1)
						{ans="YES";
					break;}
				}
				cout<<ans<<endl;
			}
	}
	

	return 0;
}