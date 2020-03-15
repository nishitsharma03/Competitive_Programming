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
	int n;
	cin>>n;
	ll int a[n],b[n];
	//vector<int> pos,neg;
	vector<ll int> v;
	ll int k;
	fab(0,n,i)
	{
		cin>>a[i];

	}
	fab(0,n,i)
	cin>>b[i];
	fab(0,n,i)
	{
		ll int p=a[i]-b[i];
		v.pb(p);

	}
	sort(all(v));
	ll int ot=0;
	fab(0,n,i)
	{
		if(v[i]>0)
		{
			int ind = lower_bound(all(v),-v[i]+1)-v.begin();
			ot+=i-ind;
		}
	}
	cout<<ot<<endl;



	return 0;
}