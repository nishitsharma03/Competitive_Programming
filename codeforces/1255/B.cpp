#pragma GCC optimize "trapv"
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
		int n,m;
		cin>>n>>m;
		int a[n];
		fab(0,n,i)
		{
			cin>>a[i];
		}
		if(m<n||n<3)
		{
			cout<<-1<<endl;
			continue;
		}
		else
		{
			cout<<2*accumulate(a,a+n,0)<<endl;
			fab(0,n-1,i)
			{
				cout<<(i+1)<<" "<<(i+2)<<endl;
			}
			cout<<n<<" "<<1<<endl;

		}
	}
	

	return 0;
}