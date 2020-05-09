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
	ll int a[16];
	a[0]=1;
	fab(1,15,i)
	{
		a[i]=a[i-1]*10;
	}
	while(t--)
	{
		ll int n;
		cin>>n;
		ll tm=n;
		int cnt=0;
		vector<ll int> v;
		while(tm>0)
			{
				ll int k=tm%10;
				if(k!=0)
				{
					v.pb(a[cnt]*k);

				}
				tm/=10;
				cnt++;
			}
			cout<<v.size()<<endl;
			for(auto i: v)
				cout<<i<<" ";
			cout<<endl;
	}
	

	return 0;
}