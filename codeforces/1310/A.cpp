//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long 
#define fab(a,b,i) for(int i=a;i<b;++i)
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
	vector<ll int> a(n),b(n);
	fab(0,n,i)
		cin>>a[i];
	fab(0,n,i)
		cin>>b[i];
	map<ll int, vector<ll int> > m;
	fab(0,n,i)
	{
		m[a[i]].pb(b[i]);
	}
	priority_queue<ll int> q;
	ll int ans=0,sm=0;
	for( auto &i:m)
	{	
		ans+=sm;
		vector<ll int> v=i.second;
		fab(0,v.size(),i)
		{
			if(v[i]==-1){
				continue;}
			
			q.push(v[i]);
			sm+=v[i];
			
		}
		sm-=(q.top());
		q.pop();
		if(sm!=0)
		{
			m[i.first+1].pb(-1);
		}

	}
	cout<<ans<<endl;

	

	return 0;
}