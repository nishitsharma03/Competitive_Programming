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
		int n;
		cin>>n;
		int a[n];

		fab(0,n,i)
		{
			cin>>a[i];
			
		}
		vector<int> ans;
		bool flag=false;
		fab(0,n,i)
		{
			if(a[i]%2)
			{
				ans.pb(i+1);
				if(ans.size()%2==0)
					break;

			}
			else
				{cout<<1<<endl<<i+1<<endl;
					flag=true;
			break;}
		}
		if(!flag)
		{
			if(ans.size()%2)
				cout<<-1<<endl;
			else
			{cout<<ans.size()<<endl;
			fab(0,ans.size(),i)
			cout<<ans[i]<<" ";
			cout<<endl;}
		}
	}

	return 0;
}