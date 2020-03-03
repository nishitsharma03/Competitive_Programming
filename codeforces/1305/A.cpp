#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;i++)
#define pb push_back
#define db double
#define mp make_pair
#define s second
#define f first
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
		int x[n],b[n];
		pair<int,int> xp[n],xpp[n];
		fab(0,n,i)
		{
			cin>>x[i];
			xp[i]=mp(x[i],i);
			xpp[i]=mp(i,x[i]);
		}
		fab(0,n,i)
		cin>>b[i];
		sort(b,b+n);
		sort(xp,xp+n);
		pair<int,int> ans[n];
		fab(0,n,i)
		{
			ans[xp[i].second]=mp(xp[i].f,b[i]);

		}
		fab(0,n,i)
		cout<<ans[i].f<<" ";
		cout<<endl;
		fab(0,n,i)
		cout<<ans[i].s<<" ";
		cout<<endl;

	}
	

	return 0;
}