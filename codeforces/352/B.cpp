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
	ll int n;
	cin>>n;
	map<ll int ,vector<ll int> > m;
	map<ll int,ll int> ans;
	ll int a[n];
	fab(0,n,i)
	{
		cin>>a[i];
		m[a[i]].pb(i);
	}
	ll int cnt=0;
	for(auto i:m)
	{
		vector<ll int > v=i.se;
		if(v.size()<2)
			{ans[i.f]=0;
				cnt++;
				continue;}
		ll int diff=v[1]-v[0];
		bool f=true;
		fab(2,v.size(),j)
		{
			if(v[j]-v[j-1]!=diff)
				f=false;

		}
		if(f)
		{
			cnt++;
			ans[i.f]=diff;

		}
	}
		cout<<cnt<<endl;
		for(auto i:ans)
			cout<<i.f<<" "<<i.se<<endl;

	

	return 0;
}