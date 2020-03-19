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
		if(n==1)
		{
			cout<<-1<<endl;
			continue;
		}
		int sum=0;
		fab(1,n,i)
		sum+=2;
		if(sum%3==0)
			{cout<<3;
		fab(0,n-2,i)
		cout<<2;
		cout<<3;}
		else
		{
			fab(0,n-1,i)
			cout<<2;
			cout<<3;

		}
		cout<<endl;
	}
	

	return 0;
}