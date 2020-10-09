//#pragma GCC optimize "trapv"
#include<bits/stdc++.h>
#define ll long long int
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
    freopen("D:/sublime/input.txt", "r", stdin);
    freopen("D:/sublime/output.txt", "w", stdout);
#endif
	int n;
	cin>>n;
	ll a[n];
	fab(0,n,i)
	cin>>a[i];
	ll sum=0;
	vector<ll> pref(n);
	fab(0,n,i)
	{
		sum+=a[i];
		pref[i]=sum;
	}
	if(sum%3!=0 or n<=2)
	{
		cout<<0<<endl;
	
		return 0;
	}
	map<ll,vector<int>> m;	
	fab(0,n-1,i)
	{
		m[pref[i]].pb(i);
	}
	ll ans=0;
	fab(0,n,i)
	{
		if(pref[i]==sum/3 and m.find(pref[i]*2)!=m.end())
		{
			int val=(m[2*pref[i]].end()-lower_bound(all(m[pref[i]*2]),i+1));
			// cout<<"Val:"<<val<<" "<<i<<" "<<pref[i]<<endl;

			
			ans+=val;
		}
	}
	cout<<ans<<endl;

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}