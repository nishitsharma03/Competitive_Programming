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
		vector<ll int> v;
		ll int s=n;
		for(int i=1;i<=s;i*=2)
		{
			v.pb(i);
			s-=i;
		}
		if(s>0)
			v.pb(s);
		sort(all(v));
		cout<<v.size()-1<<endl;
		fab(1,v.size(),i)
		cout<<v[i]-v[i-1]<<" ";
		cout<<endl;
	}

	

	return 0;
}