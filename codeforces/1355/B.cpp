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
		vector<ll int> a(n);
		fab(0,n,i)
		cin>>a[i];
		sort(all(a));
		ll int ans=0;
		fab(0,n,i)
		{
			multiset<int ,greater<int> > s;
			s.insert(a[i]);
			while(i<n and s.size()<*s.begin())
			{
				i+=1;
				s.insert(a[i]);

			}
			if(s.size()==*s.begin())
				ans++;

		}
		cout<<ans<<endl;

	}
	

	return 0;
}