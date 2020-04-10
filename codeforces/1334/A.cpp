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
		pair<ll int ,ll int> a[n];
		fab(0,n,i)
		{
			ll int l,k;
			cin>>l>>k;
			a[i]=mp(l,k);
		}
		string ans="YES";
		if(a[0].f<a[0].se)
			ans="NO";
		fab(1,n,i)
		{
			if(a[i].f-a[i-1].f<0)
				ans="NO";
			if(a[i].f-a[i-1].f<a[i].se-a[i-1].se)
				ans="NO";
			if(a[i].se-a[i-1].se<0)
				ans="NO";
			if(a[i].f<a[i].se)
				ans="NO";

		}
		cout<<ans<<endl;
	}
	

	return 0;
}