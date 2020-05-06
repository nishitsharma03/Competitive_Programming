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
vector<ll int> v;
int main()
{ quick;
#ifndef ONLINE_JUDGE
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	ll int cnt=1,k=0;
	while(k<1e9)
	{
		k=2*cnt+(3*(cnt*(cnt-1)))/2;
		v.pb(k);
		cnt++;

	}
	while(t--)
	{
		ll int n;
		cin>>n;
		ll int ans=0;
		//for( auto i: v)
			//cout<<v.size()<<" ";
		while(n>1)
		{
			auto val=lower_bound(all(v),n);
			//cout<<"val::"<<*val<<endl;
			if(*val>n)
				val--;
			n-=*val;
			ans++;

		}
		cout<<ans<<endl;

	}
	

	return 0;
}