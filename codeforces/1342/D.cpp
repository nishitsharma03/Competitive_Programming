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
	ll int n,k;
	cin>>n>>k;
	ll int a[n];
	map<ll int,ll int> m;
	fab(0,n,i)
	{
	cin>>a[i];
	m[a[i]]++;}
	sort(a,a+n);
	ll int c[k+1];
	fab(1,k+1,i)
	cin>>c[i];
	ll int sum=0;
	ll int ma=0;
	map<ll int,ll int>::reverse_iterator i;
	for(i=m.rbegin();i!=m.rend();i++)
	{
		sum+=i->se;
		int req=ceil(db(sum)/c[i->f]);
		if(req>ma)
			ma=req;
	}
	cout<<ma<<endl;
	vector< vector<ll int> > v(ma);
	fab(0,n,i)
	{
		v[i%ma].pb(a[i]);
	}
	fab(0,ma,i)
	{
		cout<<v[i].size()<<" ";
		for(auto j:v[i])
			cout<<j<<" ";
		cout<<endl;
	}
	return 0;
}