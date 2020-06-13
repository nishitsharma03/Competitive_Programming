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
    freopen("input.txt", "r", stdin);
    freopen("output.txt", "w", stdout);
#endif
	int t;
	cin>>t;
	while(t--)
	{
		int n;
		cin>>n;
		ll a[n];
		fab(0,n,i)
		cin>>a[i];
		vector<ll> v;
		v.pb(a[0]);
		fab(1,n,j)
		{
			int i=j+1;

			while(i<n and (a[i]-a[i-1])*(a[j]-a[j-1])>0)
				i++;
			v.pb(a[i-1]);
			j=i-1;
		}
		cout<<v.size()<<endl;
		for(auto i:v)
			cout<<i<<" ";
		cout<<endl;
	}
	

 cerr << "time taken : " << (float)clock() / CLOCKS_PER_SEC << " secs" << endl;
	return 0;
}