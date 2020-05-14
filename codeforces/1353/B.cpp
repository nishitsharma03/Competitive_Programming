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
		ll int a[n],b[n];
		fab(0,n,i)
		cin>>a[i];
		fab(0,n,i)
		cin>>b[i];
		sort(a,a+n);
		sort(b,b+n,greater<int>());
		ll int sum=0;
		ll int cnt=0;
		fab(0,n,i)
		{
			if(a[i]<b[i] and cnt<k)
				{swap(a[i],b[i]);
					cnt++;}
			sum+=a[i];
		}
		cout<<sum<<endl;
	}
	

	return 0;
}